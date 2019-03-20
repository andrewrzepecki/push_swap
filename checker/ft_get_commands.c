/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:14:24 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/20 16:36:48 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t		ft_parse_command(char *buff)
{
	if (!ft_strcmp(buff, "sa"))
		return (0);
	if (!ft_strcmp(buff, "sb"))
		return (1);
	if (!ft_strcmp(buff, "ss"))
		return (2);
	if (!ft_strcmp(buff, "pa"))
		return (3);
	if (!ft_strcmp(buff, "pb"))
		return (4);
	if (!ft_strcmp(buff, "ra"))
		return (5);
	if (!ft_strcmp(buff, "rb"))
		return (6);
	if (!ft_strcmp(buff, "rr"))
		return (7);
	if (!ft_strcmp(buff, "rra"))
		return (8);
	if (!ft_strcmp(buff, "rrb"))
		return (9);
	if (!ft_strcmp(buff, "rrr"))
		return (10);
	return (1995);
}
/*
void		ft_initialize_ctab(t_commands **tab)
{
	(*tab)[0].f = ft_swap_a;
	(*tab)[1].f = ft_swap_b;
	(*tab)[2].f = ft_swap_r;
	(*tab)[3].f = ft_push_a;
	(*tab)[4].f = ft_push_b;
	(*tab)[5].f = ft_rot_a;
	(*tab)[6].f = ft_rot_b;
	(*tab)[7].f = ft_rot_r;
	(*tab)[8].f = ft_rev_rot_a;
	(*tab)[9].f = ft_rev_rot_b;
	(*tab)[10].f = ft_rev_rot_r;
}
*/
int			ft_command_loop(int **stack)
{
	char		*buff;
	size_t		ret;
	t_commands	c_tab[11];

	//ft_initialize_ctab(&c_tab);
	while (get_next_line(0, &buff))
	{
		if ((ret = ft_parse_command(buff)) > 10)
			return (1);
	//	if (c_tab[ret].f(stack))
	//		return (1);
	}
	return (ft_check_sort(stack));
}
