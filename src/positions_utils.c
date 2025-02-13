/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 23:46:46 by val               #+#    #+#             */
/*   Updated: 2025/02/14 00:05:23 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_is_a(t_pos pos)
{
	return (pos == TOP_A || pos == BOT_A);
}

int	position_is_top(t_pos pos)
{
	return (pos == TOP_A || pos == TOP_B);
}

t_stack	*position_to_stack(t_data *data, t_pos pos)
{
	if (position_is_a(pos))
		return (&data->stack_a);
	else
		return (&data->stack_b);
}
