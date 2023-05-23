/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 12:18:30 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/23 12:41:34 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	reverse_rotate(t_ilist **list)
{
	t_ilist	*list_old_last;
	t_ilist	*list_new_last;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	list_old_last = ps_lstlast(*list);
	list_new_last = *list;
	while (list_new_last->next->next != NULL)
		list_new_last = list_new_last->next;
	list_old_last->next = *list;
	*list = list_old_last;
	list_new_last->next = NULL;
}

void	rra(t_ilist **stack_a, t_ilist **stack_b)
{
	(void)stack_b;
	reverse_rotate(stack_a);
	ft_putendl_fd("rra", STDOUT_FILENO);
}

void	rrb(t_ilist **stack_a, t_ilist **stack_b)
{
	(void)stack_a;
	reverse_rotate(stack_b);
	ft_putendl_fd("rrb", STDOUT_FILENO);
}

void	rrr(t_ilist **stack_a, t_ilist **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", STDOUT_FILENO);
}
