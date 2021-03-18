/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:45:21 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/05 11:30:14 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && s1[i] && s2[i]
			&& (*(unsigned char*)(s1 + i) == *(unsigned char*)(s2 + i)))
		i++;
	if ((i >= n) || (!s1[i] && !s2[i]))
		return (0);
	else
		return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i));
}
