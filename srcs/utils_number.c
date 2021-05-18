/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:22:02 by seunoh            #+#    #+#             */
/*   Updated: 2021/05/18 13:29:37 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlen(unsigned long long nbr, t_flags *flags)
{
	int	len;

	if (nbr == 0 && flags->precision != 0)
		return (1);
	len = 0;
	while (nbr)
	{
		len++;
		nbr /= flags->nbrbase;
	}
	return (len);
}

void	add_sign(char **buf, t_flags *flags, int buflen, char **tmp_buf)
{
	if (buflen >= flags->width)
	{
		if (flags->nbrsign == -1)
			*tmp_buf = ft_strjoin("-", *buf);
		else if (flags->plus == 1)
			*tmp_buf = ft_strjoin("+", *buf);
		else
			*tmp_buf = ft_strjoin(" ", *buf);
	}
	else
	{
		if (flags->nbrsign == -1)
			(*buf)[0] = '-';
		else if (flags->plus == 1)
			(*buf)[0] = '+';
		else if (flags->space == 1)
			(*buf)[0] = ' ';
	}
}
