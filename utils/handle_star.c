/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_star.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:22:34 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/22 10:27:23 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_star(t_flags *flags, va_list args)
{
	if (flags->dot)
		flags->precision = handle_precision(args, NULL, flags);
	else
		flags->width = handle_width(flags, args, NULL);
}
