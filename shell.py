#!/usr/bin/python3.8

import os
from pathlib import Path
from test import test
import subprocess as sp
import prompt_toolkit as pt

root = Path(__file__).parent.absolute()

def bin_path(file):
    return Path("bin") / file.with_suffix("")


def compile(file):
    if file.suffix in [".c", ".cpp", ".cc"]:
        os.system(f"mkdir -p {bin_path(file).parent}")
        command = [
            "clang++",
            "-std=c++20",
            "-fsanitize=address",
            "-O0",
            "-g",
            "-Wall",
            str(file),
            "-o",
            str(bin_path(file)),
        ]
        print(" ".join(command))
        r = sp.run(command, cwd=root)
        if r.returncode != 0:
            print("Compile failed.")
            return 1
        else:
            print("Compile success.")
            return 0
    else:
        print("Not supported file type")
        return 1


def compile_if_recent(func):
    def inner(*args):
        file = args[0].file
        bin_file = bin_path(file)
        if file.suffix in [".c", ".cpp", ".cc"]:
            if (
                not bin_file.is_file()
                or file.stat().st_mtime > bin_path(file).stat().st_mtime
            ):
                r = compile(file)
                if r == 1:
                    return 1
        func(*args)
        return 0

    return inner


def path_ignore(filename):
    if any(
        map(
            lambda x: x != "." and (x.startswith(".") or x.startswith("_")),
            filename.split("/"),
        )
    ):
        return False
    if filename.startswith("bin"):
        return False
    return True


class MatWaeTeulShell:
    intro = "Welcome to the matwaeteul shell. Type help or ? to list commands.\n"

    def __init__(self):
        print(
            "Welcome to the matwaeteul shell. Type the filename to start. (Ex. ./baekjoon/1092.cpp)"
        )
        self.file = None
        function_names = [attr for attr in dir(self) if callable(getattr(self, attr))]
        self.cmds = [f[3:] for f in function_names if f.startswith("do_")] + ["quit"]
        self.cmd_completer = pt.completion.WordCompleter(self.cmds)

    def file_selection(self):
        query = pt.prompt(
            f"> ",
            completer=pt.completion.merge_completers(
                [
                    pt.completion.PathCompleter(file_filter=path_ignore),
                    pt.completion.WordCompleter(["exit", "quit"]),
                ]
            ),
        )
        if query == "exit" or query == "quit":
            self.do_exit()
        
        self.file = Path(query)
        if not self.file.parent.is_dir():
            print("Directory not found")
            self.file = None
            self.file_selection()
        self.cmdloop()

    def cmdloop(self):
        command = pt.prompt(f"{self.file} > ", completer=self.cmd_completer)
        if command not in self.cmds:
            print("Command not found")
        if command == "exit" or command == "quit":
            self.do_exit()
        else:    
            if command == "code":
                self.do_code()
            if command == "test":
                self.do_test()
            if command == "run":
                self.do_run()
            if command == "scrap_test":
                self.do_scrap_test()
            if command == "compile":
                self.do_compile()
            
            self.cmdloop()

    def do_code(self):
        os.system(f"code {self.file}")
        os.system(f"code {self.file.with_suffix('.test')}")

    def do_scrap_test(self):
        print("Scraping test...")
        # TODO

    @compile_if_recent
    def do_test(self):
        print("Testing...")
        r = test(self.file)
        if r == 0:
            print("All test passed")
        else:
            print("Some test failed")

    @compile_if_recent
    def do_run(self):
        print("Running...")
        os.system(bin_path(self.file))

    def do_compile(self):
        compile(self.file)

    def do_exit(self):
        if self.file is None:
            exit(0)
        else:
            self.file = None
            print("File unloaded")
            self.file_selection()


if __name__ == "__main__":
    MatWaeTeulShell().file_selection()
