/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:37:56 by seunoh            #+#    #+#             */
/*   Updated: 2021/02/15 18:47:14 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	new_len;
	char	*str;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
	{
		if (!(str = malloc(1)))
			return (NULL);
		*str = '\0';
		return (str);
	}
	new_len = ft_strlen(&s[start]);
	len = (new_len < len ? new_len : len);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
