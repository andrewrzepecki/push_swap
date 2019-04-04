/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:27:41 by anrzepec          #+#    #+#             */
/*   Updated: 2019/04/04 17:05:40 by anrzepec         ###   ########.fr       */
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

int		ft_small_sort(t_stack **stack, int len)
{
	if (ft_quick_check(&stack[A]))
	{
		ft_free_stack(&stack[A]);
		return (0);
	}
	if (len == 3)
		ft_sort_three_a(&stack[A], 0);
	else if (len == 2)
	{
		if (stack[A]->pos != 0)
		{
			ft_swap(&stack[A]);
			ft_putendl("sa");
		}
	}
	ft_free_stack(&stack[A]);
	return (0);
}

int		main(int ac, char **av)
{
	int		max;
	t_stack	*stack[2];

	stack[A] = NULL;
	stack[B] = NULL;
	if (ft_parse_args(ac, av, &stack[A], 0))
	{
		ft_pos_tab(&stack[A]);
		if (ft_stacklen(&stack[A]) < 4)
			return (ft_small_sort(stack, ft_stacklen(&stack[A])));
		max = ft_first_split(stack, 0, ft_stacklen(&stack[A]) - 1);
		if (max > 0)
			ft_sort_stacks(stack, 0, max);
		ft_free_stack(&stack[A]);
		ft_free_stack(&stack[B]);
		return (0);
	}
	return (ft_error_output());
}
