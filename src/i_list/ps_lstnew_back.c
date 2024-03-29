/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_lstnew_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 13:13:29 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/23 12:40:14 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

t_ilist	*ps_lstnew_back(t_ilist **lst, int value)
{
	t_ilist	*new;

	new = ps_lstnew(value);
	if (new == NULL)
		return (NULL);
	ps_lstadd_back(lst, new);
	return (new);
}
