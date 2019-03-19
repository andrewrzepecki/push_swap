/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:15:44 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/19 00:58:05 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../main_header.h"


void		ft_malloc_fail(void);
int			ft_ps_output(int ret);
int			*ft_pos_tab(char **av, int ac);
int			ft_get_pos(int *tab, int t_len, int nb);
void		ft_free_stack(t_stack **stk);
t_stack		*ft_new_stkelem(int d, int *tab, int t_len);


#endif
