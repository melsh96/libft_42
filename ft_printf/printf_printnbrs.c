/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_printnbrs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:08:13 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/16 17:09:43 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_libft/ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	long	nb;
	int		len;

	len = 0;
	nb = n;
	if (nb >= 10)
		len += ft_putnbr_u(nb / 10);
	len += ft_putchar((nb % 10) + '0');
	return (len);
}

int	ft_putptr_base(unsigned long nb, char *base)
{
	unsigned long	len_base;
	unsigned long	len;

	len = 0;
	len_base = ft_strlen(base);
	if (nb >= len_base)
	{
		len += ft_putptr_base((nb / len_base), base);
		len += ft_putchar(base[nb % len_base]);
	}
	else
		len += ft_putchar(base[nb % len_base]);
	return (len);
}

int	ft_putnbr_base(int nbr, char *base)
{
	long long	nb;
	int			len_base;
	int			len;

	nb = nbr;
	len = 0;
	len_base = ft_strlen(base);
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= len_base)
	{
		len += ft_putnbr_base((nb / len_base), base);
		len += ft_putchar(base[nb % len_base]);
	}
	else
		len += ft_putchar(base[nb % len_base]);
	return (len);
}
