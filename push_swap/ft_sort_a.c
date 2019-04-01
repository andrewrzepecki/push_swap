/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 21:45:15 by anrzepec          #+#    #+#             */
/*   Updated: 2019/04/01 18:58:54 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_quicksort_a(t_stack **stack, int max_pos)
{
	if (stack[A]->pos == max_pos + 1)
	{
		stack[A]->inter = -1;
		ft_rotate(&stack[A]);
		ft_putendl("ra");
		return (1);
	}
	if (stack[A]->next->pos == max_pos + 1)
	{
		ft_swap(&stack[A]);
		ft_putendl("sa");
		stack[A]->inter = -1;
		ft_rotate(&stack[A]);
		ft_putendl("ra");
		return (1);
	}
	return (0);
}

int		ft_check_a(t_stack **stack, int max)
{
	int i;

	i = 0;
	if (stack[A]->next->pos == max + 1)
	{
		ft_swap(&stack[A]);
		ft_putendl("sa");
		i++;
	}
	if (i && stack[A]->next->pos == max + 2)
		i++;
	return (i);
}

int		ft_rotate_a(t_stack **stack, int len, int max_pos)
{
	int i;

	i = 0;
	while (i < len)
	{
		stack[A]->inter = -1;
		ft_rotate(&stack[A]);
		ft_putendl("ra");
		i++;
	}
	while (ft_quicksort_a(stack, max_pos))
		max_pos++;
	return (max_pos);
}

int		ft_push_and_sort_a(t_stack **stack, int ret)
{
	int i;
	int opti;
	int max_pos;

	i = 0;
	max_pos = stack[B]->pos;
	opti = ft_check_a(stack, max_pos);
	while (i < ret)
	{
		ft_push(&stack[B], &stack[A]);
		ft_putendl("pa");
		i++;
	}
	if (ft_quick_check(&stack[A]))
		return (max_pos + opti);
	return (ft_rotate_a(stack, ret + opti, max_pos + opti));
}
