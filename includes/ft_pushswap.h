/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:45:33 by zaddi             #+#    #+#             */
/*   Updated: 2025/12/27 17:11:39 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include "libft.h"
# include "ft_printf.h"

# define PUSHA 0
# define PUSHB 1
# define RA 2

typedef struct s_stack
{
	int			*content;
	int			*capacity;
	int			*size;
}	t_stack;

int		is_empty(t_stack *stack);
void	push(t_stack *stacka, t_stack *stack2);
void	rotate(t_stack *stack);
void	rrotate(t_stack *stack);
void	swap(t_stack *stack);
void	print_stack(t_stack *stack);
void	sorting_stack(t_stack *sa, t_stack *sb);

int		ft_strisnum(char *str);

#endif
