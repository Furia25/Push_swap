/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:27:50 by val               #+#    #+#             */
/*   Updated: 2025/02/11 23:06:57 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_new(int capacity)
{
	t_stack	*result;

	result = ft_calloc(1, sizeof(t_stack));
	if (!result)
		return (NULL);
	if (!init_stack(result, capacity))
	{
		free(result);
		return(NULL);
	}
	return (result);
}

int	stack_init(t_stack *stack, int capacity)
{
	stack->array = ft_calloc(capacity, sizeof(int));
	if (stack->array)
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