/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 10:44:07 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/23 12:40:35 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

int	ps_lstsize(t_ilist *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
