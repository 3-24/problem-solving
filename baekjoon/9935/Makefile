CC = g++
CFLAGS = -std=c++2a
BASENAME = $(shell basename $(CURDIR))

a.out: $(BASENAME).cpp
	$(CC) $(CFLAGS) $(BASENAME).cpp

.ONESHELL:
.SILENT:
test: a.out
	START=$$(date +%s.%N);
	for f in $(shell ls -d */| grep test); do
		./a.out < $${f}input.txt | diff --color -u $${f}output.txt -;
		echo $${f};
	done;
	END=$$(date +%s.%N);
	DIFF=$$(echo "$${END} - $${START}" | bc);
	echo "Elapsed time $${DIFF}s";

