/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:28:49 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/31 16:34:21 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_header.h"

int			ft_str_num_space(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9') || (s[i] == '+' || s[i] == '-'
				|| s[i] == ' '))
		{
			if (i != 0 && (s[i] == '-' || s[i] == '+') && s[i - 1] != ' ')
				return (0);
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int			ft_stack_check(t_stack **stack, int d)
{
	t_stack *new;
	t_stack **tracer;

	if (!(*stack))
	{
		*stack = ft_new_stkelem(d, NULL, 0);
		return (1);
	}
	tracer = stack;
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

int			ft_divide_str(char *s, t_stack **stack)
{
	int				i;
	char			**tab;
	long long int	d;

	i = 0;
	if (!(tab = ft_strsplit(s, ' ')))
		ft_malloc_fail();
	while (tab[i])
	{	
		d = ft_atoll(tab[i]);
		if (d > _MAX_INT_ || d < _MIN_INT_)
			return (0);
		if (!ft_stack_check(stack, (int)d))
			return (0);
		i++;
	}
	i = -1;
	while (tab[++i])
		ft_strdel(&tab[i]);
	free(tab);
	return (1);
}

int			ft_parse_args(int ac, char **av, t_stack **stack)
{
	int				i;
	int				ret;
	long long int	d;

	i = 1;
	ret = 0;
	while (i < ac)
	{
		if (ft_strnum(av[i]))
		{
			d = ft_atoll(av[i]);
			if (d > _MAX_INT_ || d < _MIN_INT_)
				return (0);
			ret = ft_stack_check(stack, (int)d);
		}
		else if (ft_str_num_space(av[i]))
			ret = ft_divide_str(av[i], stack);
		else
			ret = 0;
		if (!ret)
			break;
		i++;
	}
	return (ret);
}
