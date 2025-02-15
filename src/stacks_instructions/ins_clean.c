/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:28:16 by val               #+#    #+#             */
/*   Updated: 2025/02/15 03:48:46 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cstr(char *s1, char *s2)
{
	return (ft_strcmp(s1, s2) == 0);
}

static void	next_lsts(t_list **super_last, t_list **last, t_list **current)
{
	if (!super_last)
	{
		*last = NULL;
		*current = NULL;
		return ;
	}
	*last = (*super_last)->next;
	if (!*last)
	{
		*current = NULL;
		return ;
	}
	*current = (*last)->next;
}

static int	check_pair(t_list *last, t_list *current, char *a, char *b)
{
	return ((cstr(last->content, a) && cstr(current->content, b)) || \
		(cstr(last->content, b) && cstr(current->content, a)));
}

static void	clean_pair(t_list **s_last, t_list **last, t_list **actual, char *s)
{
	if (check_pair(*last, *actual, SWAP_A, SWAP_B))
		s = SWAP_AB;
	else if (check_pair(*last, *actual, ROTATE_A, ROTATE_B))
		s = ROTATE_AB;
	else if (check_pair(*last, *actual, RROTATE_A, RROTATE_B))
		s = RROTATE_AB;
	else if (check_pair(*last, *actual, PUSH_A, PUSH_B) || \
		check_pair(*last, *actual, SWAP_A, SWAP_B) || \
		check_pair(*last, *actual, ROTATE_A, RROTATE_A) || \
		check_pair(*last, *actual, ROTATE_B, RROTATE_B))
		s = CLEAN_CONST;
	if (s && cstr(s, CLEAN_CONST))
	{
		(*s_last)->next = (*actual)->next;
		ft_lstdelone(*last, NULL);
		ft_lstdelone(*actual, NULL);
	}
	else if (s)
	{
		(*last)->content = s;
		(*last)->next = (*actual)->next;
		ft_lstdelone(*actual, NULL);
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
		clean_pair(&super_last, &last, &current, NULL);
		super_last = super_last->next;
		next_lsts(&super_last, &last, &current);
	}
}
