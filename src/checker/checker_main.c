/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:53:12 by val               #+#    #+#             */
/*   Updated: 2025/02/22 15:25:57 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "unistd.h"

static int	read_stdin_and_perform(t_data *data)
{
	char	*heredoc;

	heredoc = get_next_line(STDIN_FILENO);
	while (heredoc)
	{
		if (!instruction_do(heredoc, data))
			return (free(heredoc), -1);
		free(heredoc);
		heredoc = get_next_line(STDIN_FILENO);
	}
	return (stack_is_sorted(&data->stack_a) && data->stack_b.top == -1);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		result;

	if (argc < 2)
		return (EXIT_SUCCESS);
	data = init_data(argc - 1);
	if (!data)
		return (print_error(), EXIT_FAILURE);
	if (!parse_argv(data, argv, argc))
		return (free_data(data), print_error(), EXIT_FAILURE);
	result = read_stdin_and_perform(data);
	if (result == -1)
		return (print_error(), free_data(data), EXIT_FAILURE);
	if (result == 0)
		return (ft_printf("KO\n"), free_data(data), EXIT_FAILURE);
	ft_printf("OK\n");
	free_data(data);
	return (EXIT_SUCCESS);
}
