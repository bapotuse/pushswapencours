/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaux <bbeaux@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:13:30 by bbeaux            #+#    #+#             */
/*   Updated: 2025/12/15 12:33:36 by bbeaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

static void	init_opts(t_opts *opts, int argc)
{
	opts->strategy = 4;
	opts->bench = 0;
	opts->args = malloc(argc * sizeof(char *));
	opts->argc = 0;
}

void	check_flag(char *arg, t_opts *opts)
{
	if (ft_strcmp(arg, "--simple") == 0)
		opts->strategy = 1;
	else if (ft_strcmp(arg, "--medium") == 0)
		opts->strategy = 2;
	else if (ft_strcmp(arg, "--complex") == 0)
		opts->strategy = 3;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		opts->strategy = 4;
	else if (ft_strcmp(arg, "--bench") == 0)
		opts->bench = 1;
}

void	parse_options(int argc, char **argv, t_opts *opts)
{
	int	i;
	int	j;

	init_opts(opts, argc);
	if (!opts->args)
		return ;
	j = 0;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			check_flag(argv[i], opts);
		else
			opts->args[j++] = argv[i];
		i++;
	}
	opts->argc = j;
}

void	run_sort(t_stack **a, t_stack **b, t_opts *opts, double *disorder)
{
	if (opts->strategy == 1)
		simple_sort(a, b);
	else if (opts->strategy == 2)
		medium_sort(a, b);
	else if (opts->strategy == 3)
		complex_sort(a, b);
	else
		adaptive_sort(a, b, disorder);
}
