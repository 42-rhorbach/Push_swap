/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:37:40 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/15 16:26:27 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
