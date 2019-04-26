/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vcommands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:14:24 by anrzepec          #+#    #+#             */
/*   Updated: 2019/04/25 15:02:06 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_execute_commands(t_stack **stack, t_commands *c_tab, int ret)
{
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
}

void		ft_refresh_screen(t_stack **stack, t_sdl_utils *sdl, int len)
{
	sdl->bg.x = 0;
	sdl->bg.y = 0;
	sdl->bg.w = WINDOW_W;
	sdl->bg.h = WINDOW_H;
	SDL_RenderClear(sdl->rend);
	SDL_SetRenderDrawColor(sdl->rend, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderFillRect(sdl->rend, &(sdl->bg));
	ft_print_stack_a(&stack[A], sdl, (double)len);
	ft_print_stack_b(&stack[B], sdl, (double)len);
	SDL_RenderPresent(sdl->rend);
	SDL_UpdateWindowSurface(sdl->window);
}

int			ft_initialize_graphs(t_sdl_utils *sdl)
{
	sdl->speed = 200;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (SDL_ERROR);
	if (!(sdl->window = SDL_CreateWindow("Push Swap",
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
					WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN)))
		return (SDL_ERROR);
	if (!(sdl->rend = SDL_CreateRenderer(sdl->window, -1,
				SDL_RENDERER_ACCELERATED)))
		return (SDL_ERROR);
	return (0);
}

int			ft_store_comms(char ***tab)
{
	int			ret;
	char		*s;
	char		*buff;
	char		*tmp;

	if (!(s = ft_memalloc(1)))
		ft_malloc_fail();
	while ((ret = get_next_line(0, &buff)) > 0)
	{
		if (ft_parse_command(buff, ret) > 10)
		{
			ft_strdel(&s);
			return (0);
		}
		if (!(tmp = ft_strjoin(s, buff)))
			ft_malloc_fail();
		ft_strdel(&buff);
		ft_strdel(&s);
		if (!(s = ft_strjoin(tmp, "\n")))
			ft_malloc_fail();
		ft_strdel(&tmp);
	}
	if (!(*tab = ft_strsplit(s, '\n')))
		ft_malloc_fail();
	ft_strdel(&s);
	return (1);
}

int			ft_vcommand_loop(t_stack **stack, int len)
{
	char		**tab;
	size_t		ret;
	t_sdl_utils	sdl;
	t_commands	c_tab[3];
	int			i[2];

	tab = NULL;
	if (!ft_store_comms(&tab))
		return (0);
	ft_initialize_ctab(c_tab);
	if (ft_initialize_graphs(&sdl))
		return (SDL_ERROR);
	i[0] = -1;
	while (tab[++i[0]] && (i[1] = ft_gevents(&sdl)) != QUIT_KEY)
	{
		ft_refresh_screen(stack, &sdl, len);
		ret = ft_parse_command(tab[i[0]], (ret = ft_strlen(tab[i[0]]) + 1));
		ft_execute_commands(stack, c_tab, ret);
		ft_refresh_screen(stack, &sdl, len);
	}
	ret = ft_check_sort(&stack[A], len);
	ft_sdl_exit(&sdl, i[1], &tab);
	return (ret);
}
