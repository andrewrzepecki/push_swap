/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:14:24 by anrzepec          #+#    #+#             */
/*   Updated: 2019/04/02 18:25:42 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_initialize_vctab(t_vcommands *tab)
{
	tab[0].f = ft_swap;
	tab[1].f = ft_rotate;
	tab[2].f = ft_rev_rotate;
}

void		ft_execute_commands(t_stack **stack, int ret)
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

void		ft_refresh_screen(stack, t_sdl_utils *sdl)
{
	SDL_RenderClear(sdl->rend);
	SDL_SetRenderDrawColor(sdl->rend, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderFillRect(sdl->rend, &sdl->surface);
	ft_print_stack_a(sdl, &stack[A], len);
	ft_print_stack_b(sdl, &stack[B], len);
	SDL_RenderPresent(sdl->rend);
	SDL_UpdateWindowSurface(sdl->window);
}

int			ft_initialize_graphs(t_sdl_utils *sdl)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (SDL_ERROR);
	if (!(sdl->window = SDL_CreateWindow("Push Swap", 
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
					WINDOW_H, WINDOW_W, SDL_WINDOW_SHOWN)))
		return (SDL_ERROR);
	if (!(sdl->surface = SDL_GetWindowSurface(sdl->win)))
		return (SDL_ERROR);
	if (!(sdl->rend = SDL_CreateRenderer(sdl->window, -1, SDL_RENDERER_ACCELERATED)))
		return (SDL_ERROR);
	return (0);
}

int			ft_vcommand_loop(t_stack **stack, int len)
{
	char		*buff;
	size_t		ret;
	t_sdl_utils	sdl;
	t_vcommands	c_tab[3];

	ft_initialize_vctab(c_tab);
	if (ft_initialize_graphs(&sdl))
		return (SDL_ERROR);
	while (get_next_line(0, &buff))
	{
		ft_refresh_screen(stack, &sdl, len);
		if ((ret = ft_parse_command(buff)) > 10)
			return (1);
		ft_execute_commands(stack, ret);
	}
	ret = ft_check_sort(&stack[A], len);
	ft_sdl_exit(&sdl, ret);
	return (ret);
}
