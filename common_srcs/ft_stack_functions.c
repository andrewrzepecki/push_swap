/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:26:34 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/20 16:36:50 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_header.h"

void		ft_set_stacks(t_stack **stack, int ac, char **av, int *tab)
{
	int		i;
	t_stack **tracer;
	t_stack	*elem;

	i = 1;
	elem = ft_new_stkelem(ft_atoi(av[i++]), tab, ac - 1);
	if (!(*stack))
		*stack = elem;
	while (i < ac)
	{
		tracer = stack;
		elem = ft_new_stkelem(ft_atoi(av[i]), tab, ac - 1);
		while ((*tracer)->next)
			tracer = &(*tracer)->next;
		(*tracer)->next = elem;
		i++;
	}
}

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
	elem->pos = ft_get_pos(tab, t_len, d);
	elem->next = NULL;
	return (elem);
}