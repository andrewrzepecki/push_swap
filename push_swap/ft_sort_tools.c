/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 15:02:49 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/23 22:12:24 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sort_split(t_stack **stack, int min)
{
	int size;

	size = ft_stacklen(&stack[B]);
	if (size == 2)
	{
		if (stack[B]->pos < stack[B]->next->pos)
		{
			ft_swap(&stack[B]);
			ft_putendl("sb");
		}
	}
	else
		ft_sort_three_b(&stack[B], min);
	if (ft_stacklen(&stack[A]) < 4)
		ft_sort_three_a(&stack[A], min + size);
	return (size);

}

int		ft_calculate_pivot(int min, int max)
{
	if (!((min - max) % 2))
		return ((min + max) / 2);
	return ((min + max) / 2 + 1);
}

int		ft_loop_positions(t_stack **stack, int pivot, int s_index)
{
	t_stack **tracer;

	tracer = stack;
	while ((*tracer))
	{
		if (s_index == A)
		{
			if ((*tracer)->pos < pivot)
				return (1);
		}
		else
			if ((*tracer)->pos >= pivot)
				return (1);
		tracer = &(*tracer)->next;
	}
	return (0);
}
