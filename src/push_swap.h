/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 15:15:16 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/23 12:38:46 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "operations.h"
# include "types.h"

t_error	set_error(t_error err);
t_error	get_error(void);
void	print_error(t_error err);

void	ps_lstadd_front(t_ilist **lst, t_ilist *new);
void	ps_lstadd_back(t_ilist **lst, t_ilist *new);
void	ps_lstclear(t_ilist **lst);
t_ilist	*ps_lstlast(t_ilist *lst);
t_ilist	*ps_lstnew_front(t_ilist **lst, int value);
t_ilist	*ps_lstnew_back(t_ilist **lst, int value);
t_ilist	*ps_lstnew(int value);
int		ps_lstsize(t_ilist *lst);

t_error	pre_sort(t_ilist *list, int list_length);
void	radix_sort(t_ilist **stack_a, t_ilist **stack_b, int list_length);

void	sort_2(t_ilist **stack_a, t_ilist **stack_b);
void	sort_3(t_ilist **stack_a, t_ilist **stack_b);
void	sort_4(t_ilist **stack_a, t_ilist **stack_b);
void	sort_5(t_ilist **stack_a, t_ilist **stack_b);

void	list_print(t_ilist *list); //temp
void	print_stacks(t_ilist *stack_a, t_ilist *stack_b); //temp

#endif
