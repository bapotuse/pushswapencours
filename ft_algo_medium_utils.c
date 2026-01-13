/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_medium_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaux <bbeaux@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:10:52 by bbeaux            #+#    #+#             */
/*   Updated: 2025/12/15 12:10:54 by bbeaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int size)
{
	if (size > 100)
		return (30);
	return (15);
}

static void	push_chunks_to_b(t_stack **a, t_stack **b, int *sorted, int size)
{
	int	chunk_size;
	int	i;
	int	start;
	int	end;
	int	idx;

	chunk_size = get_chunk_size(size);
	i = 0;
	while (i < size)
	{
		start = i;
		end = i + chunk_size - 1;
		if (end >= size)
			end = size - 1;
		idx = find_in_range_index(*a, sorted[start], sorted[end]);
		while (idx != -1)
		{
			rotate_index_to_top_a(a, idx);
			pb(a, b);
			idx = find_in_range_index(*a, sorted[start], sorted[end]);
		}
		i += chunk_size;
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	idx;

	while (*b)
	{
		idx = find_max_index(*b);
		rotate_index_to_top_b(b, idx);
		pa(a, b);
	}
}

void	medium_sort(t_stack **a, t_stack **b)
{
	int	*sorted;
	int	size;

	size = stack_size(*a);
	if (size <= 1)
		return ;
	if (size <= 5)
	{
		simple_sort(a, b);
		return ;
	}
	sorted = stack_to_sorted_array(*a, size);
	if (!sorted)
		return ;
	push_chunks_to_b(a, b, sorted, size);
	push_back_to_a(a, b);
	free(sorted);
}
