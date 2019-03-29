/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 21:45:15 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/29 20:37:16 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_quicksort_a(t_stack **stack, int max_pos)
{
	if ((*stack)->pos == max_pos + 1)
	{
		(*stack)->inter = -1;
		ft_rotate(stack);
		ft_putendl("ra");
		return (1);
	}
	if ((*stack)->next->pos == max_pos + 1)
	{
		ft_swap(stack);
		ft_putendl("sa");
		(*stack)->inter = -1;
		ft_rotate(stack);
		ft_putendl("ra");
		return (1);
	}
	return (0);
}

int		ft_push_and_sort_a(t_stack **stack, int ret)
{
	int i;
	int max_pos;

	i = 0;
	if (stack[B])
		max_pos = stack[B]->pos;
	else
		max_pos = ft_get_max_pos(&stack[A]);  
	while (i < ret)
	{
		ft_push(&stack[B], &stack[A]);
		ft_putendl("pa");
		i++;
	}
	i = 0;
	while (i < ret)
	{
		stack[A]->inter = -1;
		ft_rotate(&stack[A]);
		ft_putendl("ra");
		i++;
	}
	while (ft_quicksort_a(&stack[A], max_pos))
		max_pos++;
	return (max_pos);
}
