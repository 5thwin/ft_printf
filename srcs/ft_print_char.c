/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:58:31 by seunoh            #+#    #+#             */
/*   Updated: 2021/05/17 15:41:22 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_space(t_flags *flags)
{
	int		ret;
	char	fill_char;

	fill_char = ' ';
	if (flags->zero == 1)
		fill_char = '0';
	ret = 0;
	while (ret < flags->width - 1)
	{
		ft_putchar_fd(fill_char, 1);
		ret++;
	}
	return (ret);
}

int	print_c(t_flags *flags, va_list *ap)
{
	int		ret;
	int		c;

	ret = 0;
	if (flags->type == 'c')
		c = va_arg(*ap, int);
	else if (flags->type == '%')
		c = '%';
	if (flags->minus == 1)
	{
		ft_putchar_fd((char)c, 1);
		ret++;
	}
	ret += put_space(flags);
	if (flags->minus == 0)
	{
		ft_putchar_fd((char)c, 1);
		ret++;
	}
	return (ret);
}
