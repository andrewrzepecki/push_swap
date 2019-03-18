/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:51:29 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/18 19:02:27 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_free_stack(t_stack **stk)
{
	t_stack *prev;

	if (stk)
		while (*stk)
		{
			ft_printf("%d\n", (*stk)->value);
			prev = *stk;
			(*stk) = (*stk)->next;
			free(prev);
		}
}

t_stack		*ft_new_stkelem(int d)
{
	t_stack *elem;

	if (!(elem = (t_stack*)malloc(sizeof(t_stack))))
		ft_malloc_fail();
	elem->value = d;
	elem->next = NULL;
	return (elem);
}
