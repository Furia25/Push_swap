/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_easy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:16:17 by val               #+#    #+#             */
/*   Updated: 2025/02/26 18:08:35 by vdurand          ###   ########.fr       */
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
static int	find_value(t_data *data, int value);

void	sort_small(t_data *data)
{
	int	min;
	int	value_index;

	min = 1;
	while (data->stack_a.top > 2 || data->stack_a.size == 4)
	{
		value_index = find_value(data, min);
		if (value_index == -1)
			break ;
		while (data->stack_a.array[data->stack_a.top] != min)
		{
			if (value_index > data->stack_a.top / 2)
				rotate_a(data);
			else
				rrotate_a(data);
		}
		push_b(data);
		min++;
	}
	sort_three_a(data);
	while (data->stack_b.top >= 0)
		push_a(data);
}

static int	find_value(t_data *data, int value)
{
	size_t	index;

	index = 0;
	while (index < data->stack_a.size)
	{
		if (data->stack_a.array[index] == value)
		{
			return (index);
		}
		index++;
	}
	return (-1);
}
