/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:53:35 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/14 16:21:49 by anrzepec         ###   ########.fr       */
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
		ft_putendl("OK");
	else
		ft_putendl("Error");
	return (ret);
}

