<<<<<<< HEAD
NAME = push_swap

LIBFTDIR = libft

SRC = handle_error.c init_a_to_b.c init_b_to_a.c main.c push.c sort_stacks.c swap.c stack_init.c stack_utils.c rev_rotate.c rotate.c sort_stacks_utils.c sort_three.c
OBJ = $(SRC:%.c=%.o)
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I$(LIBFTDIR)
LDFLAGS = -L$(LIBFTDIR) -lft

LIBFT = $(LIBFTDIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJ)
				$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
				rm -f $(OBJ)
				$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
				rm -f $(NAME)
				$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all



=======

NAME		=	push_swap

LIBFT		=	libft/libft.a

ARQUIVOS	=	main.c utils.c verifications.c sorting.c \
				push_small.c return_to_a_sorted.c moves.c moves_utils.c \
				moves_utils_1.c push_small.c push_medium.c radix_sorting.c\
				
OBJETOS		=	$(ARQUIVOS:%.c=%.o)

CFLAGS		=	-Wall -Werror -Wextra

%.o: %.c
	cc -c $< -o $@

all: $(NAME)

$(NAME): $(OBJETOS) $(LIBFT)
	cc $^ -o $@

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJETOS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					@./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					@./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5 -n 5))
					@./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test25:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-25 -n 25))
					@./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test50:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-50 -n 50))
					valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test149:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-149 -n 149))
					@./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell seq -500 500 | shuf | head -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					@./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test150:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-150 -n 150))
					@./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test200:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-200 -n 200))
					@./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					@./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l


.PHONY: all clean fclean re test2 test3 test500 test1000 test5 test100
>>>>>>> e613da43a923c694a66fc8f59d58d6fdeacc795a
