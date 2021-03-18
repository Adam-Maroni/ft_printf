/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa_conversions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:09:00 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/18 13:45:17 by amaroni          ###   ########.fr       */
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

int	handle_x(va_list args)
{
	char *str;
	int n;
	
	str = (int2hexstring((unsigned long)va_arg(args, unsigned int), 'x', 8));
	n = ft_putstr_ret(str);
	return(n);
	
}

int	handle_X(va_list args)
{
	char *str;
	int n;
	
	str = (int2hexstring((unsigned long)va_arg(args, unsigned int), 'X', 8));
	n = ft_putstr_ret(str);
	return(n);
}
