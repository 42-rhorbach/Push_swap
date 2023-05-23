/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:37:40 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/23 12:39:44 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ps_lstclear(t_ilist **lst)
{
	t_ilist	*temp;

	while (*lst != NULL)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
