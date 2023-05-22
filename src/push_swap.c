/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 14:46:51 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/22 12:48:47 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_print(t_ilist *list)
{
	while (list != NULL)
	{
		printf("%d\n", list->value);
		list = list->next;
	}
}

void	print_binary(int n)
{
	int	i;

	i = 5;
	while (i > 0)
	{
		i--;
		printf("%d", (n >> i) & 1);
	}
}

void	print_stacks(t_ilist *stack_a, t_ilist *stack_b)
{
	printf("------------------\n");
	while (stack_a != NULL && stack_b != NULL)
	{
		printf("%d\t| %d\n", stack_a->value, stack_b->value);
		print_binary(stack_a->value);
		printf("\t| ");
		print_binary(stack_b->value);
		printf("\n");
		stack_a = stack_a->next;
		stack_b = stack_b->next;
	}
	while (stack_a != NULL)
	{
		printf("%d\t| \n", stack_a->value);
		print_binary(stack_a->value);
		printf("\t| \n");
		stack_a = stack_a->next;
	}
	while (stack_b != NULL)
	{
		printf("\t| %d\n", stack_b->value);
		printf("\t| ");
		print_binary(stack_b->value);
		printf("\n");
		stack_b = stack_b->next;
	}
	printf("------------------\n");
}

void	print_pre_sort(t_ilist *stack_a, t_ilist *stack_b)
{
	printf("------------------\n");
	while (stack_a != NULL && stack_b != NULL)
	{
		printf("%d\t| %d\n", stack_a->minimized_value, stack_b->minimized_value);
		printf("* %d\t| * %d\n", stack_a->value, stack_b->value);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
	}
	while (stack_a != NULL)
	{
		printf("%d\t| \n", stack_a->minimized_value);
		printf("* %d\t| \n", stack_a->value);
		stack_a = stack_a->next;
	}
	while (stack_b != NULL)
	{
		printf("\t| %d\n", stack_b->minimized_value);
		printf("\t| * %d\n", stack_b->value);
		stack_b = stack_b->next;
	}
	printf("------------------\n");
}

//DONE? make atoi with max & min int guards, no spaces, empty string checks
// TODO: check thoroughly
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
		if (c < -2147483648 || c > 2147483647)
			return (false);
		i++;
	}
	*result_ptr = c * sign;
	return (str[i] == '\0');
}

t_error	push_swap(char **input, int len)
{
	int		i;
	int		result_ptr;
	t_ilist	*stack_a;
	t_ilist	*stack_b;
	bool	parsed_num;

	if (len == 0)
		return (OK);
	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (i < len)
	{
		parsed_num = ps_atoi(input[i], &result_ptr);
		if (!parsed_num)
		{
			ps_lstclear(&stack_a);
			return (set_error(E_PARSE));
		}
		if (ps_lstnew_back(&stack_a, result_ptr) == NULL)
		{
			ps_lstclear(&stack_a);
			return (set_error(E_MALLOC));
		}
		i++;
	}
	pre_sort(stack_a, len);
	radix_sort(&stack_a, &stack_b, len);

	//TODO: check for dupe values in list
	//TODO: make brute sort
	return (EXIT_SUCCESS);
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
