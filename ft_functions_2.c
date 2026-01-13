/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaux <bbeaux@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:12:13 by bbeaux            #+#    #+#             */
/*   Updated: 2025/12/15 12:12:14 by bbeaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_bench	*bench;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = tmp->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
	bench = get_bench();
	if (bench->enabled)
	{
		bench->pa++;
		bench->total++;
	}
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_bench	*bench;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = tmp->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
	bench = get_bench();
	if (bench->enabled)
	{
		bench->pb++;
		bench->total++;
	}
}
