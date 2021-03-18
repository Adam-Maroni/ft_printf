/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 19:15:52 by amaroni           #+#    #+#             */
/*   Updated: 2021/01/04 19:32:34 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		y;
	char	*p;

	i = 0;
	p = 0;
	if (little[i] == '\0')
		return ((char *)(big));
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			p = (char *)(big + i);
			y = 0;
			while (big[i + y] == little[y] && i + y < len)
			{
				if (little[y + 1] == '\0')
					return (p);
				y++;
			}
			p = 0;
		}
		i++;
	}
	return (NULL);
}
