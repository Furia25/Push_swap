/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:27:50 by val               #+#    #+#             */
/*   Updated: 2025/02/20 12:48:21 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_push(t_stack *stack, int value)
{
	if ((size_t) stack->top == stack->size - 1)
		return (0);
	stack->top++;
	stack->array[stack->top] = value;
	return (1);
}

int	stack_swap(t_stack *stack)
{
	int	temp;

	if (stack->top < 1)
		return (0);
	temp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = temp;
	return (1);
}

int	stack_rotate(t_stack *stack)
{
	int		temp;
	size_t	index;

	if (stack->top < 1)
		return (0);
	temp = stack->array[stack->top];
	index = stack->top;
	while (index > 0)
	{
		stack->array[index] = stack->array[index - 1];
		index--;
	}
	stack->array[0] = temp;
	return (1);
}

int	stack_rrotate(t_stack *stack)
{
	int		temp;
	size_t	index;

	if (stack->top < 1)
		return (0);
	temp = stack->array[0];
	index = 0;
	while (index < (size_t) stack->top)
	{
		stack->array[index] = stack->array[index + 1];
		index++;
	}
	stack->array[stack->top] = temp;
	return (1);
}

int	*stack_pop(t_stack *stack)
{
	int	*temp;

	if (stack->top < 0)
		return (NULL);
	temp = &stack->array[stack->top];
	stack->top--;
	return (temp);
}
