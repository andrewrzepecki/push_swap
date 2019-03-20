/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:31:51 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/20 16:36:46 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CHECKER_H_
# define CHECKER_H_

# include "../main_header.h"

/* Output Funcitons */
int					ft_checker_output(int ret);

/* Command loop functions */
int					ft_command_loop(int **stack);
void				ft_initialize_ctab(int **stack);
size_t				ft_parse_command(char *buff);

#endif