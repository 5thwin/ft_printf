/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:20:43 by seunoh            #+#    #+#             */
/*   Updated: 2021/05/14 16:26:37 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_t_flags_initialize(t_flags *flags)
{
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->nbrbase = 10;
	flags->nbrsign = 0;
	flags->precision = -1;
	flags->type = 0;
	flags->width = 0;
}

void	invalid_flag_ignore(t_flags *flags)
{
	if (flags->minus == 1)
		flags->zero = 0;
}

int		flag_classifier(char c, t_flags *flags)
{
	if (c == '+')
	{
		flags->plus = 1;
		return (1);
	}
	else if (c == '-')
	{
		flags->minus = 1;
		return (1);
	}
	else if (c == '0')
	{
		flags->zero = 1;
		return (1);
	}
	else if (c == ' ')
	{
		flags->space = 1;
		return (1);
	}
	return (0);
}
