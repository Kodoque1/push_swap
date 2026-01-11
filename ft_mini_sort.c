/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:52:01 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/11 16:11:11 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	mini_sort_lt(int e1, int e2, int e3, t_list **stack)
{
	if (e3 > e1)
	{
		ft_printf("sa\n");
		swap(stack);
		ft_printf("ra\n");
		rotate(stack);
	}
	else
	{
		ft_printf("rra\n");
		reverse_rotate(stack);
	}
}

void	mini_sort_gt(int e1, int e2, int e3, t_list **stack)
{
	if (e2 > e3)
	{
		ft_printf("ra\n");
		rotate(stack);
		ft_printf("ra\n");
		rotate(stack);
	}
	else if (e1 > e3)
	{
		ft_printf("ra\n");
		rotate(stack);
	}
	else
	{
		ft_printf("sa\n");
		swap(stack);
	}
}

void	mini_sort(t_list **stack)
{
	int	e1;
	int	e2;
	int	e3;

	if (ft_lstsize(*stack) == 3)
	{
		e1 = ((t_stack_content *)(*stack)->content)->value;
		e2 = ((t_stack_content *)(*stack)->next->content)->value;
		e3 = ((t_stack_content *)(*stack)->next->next->content)->value;
		if (e1 < e2 && (e2 > e3))
			mini_sort_lt(e1, e2, e3, stack);
		else
			mini_sort_gt(e1, e2, e3, stack);
	}
}
