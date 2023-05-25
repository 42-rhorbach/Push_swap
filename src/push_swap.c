/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 14:46:51 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/25 16:23:33 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

bool	ps_atoi(const char *str, int *result_ptr)
{
	int		i;
	int		sign;
	long	c;

	sign = -1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (false);
	c = 0;
	while (ft_isdigit(str[i]))
	{
		c = ((c * 10) - (str[i] - '0'));
		if (c * sign < -2147483648 || c * sign > 2147483647)
			return (false);
		i++;
	}
	*result_ptr = c * sign;
	return (str[i] == '\0');
}

void	sort(t_ilist **stack_a, t_ilist **stack_b, int list_len)
{
	if (list_len <= 1)
		return ;
	else if (list_len == 2)
		sort_2(stack_a, stack_b);
	else if (list_len == 3)
		sort_3(stack_a, stack_b);
	else if (list_len == 4)
		sort_4(stack_a, stack_b);
	else if (list_len == 5)
		sort_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b, list_len);
}

t_error	list_init(char **input, int len, t_ilist **stack_a)
{
	int		i;
	int		result_ptr;
	bool	parsed_num;

	i = 0;
	while (i < len)
	{
		parsed_num = ps_atoi(input[i], &result_ptr);
		if (!parsed_num)
			return (set_error(E_PARSE));
		if (ps_lstnew_back(stack_a, result_ptr) == NULL)
			return (set_error(E_MALLOC));
		i++;
	}
	if (pre_sort(*stack_a, len) != OK)
		return (get_error());
	return (OK);
}

t_error	push_swap(char **input, int len)
{
	t_ilist	*stack_a;
	t_ilist	*stack_b;

	if (len == 0)
		return (OK);
	stack_a = NULL;
	stack_b = NULL;
	if (list_init(input, len, &stack_a) != OK)
	{
		ps_lstclear(&stack_a);
		ps_lstclear(&stack_b);
		return (get_error());
	}
	sort(&stack_a, &stack_b, len);
	ps_lstclear(&stack_a);
	ps_lstclear(&stack_b);
	return (OK);
}

int	main(int argc, char **argv)
{
	if (argc == 0)
		return (EXIT_SUCCESS);
	if (push_swap(&argv[1], argc - 1) != OK)
	{
		print_error(get_error());
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
