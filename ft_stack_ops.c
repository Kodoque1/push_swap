/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 12:28:48 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/16 13:24:40 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	swap(t_list **stack, char sid)
{
	t_list	*s1;
	t_list	*s2;

	if ((sid == 'a') || (sid == 'b'))
		ft_printf("s%c\n", sid);
	if (ft_lstsize(*stack) > 1)
	{
		s1 = (*stack)->next;
		s2 = s1->next;
		(*stack)->next = s2;
		s1->next = *stack;
		*stack = s1;
	}
}

void	push(t_list **stacka, t_list **stackb, char sid)
{
	t_list	*save_ptr;

	if ((sid == 'a') || (sid == 'b'))
		ft_printf("p%c\n", sid);
	if (stacka && *stacka)
	{
		save_ptr = *stacka;
		*stacka = save_ptr->next;
		ft_lstadd_front(stackb, save_ptr);
	}
}

void	rotate(t_list **stack, char sid)
{
	t_list	*front;

	if ((sid == 'a') || (sid == 'b'))
		ft_printf("r%c\n", sid);
	if (stack && *stack)
	{
		front = *stack;
		*stack = front->next;
		front->next = NULL;
		ft_lstadd_back(stack, front);
	}
}

void	reverse_rotate(t_list **stack, char sid)
{
	t_list	*back;
	t_list	*stack_index;

	if ((sid == 'a') || (sid == 'b'))
		ft_printf("rr%c\n", sid);
	back = NULL;
	if (stack && *stack && ft_lstsize(*stack) > 1)
	{
		stack_index = *stack;
		while (stack_index)
		{
			if (stack_index->next && !(stack_index->next->next))
			{
				back = stack_index->next;
				stack_index->next = NULL;
				break ;
			}
			stack_index = stack_index->next;
		}
		ft_lstadd_front(stack, back);
	}
}
