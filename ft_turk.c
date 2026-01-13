/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:32:12 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/13 20:40:12 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	to_top_cost(t_list *stack)
{
	int				size;
	int				i;
	t_stack_content	*s_content;

	size = ft_lstsize(stack);
	i = 0;
	while (i < (size / 2))
	{
		s_content = ((t_stack_content *)stack->content);
		s_content->to_top_cost = i;
		i++;
	}
	while (i < size)
	{
		s_content = ((t_stack_content *)stack->content);
		s_content->to_top_cost = i - size;
		i++;
	}
}

int	select_to_push(t_list *sa, t_list *sb)
{
	int				i;
	int				size;
	int				min_cost;
	t_stack_content	*content;

	size = ft_lstsize(sb);
	i = 0;
	min_cost = 2147483647;
	while (i < size)
	{
		content = ((t_stack_content *)sb->content);

	}
}

void	setup_smallest_bigger(t_list *sa, t_list *sb)
{
	int				j;
	int				sa_value;
	t_stack_content	*sb_content;
	int				min_bigger;

	while (sb)
	{
		min_bigger = 2147483647;
		j = 0;
		sb_content = (t_stack_content *)(sb->content);
		while (sa)
		{
			sa_value = ((t_stack_content *)(sa->content))->value;
			if ((sa_value > sb_content->value) && sa_value < min_bigger)
			{
				min_bigger = sa_value;
				sb_content->target_index = j;
			}
			j++;
			sa = sa->next;
		}
		sb = sb->next;
	}
}
