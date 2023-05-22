/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 13:17:40 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/11 13:08:01 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lstadd_front(t_ilist **lst, t_ilist *new)
{
	new->next = *lst;
	*lst = new;
}
