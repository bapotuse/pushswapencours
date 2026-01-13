/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaux <bbeaux@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:23:15 by bbeaux            #+#    #+#             */
/*   Updated: 2025/12/15 12:29:42 by bbeaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	size_t	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}

int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	address;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	address = (unsigned long)ptr;
	count += ft_putstr("0x");
	count += ft_puthex(address, 0);
	return (count);
}

int	ft_putnbr(int nb)
{
	int		count;
	long	nbr;

	count = 0;
	nbr = nb;
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar('0' + (nbr % 10));
	return (count);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
		count += ft_putnbr_unsigned(nb / 10);
	count += ft_putchar('0' + (nb % 10));
	return (count);
}
