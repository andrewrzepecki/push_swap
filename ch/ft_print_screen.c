/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:57:54 by anrzepec          #+#    #+#             */
/*   Updated: 2019/04/05 13:10:21 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_print_stack_a(t_stack **stack, t_sdl_utils *sdl, double len)
{
	SDL_Rect	rect;
	double		width;
	double		start_y;
	t_stack		**tracer;

	SDL_SetRenderDrawColor(sdl->rend, 0xFF, 0x00, 0x00, 0xFF);
	start_y = WINDOW_H / (len + 2);
	width = (WINDOW_W / 2) / (len + 2);
	tracer = stack;
	len = 0;
	while (*tracer)
	{
		rect.y = start_y + (len * start_y);
		rect.x = width;
		rect.w = width * ((*tracer)->pos + 1);
		rect.h = start_y;
		SDL_RenderFillRect(sdl->rend, &rect);
		tracer = &(*tracer)->next;
		len++;
	}
}

void		ft_print_stack_b(t_stack **stack, t_sdl_utils *sdl, double len)
{
	SDL_Rect	rect;
	double		start_y;
	double		width;
	t_stack		**tracer;

	SDL_SetRenderDrawColor(sdl->rend, 0xFF, 0x00, 0x00, 0xFF);
	start_y = WINDOW_H / (len + 2);
	width = (WINDOW_W / 2) / (len + 2);
	tracer = stack;
	len = 0;
	while (*tracer)
	{
		rect.y = start_y + (len * start_y);
		rect.x = WINDOW_W / 2 + width;
		rect.w = width * ((*tracer)->pos + 1);
		rect.h = start_y;
		SDL_RenderFillRect(sdl->rend, &rect);
		tracer = &(*tracer)->next;
		len++;
	}
}

int			ft_gevents(t_sdl_utils *sdl)
{
	const Uint8	*key;

	key = SDL_GetKeyboardState(NULL);
	while (SDL_PollEvent(&sdl->ev) != 0)
	{
		if (sdl->ev.type == SDL_QUIT)
			return (QUIT_KEY);
		if (key[SDL_SCANCODE_UP])
		{
			if (sdl->speed > 10)
				sdl->speed -= 10;
		}
		else if (key[SDL_SCANCODE_DOWN])
		{
			if (sdl->speed < 200)
				sdl->speed += 10;
		}
		break ;
	}
	return (1);
}

void		ft_sdl_exit(t_sdl_utils *sdl, int ret)
{
	int quit;

	quit = 1;
	if (ret != QUIT_KEY)
		while (quit)
		{
			while (SDL_PollEvent(&sdl->ev) != 0)
			{
				if (sdl->ev.type == SDL_QUIT)
					quit = 0;
			}
		}
	SDL_DestroyRenderer(sdl->rend);
	SDL_DestroyWindow(sdl->window);
}
