/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 09:55:18 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/17 11:22:32 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*rt;

	i = 0;
	if (!s)
		return (NULL);
	if ((rt = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))) == NULL)
		return (NULL);
	while (s[i])
	{
		rt[i] = f(i, s[i]);
		i++;
	}
	rt[i] = '\0';
	return (rt);
}
