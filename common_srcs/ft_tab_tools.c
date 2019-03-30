/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:16:18 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/30 19:21:40 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_header.h"

int			*ft_pos_tab(t_stack **stack)
{
	int i;
	int *tab;
	t_stack **tracer;

	i = ft_stacklen(stack);
	if (!(tab = (int*)malloc(sizeof(int) * (i))))
		ft_malloc_fail();
	tracer = stack;
	i = 0;
	while (*tracer)
	{
		tab[i] = (*tracer)->value;
		tracer = &(*tracer)->next;
	}
	ft_quicksort(tab, 0, ft_stacklen(stack) - 1);
	return (tab);
}