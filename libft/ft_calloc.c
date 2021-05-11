/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 18:58:42 by seunoh            #+#    #+#             */
/*   Updated: 2021/05/06 13:00:57 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	char	*ptr;

	if (!(ptr = malloc(number * size)))
		return (NULL);
	ft_memset(ptr, 0, number * size);
	return (ptr);
}
