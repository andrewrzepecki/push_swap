/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:15:44 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/23 21:45:00 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../main_header.h"

/* Parsing Error Output */
int			ft_error_output(void);

/* Stack Sorting Functions */
void		ft_sort_stacks(t_stack **stack, int min, int max);
int			ft_split_stack(t_stack **stack, int min, int max, int s_index);
int			ft_sort_split(t_stack **stack, int min);
int			ft_rotate_stack_a(t_stack **stack, int min, int max);

/* Sorting Tools */
int			ft_calculate_pivot(int min, int max);
int			ft_loop_positions(t_stack **stack, int pivot, int s_index);

void		ft_sort_three_b(t_stack **stack, int min);
void		ft_sort_three_a(t_stack **stack, int min);
#endif
