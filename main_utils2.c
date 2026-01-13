/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaux <bbeaux@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:13:51 by bbeaux            #+#    #+#             */
/*   Updated: 2025/12/15 13:09:55 by bbeaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_strategy_info(t_opts *opts, const char **strat, const char *
		*compl, double disorder)
{
	if (opts->strategy == 1)
	{
		*strat = "Simple";
		*compl = "O(n^2)";
	}
	else if (opts->strategy == 2)
	{
		*strat = "Medium";
		*compl = "O(n√n)";
	}
	else if (opts->strategy == 3)
	{
		*strat = "Complex";
		*compl = "O(n log n)";
	}
	else
	{
		*strat = "Adaptive";
		if (disorder < 0.2)
			*compl = "O(n)";
		else if (disorder < 0.5)
			*compl = "O(n√n)";
		else
			*compl = "O(n log n)";
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	print_benchmark_if_enabled(t_opts *opts, double disorder)
{
	const char	*strat;
	const char	*compl;

	if (!opts->bench)
		return ;
	get_strategy_info(opts, &strat, &compl, disorder);
	print_bench(disorder, strat, compl);
}
