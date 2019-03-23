/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_comms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:22:16 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/23 14:58:58 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_header.h"

void		ft_swap(t_stack **stack)
{
	int tmp;

	if (ft_stacklen(stack) > 1)
	{
		tmp = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = tmp;
		tmp = (*stack)->pos;
		(*stack)->pos = (*stack)->next->pos;
		(*stack)->next->pos = tmp;
	}
}

void		ft_rotate(t_stack **stack)
{
	int		first[2];
	t_stack	**tracer;
	
	if (ft_stacklen(stack) > 1)
	{
		tracer = stack;
		first[0] = (*tracer)->value;
		first[1] = (*tracer)->pos;
		while ((*tracer)->next)
		{
			(*tracer)->value = (*tracer)->next->value;
			(*tracer)->pos = (*tracer)->next->pos;
			tracer = &(*tracer)->next;
		}
		(*tracer)->value = first[0];
		(*tracer)->pos = first[1];
	}
}

void		ft_rev_rotate(t_stack **stack)
{
	t_stack	**tracer;
	t_stack **tmp;

	if (ft_stacklen(stack) > 1)
	{
		tracer = stack;
		while ((*tracer)->next->next)
			tracer = &(*tracer)->next;
		(*tracer)->next->next = *stack;
		*stack = (*tracer)->next;
		(*tracer)->next = NULL;

	}
}

void		ft_push(t_stack **src, t_stack **dst)
{
	t_stack *tmp_src;

	if (*src)
	{
		tmp_src = (*src);
		*src = (*src)->next;
		tmp_src->next = *dst;
		*dst = tmp_src;	
	}
}
