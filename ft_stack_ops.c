/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 12:28:48 by zaddi             #+#    #+#             */
/*   Updated: 2025/12/27 17:02:09 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	push(int *stacka, int *stackb)
{
	t_list	*save_ptr;

	if (*stacka)
	{
		save_ptr = *stacka;
		*stacka = save_ptr->next;
		ft_lstadd_front(stackb, save_ptr);
	}
}

void	rotate(int *stack)
{
	t_list	*save_ptr;
	t_list	*index_ptr;

	if (*stack && (*stack)->next)
	{
		save_ptr = *stack;
		*stack = save_ptr->next;
		save_ptr->next = NULL;
		index_ptr = *stack;
		while (index_ptr)
		{
			if (!(index_ptr->next))
			{
				index_ptr->next = save_ptr;
				break ;
			}
			index_ptr = index_ptr->next;
		}
	}
}
