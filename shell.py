#!/usr/bin/python3.8

import os
from pathlib import Path
import prompt_toolkit as pt
from util import MatWaeTeulUnit

root = Path(__file__).parent.absolute()

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
                    pt.completion.WordCompleter(["test"])
                ]
            ),
        )
        if query == "exit" or query == "quit":
            self.do_exit()
        
        if not Path(query).parent.is_dir():
            answer = input(f"Directory {Path(query).parent} not found. Create? (y/n)")
            if answer == "y":
                os.system(f"mkdir -p {Path(query).parent}")
            else:
                self.file_selection()
            
        self.file = MatWaeTeulUnit(query, debug=True)
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
            if command == "scrap":
                self.do_scrap()
            if command == "compile":
                self.do_compile()
            
            self.cmdloop()

    def do_code(self):
        os.system(f"code {self.file.src}")
        os.system(f"code {self.file.suite}")

    def do_scrap(self):
        print("Scraping test...")
        self.file.scrap(verbose=True)

    def do_test(self):
        print("Testing...")
        self.file.test(verbose=True, add_test=True, compile=True)

    def do_run(self):
        print("Running...")
        self.file.run(verbose=True, compile=True)

    def do_compile(self):
        self.file.compile(verbose=True)

    def do_exit(self):
        if self.file is None:
            exit(0)
        else:
            self.file = None
            print("File unloaded")
            self.file_selection()


if __name__ == "__main__":
    MatWaeTeulShell().file_selection()
