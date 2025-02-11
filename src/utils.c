/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:04:42 by val               #+#    #+#             */
/*   Updated: 2025/02/12 00:15:57 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_instruction(t_data *data, char *instruction)
{
	t_list	*temp;

	if (!data->write_mode)
		return (1);
	temp = ft_lstnew(instruction);
	if (!temp)
	{
		free_data(data);
		exit(EXIT_FAILURE);
	}
	ft_lstadd_back(&data->instructions, temp);
	return (1);
}
