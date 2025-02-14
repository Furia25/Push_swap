/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:28:16 by val               #+#    #+#             */
/*   Updated: 2025/02/14 21:14:48 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	gap_replace(t_list *start, t_list *end, void (*del)(void *), char *n)
{
	ft_lstmakegap(start, end, del);
	start->content = n;
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
		if ((last->content == SWAP_A && current->content ==  SWAP_B) || \
			(last->content == SWAP_B && current->content ==  SWAP_A))
			gap_replace(last, current, NULL, SWAP_AB);
	}
}
