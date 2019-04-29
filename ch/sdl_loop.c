/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:26:51 by anrzepec          #+#    #+#             */
/*   Updated: 2019/04/29 20:46:15 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
