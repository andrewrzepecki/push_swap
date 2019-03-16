/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:56:08 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/16 18:04:45 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int			ft_get_pivot(int **tab, int low, int high)
{
	int tmp;
	int i;
	int pivot;
	int left;
	
	pivot = (*tab)[low];
	left = low;
	i = low;
	while (i <= high)
	{
		if ((*tab)[i] < pivot)
		{
			tmp = (*tab)[i];
			(*tab)[i] = (*tab)[left + 1];
			(*tab)[left + 1] = tmp;
			left++;
		}
		i++;
	}
	tmp = pivot;
	pivot = (*tab)[left];
	(*tab)[left] = tmp;
	return (left);
}

void		ft_quicksort(int **tab, int low, int high)
{
	int		pivot;

	if (low < high)
	{
		pivot = ft_get_pivot(tab, low, high);
		ft_quicksort(tab, low, pivot);
		ft_quicksort(tab, pivot + 1, high);
	}
}