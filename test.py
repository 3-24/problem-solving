import sys
import subprocess as sp
import os
from pathlib import Path

def test(file):
    test_file = f"{file}.test"
    test_bin = Path("bin") / file.with_suffix("")
    
    # Check if test file exist
    if not os.path.isfile(test_file):
        print("No test file found.")
        return 0

    if not os.path.isfile(test_bin):
        print("No binary found.")
        return 1

    with open(test_file, "rb") as f:
        content = f.read()

    testcases = content.split(b"\n\n")

    for testcase in testcases:
        assert testcase.startswith(b"IN:\n")
        out_idx = testcase.find(b"OUT:\n")
        tc_in = testcase[4:out_idx]
        tc_out = testcase[out_idx + 5 :].strip()

        # Feed target with input and check if output is correct
        out = sp.run(test_bin, input=tc_in, shell=True, stdout=sp.PIPE)

        actual_out = b"\n".join(map(lambda x: x.strip(), out.stdout.strip().split(b"\n")))

        if tc_out == actual_out:
            print("PASS")
            return 0
        else:
            print("FAIL")
            return 1

if __name__ == '__main__':
    problem = sys.argv[1]
    test(Path(problem))