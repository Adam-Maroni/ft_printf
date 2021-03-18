/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_pad_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:04:42 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/18 13:54:12 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char *zero_pad_int(t_flags *flags, char *str)
{
	int		width;
	char	*rt;

	width = flags->width;
	rt = (char*)ft_calloc(width + ft_strlen(str) + 1, sizeof(char));
	while (width-- > (int)ft_strlen(str))
		ft_strlcat(rt, "0", ft_strlen(rt) + 2);
	ft_strlcat(rt, str, ft_strlen(rt) + ft_strlen(str) + 1);
	return (rt);
}
