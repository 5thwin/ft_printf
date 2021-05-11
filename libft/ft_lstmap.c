/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:25:48 by seunoh            #+#    #+#             */
/*   Updated: 2021/02/17 15:25:48 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dst;
	t_list	*new;

	if (lst == NULL || f == NULL)
		return (NULL);
	dst = NULL;
	while (lst)
	{
		if (!(new = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&dst, del);
			return (NULL);
		}
		ft_lstadd_back(&dst, new);
		new = new->next;
		lst = lst->next;
	}
	return (dst);
}
