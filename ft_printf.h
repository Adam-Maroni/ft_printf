/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:02:23 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/26 08:08:06 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_flags
{
	int minus;
	int dot;
	int zero;
	int width;
	int precision;
	int done;
	int space;
	int percent;
	int c;
	int d;
	int s;
	int u;
	int x;
	int x_maj;
	int p;
}					t_flags;
void				handle_star(t_flags *flags, va_list args);
void				init_flags(t_flags *flags);
void				handle_convertor(t_flags *flags, char c);
void				handle_percent(t_flags *flags);
void				fill_flags(int *rt, va_list args,
		char **string, t_flags *flags);
int					handle_percent_string(t_flags *flags);
int					handle_flags(va_list args, t_flags *flags);
int					read_str(char *string, va_list args);
int					ft_printf(const char *input, ...);
int					read_str(char *string, va_list args);
int					ft_printf(const char *input, ...);
int					handle_c(va_list args, t_flags *flags);
int					handle_d(t_flags *flags, va_list args);
int					handle_x(va_list args, t_flags *flags);
int					handle_x_maj(va_list args, t_flags *flags);
int					handle_p(va_list args, t_flags *flags);
int					handle_s(va_list args, t_flags *flags);
int					handle_u(va_list args, t_flags *flags);
int					is_convertor(char c);
int					handle_width(t_flags *flags, va_list args, char *input);
int					handle_precision(va_list args, char *input, t_flags *flags);
int					handle_digit(t_flags *flags, va_list args, char *string);
char				conversion_hex_table(unsigned long input, char c);
char				*int2hexstring(unsigned long input, char c, size_t size);
char				*p_int1(char *str, int padding, int minus, int space);
char				*precise_int(t_flags *flags, char *str);
char				*p_int2(char *str, int padding);
char				*zero_pad_int(char *str, t_flags *flags, int minus);
#endif
