/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:25:07 by seunoh            #+#    #+#             */
/*   Updated: 2021/05/18 13:11:38 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include <stdio.h>

int	main()
{
	int nbr;

	ft_printf("% 5d\n", 5);
	printf("% 5d\n",5);
	ft_printf("% 05d\n", 5);
	printf("% 05d\n",5);
	ft_printf("% 5d\n", 12345);
	printf("% 5d\n",12345);
	ft_printf("% 05d\n", 12345);
	printf("% 05d\n",12345);
	return (0);
}
