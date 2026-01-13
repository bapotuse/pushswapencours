/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaux <bbeaux@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:29:20 by bbeaux            #+#    #+#             */
/*   Updated: 2025/12/15 12:29:22 by bbeaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_stack(t_stack **s)
{
	t_stack	*prev;
	t_stack	*curr;

	if (!s || !*s || !(*s)->next)
		return ;
	prev = NULL;
	curr = *s;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = *s;
	*s = curr;
}

void	rra(t_stack **a)
{
	t_bench	*bench;

	rev_rotate_stack(a);
	write(1, "rra\n", 4);
	bench = get_bench();
	if (bench->enabled)
	{
		bench->rra++;
		bench->total++;
	}
}

void	rrb(t_stack **b)
{
	t_bench	*bench;

	rev_rotate_stack(b);
	write(1, "rrb\n", 4);
	bench = get_bench();
	if (bench->enabled)
	{
		bench->rrb++;
		bench->total++;
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	t_bench	*bench;

	rev_rotate_stack(a);
	rev_rotate_stack(b);
	write(1, "rrr\n", 4);
	bench = get_bench();
	if (bench->enabled)
	{
		bench->rrr++;
		bench->total++;
	}
}
