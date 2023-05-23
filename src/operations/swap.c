/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 12:11:05 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/23 12:42:43 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	swap(t_ilist **list)
{
	t_ilist	*first;
	t_ilist	*second;
	t_ilist	*next_in_list;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	first = *list;
	second = first->next;
	next_in_list = second->next;
	first->next = next_in_list;
	second->next = first;
	*list = second;
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
