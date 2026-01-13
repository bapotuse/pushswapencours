/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaux <bbeaux@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:16:30 by bbeaux            #+#    #+#             */
/*   Updated: 2025/12/15 12:16:31 by bbeaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}

static int	extract_and_add(char *str, int start, int end, t_stack **a)
{
	int		j;
	char	*num;
	int		error;
	t_stack	*new;

	num = malloc(end - start + 1);
	if (!num)
		return (0);
	j = 0;
	while (start < end)
		num[j++] = str[start++];
	num[j] = '\0';
	if (!is_number(num))
		return (free(num), 0);
	error = 0;
	new = malloc(sizeof(t_stack));
	if (!new)
		return (free(num), 0);
	new->value = ft_atoi_safe(num, &error);
	new->next = NULL;
	free(num);
	if (error)
		return (free(new), 0);
	ft_lstadd_back(a, new);
	return (1);
}

static int	parse_string(char *str, t_stack **a)
{
	int	i;
	int	start;

	i = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (!str[i])
			break ;
		start = i;
		while (str[i] && !is_space(str[i]))
			i++;
		if (!extract_and_add(str, start, i, a))
			return (0);
	}
	return (1);
}

int	parse_args(int ac, char **av, t_stack **a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!parse_string(av[i], a))
			return (0);
		i++;
	}
	if (has_duplicate_in_stack(*a))
		return (0);
	return (1);
}
