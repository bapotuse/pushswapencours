/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_adaptive.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaux <bbeaux@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:09:54 by bbeaux            #+#    #+#             */
/*   Updated: 2025/12/15 12:09:56 by bbeaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*i;
	t_stack	*j;

	mistakes = 0;
	total_pairs = 0;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}

static void	swap_if_needed(t_stack **a, t_stack *tmp, t_stack *prev)
{
	if (tmp->value > tmp->next->value)
	{
		if (prev)
		{
			while (tmp != *a)
				ra(a);
		}
		sa(a);
	}
}

static int	check_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	sort_low_disorder(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*prev;

	while (*a)
	{
		tmp = *a;
		prev = NULL;
		while (tmp && tmp->next)
		{
			swap_if_needed(a, tmp, prev);
			if (tmp->value <= tmp->next->value)
			{
				prev = tmp;
				tmp = tmp->next;
			}
			else
			{
				tmp = *a;
				prev = NULL;
			}
		}
		if (check_sorted(*a))
			break ;
	}
	(void)b;
}

void	adaptive_sort(t_stack **a, t_stack **b, double *disorder_out)
{
	double	disorder;
	int		size;

	if (!a || !*a)
	{
		if (disorder_out)
			*disorder_out = 0.0;
		return ;
	}
	size = stack_size(*a);
	disorder = compute_disorder(*a);
	if (disorder_out)
		*disorder_out = disorder;
	if (size <= 5)
	{
		simple_sort(a, b);
		return ;
	}
	if (disorder < 0.2)
		sort_low_disorder(a, b);
	else if (disorder < 0.5)
		medium_sort(a, b);
	else
		complex_sort(a, b);
}
