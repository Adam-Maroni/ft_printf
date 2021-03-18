/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_convertor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 13:30:24 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/13 13:44:26 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_convertor(t_flags *flags, char c)
{
	if (c == 'c')
		flags->c++;
	if (c == 's')
		flags->s++;
	if (c == 'd' || c == 'i')
		flags->d++;
	if (c == 'x')
		flags->x++;
	if (c == 'X')
		flags->X++;
	if (c == 'u')
		flags->u++;
	if (c == 'p')
		flags->p++;
}
