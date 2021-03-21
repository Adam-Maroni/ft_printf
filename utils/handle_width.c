/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:59:47 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/21 22:05:11 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_width(t_flags *flags, va_list args, char *input)
{
	int rt;

	if (input)
		rt = ft_atoi(input);
	else
		rt = va_arg(args, int);
	if (rt < 0)
	{
		rt = -rt;
		flags->minus = 1;
	}
	return (rt);
}
