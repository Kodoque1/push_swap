#include "ft_pushswap.h"
/*
    * DONE push
    * DONE rotate
    * DONE implement sorting operation
    * DONE getting args into stack
    * DONE storing the operations
    * DONE displaying the operations
    * testing
    * splitting function
    * splitting files
    * error handling
    * retesting
    * valgrind
*/

void ft_del(void* data, size_t size)
{
    size++;
    free(data);
}

int arg_to_stack(int argc, char **argv, t_list** arg_stack)
{
    int i;
    int conv;

    i = argc - 1;
    while(i > 0)
    {
        if (ft_strisnum(argv[i]))
        {
            conv = ft_atoi(argv[i]);
            ft_lstadd(arg_stack, ft_lstnew(&conv,sizeof(int)));
            i--;
        }
        else
        {
            ft_lstdel(arg_stack, ft_del);
            return (0);
        }
        
    }
    return (1);
}

void processing_args(t_list** arg_stack, t_list** sort_stack, t_list** ops)
{
    sorting_stack(arg_stack, sort_stack, ops);
    print_ops(*ops);
    ft_lstdel(arg_stack, ft_del);
    ft_lstdel(sort_stack, ft_del);
    ft_lstdel(ops, ft_del);
    exit(0);
}

int main(int argc, char **argv)
{
    t_list* arg_stack;
    t_list* sort_stack;
    t_list* ops;

    sort_stack = NULL;
    arg_stack = NULL;
    ops = NULL;
    if (argc > 1)
    {
        if (arg_to_stack(argc, argv, &arg_stack))
        {
            processing_args(&arg_stack, &sort_stack, &ops);
        }
        else
        {
            ft_printf("Error\n");
            exit(-1);
        }    
    }
    else
    {
        ft_printf("Error\n");
        exit(-1);
    }
}