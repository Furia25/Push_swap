/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:49:17 by val               #+#    #+#             */
/*   Updated: 2025/02/11 22:56:21 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_print(void *content)
{
	ft_printf((char *)content);
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->stack_a.array)
		free(data->stack_a.array);
	if (data->stack_b.array)
		free(data->stack_b.array);
	if (data->instructions)
		ft_lstclear(&data->instructions, free);
	free(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc > 1)
		return (EXIT_FAILURE);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	data->instructions = ft_lstnew(NULL);
	if (data->instructions)
		return (free_data(data), EXIT_FAILURE);
	if (stack_init(&data->stack_a, argc - 1))
		return (free_data(data), EXIT_FAILURE);
	if (stack_init(&data->stack_b, argc - 1))
		return (free_data(data), EXIT_FAILURE);
	free_data(data);
	return(EXIT_SUCCESS);
}
