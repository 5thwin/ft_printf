/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:57:15 by seunoh            #+#    #+#             */
/*   Updated: 2021/01/19 16:57:15 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*str;
	unsigned char			find;

	str = (unsigned char *)s;
	find = (unsigned char)c;
	while (n--)
	{
		if (*str == find)
			return ((unsigned char *)str);
		str++;
	}
	return (NULL);
}
