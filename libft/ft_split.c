/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:00:28 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/17 11:13:40 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_words(char *s, char c)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			y++;
		i++;
	}
	return (y);
}

static void			array_with_0(char **scp, char c)
{
	size_t i;
	size_t len;

	len = ft_strlen(*scp);
	i = 0;
	while (i < len)
	{
		if ((*scp)[i] == c)
			(*scp)[i] = '\0';
		i++;
	}
}

static void			free_mem(void *start, void *end)
{
	while (start < end)
	{
		free(start);
		start++;
	}
}

static int			split_the_copy(size_t len, char ***p_rt, char **p_scp)
{
	size_t	i;
	int		y;
	char	*ele;

	i = 0;
	y = 0;
	while (i < len)
	{
		ele = &((*p_scp)[i]);
		if (*ele)
		{
			if (!((*p_rt)[y] = (char*)ft_calloc(ft_strlen(ele) + 1
							, sizeof(*(*p_rt)[y]))))
			{
				free_mem(&((*p_rt)[0]), &((*p_rt)[y]));
				return (0);
			}
			ft_strlcpy((*p_rt)[y], ele, ft_strlen(ele) + 2);
			y++;
			i += ft_strlen(ele) - 1;
		}
		i++;
	}
	(*p_rt)[y] = NULL;
	return (1);
}

char				**ft_split(char *s, char c)
{
	char	**rt;
	size_t	len;
	char	*scp;

	if (!s)
		return (NULL);
	if (!(rt = (char**)ft_calloc(count_words(s, c) + 1, sizeof(*rt)))
			|| !(scp = ft_strdup(s)))
		return (NULL);
	len = ft_strlen(scp);
	array_with_0(&scp, c);
	if (!(split_the_copy(len, &rt, &scp)))
		return (NULL);
	free(scp);
	return (rt);
}
