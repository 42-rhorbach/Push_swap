/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pre_sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 17:35:47 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/22 13:10:58 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_ilist **list_array, int list_length)
{
	int		i;
	t_ilist	*temp;

	while (list_length > 1)
	{
		i = 0;
		while (i < list_length - 1)
		{
			if (list_array[i]->value > list_array[i + 1]->value)
			{
				temp = list_array[i + 1];
				list_array[i + 1] = list_array[i];
				list_array[i] = temp;
			}
			i++;
		}
		list_length--;
	}
}

t_ilist	**arrayify(t_ilist *list, int list_length)
{
	t_ilist	**list_array;
	int		i;

	list_array = malloc(sizeof(*list_array) * list_length);
	if (list_array == NULL)
		return (NULL);
	i = 0;
	while (list != NULL)
	{
		list_array[i] = list;
		i++;
		list = list->next;
	}
	return (list_array);
}

t_error	pre_sort(t_ilist *list, int list_length)
{
	t_ilist			**list_array;
	int				i;

	list_array = arrayify(list, list_length);
	if (list_array == NULL)
		return (set_error(E_MALLOC));
	bubble_sort(list_array, list_length);
	i = 0;
	while (i < list_length - 1)
	{
		if (list_array[i]->value == list_array[i + 1]->value)
		{
			free(list_array);
			return (set_error(E_DUPE));
		}
		i++;
	}
	i = 0;
	while (i < list_length)
	{
		list_array[i]->minimized_value = i;
		i++;
	}
	free(list_array);
	return (OK);
}
