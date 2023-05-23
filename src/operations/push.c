/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 12:12:06 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/23 12:41:13 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stddef.h>
#include <unistd.h>

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
