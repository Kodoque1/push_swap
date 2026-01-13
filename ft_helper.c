/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:54:46 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/13 20:33:09 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	ft_strisnum(char *str)
{
	if (*str == '-')
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
