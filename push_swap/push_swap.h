/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:15:44 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/18 18:38:10 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../main_header.h"


void		ft_malloc_fail(void);
int			ft_ps_output(int ret);
void		ft_free_stack(t_stack **stk);
t_stack		*ft_new_stkelem(int d);


#endif