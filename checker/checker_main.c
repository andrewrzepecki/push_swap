/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:27:41 by anrzepec          #+#    #+#             */
/*   Updated: 2019/04/03 15:42:12 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			ft_fetch_options(char **av, int ac)
{
	if (ac > 1)
		if (!ft_strcmp(av[1], "-v"))
			return (1);
	return (0);
}

int			main(int ac, char **av)
{
	int		ret;
	int		visu;
	t_stack	*stack[2];

	ret = 1;
	stack[A] = NULL;
	stack[B] = NULL;
	visu = ft_fetch_options(av, ac);
	if ((ret = ft_parse_args(ac, av, &stack[A], visu)))
	{
		ft_pos_tab(&stack[A]);
		if (visu)
			ret = ft_vcommand_loop(stack, ft_stacklen(&stack[A]));
		else
			ret = ft_command_loop(stack, ft_stacklen(&stack[A]));
	}
	ft_checker_output(ret);
	ft_free_stack(&stack[A]);
	ft_free_stack(&stack[B]);
	return (ret);
}
