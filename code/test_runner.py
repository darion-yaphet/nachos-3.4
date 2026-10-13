#!/usr/bin/env python3
"""
Nachos Educational Automated Test Suite Runner (test_runner.py)

Designed for operating system course labs, student self-testing,
and automated grading (Autograder / CI).
"""

import sys
import os
import subprocess
import time
import argparse
import math
import signal
import tempfile

# ANSI color escape codes
GREEN = "\033[92m"
RED = "\033[91m"
YELLOW = "\033[93m"
BLUE = "\033[94m"
CYAN = "\033[96m"
BOLD = "\033[1m"
RESET = "\033[0m"

# Auto-detect terminal color support
if not sys.stdout.isatty():
    GREEN = RED = YELLOW = BLUE = CYAN = BOLD = RESET = ""


class TestCase:
    def __init__(self, name, binary_path, args, expected_substrings=None, forbidden_substrings=None, description="", expected_returncode=0):
        self.name = name
        self.binary_path = binary_path
        self.args = args
        self.expected_substrings = expected_substrings or []
        self.forbidden_substrings = forbidden_substrings or []
        self.description = description
        self.expected_returncode = expected_returncode


def get_test_suite(code_dir):
    tests = [
        TestCase(
            name="threads_concurrency",
            binary_path=os.path.join(code_dir, "threads", "nachos"),
            args=[],
            expected_substrings=[
                "thread 0 looped 0 times",
                "thread 1 looped 4 times",
                "Mutex & LockGuard test PASSED (counter = 20)",
                "Condition Variable (Mesa) test PASSED",
                "Thread::Join test PASSED (status = 70)",
                "Machine halting!"
            ],
            forbidden_substrings=["Assertion failed", "FATAL", "Self-deadlock", "Lock misuse"],
            description="Thread concurrency, Lock/LockGuard mutual exclusion, Mesa Condition Variable, and Thread::Join"
        ),
        TestCase(
            name="threads_structured_logging",
            binary_path=os.path.join(code_dir, "threads", "nachos"),
            args=["-d", "t"],
            expected_substrings=[
                "[INFO][t]",
                "Starting Nachos Concurrency Test Suite",
                "All Nachos Concurrency Tests PASSED",
                "Machine halting!"
            ],
            forbidden_substrings=["Assertion failed"],
            description="Modern structured logging and thread execution tracing"
        ),
        TestCase(
            name="filesys_format_and_dump",
            binary_path=os.path.join(code_dir, "filesys", "nachos"),
            args=["-f", "-D"],
            expected_substrings=[
                "Bit map file header:",
                "Directory file header:",
                "Bitmap set:",
                "Machine halting!"
            ],
            forbidden_substrings=["Assertion failed", "Bus error", "Segmentation fault"],
            description="Virtual disk formatting, bitmap allocation, and directory initialization"
        ),
        TestCase(
            name="userprog_initialization",
            binary_path=os.path.join(code_dir, "userprog", "nachos"),
            args=[],
            expected_substrings=[
                "Machine halting!",
                "Ticks: total"
            ],
            forbidden_substrings=["Assertion failed"],
            description="User program subsystem bootstrap and clean halt"
        ),
        TestCase(
            name="vm_tlb_initialization",
            binary_path=os.path.join(code_dir, "vm", "nachos"),
            args=[],
            expected_substrings=[
                "Machine halting!",
                "Ticks: total"
            ],
            forbidden_substrings=["Assertion failed"],
            description="Virtual memory subsystem with TLB support bootstrap and halt"
        ),
    ]
    regressions = [
        ("list_ownership", "threads", ["-T", "list"], "List ownership tests PASSED"),
        ("threads_detached_lifecycle", "threads", ["-T", "lifecycle"], "Detached thread lifecycle tests PASSED"),
        ("threads_join_completed", "threads", ["-T", "join"], "Join boundary tests PASSED"),
        ("userprog_memory_boundaries", "userprog", ["-T", "usermem"], "User memory boundary tests PASSED"),
        ("vm_memory_boundaries", "vm", ["-T", "usermem"], "User memory boundary tests PASSED"),
        ("filesys_boundaries", "filesys", ["-f", "-T", "filesys"], "File system boundary tests PASSED"),
        ("network_self_delivery", "network", ["-f", "-T", "network"], "Network self-delivery tests PASSED"),
    ]
    for name, module, args, expected in regressions:
        tests.append(TestCase(name, os.path.join(code_dir, module, "nachos"), args,
                              [expected, "Machine halting!"], ["Assertion failed"]))
    for suite, diagnostics in [
        ("join-unstarted", ["Assertion failed", "../threads/thread.cc"]),
        ("join-multiple", ["Assertion failed", "../threads/thread.cc"]),
        ("lock-misuse", ["Assertion failed", "[ERROR][s]", "Lock misuse detected"]),
        ("guard-null", ["Assertion failed", "../threads/synch.h"]),
    ]:
        tests.append(TestCase("threads_reject_" + suite.replace("-", "_"),
                              os.path.join(code_dir, "threads", "nachos"),
                              ["-T", suite], diagnostics,
                              expected_returncode=-signal.SIGABRT))
    for seed in (1, 7, 42):
        tests.append(TestCase(f"threads_random_schedule_{seed}",
                              os.path.join(code_dir, "threads", "nachos"),
                              ["-rs", str(seed), "-d", "t", "-T", "join"],
                              ["All Nachos Concurrency Tests PASSED", "Join boundary tests PASSED"],
                              ["Assertion failed"]))
    return tests


def run_test(test, timeout, verbose):
    if not os.path.isfile(test.binary_path):
        return False, f"Binary '{test.binary_path}' not found. Please run 'make' first.", 0.0

    cmd = [os.path.abspath(test.binary_path)] + test.args
    start_time = time.monotonic()
    try:
        # Nachos creates DISK and Unix sockets relative to cwd. Keep tests away
        # from the developer's disk, and from each other.
        with tempfile.TemporaryDirectory(prefix="nachos-test-") as work_dir:
            proc = subprocess.run(
                cmd,
                cwd=work_dir,
                stdout=subprocess.PIPE,
                stderr=subprocess.STDOUT,
                text=True,
                timeout=timeout
            )
        elapsed = time.monotonic() - start_time
        output = proc.stdout

        if proc.returncode != test.expected_returncode:
            return False, f"Process exited with code {proc.returncode}, expected {test.expected_returncode}.\nOutput:\n{output}", elapsed

        for substr in test.expected_substrings:
            if substr not in output:
                return False, f"Expected output missing: '{substr}'.\nFull output:\n{output}", elapsed

        for substr in test.forbidden_substrings:
            if substr in output:
                return False, f"Forbidden output detected: '{substr}'.\nFull output:\n{output}", elapsed

        return True, output, elapsed

    except subprocess.TimeoutExpired:
        elapsed = time.monotonic() - start_time
        return False, f"Execution timed out after {timeout} seconds (potential deadlock or infinite loop).", elapsed
    except Exception as e:
        elapsed = time.monotonic() - start_time
        return False, f"Execution error: {str(e)}", elapsed


def main():
    parser = argparse.ArgumentParser(description="Nachos Educational Automated Test Suite Runner")
    parser.add_argument("--filter", "-f", type=str, default="", help="Filter tests by name substring")
    parser.add_argument("--verbose", "-v", action="store_true", help="Print verbose test output")
    parser.add_argument("--timeout", "-t", type=float, default=10.0, help="Per-test timeout in seconds (default: 10s)")
    args = parser.parse_args()
    if not math.isfinite(args.timeout) or args.timeout <= 0:
        parser.error("--timeout must be a finite positive number")

    script_dir = os.path.dirname(os.path.abspath(__file__))
    code_dir = script_dir

    tests = get_test_suite(code_dir)
    if args.filter:
        tests = [t for t in tests if args.filter.lower() in t.name.lower()]
    if not tests:
        parser.error(f"No tests match filter: {args.filter!r}")

    print(f"{BOLD}{BLUE}======================================================================{RESET}")
    print(f"{BOLD}{BLUE}               Nachos Educational Automated Test Suite                {RESET}")
    print(f"{BOLD}{BLUE}======================================================================{RESET}")
    print(f"Total test cases selected: {len(tests)}\n")

    passed_count = 0
    total_start = time.monotonic()

    for idx, test in enumerate(tests, start=1):
        print(f"[{idx}/{len(tests)}] Running {BOLD}{test.name}{RESET} ... ", end="", flush=True)
        success, output, elapsed = run_test(test, args.timeout, args.verbose)

        if success:
            passed_count += 1
            print(f"{GREEN}{BOLD}[PASS]{RESET} ({elapsed * 1000:.1f}ms)")
            if args.verbose:
                print(f"{CYAN}--- Output ---{RESET}\n{output.strip()}\n{CYAN}--------------{RESET}")
        else:
            print(f"{RED}{BOLD}[FAIL]{RESET} ({elapsed * 1000:.1f}ms)")
            print(f"{YELLOW}Reason:{RESET} {output}")

    total_elapsed = time.monotonic() - total_start
    print(f"\n{BOLD}{BLUE}======================================================================{RESET}")
    summary_color = GREEN if passed_count == len(tests) else RED
    print(f"Summary: {summary_color}{passed_count}/{len(tests)} passed{RESET} "
          f"({(passed_count / len(tests) * 100) if tests else 0.0:.1f}%) "
          f"- Total time: {total_elapsed:.2f}s")
    print(f"{BOLD}{BLUE}======================================================================{RESET}")

    sys.exit(0 if passed_count == len(tests) else 1)


if __name__ == "__main__":
    main()
