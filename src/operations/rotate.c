/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 12:16:51 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/23 12:41:49 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	rotate(t_ilist **list)
{
	t_ilist	*list_old_head;
	t_ilist	*list_new_head;
	t_ilist	*last_node;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	list_old_head = *list;
	list_new_head = (*list)->next;
	last_node = ps_lstlast(*list);
	*list = list_new_head;
	last_node->next = list_old_head;
	list_old_head->next = NULL;
}

void	ra(t_ilist **stack_a, t_ilist **stack_b)
{
	(void)stack_b;
	rotate(stack_a);
	ft_putendl_fd("ra", STDOUT_FILENO);
}

void	rb(t_ilist **stack_a, t_ilist **stack_b)
{
	(void)stack_a;
	rotate(stack_b);
	ft_putendl_fd("rb", STDOUT_FILENO);
}

void	rr(t_ilist **stack_a, t_ilist **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", STDOUT_FILENO);
}
