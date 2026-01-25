/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:48:12 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/25 11:03:56 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	processing_args(t_list **arg_stack)
{
	t_list	*sort_stack;

	sort_stack = NULL;
	sort_turk(arg_stack, &sort_stack);
	ft_lstclear(arg_stack, free);
	ft_lstclear(&sort_stack, free);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_list	*arg_stack;

	arg_stack = NULL;
	if (argc > 1)
	{
		if (arg_to_stack(argc - 1, argv, &arg_stack))
		{
			processing_args(&arg_stack);
			ft_printf("args passed\n");
		}
		else
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
	}
	else
	{
		ft_printf("error\n");
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
}
