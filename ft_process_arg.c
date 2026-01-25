/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 13:45:43 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/25 11:03:39 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	out_of_bound(char *num)
{
	if (*num == '-')
		return (ft_strncmp("2147483648", num + 1, 10) < 0);
	else
		return (ft_strncmp("2147483647", num, 10) < 0);
}

void	input_type(char **argv, int argc, char ***convert)
{
	ft_printf("%i\n", argc);
	if (argc == 1)
	{
		ft_printf("%s\n", argv[1]);
		*convert = ft_split(argv[1], ' ');
		ft_printf("%s\n", (*convert)[1]);
	}
	else
		*convert = argv + 1;
}

void	add_new_number(t_list **arg_stack, char *number)
{
	t_stack_content	*content;

	content = (t_stack_content *)malloc(sizeof(t_stack_content));
	content->target_index = -1;
	content->to_top_cost = -1;
	content->value = ft_atoi(number);
	ft_lstadd_back(arg_stack, ft_lstnew(content));
}

int	number_in_stack(t_list *arg_stack, char *number)
{
	t_stack_content	*content;
	int				num;

	num = ft_atoi(number);
	while (arg_stack)
	{
		content = arg_stack->content;
		if (content->value == num)
			return (1);
		arg_stack = arg_stack->next;
	}
	return (0);
}

int	arg_to_stack(int argc, char **argv, t_list **arg_stack)
{
	int		i;
	char	**convert;

	i = 0;
	convert = NULL;
	input_type(argv, argc, &convert);
	ft_printf("%p\n", convert);
	ft_printf("1:%s 2:%s 3:%s \n", convert[0], convert[1], convert[0]);
	while (i < argc)
	{
		ft_printf("num:%s \n", convert[i]);
		if (convert && ft_strisnum(convert[i]) && !out_of_bound(convert[i]))
			//&& !number_in_stack(*arg_stack, convert[i]))
		{
			add_new_number(arg_stack, convert[i]);
		}
		else
		{
			ft_lstclear(arg_stack, free);
			// free_split(convert);
			return (0);
		}
		i++;
	}
	// free_split(convert);
	return (1);
}
