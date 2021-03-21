/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:30:26 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/21 22:21:49 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*handle_s_width(int width, char *str, int minus)
{
	char *rt;

	rt = (char*)ft_calloc(width + ft_strlen(str) + 1, sizeof(char));
	if (!minus)
		while (width-- > (int)ft_strlen(str))
			ft_strlcat(rt, " ", ft_strlen(rt) + 2);
	ft_strlcat(rt, str, ft_strlen(rt) + ft_strlen(str) + 1);
	if (minus)
		while (width > (int)ft_strlen(rt))
			ft_strlcat(rt, " ", ft_strlen(rt) + 2);
	return (rt);
}

char	*handle_s_precision(int precision, char *str, int dot)
{
	char	*rt;
	int		i;

	if (precision < (int)ft_strlen(str) && dot)
	{
		i = -1;
		rt = (char*)ft_calloc(ft_strlen(str) + 1, sizeof(char));
		while (++i < precision)
			rt[i] = str[i];
	}
	else
		rt = ft_strdup(str);
	return (rt);
}

int		handle_s(va_list args, t_flags *flags)
{
	char	*rt;
	char	*tmp;
	char	*tmp2;
	int		i;

	tmp = (va_arg(args, char*));
	tmp2 = handle_s_precision(flags->precision, tmp, flags->dot);
	rt = handle_s_width(flags->width, tmp2, flags->minus);
	free(tmp2);
	i = ft_putstr_ret(rt);
	free(rt);
	return (i);
}
