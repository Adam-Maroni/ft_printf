/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:02:23 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/18 10:43:45 by amaroni          ###   ########.fr       */
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

char *zero_pad_int(t_flags *flags, char *str);

#endif
