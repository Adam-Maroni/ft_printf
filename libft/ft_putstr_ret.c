/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 08:26:12 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/22 14:29:52 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_ret(const char *string)
{
	size_t ret;

	if (!string)
		return (0);
	ret = ft_strlen(string);
	ft_putstr(string);
	return (ret);
}
