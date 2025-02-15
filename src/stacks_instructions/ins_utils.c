/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:25:30 by val               #+#    #+#             */
/*   Updated: 2025/02/15 16:48:58 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checks(char *instru, t_data *data)
{
	if (cmpstr(instru, PUSH_A))
		return (push_a(data));
	if (cmpstr(instru, PUSH_B))
		return (push_b(data));
	if (cmpstr(instru, SWAP_A))
		return (swap_a(data));
	if (cmpstr(instru, SWAP_B))
		return (swap_b(data));
	if (cmpstr(instru, SWAP_AB))
		return (swap_ab(data));
	if (cmpstr(instru, ROTATE_A))
		return (rotate_a(data));
	if (cmpstr(instru, ROTATE_B))
		return (rotate_b(data));
	if (cmpstr(instru, ROTATE_AB))
		return (rotate_ab(data));
	if (cmpstr(instru, RROTATE_A))
		return (rrotate_a(data));
	if (cmpstr(instru, RROTATE_B))
		return (rrotate_b(data));
	if (cmpstr(instru, RROTATE_AB))
		return (rrotate_ab(data));
	return (0);
}

int	instruction_do(char *instru, t_data *data)
{
	int	size;
	int	result;

	if (!instru)
		return (0);
	size = ft_strlen(instru);
	if (size < 3)
		return (0);
	if (instru[size - 1] == '\n')
		instru[size - 1] = '\0';
	result = checks(instru, data);
	return (result);
}
