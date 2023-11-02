import sys
from util import MatWaeTeulUnit

if __name__ == '__main__':
    problem = sys.argv[1]
    exit(MatWaeTeulUnit(problem).test(verbose=False, add_test=True, compile=True))