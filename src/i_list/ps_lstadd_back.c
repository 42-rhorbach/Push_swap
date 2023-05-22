/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 14:24:03 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/11 13:07:54 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lstadd_back(t_ilist **lst, t_ilist *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ps_lstlast(*lst)->next = new;
}
