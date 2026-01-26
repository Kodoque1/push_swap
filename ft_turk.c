/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:32:12 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/26 17:27:14 by zaddi            ###   ########.fr       */
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
	while (i <= (size / 2))
	{
		s_content = ((t_stack_content *)stack->content);
		s_content->to_top_cost = i;
		i++;
		stack = stack->next;
	}
	while (i < size)
	{
		s_content = ((t_stack_content *)stack->content);
		s_content->to_top_cost = i - size;
		i++;
		stack = stack->next;
	}
}

int	select_to_push(t_list *sa, t_list *sb)
{
	int				i;
	int				size;
	int				min_cost;
	int				optimal_index;
	t_stack_content	*content;

	size = ft_lstsize(sb);
	i = 0;
	optimal_index = 0;
	min_cost = 2147483647;
	while (i < size)
	{
		content = ((t_stack_content *)sb->content);
		if (compute_total_cost(content, sa) < min_cost)
		{
			min_cost = compute_total_cost(content, sa);
			optimal_index = i;
		}
		i++;
		sb = sb->next;
	}
	return (optimal_index);
}

void	setup_smallest_bigger(t_list *sa, t_list *sb)
{
	int				j;
	int				sa_value;
	t_list			*index_sa;
	int				min_bigger;

	while (sb)
	{
		min_bigger = 2147483647;
		j = 0;
		((t_stack_content *)(sb->content))->target_index = -1;
		index_sa = sa;
		while (index_sa)
		{
			sa_value = ((t_stack_content *)(index_sa->content))->value;
			if ((sa_value > ((t_stack_content *)(sb->content))->value)
			&& sa_value < min_bigger)
			{
				min_bigger = sa_value;
				((t_stack_content *)(sb->content))->target_index = j;
			}
			j++;
			index_sa = index_sa->next;
		}
		sb = sb->next;
	}
}

void	min_to_top(t_list **stack)
{
	int		min_index;

	min_index = index_min(*stack);
	rotate_to_top(get_index(*stack, min_index), stack, 'a');
}

void	sort_turk(t_list **sa, t_list **sb)
{
	int	size;

	size = ft_lstsize(*sa);
	while (size-- > 2)
		push(sa, sb, 'b');
	while (*sb)
	{
		setup_smallest_bigger(*sa, *sb);
		to_top_cost(*sa);
		to_top_cost(*sb);
		optimal_to_top(sa, sb);
		push(sb, sa, 'a');
	}
	to_top_cost(*sa);
	min_to_top(sa);
}
