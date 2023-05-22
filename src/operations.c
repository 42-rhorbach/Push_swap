/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 14:43:05 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/22 16:03:55 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_ilist **list)
{
	t_ilist	*first;
	t_ilist	*second;
	t_ilist	*next_in_list;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	first = *list;
	// second = (*list)->next;
	// second = (**list).next;
	second = first->next;
	next_in_list = second->next;
	// next_in_list = (*second).next;
	first->next = next_in_list;
	second->next = first;
	*list = second;
}

void	push(t_ilist **dest_stack, t_ilist **src_stack)
{
	t_ilist	*src_new_head;
	t_ilist	*src_old_head;
	t_ilist	*dest_old_head;

	if (*src_stack == NULL)
		return ;
	src_new_head = (*src_stack)->next;
	src_old_head = (*src_stack);
	dest_old_head = (*dest_stack);

	src_old_head->next = dest_old_head;
	*src_stack = src_new_head;
	*dest_stack = src_old_head;
}

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

void	sa(t_ilist **stack_a, t_ilist **stack_b)
{
	(void)stack_b;
	swap(stack_a);
	ft_putendl_fd("sa", STDOUT_FILENO);
}

void	sb(t_ilist **stack_a, t_ilist **stack_b)
{
	(void)stack_a;
	swap(stack_b);
	ft_putendl_fd("sb", STDOUT_FILENO);
}

void	ss(t_ilist **stack_a, t_ilist **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", STDOUT_FILENO);
}

void	pa(t_ilist **stack_a, t_ilist **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pa", STDOUT_FILENO);
}

void	pb(t_ilist **stack_a, t_ilist **stack_b)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pb", STDOUT_FILENO);
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
