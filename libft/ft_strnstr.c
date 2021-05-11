/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 21:18:08 by seunoh            #+#    #+#             */
/*   Updated: 2021/01/31 01:09:41 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	litlen;
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	litlen = ft_strlen(little);
	i = 0;
	while (*big != '\0' && i + litlen <= len)
	{
		if (ft_strncmp(big, little, litlen) == 0)
			return (char *)(big);
		big++;
		i++;
	}
	return (NULL);
}
