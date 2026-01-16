/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:54:46 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/16 13:41:47 by zaddi            ###   ########.fr       */
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

	i = 0;
	while (i < index)
	{
		i++;
		stack = stack->next;
	}
	return (stack->content);
}

void	print_stack(t_list *stack)
{
	t_stack_content	*content;

	while (stack)
	{
		content = (t_stack_content *)stack->content;
		ft_printf("content: %d, ", content->value);
		ft_printf("cost: %d, ", content->to_top_cost);
		ft_printf("index: %d\n", content->target_index);
		stack = stack->next;
	}
}

int	compute_total_cost(t_stack_content *content, t_list *sa)
{
	int	b_cost;
	int	a_cost;
	int	sum;

	b_cost = content->to_top_cost;
	if (content->target_index < 0)
		a_cost = 0;
	else
		a_cost = get_index(sa, content->target_index)->to_top_cost;
	if ((a_cost < 0) && (b_cost < 0))
	{
		a_cost = ft_abs(a_cost);
		b_cost = ft_abs(b_cost);
		sum = b_cost + a_cost - min(b_cost, a_cost);
	}
	else if ((a_cost > 0) && (b_cost > 0))
		sum = b_cost + a_cost - min(b_cost, a_cost);
	else
		sum = ft_abs(a_cost) + ft_abs(b_cost);
	return (sum);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}
