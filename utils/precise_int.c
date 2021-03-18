/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:15:39 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/18 12:15:54 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char *precise_int(t_flags *flags, char *str)
{
	char *rt;
	char *tmp;
	int width;
	int precision;

	tmp = str;
	width = flags->width;
	precision = flags->precision;
	rt = (char*)ft_calloc(width + precision + ft_strlen(tmp) + 1, sizeof(char));

	if (ft_issign(*tmp))
	{
		rt[0] = *tmp;
		tmp++;
	}
	if (!flags->minus && !flags->zero)
		;	


	return (ft_strdup (""));
}