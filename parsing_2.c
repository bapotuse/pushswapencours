/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaux <bbeaux@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:16:12 by bbeaux            #+#    #+#             */
/*   Updated: 2025/12/15 12:16:14 by bbeaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_safe(char *str, int *error)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	*error = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (*error = 1, 0);
	while (*str)
	{
		result = result * 10 + (*str - '0');
		if (sign == 1 && result > 2147483647)
			return (*error = 1, 0);
		if (sign == -1 && result > -2147483648)
			return (*error = 1, 0);
		str++;
	}
	return ((int)(result * sign));
}

int	has_duplicate_in_stack(t_stack *stack)
{
	t_stack	*cur;
	t_stack	*run;

	cur = stack;
	while (cur)
	{
		run = cur->next;
		while (run)
		{
			if (run->value == cur->value)
				return (1);
			run = run->next;
		}
		cur = cur->next;
	}
	return (0);
}
