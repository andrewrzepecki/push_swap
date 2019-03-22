/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:31:51 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/22 16:57:30 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CHECKER_H_
# define CHECKER_H_

# include "../main_header.h"

typedef	struct		s_clist
{
	char			*cmd;
	struct s_clist	*next;
}					t_clist;

/* Output Funcitons */
int					ft_checker_output(int ret);

/* Command loop functions */
int					ft_command_loop(t_stack **stack, int *tab, int t_len);
void				ft_initialize_ctab(t_commands *tab);
size_t				ft_parse_command(char *buff);

/* DEBUG TOOLS */

void			ft_print_stacks(t_stack **stack_a, t_stack **stack_b);

#endif