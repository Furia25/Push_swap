/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:15:27 by val               #+#    #+#             */
/*   Updated: 2025/02/12 00:32:12 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "libft.h"
# include <stdlib.h>
# include <stddef.h>

typedef struct s_stack
{
	int	*array;
	int	size;
	int	top;
	int	bottom;
}		t_stack;

	/*stack_init.c*/
t_stack		*stack_new(int capacity);
int			stack_init(t_stack *stack, int capacity);
void		stack_free(t_stack *stack);
	/*stack_methods.c*/
int			stack_push(t_stack *stack, int value);
int			stack_swap(t_stack *stack);
int			stack_rotate(t_stack *stack);
int			stack_rrotate(t_stack *stack);
int			*stack_pop(t_stack *stack);
	/**/
#endif