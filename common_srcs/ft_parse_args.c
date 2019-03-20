/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:28:49 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/20 16:36:54 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_header.h"

int			ft_stack_check(t_stack **chk, int d)
{
	t_stack *new;
	t_stack **tracer;

	if (!(*chk))
	{
		*chk = ft_new_stkelem(d, NULL, 0);
		return (1);
	}
	tracer = chk;
	while ((*tracer))
	{
		if ((*tracer)->value == d)
			return (0);
		tracer = &(*tracer)->next;
	}
	new = ft_new_stkelem(d, NULL, 0);
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