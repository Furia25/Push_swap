/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsorts_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:22:11 by val               #+#    #+#             */
/*   Updated: 2025/02/15 01:20:04 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	qsort_pivots(t_pos pos, int size, int *pivot_1, int *pivot_2)
{
	*pivot_2 = size / 3;
	if (pos == TOP_A || pos == BOT_A)
		*pivot_1 = 2 * size / 3;
	if (pos == TOP_B || pos == BOT_B)
		*pivot_1 = size / 2;
	if ((pos == TOP_A || pos == BOT_A) && size < 15)
		*pivot_1 = size;
	if (pos == BOT_B && size < 8)
		*pivot_2 = size / 2;
}

void	qchunks_set_positions(t_pos pos, t_qchunks *qchunks)
{
	if (pos == TOP_A)
	{
		qchunks->max.position = BOT_A;
		qchunks->mid.position = TOP_B;
		qchunks->min.position = BOT_B;
	}
	else if (pos == BOT_A)
	{
		qchunks->max.position = TOP_A;
		qchunks->mid.position = TOP_B;
		qchunks->min.position = BOT_B;
	}
	else if (pos == TOP_B)
	{
		qchunks->max.position = TOP_A;
		qchunks->mid.position = BOT_A;
		qchunks->min.position = BOT_B;
	}
	else if (pos == BOT_B)
	{
		qchunks->max.position = TOP_A;
		qchunks->mid.position = BOT_A;
		qchunks->min.position = TOP_B;
	}
}

void	qchunk_from_split(t_chunk *chunk, t_qchunks *qchunks, t_data *data)
{
	int	pivot1;
	int	pivot2;
	int	max_value;
	int	next_value;

	qchunks->min.size = 0;
	qchunks->mid.size = 0;
	qchunks->max.size = 0;
	qchunks_set_positions(chunk->position, qchunks);
	qsort_pivots(chunk->position, chunk->size, &pivot1, &pivot2);
	max_value = chunk_get_max(chunk, data);
	while (chunk->size-- > 0)
	{
		next_value = chunk_get(chunk, 1, data);
		if (next_value > max_value - pivot2)
			qchunks->max.size += move_from_position(\
				chunk->position, qchunks->max.position, data);
		else if (next_value > max_value - pivot1)
			qchunks->mid.size += move_from_position(\
				chunk->position, qchunks->mid.position, data);
		else
			qchunks->min.size += move_from_position(\
				chunk->position, qchunks->min.position, data);
	}
}
