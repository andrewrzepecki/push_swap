/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:27:41 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/22 16:57:28 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_print_stacks(t_stack **a, t_stack **b)
{
	t_stack **tracer;

	tracer = a;
	printf("STACK A: \n");
	while ((*tracer))
	{
		printf("value: %d, pos: %d\n", (*tracer)->value, (*tracer)->pos);
		tracer = &(*tracer)->next;
	}
	tracer = b;
	printf("\nSTACK B: \n");
	while ((*tracer))
	{
		printf("value: %d, pos: %d\n", (*tracer)->value, (*tracer)->pos);
		tracer = &(*tracer)->next;
	}
}

int			main(int ac, char **av)
{
	int		ret;
	int		*tab;
	t_stack	*stack[2];

	ret = 1;
	stack[A] = NULL;
	stack[B] = NULL;
	if (ft_parse_args(ac, av))
	{
		tab = ft_pos_tab(av, ac);
		ft_set_stacks(&stack[A], ac, av, NULL);
		ft_checker_output(ft_command_loop(stack, tab, ac - 1));
		ft_free_stack(&stack[A]);
		ft_free_stack(&stack[B]);
	}
	else
		return (ft_checker_output(ret));
	return (ret);
}