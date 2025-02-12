/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:04:42 by val               #+#    #+#             */
/*   Updated: 2025/02/12 01:26:12 by val              ###   ########.fr       */
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

void	check_atoi(int *check, int *number, const char *nptr)
{
	int					index;
	int					numbers_count;
	int					sign;
	long long			result;

	index = 0;
	numbers_count = 0;
	result = 0;
	sign = 1;
	*check = 1;
	if (nptr[index] == '-')
		sign *= -1;
	index++;
	while (nptr[index] && nptr[index] >= '0' && nptr[index] <= '9')
	{
		result = result * 10 + (nptr[index] - '0');
		numbers_count++;
		index++;
	}
	if (result > (long long) INT_MAX || result * sign < (long long) INT_MIN)
		*check = 0;
	if (numbers_count == 0)
		*check = 0;
	*number = result * sign;
}

void	print_error(void)
{
	ft_putstr_fd(ERROR_MESSAGE, 2);
}
