/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:27:41 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/20 16:36:46 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			main(int ac, char **av)
{
	int		ret;
	t_stack	*stack[2];

	ret = 1;
	if (ft_parse_args(ac, av))
	{
		ft_set_stacks(stack, ac, av, NULL);
		ft_checker_output(ft_command_loop(stack));
	}
	else
		return (ft_checker_output(ret));
	return (ret);
}