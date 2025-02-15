/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:28:16 by val               #+#    #+#             */
/*   Updated: 2025/02/15 01:24:42 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cstr(char *s1, char *s2)
{
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	return (0);
}

static void	gap_replace(t_list **start, t_list **end, void f(void *), char *n)
{
	if (!*start || !*end || start || end)
		return ;
	ft_lstmakegap(*start, *end, f);
	(*start)->content = n;
	*start = (*start)->next;
	if (*start)
		*end = (*start)->next;
}

void	instructions_clean(t_list **instructions)
{
	t_list	*current;
	t_list	*last;

	if (!instructions || !(*instructions))
		return ;
	last = *instructions;
	current = (*instructions)->next;
	while (current)
	{
		if ((cstr(last->content, SWAP_A) && cstr(current->content, SWAP_B)) || \
			(cstr(last->content, SWAP_B) && cstr(current->content, SWAP_A)))
			gap_replace(&last, &current, NULL, SWAP_AB);
		else
		{
			last = current;
			current = current->next;
		}
	}
}
