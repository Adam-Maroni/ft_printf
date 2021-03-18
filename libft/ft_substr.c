/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:38:13 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/17 11:04:58 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new_string;

	i = 0;
	if (!s)
		return (NULL);
	if (!(new_string = (char*)ft_calloc((len + 1), sizeof(char))))
		return (NULL);
	while ((len > 0) && (start < ft_strlen(s)))
	{
		new_string[i] = s[i + start];
		i++;
		len--;
	}
	return (new_string);
}
