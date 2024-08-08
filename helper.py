#!/usr/bin/python3.8
from util import MatWaeTeulUnit
import argparse

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    subparsers = parser.add_subparsers(dest="command")
    
    run_parser = subparsers.add_parser("run", help="Run the file")
    run_parser.add_argument("file", type=str, help="File to run")
    compile_parser = subparsers.add_parser("compile", help="Compile the file")
    compile_parser.add_argument("file", type=str, help="File to compile")
    test_parser = subparsers.add_parser("test", help="Test the file")
    test_parser.add_argument("file", type=str, help="File to test")
    scrap_parser = subparsers.add_parser("scrap", help="Scrap the test")
    scrap_parser.add_argument("file", type=str, help="File to scrap")
    
    args = parser.parse_args()
    
    file = MatWaeTeulUnit(args.file)
    
    if args.command == "run":
        file.run(verbose=True, compile=True)
    elif args.command == "compile":
        file.compile(verbose=True)
    elif args.command == "test":
        file.test(verbose=True, add_test=True, compile=True)
    else:
        file.scrap(verbose=True)