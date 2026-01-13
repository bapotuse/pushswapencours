/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaux <bbeaux@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:11:45 by bbeaux            #+#    #+#             */
/*   Updated: 2025/12/15 12:12:08 by bbeaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **s)
{
	t_stack	*first;
	t_stack	*second;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*s = second;
}

void	sa(t_stack **a)
{
	t_bench	*b;

	swap_stack(a);
	write(1, "sa\n", 3);
	b = get_bench();
	if (b->enabled)
	{
		b->sa++;
		b->total++;
	}
}

void	sb(t_stack **b)
{
	t_bench	*bench;

	swap_stack(b);
	write(1, "sb\n", 3);
	bench = get_bench();
	if (bench->enabled)
	{
		bench->sb++;
		bench->total++;
	}
}

void	ss(t_stack **a, t_stack **b)
{
	t_bench	*bench;

	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 3);
	bench = get_bench();
	if (bench->enabled)
	{
		bench->ss++;
		bench->total++;
	}
}
