/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:15:44 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/22 18:19:15 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../main_header.h"

/* Parsing Error Output */
int			ft_error_output(void);

/* Stack Sorting Functions */
void		ft_sort_stacks(t_stack **stack, int min, int max, int *tab);
int			ft_split_stack(t_stack **stack, int min, int max, int s_index);
int			ft_sort_stacks(t_stack **stack);
int			ft_rotate_stack_a(t_stack **stack, int min, int max);

#endif
