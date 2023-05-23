/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 12:21:38 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/23 12:30:35 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "types.h"

void	swap(t_ilist **list);
void	push(t_ilist **dest_stack, t_ilist **src_stack);
void	rotate(t_ilist **list);
void	reverse_rotate(t_ilist **list);

void	sa(t_ilist **stack_a, t_ilist **stack_b);
void	sb(t_ilist **stack_a, t_ilist **stack_b);
void	ss(t_ilist **stack_a, t_ilist **stack_b);
void	pa(t_ilist **stack_a, t_ilist **stack_b);
void	pb(t_ilist **stack_a, t_ilist **stack_b);
void	ra(t_ilist **stack_a, t_ilist **stack_b);
void	rb(t_ilist **stack_a, t_ilist **stack_b);
void	rr(t_ilist **stack_a, t_ilist **stack_b);
void	rra(t_ilist **stack_a, t_ilist **stack_b);
void	rrb(t_ilist **stack_a, t_ilist **stack_b);
void	rrr(t_ilist **stack_a, t_ilist **stack_b);

#endif
