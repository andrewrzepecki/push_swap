/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:15:44 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/29 20:38:55 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../main_header.h"

/* Parsing Error Output */
int			ft_error_output(void);

/* Stack Sorting Functions */
int			ft_quick_check(t_stack **stack);
void		ft_sort_stacks(t_stack **stack, int min, int max, int s_index);
int			ft_split_stack(t_stack **stack, int min, int max, int s_index);
int			ft_sort_split(t_stack **stack, int min);
int			ft_push_and_sort_a(t_stack **stack, int ret);
int			ft_push_back_b(t_stack **stack);

/* Sorting Tools */
int			ft_calculate_pivot(int min, int max);
int			ft_loop_positions(t_stack **stack, int pivot, int s_index);
int			ft_sorted_elems(t_stack **stack);

void		ft_sort_three_b(t_stack **stack, int min);
void		ft_sort_three_a(t_stack **stack, int min);
#endif
