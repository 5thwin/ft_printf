/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 18:49:49 by seunoh            #+#    #+#             */
/*   Updated: 2021/02/05 18:49:49 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		tmp;
	char	*str;

	tmp = ft_strlen(s);
	if (!(str = malloc(sizeof(char) * (tmp + 1))))
		return (NULL);
	tmp = 0;
	while (*s)
		str[tmp++] = *s++;
	str[tmp] = '\0';
	return (str);
}
