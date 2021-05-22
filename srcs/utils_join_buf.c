/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_join_buf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:16:36 by seunoh            #+#    #+#             */
/*   Updated: 2021/05/22 11:36:45 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		join_width_buf(char **buf, t_flags *flags)
{
	char	*space;
	char	*tmpbuf;
	int		space_len;

	if (flags->width <= (int)ft_strlen(*buf))
		return ((int)ft_strlen(*buf));
	space_len = flags->width - (int)ft_strlen(*buf);
	space = (char *)malloc(sizeof(char) * (space_len + 1));
	if (space == NULL)
	{
		free(*buf);
		return (-1);
	}
	fill_space(&space, flags, space_len);
	if (flags->minus == 0)
		tmpbuf = ft_strjoin(space, *buf);
	else
		tmpbuf = ft_strjoin(*buf, space);
	free(*buf);
	free(space);
	if (tmpbuf == NULL)
		return (-1);
	*buf = tmpbuf;
	return ((int)ft_strlen(*buf));
}

int		join_hex_sign(char **buf, t_flags *flags, int *buflen)
{
	char	*tmp_buf;
	int		ret;

	ret = 0;
	if (flags->type == 'p')
	{
		tmp_buf = ft_strjoin("0x", *buf);
		free(*buf);
		if (tmp_buf == NULL)
			return (-1);
		*buf = tmp_buf;
		*buflen += 2;
		ret = 1;
	}
	return (ret);
}

int		join_sign_nozero(char **buf, t_flags *flags, int *buflen)
{
	int		ret;
	char	*tmp_buf;

	ret = 0;
	if ((flags->nbrsign == -1 || flags->plus == 1 || flags->space == 1)
	&& flags->zero == 0 && (flags->type == 'd' || flags->type == 'i'))
	{
		if (flags->nbrsign == -1)
			tmp_buf = ft_strjoin("-", *buf);
		else if (flags->plus == 1)
			tmp_buf = ft_strjoin("+", *buf);
		else
			tmp_buf = ft_strjoin(" ", *buf);
		free(*buf);
		if (tmp_buf == NULL)
			return (-1);
		*buf = tmp_buf;
		*buflen += 1;
		ret = 1;
	}
	return (ret);
}

int		join_sign_zero(char **buf, t_flags *flags, int *buflen)
{
	int		ret;
	char	*tmp_buf;

	ret = 0;
	if ((flags->nbrsign == -1 || flags->plus == 1 || flags->space == 1)
		&& flags->zero == 1)
	{
		if (*buflen >= flags->width)
		{
			add_sign(buf, flags, *buflen, &tmp_buf);
			free(*buf);
			if (tmp_buf == NULL)
				return (-1);
			*buf = tmp_buf;
			ret = 1;
		}
		else
			add_sign(buf, flags, *buflen, &tmp_buf);
	}
	*buflen = ft_strlen(*buf);
	return (ret);
}
