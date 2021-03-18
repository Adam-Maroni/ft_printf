/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:41:48 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/08 18:37:29 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*rt_pointer;
	size_t	i;

	i = 0;
	if ((rt_pointer = (void*)malloc(nmemb * size)) == NULL)
		return (NULL);
	ft_bzero(rt_pointer, nmemb * size);
	return (rt_pointer);
}
