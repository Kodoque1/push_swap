/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:45:33 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/16 18:05:02 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include "ft_printf.h"
# include "libft.h"

# define PUSHA 0
# define PUSHB 1
# define RA 2

# define NEGATIVE 0
# define POSITIVE 1
# define DIFFERENT 2

typedef struct s_stack_content
{
	int			value;
	int			to_top_cost;
	int			target_index;
}				t_stack_content;

void			push(t_list **stacka, t_list **stack2, char c);
void			rotate(t_list **stack, char c);
void			reverse_rotate(t_list **stack, char c);
void			swap(t_list **stack, char c);
void			print_stack(t_list *stack);
void			mini_sort(t_list **stack);
void			setup_smallest_bigger(t_list *sa, t_list *sb);
void			rotate_to_top(t_stack_content *c, t_list **stack, char sid);
void			optimal_to_top(t_list **sa, t_list **sb);
void			sort_turk(t_list **sa, t_list **sb);
void			min_to_top(t_list **stack);
int				ft_strisnum(char *str);
int				select_to_push(t_list *sa, t_list *sb);
int				compute_total_cost(t_stack_content *content, t_list *sa);
int				min(int a, int b);
t_stack_content	*get_index(t_list *stack, int index);

#endif
