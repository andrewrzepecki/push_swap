/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:16:18 by anrzepec          #+#    #+#             */
/*   Updated: 2019/04/11 15:15:01 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_header.h"

void		ft_free_char_tab(char ***tab)
{
	int	i;

	i = -1;
	while ((*tab)[++i])
		ft_strdel(&(*tab)[i]);
	free(*tab);
}

int			ft_check_llong(char *s)
{
	int i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		while (s[i] && s[i] == '0' && c == 0)
			i++;
		c++;
		i++;
	}
	if (c < 20)
		return (0);
	return (1);
}

void		ft_set_positions(t_stack **stack, int *tab)
{
	int		i;
	t_stack	**tracer;

	tracer = stack;
	while (*tracer)
	{
		i = 0;
		while (tab[i] != (*tracer)->value)
			i++;
		(*tracer)->pos = i;
		tracer = &(*tracer)->next;
	}
}

void		ft_pos_tab(t_stack **stack)
{
	int		i;
	int		*tab;
	t_stack	**tracer;

	i = ft_stacklen(stack);
	if (!(tab = (int*)malloc(sizeof(int) * (i))))
		ft_malloc_fail();
	tracer = stack;
	i = 0;
	while (*tracer)
	{
		tab[i] = (*tracer)->value;
		tracer = &(*tracer)->next;
		i++;
	}
	ft_quicksort(tab, 0, ft_stacklen(stack) - 1);
	ft_set_positions(stack, tab);
	free(tab);
}
