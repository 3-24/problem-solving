CC = g++
CFLAGS = -std=c++2a
BASENAME = $(shell basename $(CURDIR))

a.out: $(BASENAME).cpp
	$(CC) $(CFLAGS) $(BASENAME).cpp

test: a.out
	@for f in $(shell ls -d */| grep test); do \
		./a.out < $${f}input.txt | diff --color -u $${f}output.txt -; \
		echo $${f} done; \
	done

