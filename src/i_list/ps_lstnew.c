/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 12:23:20 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/17 16:46:11 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ilist	*ps_lstnew(int value)
{
	t_ilist	*new_list;

	new_list = malloc(sizeof(t_ilist));
	if (new_list == NULL)
		return (NULL);
	new_list->value = value;
	new_list->minimized_value = value;
	new_list->next = NULL;
	return (new_list);
}
