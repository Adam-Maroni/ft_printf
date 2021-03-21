/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:44:16 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/21 15:52:03 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*handle_p_width(int width, char *str, int minus)
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

char		*handle_p_precision(int precision, char *str)
{
	char	*rt;

	rt = (char*)ft_calloc(precision + ft_strlen(str) + 1, sizeof(char));
	while (precision-- > (int)ft_strlen(str))
		ft_strlcat(rt, "0", ft_strlen(rt) + 2);
	ft_strlcat(rt, str, ft_strlen(rt) + ft_strlen(str) + 1);
	return (rt);
}

char		*add_0x(char *src)
{
	char *rt;

	rt = (char*)ft_calloc(ft_strlen(src) + 3, sizeof(char));
	ft_strlcat(rt, "0x", 3);
	ft_strlcat(rt, src, ft_strlen(src) + 3);
	free(src);
	return (rt);
}

int	handle_p(va_list args, t_flags *flags)
{
	unsigned long	i;
	char		*tmp;
	char		*tmp2;
	char		*tmp3;
	char		*rt;
	
	
	if (!(i = (unsigned long)va_arg(args, void*)))
		tmp = ft_strdup("(nil)");
	else
		tmp = int2hexstring(i, 'x', 32);

	tmp2 = (char*)ft_calloc(36, sizeof(char));
	ft_strlcat(tmp2, tmp, ft_strlen(tmp2) + ft_strlen(tmp) + 1);
	tmp3 = handle_p_precision(flags->precision, tmp2);
	if (i)
		tmp3 = add_0x(tmp3);
	rt = handle_p_width(flags->width, tmp3, flags->minus);


	i = ft_putstr_ret(rt);
	free(tmp);
	free(tmp2);
	free(tmp3);
	free(rt);
	return((int)i);
}
