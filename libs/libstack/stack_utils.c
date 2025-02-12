/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:27:50 by val               #+#    #+#             */
/*   Updated: 2025/02/12 02:17:27 by val              ###   ########.fr       */
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
	ft_putchar_fd('\n', 1);
	while (index >= 0)
	{
		ft_printf("|%d|\n", stack->array[index]);
		index--;
	}
}
