/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:52:01 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/15 15:54:28 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	mini_sort_lt(int e1, int e2, int e3, t_list **stack)
{
	if (e3 > e1)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else
		reverse_rotate(stack, 'a');
}

void	mini_sort_gt(int e1, int e2, int e3, t_list **stack)
{
	if (e2 > e3)
	{
		rotate(stack, 'a');
		rotate(stack, 'a');
	}
	else if (e1 > e3)
		rotate(stack, 'a');
	else
		swap(stack, 'a');
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
	else if (ft_lstsize(*stack) == 1)
	{
		e1 = ((t_stack_content *)(*stack)->content)->value;
		e2 = ((t_stack_content *)(*stack)->next->content)->value;
		if (e1 < e2)
			swap(stack, 'a');
	}
}
