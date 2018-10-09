#-*- coding: utf-8 -*-


def main(inputtxt):
    def changecoding(s):
        return s.decode('utf-8')[0]

    S = map(changecoding, inputtxt.split())
    print "".join(S)

with open('input5.5.txt') as fp:
   line = fp.readline()
   cnt = 0
   while line:
       if cnt != 0: main(line)
       line = fp.readline()
       cnt += 1
