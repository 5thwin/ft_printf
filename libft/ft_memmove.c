/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:57:15 by seunoh            #+#    #+#             */
/*   Updated: 2021/01/19 16:57:15 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp_dest;
	const unsigned char	*tmp_src;

	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		tmp_dest = dest + (n - 1);
		tmp_src = (unsigned char *)src + (n - 1);
		while (n--)
			*tmp_dest-- = *tmp_src--;
	}
	return (dest);
}
