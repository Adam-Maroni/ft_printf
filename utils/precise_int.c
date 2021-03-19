/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:15:39 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/19 15:47:39 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char *precise_int(t_flags *flags, char *str)
{
	char *rt;
	char *tmp;
	int width;
	int precision;

	width = flags->width;
	precision = flags->precision;

	if (precision > width)
		return (zero_pad_int(str, precision, flags->minus));
	else
	{
		rt = (char*)ft_calloc(width + precision + ft_strlen(str) + 1, sizeof(char));
		if (flags->minus)
		{
			tmp = zero_pad_int(str, precision, 0);
			ft_strlcat(rt, tmp, ft_strlen(tmp) + ft_strlen(rt) + 1);
			while (width > (int)ft_strlen(rt))
				ft_strlcat(rt, " ", ft_strlen(rt) + 2);
		}
		else
		{
			tmp = zero_pad_int(str, precision, 0);
			while (width-- > (int)ft_strlen(tmp))
				ft_strlcat(rt, " ", ft_strlen(rt) + 2);
			ft_strlcat(rt, tmp, ft_strlen(tmp) + ft_strlen(rt) + 1);
		}
		free(tmp);
	}
	return (rt);
}
