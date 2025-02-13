/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:27:50 by val               #+#    #+#             */
/*   Updated: 2025/02/13 17:34:06 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_new(size_t capacity)
{
	t_stack	*result;

	result = ft_calloc(1, sizeof(t_stack));
	if (!result)
		return (NULL);
	if (!stack_init(result, capacity))
	{
		free(result);
		return(NULL);
	}
	return (result);
}

int	stack_init(t_stack *stack, size_t capacity)
{
	stack->array = ft_calloc(capacity, sizeof(int));
	if (!stack->array)
		return (0);
	stack->bottom = 0;
	stack->top = -1;
	stack->size = capacity;
	return (1);
}

void	stack_free(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->array)
		free(stack->array);
	free(stack);
}

void	stack_print(t_stack *stack)
{
	int	index;

	index = stack->top;
	while (index >= 0)
	{
		ft_printf("|%d|\n", stack->array[index]);
		index--;
	}
}

int	stack_is_sorted(t_stack *stack)
{
	int	index;

	if (stack->top <= 0)
		return (1);
	index = stack->top;
	while (index > 0)
	{
		if (stack->array[index] > stack->array[index - 1])
			return (0);
		index--;
	}
	return (1);
}
