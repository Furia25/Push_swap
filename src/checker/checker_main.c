/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:53:12 by val               #+#    #+#             */
/*   Updated: 2025/02/15 16:54:21 by vdurand          ###   ########.fr       */
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
			break ;
		if (!instruction_do(heredoc, data))
			return (free(heredoc), 0);
		free(heredoc);
	}
	return (stack_is_sorted(&data->stack_a));
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		result;
	
	if (argc < 2)
		return (print_error(), EXIT_FAILURE);
	data = init_data(argc - 1);
	if (!data)
		return (free_data(data), print_error(), EXIT_FAILURE);
	if (!parse_argv(data, argv, argc))
		return (free_data(data), print_error(), EXIT_FAILURE);
	ft_printf("test\n");
	result = read_stdin_and_perform(data);
	if (result == -1)
		return (ft_printf("test\n"), print_error(), free_data(data), EXIT_FAILURE);
	if (result == 0)
		return (ft_printf("KO\n"), free_data(data), EXIT_FAILURE);
	ft_printf("OK\n");
	free_data(data);
	return (EXIT_SUCCESS);
}
