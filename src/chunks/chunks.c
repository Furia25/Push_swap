/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:51:23 by vdurand           #+#    #+#             */
/*   Updated: 2025/02/13 17:30:57 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_split(t_chunk *chunk, t_qchunks *qchunks, t_data *s_data)
{
	int	pivot1;
	int	pivot2;

	qchunks->min.size = 0;
	qchunks->mid.size = 0;
	qchunks->max.size = 0;
	qchunks_set_positions(chunk->POSITION, qchunks);
	
}

void	set_third_pivots(t_pos pos, int crt_size, int *pivot_1, int *pivot_2)
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
		qchunks->max.POSITION = BOT_A;
		qchunks->mid.POSITION = TOP_B;
		qchunks->min.POSITION = BOT_B;
	}
	else if (pos == BOT_A)
	{
		qchunks->max.POSITION = TOP_A;
		qchunks->mid.POSITION = TOP_B;
		qchunks->min.POSITION = BOT_B;
	}
	else if (pos == TOP_B)
	{
		qchunks->max.POSITION = TOP_A;
		qchunks->mid.POSITION = BOT_A;
		qchunks->min.POSITION = BOT_B;
	}
	else if (pos == BOT_B)
	{
		qchunks->max.POSITION = TOP_A;
		qchunks->mid.POSITION = BOT_A;
		qchunks->min.POSITION = TOP_B;
	}
}

int	chunk_get_max(t_chunk *chunk)
{
	int	max;
	int	index;
	
	if (chunk->POSITION == TOP_A || chunk->POSITION == TOP_B)
		return ;
}
