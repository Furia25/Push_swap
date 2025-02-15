/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:49:17 by val               #+#    #+#             */
/*   Updated: 2025/02/15 16:44:32 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	instructions_clean(&data->instructions);
	ft_lstiter(data->instructions->next, lst_print);
	free_data(data);
	return (EXIT_SUCCESS);
}
