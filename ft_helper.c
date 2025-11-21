#include "ft_pushswap.h"

int ft_strisnum(char* str)
{
    if(*str == '-')
        str++;
    while(*str)
    {
        if (!ft_isdigit(*str))
            return (0);
        str++;
    }
    return (1);
}

void print_ops(t_list* ops)
{
    char* s_ops[] = {"pa", "pb", "ra"};
    int i;

    if(ops)
    {
        print_ops(ops->next);
        i = *((int*) ops->content);
        ft_putstr(s_ops[i]);
        ft_putchar('\n');
    }
}