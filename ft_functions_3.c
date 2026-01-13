/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaux <bbeaux@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:12:20 by bbeaux            #+#    #+#             */
/*   Updated: 2025/12/15 12:12:22 by bbeaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack **a)
{
	t_bench	*bench;

	rotate_stack(a);
	write(1, "ra\n", 3);
	bench = get_bench();
	if (bench->enabled)
	{
		bench->ra++;
		bench->total++;
	}
}

void	rb(t_stack **b)
{
	t_bench	*bench;

	rotate_stack(b);
	write(1, "rb\n", 3);
	bench = get_bench();
	if (bench->enabled)
	{
		bench->rb++;
		bench->total++;
	}
}

void	rr(t_stack **a, t_stack **b)
{
	t_bench	*bench;

	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
	bench = get_bench();
	if (bench->enabled)
	{
		bench->rr++;
		bench->total++;
	}
}
