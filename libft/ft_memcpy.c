/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:52:36 by seunoh            #+#    #+#             */
/*   Updated: 2021/01/31 01:07:08 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp_dest;
	const unsigned char	*tmp_src;

	if (dest == src)
		return (dest);
	tmp_dest = dest;
	tmp_src = (unsigned char*)src;
	while (n--)
		*(tmp_dest++) = *(tmp_src++);
	return (dest);
}
