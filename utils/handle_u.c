/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:43:21 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/20 18:35:22 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		handle_u(va_list args, t_flags *flags)
{
	int	i;
	char	*str;

	i = va_arg(args, unsigned int);
	if (!flags->precision && !i && flags->dot)
		str = ft_strdup("");
	else  
		str = ft_uitoa(i);

	i = ft_putstr_ret(str);
	free(str);
	return (i);
}
