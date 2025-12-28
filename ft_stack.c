/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:47:49 by zaddi             #+#    #+#             */
/*   Updated: 2025/12/27 12:34:24 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	is_empty(t_list *stack)
{
	return (stack == NULL);
}

void	sorting_stack(t_list **sa, t_list **sb, t_list **ops)
{
	int	a;
	int	op;

	while (!is_empty(*sa))
	{
		a = *((int *)(*sa)->content);
		while (!is_empty(*sb) && (*((int *)(*sb)->content)) > a)
		{
			push(sb, sa);
			op = PUSHA;
			ft_lstadd_back(ops, ft_lstnew(&op));
			rotate(sa);
			op = RA;
			ft_lstadd_back(ops, ft_lstnew(&op));
		}
		push(sa, sb);
		op = PUSHB;
		ft_lstadd_back(ops, ft_lstnew(&op));
	}
	while (!is_empty(*sb))
	{
		push(sb, sa);
		op = PUSHA;
		ft_lstadd_back(ops, ft_lstnew(&op));
	}
}

void	print_stack(t_list *stack)
{
	int	i;

	while (stack)
	{
		i = *((int *)stack->content);
		ft_putnbr_fd(i, 1);
		ft_putchar_fd('\n', 1);
		stack = stack->next;
	}
}
