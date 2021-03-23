/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:32:10 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/23 10:55:54 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*handle_c_width(int width, int minus, char c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)ft_calloc(width + 2, sizeof(char));
	if (!minus)
		while (width-- > 1)
		{
			ft_strlcat(str, " ", ft_strlen(str) + 2);
			i++;
		}
	str[i] = c;
	if (minus)
		while (width > (int)ft_strlen(str))
			ft_strlcat(str, " ", ft_strlen(str) + 2);
	return (str);
}

int		handle_c(va_list args, t_flags *flags)
{
	char	c;
	char	*tmp;
	int		rt;

	rt = 0;
	c = (unsigned char)va_arg(args, int);
	if (!c)
	{
		if (flags->minus)
			rt += ft_putchar_ret((char)c);
		tmp = handle_c_width(flags->width - rt, flags->minus, '\0');
		rt += ft_putstr_ret(tmp);
		if (!flags->minus)
			rt += ft_putchar_ret((char)c);
	}
	else
	{
		tmp = handle_c_width(flags->width, flags->minus, c);
		rt += ft_putstr_ret(tmp);
	}
	free(tmp);
	return (rt);
}
