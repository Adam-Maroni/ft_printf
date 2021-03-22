/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 08:22:43 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/22 08:35:06 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_digit(t_flags *flags, va_list args, char *string)
{
	int	i;

	if (!flags->dot)
		flags->width = handle_width(flags, args, string);
	else
		flags->precision = handle_precision(args, string, flags);
	i = 0;
	while (ft_isdigit(string[i + 1]))
		i++;
	return (i);
}
