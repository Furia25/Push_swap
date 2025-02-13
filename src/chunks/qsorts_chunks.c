/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsorts_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:22:11 by val               #+#    #+#             */
/*   Updated: 2025/02/14 00:31:53 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_split(t_chunk *chunk, t_qchunks *qchunks, t_data *data)
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
	while (chunk->size--)
	{
		next_value = chunk_get(chunk, 1, data);
		if (next_value > max_value - pivot2)
			qchunks->max.size += 1;
		else if (next_value > max_value - pivot1)
			qchunks->mid.size += 1;
		else
			qchunks->min.size += 1;
	}
}

void	qsort_pivots(t_pos pos, int crt_size, int *pivot_1, int *pivot_2)
{
	*pivot_2 = crt_size / 3;
	if (pos == TOP_A || pos == BOT_A)
		*pivot_1 = 2 * crt_size / 3;
	if (pos == TOP_B || pos == BOT_B)
		*pivot_1 = crt_size / 2;
	if ((pos == TOP_A || pos == BOT_A) && crt_size < 15)
		*pivot_1 = crt_size;
	if (pos == BOT_B && crt_size < 8)
		*pivot_2 = crt_size / 2;
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
