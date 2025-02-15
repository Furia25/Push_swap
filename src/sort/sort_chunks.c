/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:39:40 by vdurand           #+#    #+#             */
/*   Updated: 2025/02/15 01:18:31 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_data *data, t_chunk *to_sort)
{
	if (to_sort->position == BOT_A || to_sort->position == BOT_B
		|| to_sort->position == TOP_B)
	{
		move_from_position(to_sort->position, TOP_A, data);
		move_from_position(to_sort->position, TOP_A, data);
	}
	if (data->stack_a.array[data->stack_a.top] > \
			data->stack_a.array[data->stack_a.top - 1])
		swap_a(data);
	to_sort->size -= 2;
}

void	sort_one(t_data *data, t_chunk *to_sort)
{
	if (to_sort->position == BOT_A || to_sort->position == BOT_B
		|| to_sort->position == TOP_B)
		move_from_position(to_sort->position, TOP_A, data);
	to_sort->size -= 1;
}

void	sort_chunk_rec(t_chunk *chunk, t_data *data)
{
	t_qchunks	splitted;

	if (chunk->position == BOT_B && (data->stack_b.top + 1) == chunk->size)
		chunk->position = TOP_B;
	if (chunk->position == BOT_A && (data->stack_a.top + 1) == chunk->size)
		chunk->position = TOP_A;
	if (chunk->size <= 2)
	{
		if (chunk->size == 1)
			sort_one(data, chunk);
		if (chunk->size == 2)
			sort_two(data, chunk);
		return ;
	}
	qchunk_from_split(chunk, &splitted, data);
	sort_chunk_rec(&splitted.max, data);
	sort_chunk_rec(&splitted.mid, data);
	sort_chunk_rec(&splitted.min, data);
}

void	sort_chunk_init(t_data *data)
{
	t_chunk	base_chunk;

	base_chunk.position = TOP_A;
	base_chunk.size = data->stack_a.size;
	sort_chunk_rec(&base_chunk, data);
}
