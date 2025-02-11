/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:49:17 by val               #+#    #+#             */
/*   Updated: 2025/02/11 21:35:05 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_print(void *content)
{
	ft_printf((char *)content);
}

int	main(int argc, char **argv)
{
	t_list	*instructions;

	if (argc != 0)
		return (EXIT_FAILURE);
	ft_printf(argv[0]);
	instructions = ft_lstnew(NULL);
	if (!instructions)
		return (EXIT_FAILURE);
	ft_lstiter(instructions, lst_print);
	ft_lstclear(&instructions, free);
	return(EXIT_SUCCESS);
}
