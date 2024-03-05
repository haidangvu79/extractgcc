#!/bin/bash

# checks that *_ok tests have no errors, and that *_bad tests do have errors

if [ $# -lt 1 ]; then
    echo "usage: $0 file1.csv [file2.csv ...]"
    exit 1
fi

checked=0
wrong=0

for f in "$@"; do
    checked=$((checked + 1))
    alarms=$(sed 1d $f | wc -l | cut -d' ' -f 1)
    if [[ "$f" =~ "_bad" ]]; then
        if [ $alarms -gt 0 ]; then
            : #echo "bad, OK: $f"
        else
            echo "bad, KO: ${f%/alarms.csv}"
            wrong=$((wrong+1))
        fi
    elif [[ "$f" =~ "_ok" ]]; then
        if [ $alarms -gt 0 ]; then
            echo "ok,  KO: ${f%/alarms.csv}"
            wrong=$((wrong+1))
        else
            : #echo "ok,  OK: $f"
        fi
    else
        echo "test neither ok nor bad? $f"
        exit 1
    fi
done

echo "Checked $checked file(s)".

if [ $wrong -gt 0 ]; then
    echo "Number of wrong tests: $wrong"
    exit 1
fi
