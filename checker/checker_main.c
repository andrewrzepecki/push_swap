/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:27:41 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/13 19:26:35 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**ft_set_stacks(int ac, char **av)
{
	
}

int		ft_parse_args(int ac, char **av)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (ac > 1)
	{
		ret = 1;
		while (++i < ac && ret)
			ret = ft_strlen(av[i]) ? ft_strnum(av[i]) : 0;
	}
	return (ret);
}

int		ft_parse_error(void)
{
	ft_putendl("Error");
	return (1);
}

int		main(int ac, char **av)
{
	char	**stack;

	if (ft_parse_args(ac, av))
		stack = ft_set_stacks(ac, av);
	else
		return (ft_parse_error());
	return (0);
}