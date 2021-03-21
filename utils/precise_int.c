/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:15:39 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/21 21:34:00 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*precise_pad_int_minus(char *str, int padding)
{
	char	*rt;
	char	*tmp;

	tmp = str;
	rt = (char*)ft_calloc(padding + ft_strlen(tmp) + 1, sizeof(char));
	if (ft_issign(*tmp))
		rt[0] = *tmp++;
	while (padding-- > (int)ft_strlen(tmp))
		ft_strlcat(rt, "0", ft_strlen(rt) + 2);
	ft_strlcat(rt, tmp, ft_strlen(rt) + ft_strlen(tmp) + 1);
	return (rt);
}

char	*precise_pad_int(char *str, int padding, int minus)
{
	char	*rt;
	char	*tmp;

	tmp = str;
	rt = (char*)ft_calloc(padding + ft_strlen(tmp) + 1, sizeof(char));

	if (ft_issign(*tmp))
		rt[0] = *tmp++;
	if (!minus)
		while (padding-- > (int)ft_strlen(tmp))
			ft_strlcat(rt, "0", ft_strlen(rt) + 2);
	ft_strlcat(rt, tmp, ft_strlen(rt) + ft_strlen(tmp) + 1);
	if (minus)
		while (padding > (int)ft_strlen(rt))
			ft_strlcat(rt, " ", ft_strlen(rt) + 2);
	return (rt);
}

char	*precise_int(t_flags *flags, char *str)
{
	char *rt;
	char *tmp;
	int width;
	int precision;

	width = flags->width;
	precision = flags->precision;
	if (precision > width && flags->minus)
		return (precise_pad_int_minus(str, precision));
	else if (precision > width)
		return (precise_pad_int(str, precision, flags->minus));
	else
	{
		rt = (char*)ft_calloc(width + precision + ft_strlen(str) + 1, sizeof(char));
		if (flags->minus)
		{
			tmp = precise_pad_int(str, precision, 0);
			ft_strlcat(rt, tmp, ft_strlen(tmp) + ft_strlen(rt) + 1);
			while (width > (int)ft_strlen(rt))
				ft_strlcat(rt, " ", ft_strlen(rt) + 2);
		}
		else
		{
			tmp = precise_pad_int(str, precision, 0);
			while (width-- > (int)ft_strlen(tmp))
				ft_strlcat(rt, " ", ft_strlen(rt) + 2);
			ft_strlcat(rt, tmp, ft_strlen(tmp) + ft_strlen(rt) + 1);
		}
		free(tmp);
	}
	return (rt);
}
