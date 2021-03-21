/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:44:16 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/21 10:31:40 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char			ull_conversion_hex_table(unsigned long input, char c)
{
    if (input > 9 && c == 'x')
        return ('a' + (input - 10));
    if (input > 9 && c == 'X')
        return ('A' + (input - 10));
    return ('0' + input);
}

char			*ulltohexstring(unsigned long input, char c, size_t size)
{
    char *str;
    char *output;
    int i;
    int y;

    i = 0;
    str = (char*)ft_calloc(size, sizeof(*str));
    while (input % 16 > 0)
    {
	    str[i] = ull_conversion_hex_table(input % 16, c);
	    input /= 16;
	    i++;
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

int	handle_p(va_list args)
{
	size_t			size;
	char			*gen_str;
	char			*tmp;
	unsigned long		i;
	
	size = 16;
	i = (unsigned long)(va_arg(args, void *));
	
	
	gen_str = "0x";
	tmp = ulltohexstring(i, 'x', size);
	i = ft_putstr_ret(gen_str) + ft_putstr_ret(tmp);
	free(tmp);
	return (i);
}
