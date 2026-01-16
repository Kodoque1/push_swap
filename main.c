/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:48:12 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/15 17:53:02 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_del(void *data)
{
	free(data);
}

int	arg_to_stack(int argc, char **argv, t_list **arg_stack)
{
	int				i;
	t_stack_content	*content;

	i = 1;
	while (i < argc)
	{
		if (ft_strisnum(argv[i]))
		{
			content = (t_stack_content *)malloc(sizeof(t_stack_content));
			content->target_index = -1;
			content->to_top_cost = -1;
			content->value = ft_atoi(argv[i]);
			ft_lstadd_back(arg_stack, ft_lstnew(content));
			i++;
		}
		else
		{
			ft_lstclear(arg_stack, ft_del);
			return (0);
		}
	}
	return (1);
}

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
	if (argc > 1)
	{
		if (arg_to_stack(argc, argv, &arg_stack))
			processing_args(&arg_stack, &sort_stack);
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
