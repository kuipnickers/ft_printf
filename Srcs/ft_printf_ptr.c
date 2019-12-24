/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_ptr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nkuipers <nkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/24 13:37:02 by nkuipers       #+#    #+#                */
/*   Updated: 2019/12/24 13:45:57 by nkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void	ft_putptr_lower_count(unsigned int nbr, int *rv)
{
	unsigned int	tmp;
	unsigned int	len;
	char			*hex;

	ft_putnstr_fd_count("0x", 1, 2, rv);
	hex = "0123456789abcdef";
	tmp = nbr;
	len = 1;
	while (tmp / 16)
	{
		tmp /= 16;
		len *= 16;
	}
	tmp = nbr;
	while (len)
	{
		ft_putchar_fd_count(hex[nbr / len], 1, rv);
		nbr %= len;
		len /= 16;
	}
}

void	prepare_ptr(t_flags *flags, unsigned int *nbr)
{
	if (flags->length == 'h')
		*nbr = ((unsigned short)*nbr);
	if (flags->length == 'H')
		*nbr = ((unsigned char)*nbr);
	flags->nbrlen = ft_nbrlen_hex(*nbr);
	if (flags->precision != -2)
		flags->zero = 0;
	if (*nbr == 0)
		flags->hash = 0;
	if (flags->precision == -2 ||
		(flags->precision < flags->nbrlen && *nbr != 0))
		flags->precision = flags->nbrlen;
}

void	printptr(t_flags *flags, va_list list, int *rv)
{
	unsigned int nbr;

	nbr = va_arg(list, unsigned int);
	prepare_hex(flags, &nbr);
	flags->width -= 2;
	if (flags->leftj)
	{
		padder(flags->precision, flags->nbrlen, '0', rv);
		if (flags->precision)
			ft_putptr_lower_count(nbr, rv);
	}
	if (!flags->leftj && flags->zero)
		padder(flags->width, flags->precision + (flags->hash * 2), '0', rv);
	else
		padder(flags->width, flags->precision + (flags->hash * 2), ' ', rv);
	if (!flags->leftj)
	{
		padder(flags->precision, flags->nbrlen, '0', rv);
		if (flags->precision)
			ft_putptr_lower_count(nbr, rv);
	}
}