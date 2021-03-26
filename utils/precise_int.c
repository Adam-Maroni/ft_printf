/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:15:39 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/26 11:12:37 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*p_int2(char *str, int padding)
{
	char	*rt;
	char	*tmp;

	tmp = str;
	if (!(rt = (char*)ft_calloc(padding + ft_strlen(tmp) + 1, sizeof(char))))
		return (NULL);
	if (ft_issign(*tmp))
		rt[0] = *tmp++;
	while (padding-- > (int)ft_strlen(tmp))
		ft_strlcat(rt, "0", ft_strlen(rt) + 2);
	ft_strlcat(rt, tmp, ft_strlen(rt) + ft_strlen(tmp) + 1);
	return (rt);
}

char	*p_int1(char *str, int padding, int minus, int space)
{
	char	*rt;
	char	*tmp;

	tmp = str;
	if (!(rt = (char*)ft_calloc(padding + ft_strlen(tmp) + 2, sizeof(char))))
		return (NULL);
	if (ft_issign(*tmp))
		rt[0] = *tmp++;
	if (space)
		ft_strlcat(rt, " ", ft_strlen(rt) + 2);
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
		return (p_int2(str, flags->precision));
	else if (flags->precision > flags->width)
		return (p_int1(str, flags->precision, flags->minus, flags->space));
	tmp = p_int1(str, flags->precision, 0, flags->space);
	if (flags->minus)
		rt = p_int1(tmp, flags->width, flags->minus, flags->space);
	else
	{
		if (!(rt = (char*)ft_calloc(flags->width + ft_strlen(tmp) + 1,
						sizeof(char))))
			return (NULL);
		while (flags->width-- > (int)ft_strlen(tmp))
			ft_strlcat(rt, " ", ft_strlen(rt) + 2);
		ft_strlcat(rt, tmp, ft_strlen(tmp) + ft_strlen(rt) + 1);
	}
	free(tmp);
	return (rt);
}
