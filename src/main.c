/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:48:12 by zaddi             #+#    #+#             */
/*   Updated: 2025/11/21 11:53:53 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_del(void *data, size_t size)
{
	size++;
	free(data);
}

int	arg_to_stack(int argc, char **argv, t_list **arg_stack)
{
	int	i;
	int	conv;

	i = argc - 1;
	while (i > 0)
	{
		if (ft_strisnum(argv[i]))
		{
			conv = ft_atoi(argv[i]);
			ft_lstadd(arg_stack, ft_lstnew(&conv, sizeof(int)));
			i--;
		}
		else
		{
			ft_lstdel(arg_stack, ft_del);
			return (0);
		}
	}
	return (1);
}

void	processing_args(t_list **arg_stack, t_list **sort_stack, t_list **ops)
{
	sorting_stack(arg_stack, sort_stack, ops);
	print_ops(*ops);
	ft_lstdel(arg_stack, ft_del);
	ft_lstdel(sort_stack, ft_del);
	ft_lstdel(ops, ft_del);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_list	*arg_stack;
	t_list	*sort_stack;
	t_list	*ops;

	sort_stack = NULL;
	arg_stack = NULL;
	ops = NULL;
	if (argc > 1)
	{
		if (arg_to_stack(argc, argv, &arg_stack))
		{
			processing_args(&arg_stack, &sort_stack, &ops);
		}
		else
		{
			ft_printf("Error\n");
			exit(-1);
		}
	}
	else
	{
		ft_printf("Error\n");
		exit(-1);
	}
}
