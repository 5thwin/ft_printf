/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 01:03:05 by seunoh            #+#    #+#             */
/*   Updated: 2021/01/31 01:04:15 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*tmp_dest;
	const unsigned char	*tmp_src;
	unsigned char		tmp_c;
	size_t				i;

	tmp_dest = dest;
	tmp_src = (unsigned char*)src;
	tmp_c = c;
	i = 0;
	while (i < n)
	{
		*(tmp_dest + i) = *(tmp_src + i);
		if (*(tmp_src + i) == tmp_c)
			return (tmp_dest + i + 1);
		i++;
	}
	return (NULL);
}
