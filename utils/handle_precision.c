/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:59:47 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/20 10:51:17 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_precision(va_list args, char *input, t_flags *flags)
{
	int rt;

	if (input)
		rt = ft_atoi(input);
	else
		rt = va_arg(args, int);
	if (rt < 0)
	{
		rt = 0;
		flags->dot = 0;
	}
	return (rt);
}
