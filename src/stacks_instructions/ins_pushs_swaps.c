/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs_swaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:37:26 by val               #+#    #+#             */
/*   Updated: 2025/02/12 00:14:17 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_data *data)
{
	int	*temp;
	
	add_instruction(data, PUSH_A);
	temp = stack_pop(&data->stack_b);
	if (!temp)
		return (0);
	stack_push(&data->stack_a, *temp);
}

int	push_b(t_data *data)
{
	int	*temp;
	
	add_instruction(data, PUSH_B);
	temp = stack_pop(&data->stack_a);
	if (!temp)
		return (0);
	stack_push(&data->stack_b, *temp);
}

int	swap_a(t_data *data)
{
	add_instruction(data, SWAP_A);
	stack_swap(&data->stack_a);
}

int	swap_b(t_data *data)
{
	add_instruction(data, SWAP_B);
	stack_swap(&data->stack_b);
}

int	swap_ab(t_data *data)
{
	add_instruction(data, SWAP_AB);
	stack_swap(&data->stack_a);
	stack_swap(&data->stack_b);
}
