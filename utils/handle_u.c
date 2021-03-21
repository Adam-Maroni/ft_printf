/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:43:21 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/21 22:13:44 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_u(va_list args, t_flags *flags)
{
	char			*rt;
	char			*tmp;
	unsigned	int	i;

	i = va_arg(args, unsigned int);
	if (!flags->precision && !i && flags->dot)
		tmp = ft_strdup("");
	else
		tmp = ft_uitoa(i);
	rt = (!flags->zero) ? precise_int(flags, tmp)
		: zero_pad_int(tmp, flags, flags->minus);
	free(tmp);
	i = ft_putstr_ret(rt);
	free(rt);
	return ((int)i);
}
