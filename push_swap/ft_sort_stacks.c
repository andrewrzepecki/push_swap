/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:49:59 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/31 13:19:22 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_split_b(t_stack **stack, int pivot, int inter)
{
	int i;
	int ret;

	i = 0;
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

int			ft_split_stack(t_stack **stack, int min, int max, int s_index)
{
	int		pivot;
	int		inter;
	int		i;

	i = 0;
	pivot = ft_calculate_pivot(min, max, s_index);
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
	inter = stack[A]->inter + 1;
	while (stack[B] && stack[B]->pos > pivot)
	{
		stack[B]->inter = inter;
		ft_push(&stack[B], &stack[A]);
		ft_putendl("pa");
		i++;
	}
	return (i + ft_split_b(stack, pivot, inter));
}

void		ft_sort_stacks(t_stack **stack, int min, int max, int s_index)
{
	int	ret;

	ret = 0;
	while (max - min > 3 || ft_stacklen(&stack[B]) > 3)
	{
		//print_stacks(stack);
		//getchar();
		ret = ft_split_stack(stack, min, max, s_index);
		max = max - ret;
		s_index = B;
	}
    ret = ft_sort_split(stack, min);
	min = ft_push_and_sort_a(stack, ret) + 1;
	if (ft_quick_check(&stack[A]))
		return ;
	max = ft_push_back_b(stack);
	ft_sort_stacks(stack, min, max, B);
}
