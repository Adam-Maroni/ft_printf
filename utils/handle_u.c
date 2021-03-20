/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:43:21 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/20 17:17:06 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		handle_u(va_list args)
{
	int	i;
	char	*str;
	str = ft_uitoa(va_arg(args, unsigned int));
	i = ft_putstr_ret(str);
	free(str);
	return (i);
}
