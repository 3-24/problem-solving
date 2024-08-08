import os
from pathlib import Path
import subprocess as sp
import urllib3
from bs4 import BeautifulSoup
import re

class MatWaeTeulUnit:
    def __init__(self, src_file, debug=False):
        self.src = Path(src_file)
        self.bin = Path("bin") / self.src.with_suffix("")
        self.suite = self.src.with_suffix(".test")
        self.platform = self.src.parent.name
        self.problem = self.src.stem
        self.debug = debug

        if self.src.suffix in [".c", ".cpp", ".cc"]:
            self.language = "C++"
        elif self.src.suffix == ".py":
            self.language = "Python"
        else:
            self.language = "Unknown"
    
    def __str__(self):
        return str(self.src)

    def compile(self, verbose=False):
        if self.language == "C++":
            os.system(f"mkdir -p {self.bin.parent}")
            if self.debug:
                compile_cmd = f"clang++ -std=c++20 -fsanitize=address -O0 -g -Werror -DONLINE_JUDGE {self.src} -o {self.bin}"
            else:
                compile_cmd = f"g++ -O2 -Wall -lm -std=gnu++20 -DONLINE_JUDGE {self.src} -o {self.bin}"
            print(compile_cmd)
            
            compile_cmd = compile_cmd.split(" ")
            
            if verbose:
                r = sp.run(compile_cmd)
            else:
                r = sp.run(compile_cmd, stdout=sp.DEVNULL, stderr=sp.DEVNULL)

            r = r.returncode
            
            if r == 0:
                print("Compilation success")
            else:
                print("Compilation failed")
            return r
        elif self.language == "Python":
            pass
        else:
            print("Unsupported file type")
            return 1

    def get_edited_time(self):
        return self.src.stat().st_mtime

    def get_compiled_time(self):
        return self.bin.stat().st_mtime

    def compile_if_recent(self, verbose=False):
        if not self.bin.is_file() or self.src.stat().st_mtime > self.bin.stat().st_mtime:
            return self.compile(verbose=verbose)
        return 0
    
    def scrap(self, verbose=True):
        existing_tcs = set(self.parse_test())
        scraped_tcs = set(self.scrap_test(verbose))

        if not self.suite.is_file():
            self.suite.touch()
        
        for tc in scraped_tcs - existing_tcs:
            self.add_test(*tc)
        
        print("Scraping done successfully")
        print(f"Check {len(scraped_tcs)} test cases in {self.suite}")

    def scrap_test(self, verbose=False):
        if self.platform == "baekjoon":
            problem_url = f"https://www.acmicpc.net/problem/{self.problem}"
            print(f"Scraping test from {problem_url}")
            # Get problem page
            http = urllib3.PoolManager()
            r = http.request("GET", problem_url, headers={"User-Agent": 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/99.0.4844.84 Safari/537.36'})
            soup = BeautifulSoup(r.data, "html.parser")
            
            if not soup.find("span", {"class": "problem-label problem-label-spj"}) is None:
                print("Special Judge problem")
                return []
            
            samples = list(
                map(
                    lambda x: x.text.replace("\r\n", "\n").encode().rstrip() + b"\n",
                    soup.findAll("pre", {"class": "sampledata"}),
                )
            )

            return [
                (samples[i], samples[i + 1])
                for i in range(0, len(samples), 2)
            ]

        else:
            print("Unsupported platform")
            return []

    def add_test(self, input, output):
        with open(self.suite, "rb") as f:
            content = f.read()
            for i in range(2, -1, -1):
                if content.endswith(b"\n" * i):
                    linebreak = 2 - i
                    break
            if content == b"":
                linebreak = 0

        with open(self.suite, "ab") as f:
            f.write(linebreak * b"\n")
            f.write(b"IN:\n")
            f.write(input)
            f.write(b"OUT:\n")
            f.write(output)

    def add_test_if_necessary(self, verbose):
        if not self.suite.is_file():
            #existing_tcs = set(self.parse_test())
            scraped_tcs = set(self.scrap_test(verbose))
            
            self.suite.touch()
            
            for tc in scraped_tcs:
                self.add_test(*tc)

    def parse_test(self):
        if not self.suite.is_file():
            return []
        with open(self.suite, "rb") as f:
            content = f.read()

        matches = list(
            map(lambda s: s.rstrip() + b"\n", re.split(b"IN:\n|OUT:\n", content)[1:])
        )

        tests = []
        for i in range(0, len(matches), 2):
            tests.append((matches[i], matches[i + 1]))

        return tests

    def _command(self):
        if self.language == "Python":
            return ["python3", str(self.src)]
        else:
            return [str(self.bin)]

    def run(self, compile=True, verbose=False):
        if compile:
            self.compile_if_recent(verbose)
        sp.run(self._command())
    
    def test(self, verbose=False, add_test=True, compile=True):
        if compile:
            r = self.compile_if_recent(verbose)
            if r == 1:
                return 1
        if add_test:
            self.add_test_if_necessary(verbose)

        test_suite = self.parse_test()

        passed = True
        for tc_in, tc_out in test_suite:
            # Feed target with input and check if output is correct
            proc = sp.Popen(self._command(), stdin=sp.PIPE, stdout=sp.PIPE)
            try:
                proc.stdin.write(tc_in)
                actual_out = proc.communicate(timeout=1)[0]
            except sp.TimeoutExpired:
                proc.kill()
                print("Timeout")
                print("FAIL")
                passed = False
                continue
                
            tc_out = b'\n'.join(map(lambda x: x.rstrip(), (tc_out.rstrip() + b'\n').split(b'\n')))
            actual_out = b'\n'.join(map(lambda x: x.rstrip(), (actual_out.rstrip() + b'\n').split(b'\n')))

            if tc_out == actual_out:
                print("PASS")
            else:
                print("FAIL")
                print("Expected: ", tc_out)
                print("Output: ", actual_out)
                passed = False

        if passed:
            return 0
        else:
            return 1

