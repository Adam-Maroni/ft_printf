/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:29:42 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/04 11:17:39 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void *src, int n)
{
	int i;

	i = 0;
	if ((dest) || (src))
		while (i < n)
		{
			*((char*)dest + i) = *((char*)src + i);
			i++;
		}
	return (dest);
}
