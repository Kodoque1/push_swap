/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:54:46 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/25 11:04:13 by zaddi            ###   ########.fr       */
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


