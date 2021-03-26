/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:30:26 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/26 10:41:40 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*handle_s_width(int width, char *str, int minus)
{
	char	*rt;
	char	*tmp;

	tmp = str;
	if (!tmp)
		if (!(tmp = (char*)ft_calloc(1, sizeof(char))))
			return (NULL);
	if (!(rt = (char*)ft_calloc(width + ft_strlen(tmp) + 1, sizeof(char))))
		return (NULL);
	if (!minus)
		while (width-- > (int)ft_strlen(tmp))
			ft_strlcat(rt, " ", ft_strlen(rt) + 2);
	ft_strlcat(rt, tmp, ft_strlen(rt) + ft_strlen(tmp) + 1);
	if (minus)
		while (width > (int)ft_strlen(rt))
			ft_strlcat(rt, " ", ft_strlen(rt) + 2);
	if (tmp != str)
		free(tmp);
	return (rt);
}

char	*handle_s_precision(int precision, char *str, int dot)
{
	char	*rt;
	int		i;

	if (!str)
		rt = NULL;
	else if (precision < (int)ft_strlen(str) && dot)
	{
		i = -1;
		if (!(rt = (char*)ft_calloc(ft_strlen(str) + 1, sizeof(char))))
			return (NULL);
		while (++i < precision)
			rt[i] = str[i];
	}
	else
		rt = ft_strdup(str);
	return (rt);
}

int		handle_s(va_list args, t_flags *flags)
{
	char	*rt;
	char	*tmp;
	char	*tmp2;
	int		i;

	tmp = ft_strdup(va_arg(args, char*));
	if (!tmp && (!flags->dot || flags->precision))
		tmp = ft_strdup("(null)");
	tmp2 = handle_s_precision(flags->precision, tmp, flags->dot);
	rt = handle_s_width(flags->width, tmp2, flags->minus);
	i = ft_putstr_ret(rt);
	free(tmp);
	free(tmp2);
	free(rt);
	return (i);
}
