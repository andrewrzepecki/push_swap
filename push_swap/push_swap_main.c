/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:27:41 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/18 19:02:26 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_stack_check(t_stack **chk, int d)
{
	t_stack *new;
	t_stack **tracer;

	if (!(*chk))
	{
		*chk = ft_new_stkelem(d);
		return (1);
	}
	tracer = chk;
	while (*tracer)
	{
		if ((*tracer)->value == d)
			return (0);
		tracer = &(*tracer)->next;
	}
	new = ft_new_stkelem(d);
	new->next = *tracer;
	*tracer = new;
	return (1);
}

int			ft_check_double(char *s, int index, int len)
{
	static t_stack	*chk;
	int				d;

	d = ft_atoi(s);
	if (!ft_stack_check(&chk, d))
	{
		ft_free_stack(&chk);
		return (0);
	}
	if (index + 1 == len)
		ft_free_stack(&chk);
	return (1); 
}

int			ft_parse_args(int ac, char **av)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (ac > 1)
	{
		ret = 1;
		/* To add more thorough test for parsing strings */
		while (++i < ac && ret && (ret = ft_check_double(av[i], i, ac)))
			ret = ft_strlen(av[i]) ? ft_strnum(av[i]) : 0;
	}
	return (ret);
}

void		ft_set_stacks(t_stack **stack, int ac, char **av)
{
	int		i;
	t_stack **tracer;
	t_stack	*elem;

	i = 0;
	while (++i < ac)
	{
		tracer = stack;
		elem = ft_new_stkelem(ft_atoi(av[i]));
		if (!(*stack))
			*stack = elem;
		while (tracer)
			tracer = &(*tracer)->next;
		elem->next = *tracer;
		*tracer = elem;
	}
}

int			main(int ac, char **av)
{
	int		ret;
	char	**commands;
	t_stack	*stack[2];

	ret = 1;
	stack[A] = NULL;
	stack[B] = NULL;
	if (ft_parse_args(ac, av))
	{
		ft_set_stacks(&stack[A], ac, av);
		ft_free_stack(&stack[A]);
		//commands = sort_stack(stack);
		return (0);
	}
	else
		return (ft_ps_output(ret));
	//return (ft_commands_output(commands));
}