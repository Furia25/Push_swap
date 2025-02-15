/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:15:44 by val               #+#    #+#             */
/*   Updated: 2025/02/15 01:18:54 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_top_a(t_pos dest, t_data *data)
{
	if (dest == TOP_B)
		push_b(data);
	else if (dest == BOT_A)
		rotate_a(data);
	else if (dest == BOT_B)
	{
		push_b(data);
		rotate_b(data);
	}
}

static void	move_top_b(t_pos dest, t_data *data)
{
	if (dest == TOP_A)
		push_a(data);
	else if (dest == BOT_B)
		rotate_b(data);
	else if (dest == BOT_A)
	{
		push_a(data);
		rotate_a(data);
	}
}

static void	move_bottom_a(t_pos dest, t_data *data)
{
	if (dest == TOP_A)
		rrotate_a(data);
	else if (dest == TOP_B)
	{
		rrotate_a(data);
		push_b(data);
	}
	else if (dest == BOT_B)
	{
		rrotate_a(data);
		push_b(data);
		rotate_b(data);
	}
}

static void	move_bottom_b(t_pos dest, t_data *data)
{
	if (dest == TOP_B)
		rrotate_b(data);
	else if (dest == TOP_A)
	{
		rrotate_b(data);
		push_a(data);
	}
	else if (dest == BOT_A)
	{
		rrotate_b(data);
		push_a(data);
		rotate_a(data);
	}
}

int	move_from_position(t_pos from, t_pos dest, t_data *data)
{
	if (from == TOP_A)
		move_top_a(dest, data);
	else if (from == TOP_B)
		move_top_b(dest, data);
	else if (from == BOT_A)
		move_bottom_a(dest, data);
	else if (from == BOT_B)
		move_bottom_b(dest, data);
	return (1);
}
