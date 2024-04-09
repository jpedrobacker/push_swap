NAME = push_swap
LIBFTPRINTF = libftprintf/libftprintf.a
LIBFT = libftprintf/libft/libft.a
CC = gcc
SRC_DIR = src/
FIND = $(shell find $(SRC_DIR))
SRC = $(filter %.c, $(FIND))

all: $(NAME)

$(NAME): $(SRC)
		$(CC) $(SRC) $(LIBFTPRINTF) -o push_swap

git:
	@git add -A
	@git commit -m "checkpoint at $$(date '+%Y-%m-%dT%H:%M:%S%z')"
	@git push
	@echo Checkpoint created and pushed to remote

lib:
	@make -C libftprintf

checker:
		@wget https://cdn.intra.42.fr/document/document/24886/checker_linux
		@chmod 777 checker_linux

test100a:	${NAME}
		$(eval ARG = ${shell seq 0 1000 | shuf -n 100})
		./push_swap ${ARG} | ./checker_linux ${ARG}
		@echo -n "Command: "
		valgrind ./push_swap ${ARG} | wc -l

test500a:	${NAME}
		$(eval ARG = ${shell seq 0 1000 | shuf -n 500})
		./push_swap ${ARG} | ./checker_linux ${ARG}
		@echo -n "Command: "
		valgrind ./push_swap ${ARG} | wc -l

clean:
	@make clean -C libftprintf
	rm -rf $(NAME)

fclean: clean
	@make fclean -C libftprintf

re: fclean lib all
