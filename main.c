/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:48:12 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/18 16:51:25 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	processing_args(t_list **arg_stack, t_list **sort_stack)
{
	sort_turk(arg_stack, sort_stack);
	ft_lstclear(arg_stack, ft_del);
	ft_lstclear(sort_stack, ft_del);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_list	*arg_stack;
	t_list	*sort_stack;

	sort_stack = NULL;
	arg_stack = NULL;
	if (argc == 2)
	{

		if (arg_to_stack(argc - 1, argv + 1, &arg_stack))
			processing_args(&arg_stack, &sort_stack);
		else
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
}
