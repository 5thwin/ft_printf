/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:53:37 by seunoh            #+#    #+#             */
/*   Updated: 2021/05/22 11:28:11 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	set_nbr_base_sign(t_flags *flags, va_list *ap)
{
	unsigned long long	ret;

	ret = 0;
	if (flags->type == 'd' || flags->type == 'i')
	{
		ret = (unsigned long long)va_arg(*ap, unsigned long long);
		if ((int)ret < 0)
		{
			flags->nbrsign = -1;
			ret = -ret;
		}
	}
	else if (flags->type == 'x' || flags->type == 'X')
	{
		flags->nbrbase = 16;
		ret = (unsigned long long)va_arg(*ap, unsigned int);
	}
	else if (flags->type == 'u')
		ret = (unsigned long long)va_arg(*ap, unsigned int);
	else if (flags->type == 'p')
	{
		flags->nbrbase = 16;
		ret = va_arg(*ap, unsigned long long);
	}
	return (ret);
}

void				fill_precision_zero_null(char **buf, int nbrlen, int buflen)
{
	int i;

	i = 0;
	while (i < buflen - nbrlen)
		(*buf)[i++] = '0';
	(*buf)[buflen] = '\0';
}

void				fill_nbr(unsigned long long nbr, char **buf,
									t_flags *flags, int buflen)
{
	int i;

	if (nbr == 0 && flags->precision != 0)
		(*buf)[buflen - 1] = '0';
	i = 1;
	while (nbr)
	{
		(*buf)[buflen - i] = ft_baseset(flags->type)[nbr % flags->nbrbase];
		nbr /= flags->nbrbase;
		i++;
	}
}

int					process_buf(t_flags *flags, char **buf, int *buflen)
{
	if (join_sign_nozero(buf, flags, buflen) == -1)
		return (-1);
	if (join_hex_sign(buf, flags, buflen) == -1)
		return (-1);
	if (join_width_buf(buf, flags) == -1)
		return (-1);
	if (join_sign_zero(buf, flags, buflen) == -1)
		return (-1);
	return (0);
}

int					print_nbr(t_flags *flags, va_list *ap)
{
	unsigned long long	nbr;
	int					nbrlen;
	char				*buf;
	int					buflen;

	nbr = set_nbr_base_sign(flags, ap);
	nbrlen = ft_nbrlen(&nbr, flags);
	buflen = ft_max_int(nbrlen, flags->precision);
	buf = (char *)malloc(sizeof(char) * (buflen + 1));
	if (buf == NULL)
		return (-1);
	fill_precision_zero_null(&buf, nbrlen, buflen);
	fill_nbr(nbr, &buf, flags, buflen);
	if (process_buf(flags, &buf, &buflen) == -1)
		return (-1);
	ft_putstr_fd(buf, 1);
	free(buf);
	return (buflen);
}
