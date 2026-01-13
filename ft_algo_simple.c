/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaux <bbeaux@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:11:25 by bbeaux            #+#    #+#             */
/*   Updated: 2025/12/15 12:11:27 by bbeaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_stack *a)
{
	int		min;
	int		index;
	int		i;
	t_stack	*tmp;

	min = a->value;
	index = 0;
	i = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

static void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(*a))
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static void	sort_small(t_stack **a, t_stack **b)
{
	int	size;
	int	min_idx;

	size = stack_size(*a);
	while (size > 3)
	{
		min_idx = find_min_index(*a);
		if (min_idx <= size / 2)
		{
			while (min_idx-- > 0)
				ra(a);
		}
		else
		{
			while (min_idx++ < size)
				rra(a);
		}
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	simple_sort(t_stack **a, t_stack **b)
{
	int	size;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	if (size == 1 || is_sorted(*a))
		return ;
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else if (size == 3)
		sort_three(a);
	else
		sort_small(a, b);
}
