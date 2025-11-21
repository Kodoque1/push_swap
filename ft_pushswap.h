/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:45:33 by zaddi             #+#    #+#             */
/*   Updated: 2025/11/21 11:47:41 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include "libft/libft.h"
# include "libftprintf/ft_printf.h"

# define PUSHA 0
# define PUSHB 1
# define RA 2

int		is_empty(t_list *stack);
void	push(t_list **stack1, t_list **stack2);
void	rotate(t_list **stack);
void	print_stack(t_list *stack);
void	sorting_stack(t_list **sa, t_list **sb, t_list **ops);

int		ft_strisnum(char *str);
void	print_ops(t_list *ops);

#endif
