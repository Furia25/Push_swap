/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:39:40 by vdurand           #+#    #+#             */
/*   Updated: 2025/02/13 23:41:18 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_chunk_init(t_data *data)
{
	t_chunk	base_chunk;

	base_chunk.position = TOP_A;
	base_chunk.size = data->stack_a.size;
	sort_chunk_rec(base_chunk, data);
}

void	sort_chunk_rec(t_chunk chunk, t_data *data)
{
	t_qchunks	splitted;

	if (chunk.size <= 3)
	{
		//sort
		return ;
	}
	chunk_split(&splitted, data);
	sort_chunk_rec(splitted.max, data);
	sort_chunk_rec(splitted.mid, data);
	sort_chunk_rec(splitted.min, data);
}
