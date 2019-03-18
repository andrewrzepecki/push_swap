/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:21:22 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/18 18:40:48 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HEADER_H
# define MAIN_HEADER_H

#include "libft/libft.h"

# define A 0
# define B 1

typedef struct		s_stack
{
	int				value;
	int				pos;
	struct s_stack	*next;
}					t_stack;

#endif