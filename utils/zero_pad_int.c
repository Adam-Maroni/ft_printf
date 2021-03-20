/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_pad_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:04:42 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/20 09:27:30 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char *zero_pad_int(char *str, t_flags *flags, int minus)
{
	char	*rt;
	char	*tmp;
	int	padding;

	if (minus)
		return (precise_int(flags, str));
	tmp = str;
	(flags->precision >= flags->width) ? (padding = flags->precision) : (padding = flags->width);
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
