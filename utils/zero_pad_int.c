/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_pad_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:04:42 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/21 22:02:31 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*zero_pad_int(char *str, t_flags *flags, int minus)
{
	char	*rt;
	char	*tmp;
	int		padding;

	if (minus || flags->precision || flags->dot)
		return (precise_int(flags, str));
	tmp = str;
	if (flags->precision >= flags->width)
		padding = flags->precision;
	else
		padding = flags->width;
	rt = (char*)ft_calloc(padding + ft_strlen(tmp) + 1, sizeof(char));
	if (ft_issign(*tmp))
	{
		rt[0] = *tmp++;
		padding--;
	}
	while (padding-- > (int)ft_strlen(tmp))
		ft_strlcat(rt, "0", ft_strlen(rt) + 2);
	ft_strlcat(rt, tmp, ft_strlen(rt) + ft_strlen(tmp) + 1);
	return (rt);
}
