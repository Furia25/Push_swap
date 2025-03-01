/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:01:51 by val               #+#    #+#             */
/*   Updated: 2025/02/24 17:10:55 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include "stack.h"
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

# define ERROR_MESSAGE "Error\n"
//
# define PUSH_A			"pa"
# define PUSH_B			"pb"
//
# define SWAP_A			"sa"
# define SWAP_B			"sb"
# define SWAP_AB		"ss"
//
# define ROTATE_A		"ra"
# define ROTATE_B		"rb"
# define ROTATE_AB		"rr"
//
# define RROTATE_A		"rra"
# define RROTATE_B		"rrb"
# define RROTATE_AB		"rrr"
# define CLEAN_CONST	"DESTROY"

typedef enum e_pos
{
	TOP_A,
	BOT_A,
	TOP_B,
	BOT_B
}		t_pos;

typedef struct s_data
{
	t_bool	write_mode;
	t_stack	stack_a;
	t_stack	stack_b;
	t_list	*instructions;
}		t_data;

typedef struct s_chunk
{
	t_pos	position;
	int		size;
}		t_chunk;

typedef struct s_qchunks
{
	t_chunk	max;
	t_chunk	mid;
	t_chunk	min;
}		t_qchunks;

/*Utils - main_utils.c*/

int		parse_argv(t_data *data, char **argv, size_t argc);
t_data	*init_data(int capacity);
void	free_data(t_data *data);
/*********************/

/*Utils - utils.c*/

int		add_instruction(t_data *data, char *instruction);
void	check_atoi(int *check, int *number, const char *nptr);
void	print_error(void);
void	lst_print(void *content);
/*************** */

int		instruction_do(char *instru, t_data *data);
/*Stacks Instructions - ins_clean.c*/

int		cmpstr(char *s1, char *s2);
void	instructions_clean(t_list **instructions);
/***********************************/

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

/*Sort - sort.c*/

int		sort(t_data *data);
void	sort_three_a(t_data *data);
void	sort_fourfive_a(t_data *data);
void	sort_small(t_data *data);
/***************/

void	sort_chunk_init(t_data *data);
void	sort_chunk_rec(t_chunk *chunk, t_data *data);

int		position_is_a(t_pos pos);
int		position_is_top(t_pos pos);
t_stack	*position_to_stack(t_data *data, t_pos pos);

int		chunk_get(t_chunk *chunk, int n, t_data *data);
int		chunk_get_max(t_chunk *chunk, t_data *data);
void	qchunk_from_split(t_chunk *chunk, t_qchunks *qchunks, t_data *data);

int		move_from_position(t_pos from, t_pos dest, t_data *data);

#endif
