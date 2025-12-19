


NAME := push_swap
SRC := main.c ft_helper.c ft_stack.c
OBJ  := $(SRC:.c=.o)

# === DEPS DIR ===

LIBFT_DIR = libft
LIBPRINTF_DIR = libprintf

# === DEPS NAME ===

LIBFT = $(LIBFT_DIR)/libft.a
LIBPRINTF = $(LIBPRINTF_DIR)/libprintf.a

# === UTILS ===

RM := rm -f

# === COMPILER ===

CC := cc
CFLAGS := -Werror -Wextra -Wall -g3
INCLUDES = -I includes -I $(LIBFT_DIR)/includes $(LIBPRINTF_DIR)/includes
LIBS = $(LIBFT) $(LIBPRINTF)

# === MAIN RULE ===

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

# === DEPS BUILD ===

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBFOO):
	$(MAKE) -C $(LIBFOO_DIR)

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

