/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:31:51 by anrzepec          #+#    #+#             */
/*   Updated: 2019/04/10 15:38:45 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <SDL2/SDL.h>
# include "../main_header.h"

# define SDL_ERROR	4
# define WINDOW_W	600
# define WINDOW_H	600
# define QUIT_KEY	42

typedef struct		s_sdl_utils
{
	SDL_Window		*window;
	SDL_Rect		bg;
	SDL_Renderer	*rend;
	int				speed;
	SDL_Event		ev;
}					t_sdl_utils;

int					ft_checker_output(int ret);

int					ft_command_loop(t_stack **stack, int len);
void				ft_initialize_ctab(t_commands *tab);
int					ft_check_sort(t_stack **stack, int len);
void				ft_push_stacks(int function, t_stack **stack);
size_t				ft_parse_command(char *buff);

int					ft_vcommand_loop(t_stack **stack, int len);
void				ft_print_stack_a(t_stack **stack, t_sdl_utils *sdl,
					double len);
void				ft_print_stack_b(t_stack **stack, t_sdl_utils *sdl,
					double len);
int					ft_gevents(t_sdl_utils *sdl);
void				ft_sdl_exit(t_sdl_utils *sdl, int ret, char ***tab);

void				ft_print_stacks(t_stack **stack_a, t_stack **stack_b);

#endif
