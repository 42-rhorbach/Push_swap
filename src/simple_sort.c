/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 13:21:41 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/23 13:17:41 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_ilist **stack_a, t_ilist **stack_b)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, stack_b);
}

void	sort_3(t_ilist **stack_a, t_ilist **stack_b)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a < c && c < b)
	{
		rra(stack_a, stack_b);
		sa(stack_a, stack_b);
	}
	if (b < a && a < c)
		sa(stack_a, stack_b);
	if (c < a && a < b)
		rra(stack_a, stack_b);
	if (b < c && c < a)
		ra(stack_a, stack_b);
	if (c < b && b < a)
	{
		ra(stack_a, stack_b);
		sa(stack_a, stack_b);
	}
}

// 0 // -
// 1
// 2

// 0 // rra sa / sa rra
// 2
// 1

// 1 // sa
// 0
// 2

// 1 // rra
// 2
// 0

// 2 // ra
// 0
// 1

// 2 // sa ra / ra sa
// 1
// 0

/*
if ((c < b && b < a) || (b < c && c < a))
	ra;
if ((c < a && a < b) || (a < c && c < b))
	rra;
if ((a < c && c < b) || (a < b && b < c) || (c < b && b < a))
	sa;
*/

void	sort_4(t_ilist **stack_a, t_ilist **stack_b)
{
	int	a;
	int	b;
	int	c;
	int	d;

	pb(stack_a, stack_b);
	sort_3(stack_a, stack_b);
	a = (*stack_b)->value;
	b = (*stack_a)->value;
	c = (*stack_a)->next->value;
	d = (*stack_a)->next->next->value;
	if (c < a && a < d)
		rra(stack_a, stack_b);
	pa(stack_a, stack_b);
	if (b < a && a < c)
		sa(stack_a, stack_b);
	if (c < a)
		ra(stack_a, stack_b);
	if (c < a && a < d)
		ra(stack_a, stack_b);
}

// 1 0 // pa
// 2
// 3

// 0 1 // pa sa
// 2
// 3

// 0 2 // rra pa ra ra // ra pa sa rra
// 1
// 3

// 0 3 // pa ra
// 1
// 2

void	sort_5(t_ilist **stack_a, t_ilist **stack_b)
{
	int const	a = (*stack_a)->value;
	int			b;
	int			c;
	int			d;
	int			e;

	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	b = (*stack_a)->value;
	c = (*stack_a)->next->value;
	d = (*stack_a)->next->next->value;
	e = (*stack_a)->next->next->next->value;
	if (c < a && a < d)
		ra(stack_a, stack_b);
	if (d < a && a < e)
		rra(stack_a, stack_b);
	pa(stack_a, stack_b);
	if (b < a && a < d)
		sa(stack_a, stack_b);
	if (c < a && a < d)
		rra(stack_a, stack_b);
	if (d < a)
		ra(stack_a, stack_b);
	if (d < a && a < e)
		ra(stack_a, stack_b);
}

// 1 0 // pa
// 2
// 3
// 4

// 0 1 // pa sa
// 2
// 3
// 4

// 0 2 // ra pa sa rra
// 1
// 3
// 4

// 0 3 // rra pa ra ra
// 1
// 2
// 4

// 0 4 // pa ra
// 1
// 2
// 3

/*


	if (a < b)
		pa; return ;
	if (b < a && a < d)
	{
		if (c < a)
			ra;
		pa; sa;
		if (c < a)
			rra;
		return;
	}
	if (d < a)
	{
		if (a < e)
			rra;
		pa; ra;
		if (a < e)
			ra;
		return;
	}



	if (c < a && a < d)
		ra;
	if (d < a && a < e)
		rra;
	pa;
	if (b < a && a < d)
		sa;
	if (c < a && a < d)
		rra;
	if (d < a)
		ra;
	if (d < a && a < e)
		ra;
*/
