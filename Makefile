NAME = push_swap
LIBFTPRINTF = libftprintf/libftprintf.a
LIBFT = libftprintf/libft/libft.a
CC = gcc
SRC_DIR = src/
FIND = $(shell find $(SRC_DIR))
SRC = $(filter %.c, $(FIND))
VAR = $(shell echo {1..100} | tr " " "\n" | sort --random-sort | tr "\n" " ")

all: $(NAME)

$(NAME): $(SRC)
		$(CC) $(SRC) $(LIBFTPRINTF) -o push_swap

big:
	./push_swap 2

test:
		@echo $(VAR)

checkpoint:
	@git add -A
	@git commit -m "checkpoint at $$(date '+%Y-%m-%dT%H:%M:%S%z')"
	@git push
	@echo Checkpoint created and pushed to remote

lib:
	@make -C libftprintf

test100a:	${NAME}
			$(eval ARG = ${shell seq -1000000 1000000 | shuf -n 100})
			./push_swap ${ARG} | ./checker_linux ${ARG}
			@echo -n "Command: "
			./push_swap ${ARG} | wc -l

test500a:	${NAME}
			$(eval ARG = ${shell seq -1000000 1000000| shuf -n 500})
			./push_swap ${ARG} | ./checker_linux ${ARG}
			@echo -n "Command: "
			./push_swap ${ARG} | wc -l

clean:
	@make clean -C libftprintf
	rm -rf $(NAME)

fclean: clean
	@make fclean -C libftprintf

re: fclean lib all
