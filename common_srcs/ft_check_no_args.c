/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_no_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 10:58:55 by anrzepec          #+#    #+#             */
/*   Updated: 2019/04/16 17:32:47 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_header.h"

int		ft_check_no_args(char **av, int ac, int v)
{
	int i;

	i = (v != 0) ? 2 : 1;
	if (i == ac)
		return (1);
	while (i < ac)
	{
		if (!ft_strlen(av[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
