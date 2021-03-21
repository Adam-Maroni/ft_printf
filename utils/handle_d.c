/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 08:36:48 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/21 21:32:39 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_d(t_flags *flags, va_list args)
{
	int		printed;
	int		n;
	char	*str;
	char	*temp;

	n = va_arg(args, int);
	printed = 0;
	if (!flags->precision && !n && flags->dot)
		str = ft_strdup("");
	else
		str = ft_itoa(n);
	temp = str;
	str = (!flags->zero) ? precise_int(flags, str)
		: zero_pad_int(str, flags, flags->minus);
	free(temp);
	printed = ft_putstr_ret(str);
	free(str);
	return (printed);
}
