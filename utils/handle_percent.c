/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:15:33 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/26 08:10:33 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_percent(t_flags *flags)
{
	flags->percent++;
	flags->done++;
}

int		handle_percent_string(t_flags *flags)
{
	char	*tmp;
	int		rt;

	tmp = (!flags->zero) ? precise_int(flags, "%")
		: zero_pad_int("%", flags, flags->minus);
	rt = ft_putstr_ret(tmp);
	free(tmp);
	return (rt);
}
