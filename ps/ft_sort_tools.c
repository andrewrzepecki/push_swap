/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 15:02:49 by anrzepec          #+#    #+#             */
/*   Updated: 2019/04/04 16:58:15 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_quick_check(t_stack **stack)
{
	int		pos;
	t_stack **tracer;

	pos = 0;
	tracer = stack;
	while (*tracer)
	{
		if ((*tracer)->pos == pos)
			pos++;
		else
			return (0);
		tracer = &(*tracer)->next;
	}
	return (1);
}

int		ft_push_back_b(t_stack **stack)
{
	int i;
	int max_pos;
	int inter;

	i = 0;
	inter = stack[A]->inter;
	max_pos = stack[A]->pos;
	while (stack[A]->inter == inter && inter != -1)
	{
		max_pos = max_pos > stack[A]->pos ? max_pos : stack[A]->pos;
		ft_push(&stack[A], &stack[B]);
		ft_putendl("pb");
		i++;
	}
	return (max_pos);
}

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
	else if (size == 3)
		ft_sort_three_b(&stack[B], min);
	return (size);
}

int		ft_calculate_pivot(int min, int max)
{
	if (!((min + max) % 2))
		return (((min + max) / 2) + 1);
	return (((min + max) / 2));
}

int		ft_loop_positions(t_stack **stack, int pivot, int s_index)
{
	t_stack **tracer;
	int		i;

	i = 0;
	tracer = stack;
	while ((*tracer))
	{
		if (s_index == A)
		{
			if ((*tracer)->pos < pivot)
				return (i);
		}
		else if ((*tracer)->pos > pivot)
			return (i);
		i++;
		tracer = &(*tracer)->next;
	}
	return (-1);
}
