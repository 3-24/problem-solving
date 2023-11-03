# :balloon: Problem-Solving :balloon:

Collection of my algorithmic problem-solving challenges!

![profile1](http://mazassumnida.wtf/api/v2/generate_badge?boj=uncertainty)
![profile2](http://mazandi.herokuapp.com/api?handle=uncertainty&theme=warm)

## MatWaeTeul (맞왜틀)

Custom interactive shell for algorithmic problem-solving to easily do compilation, execution, and testing.

### Usage

Following example shows simple use case that loads specific source code and testing it.

```
Welcome to the matwaeteul shell. Type the filename to start. (Ex. ./baekjoon/1092.cpp)
> baekjoon/13907.cpp
baekjoon/13907.cpp > code
(vscode windows are opened and write the source code and test cases)
baekjoon/13907.cpp > run
clang++ -std=c++20 -fsanitize=address -O0 -g -Wall baekjoon/13907.cpp -o bin/baekjoon/13907
Compile success.
(run with some inputs and check the outputs)
baekjoon/13907.cpp > test
Testing...
PASS
All test passed
baekjoon/13907.cpp > quit
> quit
```

### Installation

To use it, you need Python 3.8 and install the dependent libraries.

```bash
pip install -r requirements.txt
```

Then, run it with
```bash
python shell.py
```

## Achievements :trophy:

- solved.ac Platinum (23/07/26)
- solved.ac CLASS 5** (23/08/30)
- solved.ac CLASS 6** (23/11/03)