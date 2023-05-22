/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 12:26:02 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/22 12:42:51 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_error	*get_error_ptr(void)
{
	static t_error	err_ptr = OK;

	return (&err_ptr);
}

t_error	set_error(t_error err)
{
	t_error	*err_ptr;

	err_ptr = get_error_ptr();
	*err_ptr = err;
	return (*err_ptr);
}

t_error	get_error(void)
{
	t_error	*err_ptr;

	err_ptr = get_error_ptr();
	return (*err_ptr);
}

void	print_error(t_error err)
{
	static const char	*error_table[] = {
	[E_PARSE] = "Failed to parse integer.",
	[E_DUPE] = "No duplicates allowed.",
	[E_MALLOC] = "Failed to allocate memory."

	};

	ft_putstr_fd("push_swap: ", STDERR_FILENO);
	ft_putendl_fd((char *)error_table[err], STDERR_FILENO);
}
