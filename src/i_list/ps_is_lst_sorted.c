/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_is_lst_sorted.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/30 13:10:52 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/30 13:24:54 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

bool	ps_is_lst_sorted(t_ilist *lst)
{
	while (lst->next != NULL)
	{
		if (lst->value > lst->next->value)
			return (false);
		lst = lst->next;
	}
	return (true);
}
