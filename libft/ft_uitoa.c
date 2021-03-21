/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 08:01:16 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/21 20:47:32 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_digit(unsigned int n)
{
	int	cp;

	cp = 1;
	while ((n /= 10) > 0)
		cp++;
	return (cp);
}

static void		add_element(char *array, int i, int start, unsigned int n)
{
	array[i] = '\0';
	while (--i >= start)
	{
		array[i] = '0' + (char)(n % 10);
		n /= 10;
	}
}

char			*ft_uitoa(unsigned int n)
{
	char	*array;

	if (n == 0)
		return (ft_strdup("0"));
	else
	{
		if (!(array = (char*)malloc((count_digit((unsigned int)(n)) + 1)
						* sizeof(*array))))
			return (NULL);
		add_element(array, count_digit((unsigned int)(n)),
				0, (unsigned int)(n));
	}
	return (array);
}
