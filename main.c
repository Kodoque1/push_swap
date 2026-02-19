/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:48:12 by zaddi             #+#    #+#             */
/*   Updated: 2026/02/19 16:22:54 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	is_sorted(t_list *stack)
{
	t_stack_content	*current;
	t_stack_content	*next;

	if (!stack || !stack->next)
		return (OK);
	while (stack->next)
	{
		current = (t_stack_content *)stack->content;
		next = (t_stack_content *)stack->next->content;
		if (current->value > next->value)
			return (NOK);
		stack = stack->next;
	}
	return (OK);
}

void	processing_args(t_list **arg_stack)
{
	t_list	*sort_stack;

	if (is_sorted(*arg_stack))
	{
		ft_lstclear(arg_stack, free);
		exit(0);
	}
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
	if (argc == 1)
		return (0);
	if (arg_to_stack(argc - 1, argv, &arg_stack))
		processing_args(&arg_stack);
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (0);
}
