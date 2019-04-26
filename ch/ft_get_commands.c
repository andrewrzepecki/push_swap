/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:14:24 by anrzepec          #+#    #+#             */
/*   Updated: 2019/04/25 16:11:18 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t		ft_parse_command(char *buff, int len)
{
	if (!ft_strcmp(buff, "sa") && (int)ft_strlen(buff) == len - 1)
		return (0);
	if (!ft_strcmp(buff, "ra") && (int)ft_strlen(buff) == len - 1)
		return (1);
	if (!ft_strcmp(buff, "rra") && (int)ft_strlen(buff) == len - 1)
		return (2);
	if (!ft_strcmp(buff, "sb") && (int)ft_strlen(buff) == len - 1)
		return (3);
	if (!ft_strcmp(buff, "rb") && (int)ft_strlen(buff) == len - 1)
		return (4);
	if (!ft_strcmp(buff, "rrb") && (int)ft_strlen(buff) == len - 1)
		return (5);
	if (!ft_strcmp(buff, "ss") && (int)ft_strlen(buff) == len - 1)
		return (6);
	if (!ft_strcmp(buff, "rr") && (int)ft_strlen(buff) == len - 1)
		return (7);
	if (!ft_strcmp(buff, "rrr") && (int)ft_strlen(buff) == len - 1)
		return (8);
	if (!ft_strcmp(buff, "pa") && (int)ft_strlen(buff) == len - 1)
		return (9);
	if (!ft_strcmp(buff, "pb") && (int)ft_strlen(buff) == len - 1)
		return (10);
	return (1995);
}

void		ft_initialize_ctab(t_commands *tab)
{
	tab[0].f = ft_swap;
	tab[1].f = ft_rotate;
	tab[2].f = ft_rev_rotate;
}

void		ft_push_stacks(int function, t_stack **stack)
{
	if (function == 9)
		ft_push(&stack[B], &stack[A]);
	else
		ft_push(&stack[A], &stack[B]);
}

int			ft_check_sort(t_stack **stack, int len)
{
	t_stack	**tracer;
	int		i;

	i = 0;
	tracer = stack;
	while (*tracer)
	{
		if ((*tracer)->pos != i)
			return (2);
		tracer = &(*tracer)->next;
		i++;
	}
	return (i == len ? 1 : 2);
}

int			ft_command_loop(t_stack **stack, int len)
{
	char		*buff;
	int			ret;
	t_commands	c_tab[3];

	ft_initialize_ctab(c_tab);
	while ((ret = get_next_line(0, &buff)) > 0)
	{
		if ((ret = ft_parse_command(buff, ret)) > 10)
			return (0);
		if (ret < 3)
			c_tab[ret].f(&stack[A]);
		else if (ret < 6)
			c_tab[ret - 3].f(&stack[B]);
		else if (ret < 9)
		{
			c_tab[ret - 6].f(&stack[A]);
			c_tab[ret - 6].f(&stack[B]);
		}
		else
			ft_push_stacks(ret, stack);
		ft_strdel(&buff);
	}
	return (ft_check_sort(&stack[A], len));
}
