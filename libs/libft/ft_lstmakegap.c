/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmakegap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:05:39 by val               #+#    #+#             */
/*   Updated: 2025/02/14 21:05:58 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmakegap(t_list *gap_start, t_list *gap_end, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	if (!gap_start || !gap_end)
		return ;
	current = gap_start->next;
	while (current && current != gap_end)
	{
		temp = current->next;
		ft_lstdelone(current, del);
		current = temp;
	}
	if (current == gap_end)
	{
		gap_start->next = gap_end->next;
		ft_lstdelone(gap_end, del);
	}
}