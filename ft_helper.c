/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:54:46 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/09 18:04:01 by zaddi            ###   ########.fr       */
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

void	print_ops(t_list *ops)
{
	char	*s_ops[3];
	int		i;

	s_ops[0] = "pa";
	s_ops[1] = "pb";
	s_ops[2] = "ra";
	if (ops)
	{
		print_ops(ops->next);
		i = *((int *)ops->content);
		ft_putstr_fd(s_ops[i], 1);
		ft_putchar_fd('\n', 1);
	}
}

void	sorta_3(t_list *stack)
{
	int	e1;
	int	e2;
	int	e3;

	e1 = *((int *) stack->content);
	e2 = *((int *) stack->next->content);
	e3 = *((int *) stack->next->next->content);

	if ( e1 < e2)
	{
		if (e2 > e3)
		{
			ft_printf("sa\n");
			swap(stack);
			ft_printf("ra\n");
			rotate(stack);
		}
	}
	else
	{

	}
}
