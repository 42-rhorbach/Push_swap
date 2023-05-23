/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_lstnew_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 13:17:40 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/23 12:40:24 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

t_ilist	*ps_lstnew_front(t_ilist **lst, int value)
{
	t_ilist	*new;

	new = ps_lstnew(value);
	if (new == NULL)
		return (NULL);
	ps_lstadd_front(lst, new);
	return (new);
}
