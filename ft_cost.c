/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 13:58:20 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/18 13:58:45 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	compute_total_cost(t_stack_content *content, t_list *sa)
{
	int	b_cost;
	int	a_cost;
	int	sum;

	b_cost = content->to_top_cost;
	if (content->target_index < 0)
		a_cost = get_index(sa, index_min(sa))->to_top_cost;
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
