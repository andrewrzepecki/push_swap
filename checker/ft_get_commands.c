/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:14:24 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/14 18:33:20 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			ft_parse_command(char *buff)
{
	if (!ft_strcmp(buff, "sa\n"))
		return (0);
	if (!ft_strcmp(buff, "sb\n"))
		return (1);
	if (!ft_strcmp(buff, "ss\n"))
		return (2);
	if (!ft_strcmp(buff, "pa\n"))
		return (3);
	if (!ft_strcmp(buff, "pb\n"))
		return (4);
	if (!ft_strcmp(buff, "ra\n"))
		return (5);
	if (!ft_strcmp(buff, "rb\n"))
		return (6);
	if (!ft_strcmp(buff, "rr\n"))
		return (7);
	if (!ft_strcmp(buff, "rra\n"))
		return (8);
	if (!ft_strcmp(buff, "rrb\n"))
		return (9);
	if (!ft_strcmp(buff, "rrr\n"))
		return (10);
	return (1995);
}

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

int			ft_command_loop(int **stack)
{
	char		buff[BUFF_SIZE + 1];
	size_t		ret;
	t_commands	c_tab[11];

	ft_initialize_ctab(&c_tab);
	while (1)
	{
		if ((ret = read(0, buff, BUFF_SIZE)) < 0)
			break;
		buff[ret] = '\0';
		if ((ret = ft_parse_command(buff)) > 10)
			return (1)
		if (c_tab[ret].f(stack))
			return (0);
	}
	return (1);
}
