/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:45:33 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/13 20:36:15 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include "ft_printf.h"
# include "libft.h"

# define PUSHA 0
# define PUSHB 1
# define RA 2

typedef struct s_stack_content
{
	int			value;
	int			to_top_cost;
	int			target_index;
}				t_stack_content;

int				is_empty(t_list *stack);
void			push(t_list **stacka, t_list **stack2);
void			rotate(t_list **stack);
void			reverse_rotate(t_list **stack);
void			swap(t_list **stack);
void			print_stack(t_list *stack);
void			sorting_stack(t_list **sa, t_list **sb);
void			mini_sort(t_list **stack);
void			setup_smallest_bigger(t_list *sa, t_list *sb);
int				ft_strisnum(char *str);
int				compute_total_cost(t_stack_content *content, t_list *sa);
t_stack_content	*get_index(t_list *stack, int index);

#endif
