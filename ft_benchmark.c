/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_benchmark.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaux <bbeaux@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:25:23 by bbeaux            #+#    #+#             */
/*   Updated: 2025/12/15 12:26:34 by bbeaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench	*get_bench(void)
{
	static t_bench	bench = {0};

	return (&bench);
}

void	reset_bench(void)
{
	t_bench	*b;

	b = get_bench();
	b->enabled = 0;
	b->sa = 0;
	b->sb = 0;
	b->ss = 0;
	b->pa = 0;
	b->pb = 0;
	b->ra = 0;
	b->rb = 0;
	b->rr = 0;
	b->rra = 0;
	b->rrb = 0;
	b->rrr = 0;
	b->total = 0;
}

void	print_bench(double disorder, const char *strategy,
		const char *complexity)
{
	t_bench	*b;
	int		disorder_pct;

	b = get_bench();
	disorder_pct = (int)(disorder * 100.0);
	ft_printf("[bench] disorder: %d%%\n", disorder_pct);
	ft_printf("[bench] strategy: %s / %s\n", strategy, complexity);
	ft_printf("[bench] total_ops: %d\n", b->total);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		b->sa, b->sb, b->ss, b->pa, b->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		b->ra, b->rb, b->rr, b->rra, b->rrb, b->rrr);
}
