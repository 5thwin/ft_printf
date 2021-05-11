/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:09:02 by seunoh            #+#    #+#             */
/*   Updated: 2021/05/10 22:31:08 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>
# define TYPE_DIC "csdiupxXnfge%\0"

typedef struct	s_flags
{
	int		plus;
	int		minus;
	int		zero;
	int		space;
	int		width;
	int		precision;
	char	type;
	int		nbrbase;
	int		nbrsign;
}				t_flags;

/*
******************  <ft_printf.c>  ******************
*/
int				ft_printf(const char *format, ...);
/*
******************  <ft_print_nbr.c>  ******************
*/
int				print_nbr(t_flags *flags, va_list ap);
/*
******************  <ft_print_str.c>  ******************
*/
int				print_s(t_flags *flags, va_list ap);
void			fill_space(char **space, t_flags *flags, int len);
/*
******************  <ft_flags.c>  ******************
*/
void			ft_t_flags_initialize(t_flags *flags);
int				flag_classifier(char c, t_flags *flags);
/*
******************  <ft_width.c>  ******************
*/
int				set_width(const char *format, t_flags *flags,
							va_list ap, int *i);

/*
******************  <ft_precision.c>  ******************
*/
int				set_precision(const char *format, t_flags *flags,
								va_list ap, int *i);

/*
******************  <utils_base.c>  ******************
*/
int				ft_max_int(int a, int b);
char			*ft_baseset(char type);

/*
******************  <utils_join_buf.c>  ******************
*/
int				join_width_buf(char **buf, t_flags *flags);
int				join_hex_sign(char **buf, t_flags *flags, int *buflen);
int				join_minus_nozero(char **buf, t_flags *flags, int *buflen);
int				join_minus_zero(char **buf, t_flags *flags, int *buflen);
#endif
