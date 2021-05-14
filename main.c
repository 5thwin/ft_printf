/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:25:07 by seunoh            #+#    #+#             */
/*   Updated: 2021/05/14 16:51:25 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include <stdio.h>

int	main()
{
	int nbr;
	int	myret[10];
	int	stret[10];
	char a = 'k';

	nbr = -123456;
	myret[0] = ft_printf("||%-020.d||\n", nbr);
	stret[0] = printf("||%-020.d||\n", nbr);
	myret[1] = ft_printf("||%016s||\n", "hello world");
	stret[1] = printf("||%016s||\n", "hello world");
	myret[2] = ft_printf("%10c\n", a);
	stret[2] = printf("%10c\n", a);
	//myret[3] = ft_printf("%-5%\n");
	//stret[3] = printf("%-5%\n");
	//stret[4] = printf("%-5p\n", &a);
	//myret[4] = ft_printf("%-5p\n", &a);
	ft_printf("%d %d %d %d\n", myret[0], stret[0], myret[1], stret[1]);
	printf("%d %d %d %d %d %d\n", myret[0], stret[0], myret[1], stret[1], myret[2], stret[2]);
	ft_printf("%s %d %s %d %s %d\n", "1: ", 1, ", 2: ",2, " 3: ", 3);
	return (0);
}
