/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:15:27 by val               #+#    #+#             */
/*   Updated: 2025/02/20 12:48:16 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <stddef.h>

typedef struct s_stack
{
	int		*array;
	size_t	size;
	int		top;
	int		bottom;
}		t_stack;

	/*stack_utils.c*/
t_stack		*stack_new(size_t capacity);
int			stack_is_sorted(t_stack *stack);
int			stack_init(t_stack *stack, size_t capacity);
void		stack_free(t_stack *stack);
void		stack_print(t_stack *stack);

	/*stack_methods.c*/
int			stack_push(t_stack *stack, int value);
int			stack_swap(t_stack *stack);
int			stack_rotate(t_stack *stack);
int			stack_rrotate(t_stack *stack);
int			*stack_pop(t_stack *stack);
	/**/
#endif