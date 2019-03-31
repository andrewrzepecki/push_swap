/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:27:41 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/31 12:51:43 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			main(int ac, char **av)
{
	int		ret;
	t_stack	*stack[2];

	ret = 1;
	stack[A] = NULL;
	stack[B] = NULL;
	if ((ret = ft_parse_args(ac, av, &stack[A])))
	{
		ft_pos_tab(&stack[A]);
		ret = ft_command_loop(stack, ft_stacklen(&stack[A]));
	}
	ft_checker_output(ret);
	ft_free_stack(&stack[A]);
	ft_free_stack(&stack[B]);
	return (ret);
}
