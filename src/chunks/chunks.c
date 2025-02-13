/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:51:23 by vdurand           #+#    #+#             */
/*   Updated: 2025/02/14 00:28:14 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_get(t_chunk *chunk, int n, t_data *data)
{
	t_stack	*stack;
	int		index;
	int		direction;
	
	if (n > chunk->size && chunk->size > 1)
		return (chunk_get(chunk, n - chunk->size, data));
	direction = position_is_top(chunk->position);
	stack = position_to_stack(data, chunk->position);
	if (direction)
		index = stack->top;
	else
		index = stack->bottom;
	if (direction)
		while (--n > 0)
			index--;
	else
		while (--n > 0)
			index++;
	return (stack->array[index]);
}

int	chunk_get_max(t_chunk *chunk, t_data *data)
{
	t_stack	*stack;
	int		max;
	int		index;

	stack = position_to_stack(data, chunk->position);
	if (position_is_top(chunk->position))
		index = stack->top;
	else
		index = stack->bottom;
	max = stack->array[index];
	while (chunk->size > 0)
	{
		if (max < stack->array[index])
			max = stack->array[index];
		if (position_is_top(chunk->position))
			index--;
		else
			index++;
		chunk->size--;
	}
	return (max);
}
