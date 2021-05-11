/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:10:47 by seunoh            #+#    #+#             */
/*   Updated: 2021/02/15 18:52:22 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int		len;

	len = ((n <= 0) ? 1 : 0);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*dst;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numlen(n);
	neg = ((n < 0) ? 1 : 0);
	n = ((n < 0) ? -1 * n : n);
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dst[len--] = '\0';
	while (len >= 0)
	{
		dst[len--] = '0' + n % 10;
		n /= 10;
	}
	if (neg)
		dst[0] = '-';
	return (dst);
}
