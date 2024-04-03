NAME = push_swap
LIB = src/libftprintf.a
CC = gcc
SRC_DIR = src/
FIND = $(shell find $(SRC_DIR))
SRC = $(filter %.c, $(FIND))
VAR := $(shell echo {1..100} | tr " " "\n" | sort --random-sort | tr "\n" " ")

comp:
	$(CC) $(SRC) $(LIB) -o push_swap

big:
	./push_swap $(VAR)

test:
		@echo $(VAR)

checkpoint:
	@git add -A
	@git commit -m "checkpoint at $$(date '+%Y-%m-%dT%H:%M:%S%z')"
	@git push
	@echo Checkpoint created and pushed to remote

lib:
	@make -C libftprintf
	@make clean -C libftprintf
	@mv libftprintf/libftprintf.a src

clean:
	rm -rf *.a
