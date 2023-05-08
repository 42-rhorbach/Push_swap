/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 14:43:05 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/08 17:04:02 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list)
{
	t_list	*first;
	t_list	*second;
	t_list	*next_in_list;

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

void	push(t_list **dest_stack, t_list **src_stack)
{
	t_list	*src_new_head;
	t_list	*src_old_head;
	t_list	*dest_old_head;

	if (*src_stack == NULL)
		return ;
	src_new_head = (*src_stack)->next;
	src_old_head = (*src_stack);
	dest_old_head = (*dest_stack);

	src_old_head->next = dest_old_head;
	*src_stack = src_new_head;
	*dest_stack = src_old_head;
}

void	rotate(t_list **list)
{
	t_list	*list_old_head;
	t_list	*list_new_head;
	t_list	*last_node;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	list_old_head = *list;
	list_new_head = (*list)->next;
	last_node = ft_lstlast(*list);

	*list = list_new_head;
	last_node->next = list_old_head;
	list_old_head->next = NULL;
}

void	reverse_rotate(t_list **list)
{
	t_list	*list_old_last;
	t_list	*list_new_last;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	list_old_last = ft_lstlast(*list);
	list_new_last = *list;
	while (list_new_last->next->next != NULL)
		list_new_last = list_new_last->next;
	list_old_last->next = *list;
	*list = list_old_last;
	list_new_last->next = NULL;
}

void	sa(t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	swap(stack_a);
}

void	sb(t_list **stack_a, t_list **stack_b)
{
	(void)stack_a;
	swap(stack_b);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
}

void	ra(t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	rotate(stack_a);
}

void	rb(t_list **stack_a, t_list **stack_b)
{
	(void)stack_a;
	rotate(stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	rra(t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	reverse_rotate(stack_a);
}

void	rrb(t_list **stack_a, t_list **stack_b)
{
	(void)stack_a;
	reverse_rotate(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
