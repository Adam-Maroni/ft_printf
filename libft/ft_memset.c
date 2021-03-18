/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:13:56 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/04 13:07:46 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		*((unsigned char*)(s + i)) = (unsigned char)c;
		i++;
	}
	return (s);
}
