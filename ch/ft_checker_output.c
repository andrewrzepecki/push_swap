/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:53:35 by anrzepec          #+#    #+#             */
/*   Updated: 2019/04/05 11:20:55 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_malloc_fail(void)
{
	ft_putendl("malloc() error!");
	exit(1);
}

int			ft_checker_output(int ret)
{
	if (!ret)
		ft_putendl("Error");
	else if (ret == 1)
		ft_putendl("OK");
	else if (ret == SDL_ERROR)
		ft_putendl("SDL_ERROR");
	else if (ret == QUIT_KEY)
		ft_putendl("Window exit");
	else
		ft_putendl("KO");
	return (ret);
}
