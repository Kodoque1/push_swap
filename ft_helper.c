/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:54:46 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/26 17:27:20 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_del(void *data)
{
	free(data);
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

int	number_in_stack(t_list *arg_stack, char *number)
{
	t_stack_content	*content;
	int				num;

	num = ft_atoi(number);
	while (arg_stack)
	{
		content = arg_stack->content;
		if (content->value == num)
			return (1);
		arg_stack = arg_stack->next;
	}
	return (0);
}

int	index_min(t_list *stack)
{
	int				min;
	int				min_index;
	int				i;
	t_stack_content	*content;

	min = 2147483647;
	i = 0;
	while (stack)
	{
		content = (t_stack_content *)stack->content;
		if (content->value < min)
		{
			min = content->value;
			min_index = i;
		}
		i++;
		stack = stack->next;
	}
	return (min_index);
}
