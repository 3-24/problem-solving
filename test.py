import sys
import subprocess as sp

problem = sys.argv[1]

with open(f"{problem}.test", 'rb') as f:
    content = f.read()

testcases = content.split(b'\n\n')
for testcase in testcases:
    assert(testcase.startswith(b"IN:\n"))
    out_idx = testcase.find(b"OUT:\n")
    tc_in = testcase[4:out_idx]
    tc_out = testcase[out_idx+5:]
    
    # Feed target with input and check if output is correct
    out = sp.run(target, input=tc_in, shell=True, stdout=sp.PIPE)
    if (tc_out.strip() == out.stdout.strip()):
        print("PASS")
    else:
        print("FAIL")
    