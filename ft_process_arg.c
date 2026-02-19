/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 13:45:43 by zaddi             #+#    #+#             */
/*   Updated: 2026/02/19 16:22:54 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	out_of_bound(char *str)
{
	int	sign;
	long	nbr;

	nbr = 0;
	sign = 1;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	nbr = nbr * sign;
	if ((nbr > 2147483647) || (nbr < -2147483648))
		return (NOK);
	else
		return (OK);
}

int	arg_to_stack(int argc, char **argv, t_list **arg_stack)
{
	char **strs;
	int ret;

	strs = NULL;
	if (argc == 1)
	{
		strs = ft_split(argv[1], ' ');
		if (strs)
			ret = convert(count_word(argv[1], ' '), strs, arg_stack);
		else
			return (NOK);
	}
	else
		ret = convert(argc, argv+1, arg_stack);
	if (strs)
		free_array(strs);
	return (ret);
}

int	add_new_number(t_list **arg_stack, char *number)
{
	t_stack_content	*content;
	t_list			*node;

	content = (t_stack_content *)malloc(sizeof(t_stack_content));
	if (!content)
		return (NOK);
	content->target_index = -1;
	content->to_top_cost = -1;
	content->value = ft_atoi(number);
	node = ft_lstnew(content);
	if (!node)
	{
		free(content);
		return (NOK);
	}
	ft_lstadd_back(arg_stack, node);
	return (OK);
}

int	convert(int argc, char **argv, t_list **arg_stack)
{
	int		i;

	i = 0;
	while (i < argc)
	{
		if (ft_strisnum(argv[i]) && !out_of_bound(argv[i])
			&& !number_in_stack(*arg_stack, argv[i]))
		{
			if (!add_new_number(arg_stack, argv[i]))
				return (NOK);
		}
		else
			return (NOK);
		i++;
	}
	return (OK);
}
