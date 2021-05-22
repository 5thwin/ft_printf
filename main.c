/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:25:07 by seunoh            #+#    #+#             */
/*   Updated: 2021/05/22 13:43:31 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include <stdio.h>

int	main()
{
	int	a = -2;
	int	b = -2;
	int	l = 0;
	ft_printf("%*.*d\n", a, b, l);
	ft_printf("%*.*d, %*.*d\n", a, b, l, a, b, l);
	ft_printf("%*.*d, %*.*d, %*.*d\n", a, b, l, a, b, l, a, b, l);
	//ft_printf("%*.*d, %*.*d, %*.*d, %*.*d\n", a, b, l, a, b, l, a, b, l, a, b, l);
	//ft_printf("%*.*d, %*.*d, %*.*d, %*.*d %*.*d\n", a, b, l, a, b, l, a, b, l, a, b, l, a, b, l);
	return (0);
}
