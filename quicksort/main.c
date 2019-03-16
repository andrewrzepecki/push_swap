/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:46:32 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/16 17:52:38 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void		ft_quicksort(int **tab, int low, int high);

void		print_tab(int *tab, int len)
{
	int i;
	i = -1;
	while (++i < len - 1)
		ft_printf("%d\n", tab[i]);
}

int			main(int ac, char **av)
{
	int i;
	int	*tab;
	int min;
	int max;

	tab = (int*)malloc(sizeof(int) * (ac - 1));
	i = 0;
	min = ft_atoi(av[1]);
	max = ft_atoi(av[2]);
	while (++i < ac)
		tab[i - 1] = ft_atoi(av[i]);
	ft_quicksort(&tab, 0, ac - 2);
	print_tab(tab, ac);
	return (0);
}