/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:16:18 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/21 19:17:45 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_header.h"

int			*ft_pos_tab(char **av, int ac)
{
	int i;
	int *tab;

	if (!(tab = (int*)malloc(sizeof(int) * (ac - 1))))
		ft_malloc_fail();
	i = 0;
	while (++i < ac)
		tab[i - 1] = ft_atoi(av[i]);
	ft_quicksort(tab, 0, ac - 2);
	return (tab);
}