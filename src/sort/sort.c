/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:47:03 by val               #+#    #+#             */
/*   Updated: 2025/02/14 15:18:53 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_data *data)
{
	data->write_mode = TRUE;
	if (data->stack_a.top == 2)
		return (sort_three_a(data), 1);
	if (data->stack_a.top == 1)
		if (data->stack_a.array[0] < data->stack_a.array[1])
			return (swap_a(data), 1);
	if (data->stack_a.top == 3 || data->stack_a.top == 4)
		return (sort_fourfive_a(data), 1);
	else
		return (sort_chunk_init(data), 1);
	return (1);
}
