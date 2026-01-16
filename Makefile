


NAME := push_swap
SRC := main.c ft_helper.c ft_stack_ops.c ft_turk.c ft_mini_sort.c ft_turk_top.c
OBJ  := $(SRC:.c=.o)

# === DEPS DIR ===

LIBFT_DIR = libft
LIBPRINTF_DIR = libprintf

# === DEPS NAME ===

LIBFT = $(LIBFT_DIR)/libft.a
LIBPRINTF = $(LIBPRINTF_DIR)/libftprintf.a

# === UTILS ===

RM := rm -f

# === COMPILER ===

CC := cc
CFLAGS := -Werror -Wextra -Wall -g3
INCLUDES = -I includes -I $(LIBFT_DIR)/includes -I $(LIBPRINTF_DIR)/includes
LIBS = $(LIBPRINTF) $(LIBFT)

# === MAIN RULE ===

%.o : %.c
	$(CC) $(INCLUDES) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBPRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBS) -o $(NAME)

# === DEPS BUILD ===

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBPRINTF):
	$(MAKE) -C $(LIBPRINTF_DIR)

# === CLEANING UP ===

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(LIBPRINTF_DIR) clean
	$(RM) $(OBJ) $(OBJ:.o=.d)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(LIBPRINTF)
	$(RM) $(NAME)

re:	fclean all

# === TESTS ===

