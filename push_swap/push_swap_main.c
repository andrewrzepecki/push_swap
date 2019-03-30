/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:27:41 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/30 16:32:13 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_stacks(t_stack **stack)
{
	t_stack **tracer_a;
	t_stack **tracer_b;

	tracer_a = &stack[A];
	tracer_b = &stack[B];
	while (*tracer_b || *tracer_a)
	{
		if (*tracer_a && *tracer_b)
			printf("int: %3d %-10d || int: %3d %10d\n", (*tracer_a)->inter, (*tracer_a)->value, (*tracer_b)->inter, (*tracer_b)->value);
		if (*tracer_a && !*tracer_b)
			printf("int: %3d %-10d || int: %3d %10s\n", (*tracer_a)->inter, (*tracer_a)->value, -42, "empty");
		if (!*tracer_a && *tracer_b)
			printf("int: %3d %-10s || int: %3d%10d\n", -42, "empty", (*tracer_b)->inter, (*tracer_b)->value);
		if (*tracer_a)
			tracer_a = &(*tracer_a)->next;
		if (*tracer_b)
			tracer_b = &(*tracer_b)->next;
	}
}

int			ft_quick_check(t_stack **stack)
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

int			main(int ac, char **av)
{
	int		ret;
	int		*tab;
	char	**commands;
	t_stack	*stack[2];

	ret = 1;
	stack[A] = NULL;
	stack[B] = NULL;
	if (ft_parse_args(ac, av))
	{
		tab = ft_pos_tab(av, ac);
		ft_set_stacks(&stack[A], ac, av, tab);
		free(tab);
		ft_sort_stacks(stack, 0, ac - 2, A);
		ft_free_stack(&stack[A]);
		ft_free_stack(&stack[B]);
		return (0);
	}
	return (ft_error_output());
	//return (ft_commands_output(commands));
}
