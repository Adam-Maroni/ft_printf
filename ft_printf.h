/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:02:23 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/20 18:16:36 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct s_flags
{
	int minus;
	int dot;
	int zero;
	int star;
	int width;
	int precision;
	int n_precision;
	int done;
	int percent;
	int c;
	int d;
	int s;
	int u;
	int x;
	int X;
	int p;
}	t_flags;

int			handle_flags(va_list args, char *string, int i, t_flags *flags);
int			fill_flags(int *rt, va_list args, char *string, int i, t_flags *flags);
int			read_str(char *string, va_list args);
int			ft_printf(const char *input, ...);
void			init_flags(t_flags *flags);;
int				handle_flags(va_list args, char *string, int i, t_flags *flags);;
int			fill_flags(int *rt, va_list args, char *string, int i, t_flags *flags);;
int			read_str(char *string, va_list args);;
int			ft_printf(const char *input, ...);;
int	handle_percent(char *string, int i);;
int	handle_c(va_list args);;
int main(void);
void	handle_convertor(t_flags *flags, char c);
int handle_d(t_flags *flags, va_list args);
char conversion_hex_table(unsigned long input, char c);
char *int2hexstring(unsigned long input, char c, size_t size);
int	handle_x(va_list args, t_flags *flags);
int	handle_X(va_list args, t_flags *flags);
char			ull_conversion_hex_table(unsigned long long input, char c);
char			*ulltohexstring(unsigned long long input, char c, size_t size);
int	handle_p(va_list args);
int	handle_percent(char *string, int i);
int	handle_s(va_list args, t_flags *flags);
int		handle_u(va_list args);
char *precise_int(t_flags *flags, char *str);
char *zero_pad_int(char *str, t_flags *flags, int minus);
int	is_convertor(char c);
int	handle_width(t_flags *flags, va_list args, char *input);
int	handle_precision(va_list args, char *input, t_flags *flags);
#endif
