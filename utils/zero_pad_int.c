/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_pad_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:04:42 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/19 16:22:49 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char *zero_pad_int(char *str, int padding, int minus)
{
	char	*rt;
	char	*tmp;

	tmp = str;
	rt = (char*)ft_calloc(padding + ft_strlen(tmp) + 1, sizeof(char));

	if (ft_issign(*tmp))
	{
		rt[0] = *tmp++;
		if (!minus)
			padding--;
	}
	if (!minus)
		while (padding-- > (int)ft_strlen(tmp))
			ft_strlcat(rt, "0", ft_strlen(rt) + 2);
	ft_strlcat(rt, tmp, ft_strlen(rt) + ft_strlen(tmp) + 1);
	if (minus)
		while (padding > (int)ft_strlen(rt))
			ft_strlcat(rt, " ", ft_strlen(rt) + 2);
	return (rt);
}
