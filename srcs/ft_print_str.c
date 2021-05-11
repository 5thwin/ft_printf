/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:57:23 by seunoh            #+#    #+#             */
/*   Updated: 2021/05/10 22:04:43 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*trim_str_precision(char *str, int prec)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (prec + 1));
	if (buf == NULL)
		return (NULL);
	ft_strlcpy(buf, str, prec + 1);
	return (buf);
}

void	fill_space(char **space, t_flags *flags, int len)
{
	char	fill_char;
	int		i;

	fill_char = ' ';
	if (flags->zero == 1)
		fill_char = '0';
	i = 0;
	while (i < len)
		*space[i++] = fill_char;
	*space[i] = '\0';
}

int		print_s(t_flags *flags, va_list ap)
{
	char	*arg_str;
	char	*buf;
	int		ret;

	arg_str = (char *)va_arg(ap, void *);
	if (arg_str == NULL)
		arg_str = "null";
	if (flags->precision == -1 || (size_t)flags->precision > ft_strlen(arg_str))
		flags->precision = ft_strlen(arg_str);
	buf = trim_str_precision(arg_str, flags->precision);
	if (buf == NULL)
		return (-1);
	if (join_width_buf(&buf, flags) == -1)
		return (-1);
	ret = (int)ft_strlen(buf);
	ft_putstr_fd(buf, 1);
	free(buf);
	return (ret);
}
