/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 13:45:43 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/18 16:49:03 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	out_of_bound(char *num)
{
	if (*num == '-')
		return (ft_strcmp("2147483648", num + 1) < 0);
	else
		return (ft_strcmp("2147483647", num) < 0);
}
char	**input_type(char **argv, int argc, char **convert)
{
	if (argc == 2)
		convert = ft_split(argv[1], ' ');
}

void	add_new_number(t_list **arg_stack, int number)
{
	t_stack_content	*content;

	content = (t_stack_content *)malloc(sizeof(t_stack_content));
	content->target_index = -1;
	content->to_top_cost = -1;
	content->value = ft_atoi(number);
	ft_lstadd_back(arg_stack, ft_lstnew(content));
}

int	number_in_stack(t_list *arg_stack, int number)
{
	t_stack_content	*content;

	while (arg_stack)
	{
		content = arg_stack->content;
		if (content->value == number)
			return (1);
		arg_stack = arg_stack->next;
	}
	return (0);
}

int	arg_to_stack(int argc, char **argv, t_list **arg_stack)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_strisnum(argv[i]) && !out_of_bound(argv[i])
			&& !number_in_stack(*arg_stack, argv[i]))
			add_new_number(arg_stack, argv[i++]);
		else
		{
			ft_lstclear(arg_stack, ft_del);
			return (0);
		}
	}
	return (1);
}
