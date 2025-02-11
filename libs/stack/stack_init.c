/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:27:50 by val               #+#    #+#             */
/*   Updated: 2025/02/11 16:33:27 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_new(int capacity)
{
	t_stack	*result;

	result = ft_calloc(1, sizeof(t_stack));
	if (!result)
		return (NULL);
	result->array = ft_calloc(capacity, sizeof(int));
	if (result->array)
		return (free(result), NULL);
	result->bottom = -1;
	result->top = -1;
	result->size = capacity;
}