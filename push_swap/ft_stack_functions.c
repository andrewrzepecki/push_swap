/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:51:29 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/19 00:54:35 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_free_stack(t_stack **stk)
{
	t_stack *prev;

	if (stk)
		while (*stk)
		{
			printf("val: %d, pos: %d\n", (*stk)->value, (*stk)->pos);
			prev = *stk;
			(*stk) = (*stk)->next;
			free(prev);
		}
}

int			ft_get_pos(int *tab, int t_len, int nb)
{
	int i;

	i = -1;
	while (++i < t_len)
		if (nb == tab[i])
			break;
	return (i);
}

t_stack		*ft_new_stkelem(int d, int *tab, int t_len)
{
	t_stack *elem;

	if (!(elem = (t_stack*)malloc(sizeof(t_stack))))
		ft_malloc_fail();
	elem->value = d;
	if (tab)
		elem->pos = ft_get_pos(tab, t_len, d);
	elem->next = NULL;
	return (elem);
}
