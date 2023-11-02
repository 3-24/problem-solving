#!/bin/bash
for problem in $(find ./baekjoon -name "*.cpp"); do
    python3 test.py $problem 
    if [[ $? -ne 0 ]]; then
        echo "[FAIL] $problem"
        exit 1
    else
        echo "[PASS] $problem"
    fi
done
exit 0

