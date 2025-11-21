#include "libft/libft.h"
#include "libftprintf/ft_printf.h"

#define PUSHA 0
#define PUSHB 1
#define RA 2

int is_empty(t_list* stack);
void push(t_list** stack1, t_list** stack2);
void rotate(t_list** stack);
void print_stack(t_list* stack);
void sorting_stack(t_list** sa, t_list** sb, t_list** ops);

int ft_strisnum(char* str);
void print_ops(t_list* ops);