/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 11:24:34 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/15 16:26:35 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ilist	*ps_lstlast(t_ilist *lst)
{
	while (lst != NULL && lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
