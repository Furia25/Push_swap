/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:15:27 by val               #+#    #+#             */
/*   Updated: 2025/02/11 19:23:29 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "libft.h"

typedef struct s_stack
{
	int	*array;
	int	size;
	int	top;
	int	bottom;
}		t_stack;

#endif