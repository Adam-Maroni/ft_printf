/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 10:43:27 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/05 13:59:51 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, char *src, size_t size)
{
	unsigned long y;

	y = ft_strlen(src);
	if (size <= 0)
		return (y);
	while ((size-- > 1) && (*src))
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (y);
}
