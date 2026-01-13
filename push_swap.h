/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaux <bbeaux@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:16:52 by bbeaux            #+#    #+#             */
/*   Updated: 2025/12/15 12:33:20 by bbeaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct s_bench
{
	int				enabled;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_bench;

typedef struct s_opts
{
	int				strategy;
	int				bench;
	char			**args;
	int				argc;
}					t_opts;

int					parse_args(int ac, char **av, t_stack **a);
int					is_number(char *str);
int					ft_atoi_safe(char *str, int *error);
int					has_duplicate_in_stack(t_stack *stack);
int					stack_size(t_stack *s);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
void				free_stack(t_stack **stack);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				swap_stack(t_stack **s);
void				rotate_stack(t_stack **stack);
void				rev_rotate_stack(t_stack **s);
void				simple_sort(t_stack **a, t_stack **b);
void				medium_sort(t_stack **a, t_stack **b);
int					*stack_to_sorted_array(t_stack *a, int size);
int					find_in_range_index(t_stack *a, int minv, int maxv);
void				rotate_index_to_top_a(t_stack **s, int index);
void				rotate_index_to_top_b(t_stack **s, int index);
int					find_max_index(t_stack *s);
int					get_chunk_size(int size);
void				complex_sort(t_stack **a, t_stack **b);
int					get_rank(int value, int *sorted, int size);
void				copy_stack_to_array(t_stack *a, int *arr);
void				sort_array(int *arr, int size);
int					*create_sorted_array(t_stack *a, int size);
void				assign_ranks(t_stack *a, int *sorted, int size);
int					get_max_bits(int max);
void				adaptive_sort(t_stack **a, t_stack **b,
						double *disorder_out);
double				compute_disorder(t_stack *a);
t_bench				*get_bench(void);
void				reset_bench(void);
void				print_bench(double disorder, const char *strategy,
						const char *complexity);
int					is_sorted(t_stack *a);
void				parse_options(int argc, char **argv, t_opts *opts);
void				run_sort(t_stack **a, t_stack **b, t_opts *opts,
						double *disorder);
void				print_benchmark_if_enabled(t_opts *opts, double disorder);
void				*ft_memcpy(void *dst, const void *src, size_t n);

int					ft_printf(const char *str, ...);
int					ft_print_args(char format, va_list args);
int					ft_putchar(char c);
int					ft_putstr(char *str);
int					ft_putptr(void *ptr);
int					ft_putnbr(int nb);
int					ft_putnbr_unsigned(unsigned int nb);
int					ft_puthex(unsigned long n, int uppercase);
int					ft_strcmp(char *s1, char *s2);
#endif