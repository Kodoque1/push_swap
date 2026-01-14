/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:54:46 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/14 11:46:25 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	ft_strisnum(char *str)
{
	if ((*str == '-') || (*str == '-'))
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

t_stack_content	*get_index(t_list *stack, int index)
{
	int	i;

	while (i < index)
	{
		i++;
		stack = stack->next;
	}
	return (stack->content);
}

int	compute_total_cost(t_stack_content *content, t_list *sa)
{
	int	b_cost;
	int	a_cost;

	b_cost = content->to_top_cost;
	a_cost = get_index(sa, content->target_index)->to_top_cost;
	return (b_cost + a_cost);
}

void	rotate_to_top(t_stack_content *c, t_list **stack, char sid)
{
	int	top_cost;

	if (c->to_top_cost < 0)
	{
		top_cost = ft_abs(c->to_top_cost);
		while (top_cost)
		{
			reverse_rotate(stack, sid);
			top_cost--;
		}
	}
	else
	{
		top_cost = c->to_top_cost;
		while (top_cost)
		{
			rotate(stack, sid);
			top_cost--;
		}
	}
}
