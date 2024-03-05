#!/usr/bin/env python3

"""Benchmarks OSCS targets to compare performance with and without use of -ast-diff"""

import argparse
import csv
import os
import sys

import subprocess as sp
from shutil import which, rmtree
from pathlib import Path

frama_c_config = which("frama-c-config")
make = which("make")

if frama_c_config is None:
    sys.exit("error: cannot find frama-c-config in the path")


def run_and_check(args):
    with sp.Popen(args, stdout=sp.PIPE, stderr=sp.STDOUT) as proc:
        out, _ = proc.communicate()
        if proc.returncode != 0:
            sys.exit(f"Error: {args} returned {proc.returncode}: {out}")
        return out.decode()


frama_c_lib = Path(run_and_check([frama_c_config, "-print-lib-path"]))

sys.path.append(str(frama_c_lib / "analysis-scripts"))

import frama_c_results as fcres

def create_csv(f, rows):
    with open(f, "w", newline="", encoding="utf-8", errors="ignore") as file:
        fieldnames = ["name", "user_time_standard", "user_time_ast_diff", "gain"]
        writer = csv.DictWriter(file, fieldnames=fieldnames, extrasaction="ignore")
        writer.writeheader()
        writer.writerows(rows)


def process_target(target):
    print(f"now processing {target}")
    if os.access(target, os.F_OK):
        rmtree(Path(target), ignore_errors=True)
    print("standard pass")
    res = sp.run([make, target], stdout=sp.DEVNULL)
    row = {"name": target}
    if res.returncode == 0:
        standard = fcres.load(target + "/stats.txt")
        timeout = 60
        if "user_time" in standard:
            row["user_time_standard"] = standard["user_time"]
            baseline = float(standard["user_time"])
            timeout = baseline * 5
            env = os.environ.copy()
            env["AST_DIFF"] = "1"
            print("AST diff pass")
            try:
                sp.run(
                    [make, target],
                    env=env,
                    timeout=timeout,
                    stdout=sp.DEVNULL,
                    stderr=sp.DEVNULL,
                )
                ast_diff = fcres.load(target + "/stats.txt")
                if "user_time" in ast_diff:
                    row["user_time_ast_diff"] = ast_diff["user_time"]
                    with_ast_diff = float(row["user_time_ast_diff"])
                    row["gain"] = (baseline - with_ast_diff) / baseline
                else:
                    row["user_time_ast_diff"] = "FAILURE"
            except sp.TimeoutExpired:
                row["user_time_ast_diff"] = "TIMEOUT"
        return row
    else:
        sys.exit(f"error when processing target: {target}")


def run_bench(targets):
    total_standard = 0
    total_ast_diff = 0
    rows = []
    for t in targets:
        row = process_target(t)
        if "gain" in row:
            total_standard += float(row["user_time_standard"])
            total_ast_diff += float(row["user_time_ast_diff"])
        rows.append(row)
    rows.append(
        {
            "name": "total when both succeed",
            "user_time_standard": total_standard,
            "user_time_ast_diff": total_ast_diff,
            "gain": (total_standard - total_ast_diff) / total_standard,
        }
    )
    return rows


parser = argparse.ArgumentParser(
    description="Run analyses first in normal mode "
    "and then in incremental mode "
    "(without syntactic diff)"
)
parser.add_argument(
    "-o",
    "--output",
    action="store",
    metavar="PATH",
    type=Path,
    help="store results in the given file",
)

args, targets = parser.parse_known_args()
if not targets:
    print("No targets specified in command line, running for all targets")
    targets = run_and_check([make, "display-targets"]).split()
rows = run_bench(targets)
if args.output is not None:
    create_csv(args.output, rows)
else:
    print("Results:")
    print("name,user_time_standard,user_time_ast_diff,gain")
    for row in rows:
        print(
            f"{row['name']},{row['user_time_standard']},{row['user_time_ast_diff']},{row['gain']}"
        )
