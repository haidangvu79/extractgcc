#!/bin/bash

DIR=01_w_Defects

FILES=$(awk '/SUBDIR_SRCS/{flag=1;next}/^$/{flag=0}flag' GNUmakefile)

FILES_WITH_DIR=$(echo "$FILES" | sed "s|[^ ]* |$DIR/&|g" | tr -d '\\')

grep "Tool should detect" -n $FILES_WITH_DIR | grep -v "FC-noUB" | grep -v "FC-disabled" | cut -d: -f1-2 > intended-errors.txt

cat 01_w_Defects.eva/alarms.csv | tail -n +2 | cut -f2-3 | sed 's/\t/:/g' | sed "s|^|$DIR/|" > actual-errors.txt

echo "Compare files intended-errors.txt and actual-errors.txt to check for discrepancies."


## Note: the files have some "well-known" discrepancies:
# - A few extra lines appear on "actual-errors.txt" due to Frama-C/Eva
#   generating two alarms for the same statement; these are easily identifiable
#   by having identical line numbers to the previous warning;
# - A few extra lines appear on "intended-errors.txt" due to the fact that
#   calls to strcpy() are reported inside the stub implementation of the
#   function, not on the caller;
# - the warnings in return_local differ in line numbers due to being reported
#   when the dangling variable is used, not when it is created;
# - at the end, the lines related to the stdlib (stdlib.h, string.c, string.h)
#   correspond to warnings created in their callers.
