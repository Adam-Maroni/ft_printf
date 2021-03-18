/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 00:11:59 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/16 21:54:51 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	unsigned char	*c_s1;
	unsigned char	*c_s2;
	size_t			i;

	c_s1 = (unsigned char*)(s1);
	c_s2 = (unsigned char*)(s2);
	i = 0;
	while ((c_s1[i] == c_s2[i]) && (i < (n - 1)))
		i++;
	if (i >= n)
		return (0);
	else
		return ((int)(c_s1[i] - c_s2[i]));
}
