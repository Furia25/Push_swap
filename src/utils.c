/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:04:42 by val               #+#    #+#             */
/*   Updated: 2025/02/15 01:19:33 by val              ###   ########.fr       */
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
	int					sign;
	size_t				size;
	long long			result;

	*check = 1;
	sign = 1;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	size = ft_strlen(nptr);
	if (size == 0 || (*nptr == '0' && size > 1))
		*check = 0;
	result = 0;
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			*check = 0;
		result = result * 10 + (*nptr++ - '0');
	}
	if (result * sign > (long long) INT_MAX || \
		result * sign < (long long) INT_MIN)
		*check = 0;
	*number = result * sign;
}

void	print_error(void)
{
	ft_putstr_fd(ERROR_MESSAGE, 2);
}

void	lst_print(void *content)
{
	ft_printf("%s\n", (char *)content);
}
