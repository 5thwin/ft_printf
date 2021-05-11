/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:50:25 by seunoh            #+#    #+#             */
/*   Updated: 2021/02/15 18:49:41 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_nulstr(char const *s1)
{
	if (!s1)
		return (NULL);
	return (ft_strdup(s1));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		ft_nulstr(s1);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_in_set(s1[start], set))
		start++;
	while (end > start && ft_in_set(s1[end - 1], set))
		end--;
	if (!(str = malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	ft_strlcpy(str, &s1[start], end - start + 1);
	return (str);
}
