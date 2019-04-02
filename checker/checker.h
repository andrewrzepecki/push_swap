/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:31:51 by anrzepec          #+#    #+#             */
/*   Updated: 2019/04/02 18:25:41 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CHECKER_H_
# define CHECKER_H_

# include <SDL2/SDL.h>
# include "../main_header.h"

# define SDL_ERROR	4;
# define WINDOW_W	700;
# define WINDOW_H	900;


typedef struct		s_sdl_utils
{
	SDL_Window		*window;
	SDL_Surface		*surface;
	SDL_Renderer	*rend;
}					t_sdl_utils;

/* Output Funcitons */
int					ft_checker_output(int ret);

/* Command loop functions */
int					ft_command_loop(t_stack **stack, int len);
void				ft_initialize_ctab(t_commands *tab);
int					ft_check_sort(t_stack **stack, int len);
void				ft_push_stacks(int function, t_stack **stack);
size_t				ft_parse_command(char *buff);

/* VISUALISER FUNCTIONS */
int					ft_vcommand_loop(t_stack **stack, int len);

/* DEBUG TOOLS */
void				ft_print_stacks(t_stack **stack_a, t_stack **stack_b);

#endif
