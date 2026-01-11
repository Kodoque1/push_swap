/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:54:46 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/11 17:28:59 by zaddi            ###   ########.fr       */
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

void	to_top_cost(t_list *stack)
{
	int	size;

	size = ft_lstsize()
	while(stack)
	{

	}
}
