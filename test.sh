#!/bin/bash
count=0
fail=0
for problem in $(find ./baekjoon -name "*.cpp"); do
    {
        python3 test.py $problem 
        if [[ $? -ne 0 ]]; then
            echo "[FAIL] $problem"
            fail=1
        else
            echo "[PASS] $problem"
        fi
        count=$((count+1))
    } &
    if [[ $((count%$(nproc))) -eq 0 ]]; then
        wait
    fi
    if [[ $fail -eq 1 ]]; then
        exit 1
    fi
done
wait
exit $fail