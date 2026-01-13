/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaux <bbeaux@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:14:56 by bbeaux            #+#    #+#             */
/*   Updated: 2025/12/15 12:59:45 by bbeaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	temp_dest = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	return (dst);
}

char	**create_parse_argv(t_opts *opts, char **argv)
{
	char	**parse_argv;

	parse_argv = malloc((opts->argc + 1) * sizeof(char *));
	if (!parse_argv)
		return (NULL);
	parse_argv[0] = argv[0];
	ft_memcpy(parse_argv + 1, opts->args, opts->argc * sizeof(char *));
	return (parse_argv);
}

int	handle_error(t_stack **stack_a, char **parse_argv, t_opts *opts)
{
	write(2, "Error\n", 6);
	free_stack(stack_a);
	if (parse_argv)
		free(parse_argv);
	if (opts->args)
		free(opts->args);
	return (1);
}

int	process_stacks(t_stack **a, t_stack **b, t_opts *opts)
{
	double	disorder;

	disorder = 0.0;
	if (opts->bench)
	{
		reset_bench();
		get_bench()->enabled = 1;
		disorder = compute_disorder(*a);
	}
	if (!is_sorted(*a))
		run_sort(a, b, opts, &disorder);
	print_benchmark_if_enabled(opts, disorder);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_opts	opts;
	char	**parse_argv;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	parse_options(argc, argv, &opts);
	if (opts.argc == 0)
	{
		free(opts.args);
		return (0);
	}
	parse_argv = create_parse_argv(&opts, argv);
	if (!parse_argv || !parse_args(opts.argc + 1, parse_argv, &stack_a))
		return (handle_error(&stack_a, parse_argv, &opts));
	free(parse_argv);
	process_stacks(&stack_a, &stack_b, &opts);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(opts.args);
	return (0);
}
