/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:49:59 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/22 18:19:12 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_split_stack(t_stack **stack, int min, int max, int s_index)
{
	int		start;
	int		pivot;

	pivot = ft_get_pivot(min, max);
	if (s_index == A)
		while (1)
		{
			if (stack[A]->pos < pivot)
			   ft_push(&stack[A], &stack[B]);
			else
				return (ft_split_a(stack[A]->pos, pivot, stack));
		}
	else
		while (1)
		{
			if (stack[B]->pos > pivot)
				ft_push(&stack[B], &stack[A]);
			else
				return (ft_split_b(stack[B]->pos, pivot, stack));
		}
}

void		ft_sort_stacks(t_stack **stack, int min, int max)
{
	int s_index;
	int	ret;

	s_index = A;
	while (max - min > 3)
	{
		ret = ft_split_stack(stack, min, max, s_index);
		max -= ret;
		s_index = B;
	}
	ret = ft_sort_split(stacks);
	ft_push_a(ret);
	min = ft_rotate_a(&stack[A], min, max);
	max = min + ft_biggest_sort(&stack[A]);
	if (ft_quick_check(&stack[A]))
		return ;
	ft_sort_stack(stack, min, max);
}
