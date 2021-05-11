/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:17:52 by seunoh            #+#    #+#             */
/*   Updated: 2021/05/10 22:16:34 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_width(const char *format, t_flags *flags, va_list ap, int *i)
{
	if (ft_isdigit(format[*i]))
	{
		flags->width = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			(*i)++;
	}
	else
	{
		flags->width = va_arg(ap, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width *= -1;
		}
		(*i)++;
	}
	return (flags->width);
}
