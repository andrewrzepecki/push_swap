/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:49:59 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/23 21:39:06 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_split_b(t_stack **stack, int pivot)
{
	int i;

	i = 0;
	ft_rotate(&stack[B]);
	ft_putendl("rb");
	while (ft_loop_positions(&stack[B], pivot, B))
	{
		if (stack[B]->pos >= pivot)
		{
			ft_push(&stack[B], &stack[A]);
			ft_putendl("pa");
			i++;
		}
		ft_rotate(&stack[B]);
		ft_putendl("rb");
	}
	return (i);
}

int			ft_split_a(t_stack **stack, int pivot)
{
	int i;

	i = 0;
	ft_rotate(&stack[A]);
	ft_putendl("ra");
	while (ft_loop_positions(&stack[A], pivot, A))
	{
		if (stack[A]->pos < pivot)
		{
			ft_push(&stack[A], &stack[B]);
			ft_putendl("pb");
			i++;
		}
		ft_rotate(&stack[A]);
		ft_putendl("ra");
	}
	return (i);
}

int			ft_split_stack(t_stack **stack, int min, int max, int s_index)
{
	int		pivot;
	int		i;

	i = 0;
	pivot = ft_calculate_pivot(min, max);
	if (s_index == A)
	{
		while (stack[A]->pos < pivot)
		{
			ft_push(&stack[A], &stack[B]);
			ft_putendl("pb");
			i++;
		}
		return (i + ft_split_a(stack, pivot));
	}
	while (stack[B]->pos >= pivot)
	{
		ft_push(&stack[B], &stack[A]);
		ft_putendl("pa");
		i++;
	}
	return (i + ft_split_b(stack, pivot));
}

void		ft_sort_stacks(t_stack **stack, int min, int max)
{
	int s_index;
	int	ret;

	s_index = A;
	while (max - min > 3)
	{
		ret = ft_split_stack(stack, min, max, s_index);
		max = max - ret;
		s_index = B;
	}
    ret = ft_sort_split(stack, min);
/*	ft_push_a(ret);
	min = ft_rotate_a(&stack[A], min, max);
	max = min + ft_biggest_sort(&stack[A]);
	if (ft_quick_check(&stack[A]))
		return ;
	ft_sort_stack(stack, min, max);*/
}
