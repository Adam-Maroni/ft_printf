/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:19:48 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/16 23:24:52 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	char	*lastd;
	char	*lasts;
	char	*s;
	char	*d;

	s = src;
	d = dest;
	lastd = d + (n - 1);
	lasts = s + (n - 1);
	if (!src && !dest)
		return (dest);
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
		while (n--)
			*lastd-- = *lasts--;
	return (dest);
}
