/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:57:54 by anrzepec          #+#    #+#             */
/*   Updated: 2019/04/03 15:38:18 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_print_stack_a(t_stack **stack, t_sdl_utils *sdl, int len)
{
	SDL_Rect	rect;
	int			width;
	int 		start_y;
	int			start_x;
	t_stack		**tracer;

	SDL_SetRenderDrawColor(sdl->rend, 0xFF, 0x00, 0x00, 0xFF);
	start_y = WINDOW_H / (len + 2);
	width = (WINDOW_W / 2) / (len + 2);
	tracer = stack;
	while (*tracer)
	{
		rect.y = start_y;
		rect.x = 0 + width;
		rect.w = width * ((*tracer)->pos + 1);
		rect.h = start_y;
		start_y += start_y;
		SDL_RenderFillRect(sdl->rend, &rect);
		tracer = &(*tracer)->next;
	}
}

void		ft_print_stack_b(t_stack **stack, t_sdl_utils *sdl, int len)
{
	SDL_Rect	rect;
	int 		start_y;
	int			width;
	t_stack		**tracer;

	SDL_SetRenderDrawColor(sdl->rend, 0xFF, 0x00, 0x00, 0xFF);
	start_y = WINDOW_H / (len + 2);
	width = (WINDOW_W / 2) / (len + 2);
	tracer = stack;
	while (*tracer)
	{
		rect.y = start_y;
		rect.x = WINDOW_W / 2 + width;
		rect.w = width * ((*tracer)->pos + 1);
		rect.h = start_y;
		start_y += start_y;
		SDL_RenderFillRect(sdl->rend, &rect);
		tracer = &(*tracer)->next;
	}
}

void		ft_sdl_exit(t_sdl_utils *sdl, int ret)
{
	
}
