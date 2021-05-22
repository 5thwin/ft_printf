/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:24:27 by seunoh            #+#    #+#             */
/*   Updated: 2021/05/22 11:19:54 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_precision(const char *format, t_flags *flags, va_list *ap, int *i)
{
	(*i)++;
	flags->precision = 0;
	if (ft_isdigit(format[*i]))
	{
		flags->precision = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			(*i)++;
		if (flags->precision < 0)
			flags->precision = -1;
	}
	else if (format[*i] == '*')
	{
		flags->precision = va_arg(*ap, int);
		(*i)++;
		if (flags->precision < 0)
			flags->precision = -1;
	}
	return (flags->precision);
}
