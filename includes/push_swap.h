/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:01:51 by val               #+#    #+#             */
/*   Updated: 2025/02/12 00:33:15 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include "stack.h"
# include <stdlib.h>
# include <stddef.h>

# define PUSH_A		"pa"
# define PUSH_B		"pb"
//
# define SWAP_A		"sa"
# define SWAP_B		"sb"
# define SWAP_AB	"ss"
//
# define ROTATE_A	"ra"
# define ROTATE_B	"rb"
# define ROTATE_AB	"rr"
//
# define RROTATE_A	"rra"
# define RROTATE_B	"rrb"
# define RROTATE_AB	"rrr"

typedef struct s_data
{
	t_bool	write_mode;
	t_stack	stack_a;
	t_stack	stack_b;
	t_list	*instructions;
}		t_data;

/*Utils - utils.c*/

int		add_instruction(t_data *data, char *instruction);
void	free_data(t_data *data);
/*************** */

/*Stacks Instructions - ins_pushs_swaps.c*/

int		push_a(t_data *data);
int		push_b(t_data *data);
int		swap_a(t_data *data);
int		swap_b(t_data *data);
int		swap_ab(t_data *data);
/*****************************************/

/*Stacks Instructions - ins_reverse_rotate.c*/

int		rrotate_a(t_data *data);
int		rrotate_b(t_data *data);
int		rrotate_ab(t_data *data);
/********************************************/

/*Stacks Instructions - ins_rotate.c*/

int		rotate_a(t_data *data);
int		rotate_b(t_data *data);
int		rotate_ab(t_data *data);
/************************************/

#endif
