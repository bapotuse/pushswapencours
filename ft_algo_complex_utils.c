/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_complex_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaux <bbeaux@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:10:16 by bbeaux            #+#    #+#             */
/*   Updated: 2025/12/15 12:10:19 by bbeaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int max)
{
	int	bits;

	bits = 0;
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

static void	process_bit(t_stack **a, t_stack **b, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((((*a)->value >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		i++;
	}
	while (*b)
		pa(a, b);
}

void	complex_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	*sorted;
	int	max_bits;
	int	bit;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	if (size <= 1)
		return ;
	sorted = create_sorted_array(*a, size);
	if (!sorted)
		return ;
	assign_ranks(*a, sorted, size);
	free(sorted);
	max_bits = get_max_bits(size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		process_bit(a, b, bit, size);
		bit++;
	}
}
