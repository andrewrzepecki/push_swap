/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 21:17:11 by anrzepec          #+#    #+#             */
/*   Updated: 2019/04/09 18:35:18 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_min_rotate(t_stack **stack, int *min)
{
	stack[A]->inter = -1;
	(*min)++;
	ft_rotate(&stack[A]);
	ft_putendl("ra");
}

void	ft_min_plus_one_rotate(t_stack **stack, int *min)
{
	ft_swap(&stack[A]);
	ft_putendl("sa");
	ft_min_rotate(stack, min);
	ft_min_rotate(stack, min);
}

void	ft_sort_bmax(t_stack **stack, int min)
{
	if ((*stack)->next->pos == min)
	{
		ft_rev_rotate(stack);
		ft_putendl("rrb");
		return ;
	}
	ft_swap(stack);
	ft_putendl("sb");
}

void	ft_sort_bmin(t_stack **stack, int min)
{
	if ((*stack)->next->pos == min + 2)
	{
		ft_rotate(stack);
		ft_putendl("rb");
		return ;
	}
	ft_swap(stack);
	ft_putendl("sb");
	ft_rev_rotate(stack);
	ft_putendl("rrb");
}

void	ft_sort_three_b(t_stack **stack, int min)
{
	if (ft_stacklen(stack) >= 3)
	{
		if (min == (*stack)->pos)
			return (ft_sort_bmin(stack, min));
		else if (min + 1 == (*stack)->pos)
			return (ft_sort_bmax(stack, min));
		else if (min + 2 == (*stack)->pos)
		{
			if (min + 1 != (*stack)->next->pos)
			{
				ft_swap(stack);
				ft_putendl("sb");
				ft_rotate(stack);
				ft_putendl("rb");
			}
			return ;
		}
	}
}
