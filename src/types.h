/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   types.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 12:29:41 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/05/23 12:29:48 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_ilist
{
	int				value;
	unsigned int	minimized_value;
	struct s_ilist	*next;
}					t_ilist;

typedef enum e_error
{
	OK,
	E_PARSE,
	E_DUPE,
	E_MALLOC,
}	t_error;

#endif
