/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:49:17 by val               #+#    #+#             */
/*   Updated: 2025/02/12 01:01:34 by val              ###   ########.fr       */
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

static t_data	*init_data(int capacity)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->write_mode = FALSE;
	data->instructions = ft_lstnew(NULL);
	if (data->instructions)
		return (free_data(data), NULL);
	if (stack_init(&data->stack_a, capacity))
		return (free_data(data), NULL);
	if (stack_init(&data->stack_b, capacity))
		return (free_data(data), NULL);
	return (data);
}

int	parse_argv(t_data *data, char **argv, size_t argc)
{
	int		check;
	int		number;
	size_t	index;

	index = argc - 1;
	while (index > 0)
	{
		check_atoi(&check, &number, argv[index]);
		if (!check)
			return (0);
		stack_push(&data->stack_a, number);
		index--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc > 1)
		return (EXIT_FAILURE);
	data = init_data(argc - 1);
	if (!data)
		return (EXIT_FAILURE);
	if (!parse_argv(data, argv, argc))
		return (free_data(data), EXIT_FAILURE);
	free_data(data);
	return (EXIT_SUCCESS);
}
