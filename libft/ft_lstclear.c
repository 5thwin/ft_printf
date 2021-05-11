/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:56:46 by seunoh            #+#    #+#             */
/*   Updated: 2021/02/17 17:13:09 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*target;

	if (!lst || !del)
		return ;
	target = *lst;
	while (target != NULL)
	{
		tmp = target->next;
		ft_lstdelone(target, del);
		target = tmp;
	}
	*lst = NULL;
}
