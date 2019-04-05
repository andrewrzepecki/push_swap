/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:56:08 by anrzepec          #+#    #+#             */
/*   Updated: 2019/04/05 11:27:57 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_header.h"

int			ft_get_pivot(int **tab, int low, int high)
{
	int tmp;
	int i;
	int pivot;
	int left;

	pivot = high;
	left = low;
	i = low;
	while (i < high)
	{
		if ((*tab)[i] < (*tab)[pivot])
		{
			tmp = (*tab)[i];
			(*tab)[i] = (*tab)[left];
			(*tab)[left] = tmp;
			left++;
		}
		i++;
	}
	tmp = (*tab)[pivot];
	(*tab)[pivot] = (*tab)[left];
	(*tab)[left] = tmp;
	return (left);
}

void		ft_quicksort(int *tab, int low, int high)
{
	int		pivot;

	if (low < high)
	{
		pivot = ft_get_pivot(&tab, low, high);
		ft_quicksort(tab, low, pivot - 1);
		ft_quicksort(tab, pivot + 1, high);
	}
}
