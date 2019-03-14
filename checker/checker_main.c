/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:27:41 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/14 16:22:55 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	new->next = (*tracer);
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

int			main(int ac, char **av)
{
	int	ret;
	int	*stack[2];

	ret = 1;
	if (ft_parse_args(ac, av))
	{
		ft_putendl("Good");//stack = ft_set_stacks(ac, av);
		ret = ft_checker_output(ft_command_loop(stack));
	}
	else
		return (ft_checker_output(ret));
	return (ret);
}