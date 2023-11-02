#!/bin/bash
count=0
success=1
for problem in $(find ./baekjoon -name "*.cpp"); do
    {
        python3 test.py $problem 
        if [[ $? -ne 0 ]]; then
            echo "[FAIL] $problem"
            success=0
        else
            echo "[PASS] $problem"
        fi
        count=$((count+1))
    } &
    if [[ $((count%$(nproc))) -eq 0 ]]; then
        wait
    fi
    if [[ $success -eq 0 ]]; then
        exit 1
    fi
done
wait
exit $success