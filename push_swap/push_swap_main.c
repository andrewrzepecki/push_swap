/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:27:41 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/20 16:32:46 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int			main(int ac, char **av)
{
	int		ret;
	int		*tab;
	char	**commands;
	t_stack	*stack[2];

	ret = 1;
	stack[A] = NULL;
	stack[B] = NULL;
	if (ft_parse_args(ac, av))
	{
		tab = ft_pos_tab(av, ac);
		ft_set_stacks(&stack[A], ac, av, tab);
		free(tab);
		//ft_sort_stacks(stack, 0, ac - 1);
		ft_free_stack(&stack[A]);
		return (0);
	}
	return (ft_error_output());
	//return (ft_commands_output(commands));
}
