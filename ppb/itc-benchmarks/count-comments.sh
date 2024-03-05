#!/bin/bash

comments01=$(grep -E '// ?Frama-C/Eva' 01_w_Defects/*.c | wc -l)
comments01_main=$(grep -E '// ?Frama-C/Eva' 01_w_Defects/main.c | wc -l)
comments01=$((comments01 - comments01_main))

comments02=$(grep -E '// ?Frama-C/Eva' 02_wo_Defects/*.c | wc -l)
comments02_main=$(grep -E '// ?Frama-C/Eva' 02_wo_Defects/main.c | wc -l)
comments02=$((comments02 - comments02_main))

echo "Comments 01: $comments01"
echo "Comments 02: $comments02"

for f in 01_w_Defects/*.c; do
    adjusted=$(grep -E 'FC-adjusted' $f | wc -l)
    if [ $adjusted -gt 0 ]; then
        echo "$f: $adjusted #adjusted"
    fi
    adapted=$(grep -E 'FC-adapted' $f | wc -l)
    if [ $adapted -gt 0 ]; then
        echo "$f: $adapted #adapted"
    fi
    alarm_but_no_ub=$(grep -E 'FC-alarm-but-noUB' $f | wc -l)
    if [ $alarm_but_no_ub -gt 0 ]; then
        echo "$f: $alarm_but_no_ub #alarm-but-noUB"
    fi
    different_ub=$(grep -E 'FC-different-UB' $f | wc -l)
    if [ $different_ub -gt 0 ]; then
        echo "$f: $different_ub #different-UB"
    fi
    no_ub=$(grep -E 'FC-noUB' $f | wc -l)
    if [ $no_ub -gt 0 ]; then
        echo "$f: $no_ub #noUB"
    fi
    disabled=$(grep -E 'FC-disabled' $f | wc -l)
    if [ $disabled -gt 0 ]; then
        echo "$f: $disabled #disabled"
    fi
done
