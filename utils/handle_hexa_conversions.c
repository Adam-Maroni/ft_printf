/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa_conversions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:09:00 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/20 18:26:46 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char conversion_hex_table(unsigned long input, char c)
{
    if (input > 9 && c == 'x')
        return ('a' + (input - 10));
    if (input > 9 && c == 'X')
        return ('A' + (input - 10));
    return ('0' + input);
}

char *int2hexstring(unsigned long input, char c, size_t size)
{
    char *str;
    char *output;
    int i;
    int y;

    if (!input)
	    return (ft_strdup("0"));
    i = 0;
    str = (char*)ft_calloc(size, sizeof(*str));
    while (input)
    {
	    str[i] = conversion_hex_table(input % 16, c);
	    i++;
	    input /= 16;
    }
    i = ft_strlen(str);
    y = 0;
    output = ft_strdup(str);
    while (i-- > 0)
    {
        output[y] = str[i];
        y++;
    }
    free (str);
    return (output);
}


char		*handle_x_width(int width, char *str, int minus)
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

char		*handle_x_precision(int precision, char *str, int dot)
{
	char	*rt;

	rt = (char*)ft_calloc(precision + ft_strlen(str) + 1, sizeof(char));
	if (precision > (int)ft_strlen(str) && dot)
		while (precision-- > (int)ft_strlen(str))
			ft_strlcat(rt, "0", ft_strlen(rt) + 2);
	ft_strlcat(rt, str, ft_strlen(rt) + ft_strlen(str) + 1);
	return (rt);
}

int	handle_x(va_list args, t_flags *flags)
{
	char	*rt;
	char	*tmp;
	char	*tmp2;
	int	i;

	tmp = (int2hexstring((unsigned long)va_arg(args, unsigned int), 'x', 8));
	tmp2 = handle_x_precision(flags->precision, tmp, flags->dot);
	rt = handle_x_width(flags->width, tmp2, flags->minus);

	free(tmp);
	free(tmp2);
	i = ft_putstr_ret(rt);
	free(rt);
	return(i);
}

int	handle_X(va_list args, t_flags *flags)
{
	char	*rt;
	char	*tmp;
	char	*tmp2;
	int	i;

	tmp = (int2hexstring((unsigned long)va_arg(args, unsigned int), 'X', 8));
	tmp2 = handle_x_precision(flags->precision, tmp, flags->dot);
	rt = handle_x_width(flags->width, tmp2, flags->minus);

	free(tmp);
	free(tmp2);
	i = ft_putstr_ret(rt);
	free(rt);
	return(i);
}
