/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:16:17 by val               #+#    #+#             */
/*   Updated: 2025/02/12 18:30:46 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->stack_a.array[2];
	b = data->stack_a.array[1];
	c = data->stack_a.array[0];
	if (a > b && b < c && a < c)
		swap_a(data);
	else if (a > b && b > c)
	{
		swap_a(data);
		rrotate_a(data);
	}
	else if (a > b && b < c && a > c)
		rotate_a(data);
	else if (a < b && b > c && a < c)
	{
		swap_a(data);
		rotate_a(data);
	}
	else if (a < b && b > c && a > c)
		rrotate_a(data);
}

void	sort_fourfive_a(t_data *data)
{
	while (data->stack_a.top > 2)
	{
		if (((data->stack_a.array[data->stack_a.top] == 1 || \
			data->stack_a.array[data->stack_a.top] == 2) \
			&& data->stack_a.size != 4) || \
			data->stack_a.array[data->stack_a.top] == 1)
			push_b(data);
		else
			rotate_a(data);
	}
	sort_three_a(data);
	if (data->stack_b.top == 1 && \
		data->stack_b.array[0] > data->stack_b.array[1])
		swap_b(data);
	push_a(data);
	push_a(data);
}
