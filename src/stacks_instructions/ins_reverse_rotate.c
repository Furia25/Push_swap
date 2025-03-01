/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:18:26 by val               #+#    #+#             */
/*   Updated: 2025/02/12 01:02:08 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrotate_a(t_data *data)
{
	add_instruction(data, RROTATE_A);
	stack_rrotate(&data->stack_a);
	return (1);
}

int	rrotate_b(t_data *data)
{
	add_instruction(data, RROTATE_B);
	stack_rrotate(&data->stack_b);
	return (1);
}

int	rrotate_ab(t_data *data)
{
	add_instruction(data, RROTATE_AB);
	stack_rrotate(&data->stack_a);
	stack_rrotate(&data->stack_b);
	return (1);
}
