#include "ft_pushswap.h"

int is_empty(t_list* stack)
{
    return (stack == NULL);
}

void push(t_list** stack1, t_list** stack2)
{
    t_list* save_ptr;
    if(*stack1)
    {
        save_ptr = *stack1;
        *stack1 = save_ptr->next;
        ft_lstadd(stack2, save_ptr);
    }
}

void rotate(t_list** stack)
{
    t_list* save_ptr;
    t_list* index_ptr;

    if(*stack && (*stack)->next)
    {
        save_ptr = *stack;
        *stack = save_ptr->next;
        save_ptr->next = NULL;
        index_ptr = *stack;
        while(index_ptr)
        {
            if(!(index_ptr->next))
            {
                index_ptr->next = save_ptr;
                break;
            }
            index_ptr = index_ptr->next;
        }
    } 
}

void sorting_stack(t_list** sa, t_list** sb, t_list** ops)
{
    int a;
    int op;

    while(!is_empty(*sa))
    {
        a = *((int*) (*sa)->content);

        while(!is_empty(*sb) && (*((int*) (*sb)->content)) > a)
        {
            push(sb, sa);
            op = PUSHA;
            ft_lstadd(ops, ft_lstnew(&op, sizeof(int)));
            rotate(sa);
            op = RA;
            ft_lstadd(ops, ft_lstnew(&op, sizeof(int)));
        }
        push(sa, sb);
        op = PUSHB;
        ft_lstadd(ops, ft_lstnew(&op,sizeof(int)));
    }
    while(!is_empty(*sb))
    {
        push(sb, sa);
        op = PUSHA;
        ft_lstadd(ops, ft_lstnew(&op, sizeof(int)));
    }
}

void print_stack(t_list* stack)
{
    int i;

    while(stack)
    {
        i = *((int*) stack->content);
        ft_putnbr(i);
        ft_putchar('\n');
        stack = stack->next;
    }
}