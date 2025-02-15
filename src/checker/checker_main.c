/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:53:12 by val               #+#    #+#             */
/*   Updated: 2025/02/15 13:41:51 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "unistd.h"

static int	read_stdin_and_perform(t_data *data)
{
	char	*heredoc;

	while (1)
	{
		heredoc = get_next_line(STDIN_FILENO);
		if (!heredoc)
			return (0);
		if (!instruction_do(heredoc, data))
			return (free(heredoc), 0);
		free(heredoc);
	}
	free(heredoc);
	return (stack_is_sorted(&data->stack_a));
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
	if (stack_is_sorted(&data->stack_a))
		return (ft_printf("OK\n"), free_data(data), EXIT_SUCCESS);
	if (!read_stdin_and_perform(data))
		return (ft_printf("KO LOL\n"), free_data(data), EXIT_FAILURE);
	ft_printf("OK\n");
	free_data(data);
	return (EXIT_SUCCESS);
}
