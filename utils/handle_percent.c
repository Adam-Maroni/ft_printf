/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:15:33 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/18 12:35:41 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_percent(char *string, int i)
{
	char	*str;
	int		y;

	y = i;
	str = NULL;
	while (string[y] && !ft_isspace(string[y]))
		y++;
	str = (char*)ft_calloc((y - i) + 1, sizeof(char));
	ft_strlcpy(str, &(string[i]), (y - i) + 1);
	y = ft_putstr_ret(str);
	return (y);
}
