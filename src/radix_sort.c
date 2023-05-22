/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 17:42:08 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/22 16:05:01 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_ilist **stack_a, t_ilist **stack_b, int list_length)
{
	int	shift;
	int	i;

	shift = 0;
	while ((list_length - 1) >> shift != 0)
	{
		i = 0;
		while ((*stack_a) != NULL && i < list_length)
		{
			if (((*stack_a)->minimized_value & (1 << shift)) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a, stack_b);
			i++;
		}
		while ((*stack_b) != NULL)
			pa(stack_a, stack_b);
		shift++;
	}
}

	// (getal & 0b00001) == 1 | 0
	// (getal & (0b00001 << 1)) == 2 | 0
	// (getal & 0b00100) == 4 | 0

	// (getal & 0b00001) >> 0 == 1 | 0
	// (getal & 0b00010) >> 1 == 1 | 0
	// (getal & 0b00100) >> 2 == 1 | 0


	// (getal) % 2 == 0 | 1
	// (getal / 2) % 2 == 0 | 1
	// (getal / 2 / 2) % 2 == 0 | 1
	// (getal / 2 / 2 / 2) % 2 == 0 | 1

	// (getal) % 3 == 0 | 1 | 2
	// (getal / 3) % 3 == 0 | 1 | 2
	// (getal / 3 / 3) % 3 == 0 | 1 | 2
	// (getal / 3 / 3 / 3) % 3 == 0 | 1 | 2
