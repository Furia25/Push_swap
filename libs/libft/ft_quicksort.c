/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:49:15 by val               #+#    #+#             */
/*   Updated: 2025/02/12 15:05:27 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	index;
	int	j;

	pivot = arr[high];
	index = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] <= pivot)
		{
			index++;
			ft_swap(&arr[index], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[index + 1], &arr[high]);
	return (index + 1);
}

void	ft_quicksort(int arr[], int low, int high)
{
	int	pindex;

	if (low > high)
		return ;
	pindex = partition(arr, low, high);
	ft_quicksort(arr, low, pindex - 1);
	ft_quicksort(arr, pindex + 1, high);
}
