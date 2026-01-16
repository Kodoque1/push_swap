/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:32:12 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/16 14:11:29 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"


void	double_rotate(t_list **sa, t_list **sb, int rot, int sign)
{
	if (sign > 0)
	{
		while (rot--)
		{
			rotate(sa, 'x');
			rotate(sb, 'x');
			ft_printf("rr\n");
		}
	}
	else
	{
		while (rot--)
		{
			reverse_rotate(sa, 'x');
			reverse_rotate(sb, 'x');
			ft_printf("rrr\n");
		}
	}
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

void	optimal_to_top(t_list **sa, t_list **sb)
{
	int				index;
	int				rot;
	t_stack_content	*nb;
	t_stack_content	*na;

	index = select_to_push(*sa, *sb);
	nb = get_index(*sb, index);
	na = NULL;
	if (nb->target_index > 0)
	{
		na = get_index(*sa, nb->target_index);
		if ((na->to_top_cost > 0) && (nb->to_top_cost > 0))
		{
			rot = min(na->to_top_cost, nb->to_top_cost);
			na->to_top_cost -= rot;
			nb->to_top_cost -= rot;
			double_rotate(sa, sb, rot, 1);
		}
		else if ((na->value < 0) && (nb->value < 0))
		{
			rot = min(ft_abs(na->to_top_cost), ft_abs(nb->to_top_cost));
			na->to_top_cost += rot;
			nb->to_top_cost += rot;
			double_rotate(sa, sb, rot, -1);
		}
	}
	rotate_to_top(nb, sb, 'b');
	if (na)
		rotate_to_top(na, sa, 'a');
}
