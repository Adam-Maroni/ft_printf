/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:15:39 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/21 21:56:16 by amaroni          ###   ########.fr       */
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

	if (flags->precision > flags->width && flags->minus)
		return (precise_pad_int_minus(str, flags->precision));
	else if (flags->precision > flags->width)
		return (precise_pad_int(str, flags->precision, flags->minus));
	rt = (char*)ft_calloc(flags->width + flags->precision
			+ ft_strlen(str) + 1, sizeof(char));
	tmp = precise_pad_int(str, flags->precision, 0);
	if (flags->minus)
	{
		ft_strlcat(rt, tmp, ft_strlen(tmp) + ft_strlen(rt) + 1);
		while (flags->width > (int)ft_strlen(rt))
			ft_strlcat(rt, " ", ft_strlen(rt) + 2);
	}
	else
	{
		while (flags->width-- > (int)ft_strlen(tmp))
			ft_strlcat(rt, " ", ft_strlen(rt) + 2);
		ft_strlcat(rt, tmp, ft_strlen(tmp) + ft_strlen(rt) + 1);
	}
	free(tmp);
	return (rt);
}
