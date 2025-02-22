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



