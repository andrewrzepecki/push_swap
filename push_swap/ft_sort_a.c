/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 21:45:15 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/23 22:15:10 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_amin(t_stack **stack, int min)
{
	if ((*stack)->next->pos == min)
	{
		ft_swap(stack);
		ft_putendl("sa");
		return ;
	}
	ft_rev_rotate(stack);
	ft_putendl("rra");
}

void	ft_sort_amax(t_stack **stack, int min)
{
	if ((*stack)->next->pos == min)
	{
		ft_rotate(stack);
		ft_putendl("ra");
		return ;
	}
	ft_swap(stack);
	ft_putendl("sa");
	ft_rev_rotate(stack);
	ft_putendl("rra");
}

void	ft_sort_three_a(t_stack **stack, int min)
{
	if (ft_stacklen(stack) >= 3)
	{
		if (min + 2 == (*stack)->pos)
			return (ft_sort_amax(stack, min));
		else if (min + 1 == (*stack)->pos)
			return (ft_sort_amin(stack, min));
		else if (min == (*stack)->pos)
		{
			if ((*stack)->next->pos == min + 2)
			{
				ft_rev_rotate(stack);
				ft_putendl("rra");
				ft_swap(stack);
				ft_putendl("sa");
			}
			return ;
		}
	}
}
