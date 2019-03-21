/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:27:41 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/21 19:52:28 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			main(int ac, char **av)
{
	int		ret;
	int		*tab;
	t_stack	*stack[2];

	ret = 1;
	stack[A] = NULL;
	stack[B] = NULL;
	if (ft_parse_args(ac, av))
	{
		tab = ft_pos_tab(av, ac);
		ft_set_stacks(&stack[A], ac, av, NULL);
		ft_checker_output(ft_command_loop(stack, tab, ac - 1));
		ft_free_stack(&stack[A]);
		ft_free_stack(&stack[B]);
	}
	else
		return (ft_checker_output(ret));
	return (ret);
}