/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaux <bbeaux@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:11:13 by bbeaux            #+#    #+#             */
/*   Updated: 2025/12/15 12:11:14 by bbeaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_sorted_array(t_stack *a, int size)
{
	int	*arr;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	copy_stack_to_array(a, arr);
	sort_array(arr, size);
	return (arr);
}

int	find_in_range_index(t_stack *a, int minv, int maxv)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->value >= minv && a->value <= maxv)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

void	rotate_index_to_top_a(t_stack **s, int index)
{
	int	size;

	size = stack_size(*s);
	if (index <= size / 2)
	{
		while (index-- > 0)
			ra(s);
	}
	else
	{
		while (index++ < size)
			rra(s);
	}
}

void	rotate_index_to_top_b(t_stack **s, int index)
{
	int	size;

	size = stack_size(*s);
	if (index <= size / 2)
	{
		while (index-- > 0)
			rb(s);
	}
	else
	{
		while (index++ < size)
			rrb(s);
	}
}

int	find_max_index(t_stack *s)
{
	int	max;
	int	idx;
	int	i;

	if (!s)
		return (-1);
	max = s->value;
	idx = 0;
	i = 0;
	while (s)
	{
		if (s->value > max)
		{
			max = s->value;
			idx = i;
		}
		s = s->next;
		i++;
	}
	return (idx);
}
