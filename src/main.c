/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:49:17 by val               #+#    #+#             */
/*   Updated: 2025/02/12 02:30:31 by val              ###   ########.fr       */
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
	data->write_mode = TRUE;
	data->instructions = ft_lstnew(NULL);
	if (!data->instructions)
		return (NULL);
	if (!stack_init(&data->stack_a, capacity))
		return (NULL);
	if (!stack_init(&data->stack_b, capacity))
		return (NULL);
	return (data);
}

int	simplify_stack(t_stack *stack)
{
	
}

int	parse_argv(t_data *data, char **argv, size_t argc)
{
	int		check;
	int		number;
	size_t	index;
	int		j;

	index = argc - 1;
	while (index > 0)
	{
		check_atoi(&check, &number, argv[index]);
		if (!check)
			return (0);
		stack_push(&data->stack_a, number);
		j = data->stack_a.top - 1;
		while (j >= 0)
		{
			if (data->stack_a.array[j] == number)
				return (0);
			j--;
		}
		index--;
	}
	if (!simplify_stack(&data->stack_a))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (print_error(), EXIT_FAILURE);
	data = init_data(argc - 1);
	if (!data)
		return (free_data(data), print_error(), EXIT_FAILURE);
	if (!parse_argv(data, argv, argc))
		return (free_data(data), print_error(), EXIT_FAILURE);
	stack_print(&data->stack_a);
	free_data(data);
	return (EXIT_SUCCESS);
}
