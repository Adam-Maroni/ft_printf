/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:43:21 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/20 20:39:24 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*handle_u_width(int width, char *str, int minus)
{
	char *rt;

	rt = (char*)ft_calloc(width + ft_strlen(str) + 1, sizeof(char));

	if(!minus)
		while (width-- > (int)ft_strlen(str))
			ft_strlcat(rt, " ", ft_strlen(rt) + 2);
	ft_strlcat(rt, str, ft_strlen(rt) + ft_strlen(str) + 1);
	if (minus)
		while (width > (int)ft_strlen(rt))
			ft_strlcat(rt, " ", ft_strlen(rt) + 2);
	return (rt);
}

char		*handle_u_precision(int precision, char *str, int dot)
{
	char	*rt;

	rt = (char*)ft_calloc(precision + ft_strlen(str) + 1, sizeof(char));
	if (precision > (int)ft_strlen(str) && dot)
		while (precision-- > (int)ft_strlen(str))
			ft_strlcat(rt, "0", ft_strlen(rt) + 2);
	ft_strlcat(rt, str, ft_strlen(rt) + ft_strlen(str) + 1);
	return (rt);
}

int		handle_u(va_list args, t_flags *flags)
{
	char	*rt;
	char	*tmp;
	char	*tmp2;
	unsigned int	i;

	i = va_arg(args, unsigned int);
	if (!flags->precision && !i && flags->dot)
		tmp = ft_strdup("");
	else  
		tmp = ft_uitoa(i);
	tmp2 = handle_u_precision(flags->precision, tmp, flags->dot);
	rt = handle_u_width(flags->width, tmp2, flags->minus);
	free(tmp);
	free(tmp2);
	i = ft_putstr_ret(rt);
	free(rt);
	return ((int)i);
}
