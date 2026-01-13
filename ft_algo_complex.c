/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaux <bbeaux@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:10:35 by bbeaux            #+#    #+#             */
/*   Updated: 2025/12/15 12:10:37 by bbeaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rank(int value, int *sorted, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (0);
}

void	copy_stack_to_array(t_stack *a, int *arr)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	min_idx;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		if (min_idx != i)
		{
			temp = arr[i];
			arr[i] = arr[min_idx];
			arr[min_idx] = temp;
		}
		i++;
	}
}

int	*create_sorted_array(t_stack *a, int size)
{
	int		*arr;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	copy_stack_to_array(a, arr);
	sort_array(arr, size);
	return (arr);
}

void	assign_ranks(t_stack *a, int *sorted, int size)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		tmp->value = get_rank(tmp->value, sorted, size);
		tmp = tmp->next;
	}
}
