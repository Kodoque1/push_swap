/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 13:58:20 by zaddi             #+#    #+#             */
/*   Updated: 2026/02/21 20:59:36 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	compute_total_cost(t_stack_content *content, t_list *sa)
{
	int				b_cost;
	int				a_cost;
	t_stack_content	*temp;

	b_cost = content->to_top_cost;
	if (content->target_index < 0)
		temp = get_index(sa, index_min(sa));
	else
		temp = get_index(sa, content->target_index);
	if (!temp)
		return (0);
	a_cost = temp->to_top_cost;
	if ((a_cost < 0) && (b_cost < 0))
	{
		a_cost = ft_abs(a_cost);
		b_cost = ft_abs(b_cost);
		return (b_cost + a_cost - ft_min(b_cost, a_cost));
	}
	else if ((a_cost > 0) && (b_cost > 0))
		return (b_cost + a_cost - ft_min(b_cost, a_cost));
	return (ft_abs(a_cost) + ft_abs(b_cost));
}
