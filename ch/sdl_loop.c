/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:26:51 by anrzepec          #+#    #+#             */
/*   Updated: 2019/04/30 09:25:05 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			ft_read_file(char **s)
{
	char	*buff;
	char	*tmp;
	int		ret;

	while ((ret = get_next_line(0, &buff)) > 0)
	{
		if (ft_parse_command(buff, ret) > 10)
		{
			ft_strdel(&buff);
			return (0);
		}
		if (!(tmp = ft_strjoin(*s, buff)))
			ft_malloc_fail();
		ft_strdel(&buff);
		ft_strdel(&(*s));
		if (!(*s = ft_strjoin(tmp, "\n")))
			ft_malloc_fail();
		ft_strdel(&tmp);
	}
	return (1);
}

void		ft_graph_loop(t_sdl_utils *sdl, t_stack **stack, int len, char **tab)
{
	int 		ret;
	int			i;
	int			q;
	t_commands	c_tab[3];

	i = 0;
	ft_initialize_ctab(c_tab);
	while ((q = ft_gevents(sdl)) != QUIT_KEY)
	{
		ft_refresh_screen(stack, sdl, len);
		while (tab[i] && q != QUIT_KEY)
		{
			ret = ft_strlen(tab[i]) + 1;
			ret = ft_parse_command(tab[i], ret);
			ft_execute_commands(stack, c_tab, ret);
			ft_refresh_screen(stack, sdl, len);
			q = ft_gevents(sdl);
			i++;
		}
	}
}
