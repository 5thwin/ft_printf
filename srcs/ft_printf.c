/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:08:57 by seunoh            #+#    #+#             */
/*   Updated: 2021/05/14 16:24:23 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(t_flags *flags, va_list ap)
{
	if (flags->type == 's')
		return (print_s(flags, ap));
	if (flags->type == 'd' || flags->type == 'i' || flags->type == 'p'
		|| flags->type == 'x' || flags->type == 'X' || flags->type == 'u')
		return (print_nbr(flags, ap));
	if (flags->type == 'c' || flags->type == '%')
		return (print_c(flags, ap));
	return (-1);
}

int	set_length_and_type(const char *format, t_flags *flags, va_list ap, int *i)
{
	if (ft_strchr(TYPE_DIC, format[*i]) != (NULL))
		flags->type = format[(*i)++];
	if (ap == 0)
		;
	return (1);
}

int	type_analysis(const char *format, va_list ap, int *i)
{
	t_flags	flags;

	ft_t_flags_initialize(&flags);
	while (flag_classifier(format[++(*i)], &flags))
		;
	if (ft_isdigit(format[*i]) || format[*i] == '*')
		set_width(format, &flags, ap, i);
	if (format[*i] == '.')
		set_precision(format, &flags, ap, i);
	set_length_and_type(format, &flags, ap, i);
	invalid_flag_ignore(&flags);
	return (print_format(&flags, ap));
}

int	ft_printf(const char *format, ...)
{
	int		num_printed;
	int		i;
	int		typelen;
	va_list	ap;

	va_start(ap, format);
	num_printed = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i++], 1);
			num_printed++;
		}
		else
		{
			typelen = type_analysis(format, ap, &i);
			if (typelen == -1)
				return (-1);
			num_printed += typelen;
		}
	}
	va_end(ap);
	return (num_printed);
}
