main.cpp에서 Segmentation Fault 발생했을 때
```
$ g++ -o a.out -g main.cpp
$ gdb -q ./a.out
(gdb) run
(gdb) info locals
```