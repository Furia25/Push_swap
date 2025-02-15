/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:28:16 by val               #+#    #+#             */
/*   Updated: 2025/02/15 03:16:35 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cstr(char *s1, char *s2)
{
	return (ft_strcmp(s1, s2) == 0);
}

static void next_lsts(t_list **super_last, t_list **last, t_list **current)
{
	if (!super_last)
	{
		*last = NULL;
		*current = NULL;
	}
	*last = (*super_last)->next;
	if (!*last)
		*current = NULL;
	*current = (*last)->next;
}

static int	check_pair(t_list *last, t_list *current, char *a, char *b)
{
	return ((cstr(last->content, a) && cstr(current->content, b)) || \
		(cstr(last->content, b) && cstr(current->content, a)));
}

static void	clean_pair(t_list **super_last, t_list **last, t_list **current)
{
	char	*replace;

	replace = NULL;
	if (check_pair(*last, *current, SWAP_A, SWAP_B))
		replace = SWAP_AB;
	else if (check_pair(*last, *current, ROTATE_A, ROTATE_B))
		replace = ROTATE_AB;
	else if (check_pair(*last, *current, RROTATE_A, RROTATE_B))
		replace = RROTATE_AB;
	else if (check_pair(*last, *current, PUSH_A, PUSH_B) || \
		check_pair(*last, *current, SWAP_A, SWAP_B) || \
		check_pair(*last, *current, ROTATE_A, RROTATE_A) || \
		check_pair(*last, *current, ROTATE_B, RROTATE_B))
		replace = CLEAN_CONST;
	if (replace && cstr(replace, CLEAN_CONST))
	{
		(*super_last)->next = (*current)->next;
		ft_lstdelone(*last, NULL);
		ft_lstdelone(*current, NULL);
	}
	else if (replace)
	{
		(*last)->content = replace;
		(*last)->next = (*current)->next;
		ft_lstdelone(*current, NULL);
	}
}

void	instructions_clean(t_list **origin)
{
	t_list	*current;
	t_list	*last;
	t_list	*super_last;

	if (!*origin)
		return ;
	super_last = *origin;
	next_lsts(&super_last, &last, &current);
	while (current)
	{
		clean_pair(&super_last, &last, &current);
		super_last = super_last->next;
		next_lsts(&super_last, &last, &current);
	}
}
