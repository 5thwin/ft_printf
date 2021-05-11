/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:17:02 by seunoh            #+#    #+#             */
/*   Updated: 2021/02/15 18:48:19 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strcnt(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			cnt++;
			while (*s != c && *s)
				s++;
		}
		else if (*s == c)
			s++;
	}
	return (cnt);
}

static char		**ft_free2mem(char **mem)
{
	size_t	i;

	i = 0;
	while (mem[i])
		free(mem[i++]);
	free(mem);
	return (NULL);
}

static char		**ft_splinter(char **dst, char const *s, char c, size_t cnt)
{
	size_t	ord;
	size_t	len;
	size_t	i;

	ord = 0;
	i = 0;
	while (s[i] && ord < cnt)
	{
		while (s[i] == c)
			i++;
		len = 0;
		while (s[i + len] != c && s[i + len])
			len++;
		if (!(dst[ord] = (char *)malloc(sizeof(char) * (len + 1))))
			return (ft_free2mem(dst));
		ft_strlcpy(dst[ord], &s[i], len + 1);
		i += len;
		ord++;
	}
	return (dst);
}

char			**ft_split(char const *s, char c)
{
	size_t	cnt;
	char	**dst;

	if (!s)
		return (NULL);
	cnt = ft_strcnt(s, c);
	if (!(dst = (char **)malloc(sizeof(char*) * (cnt + 1))))
		return (NULL);
	dst[cnt] = NULL;
	if (cnt == 0)
		return (dst);
	return (ft_splinter(dst, s, c, cnt));
}
