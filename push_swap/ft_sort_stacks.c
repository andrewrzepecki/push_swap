/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:49:59 by anrzepec          #+#    #+#             */
/*   Updated: 2019/04/01 18:50:27 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_split_b(t_stack **stack, int min, int max)
{
	int i;
	int inter;
	int ret;
	int pivot;

	i = 0;
	pivot = ft_calculate_pivot(min, max);
	inter = stack[A]->inter + 1;
	while ((ret = ft_loop_positions(&stack[B], pivot, B)) > -1)
	{
		while (ret)
		{
			ft_rotate(&stack[B]);
			ft_putendl("rb");
			ret--;
		}
		stack[B]->inter = inter;
		ft_push(&stack[B], &stack[A]);
		ft_putendl("pa");
		i++;
	}
	return (i);
}

int			ft_split_a(t_stack **stack, int pivot)
{
	int i;
	int ret;

	i = 0;
	while ((ret = ft_loop_positions(&stack[A], pivot, A)) > -1)
	{
		while (ret)
		{
			ft_rotate(&stack[A]);
			ft_putendl("ra");
			ret--;
		}
		ft_push(&stack[A], &stack[B]);
		ft_putendl("pb");
		i++;
	}
	return (i);
}

int			ft_first_split(t_stack **stack, int min, int max)
{
	int	pivot;
	int ret;

	if (ft_quick_check(&stack[A]))
		return (-1);
	pivot = (min + max) / 2 + 1;
	ret = ft_split_a(stack, pivot);
	return (ret - 1);
}

void		ft_sort_stacks(t_stack **stack, int min, int max, int s_index)
{
	int	ret;

	ret = 0;
	while (ft_stacklen(&stack[B]) > 3)
	{
		ret = ft_split_b(stack, min, max);
		max = max - ret;
	}
    ret = ft_sort_split(stack, min);
	min = ft_push_and_sort_a(stack, ret) + 1;
	if (ft_quick_check(&stack[A]))
		return ;
	max = ft_push_back_b(stack);
	ft_sort_stacks(stack, min, max, B);
}
