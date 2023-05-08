/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 14:46:51 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/08 17:11:14 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_print(t_list *list)
{
	while (list != NULL)
	{
		printf("%s\n", list->content);
		list = list->next;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*new_val;

	stack_a = NULL;
	stack_b = NULL;
	// if (argc == 0)
	// 	return (error);
	// //TODO: parse to int
	i = 1;
	while (i < argc)
	{
		printf("adding: %s\n", argv[i]);
		new_val = ft_lstnew(argv[i]);
		if (new_val == NULL)
		{
			ft_lstclear(&stack_a, NULL);
			return (0);
		}
		ft_lstadd_back(&stack_a, new_val);
		i++;
	}

	//functions for all operations DONE
	list_print(stack_a);
	// printf("argc: %i\n", argc);
}
