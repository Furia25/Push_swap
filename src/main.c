/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:49:17 by val               #+#    #+#             */
/*   Updated: 2025/02/14 16:58:42 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->stack_a.array)
		free(data->stack_a.array);
	if (data->stack_b.array)
		free(data->stack_b.array);
	if (data->instructions)
		ft_lstclear(&data->instructions, NULL);
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
	int		*temp;
	int		index;
	int		j;

	temp = malloc(stack->size * sizeof(int));
	if (!temp)
		return (0);
	ft_memcpy((void *)temp, (void *)stack->array, stack->size * sizeof(int));
	ft_quicksort(temp, 0, stack->top);
	index = 0;
	while (index <= stack->top)
	{
		j = 0;
		while (j <= stack->top && stack->array[index] != temp[j])
			j++;
		if (j <= stack->top)
			stack->array[index] = j + 1;
		index++;
	}
	free(temp);
	return (1);
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
		if (!check || ft_strlen(argv[index]) <= 0 || \
			(argv[index][0] == '-' && !ft_isdigit(argv[index][1])))
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
	data->write_mode = TRUE;
	if (stack_is_sorted(&data->stack_a))
		return (free_data(data), EXIT_SUCCESS);
	if (!sort(data))
		return (free_data(data), print_error(), EXIT_FAILURE);
	//stack_print(&data->stack_a);
	ft_lstiter(data->instructions->next, lst_print);
	free_data(data);
	return (EXIT_SUCCESS);
}
