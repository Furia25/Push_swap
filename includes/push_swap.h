/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:01:51 by val               #+#    #+#             */
/*   Updated: 2025/02/11 19:50:48 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include "unistd.h"
# include <stdlib.h>
# include "stack.h"

typedef struct s_data
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_list	instructions;
}		t_data;

#endif
