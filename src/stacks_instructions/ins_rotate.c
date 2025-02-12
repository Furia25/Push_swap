/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:18:26 by val               #+#    #+#             */
/*   Updated: 2025/02/12 01:02:03 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(t_data *data)
{
	add_instruction(data, ROTATE_A);
	stack_rotate(&data->stack_a);
	return (1);
}

int	rotate_b(t_data *data)
{
	add_instruction(data, ROTATE_B);
	stack_rotate(&data->stack_b);
	return (1);
}

int	rotate_ab(t_data *data)
{
	add_instruction(data, ROTATE_AB);
	stack_rotate(&data->stack_a);
	stack_rotate(&data->stack_b);
	return (1);
}
