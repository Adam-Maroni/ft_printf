/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:09:31 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/21 22:48:46 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->dot = 0;
	flags->zero = 0;
	flags->star = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->n_precision = 0;
	flags->percent = 0;
	flags->c = 0;
	flags->d = 0;
	flags->s = 0;
	flags->u = 0;
	flags->x = 0;
	flags->X = 0;
	flags->p = 0;
}

int				handle_flags(va_list args, t_flags *flags)
{
	if (flags->percent)
		return (handle_percent());
	if (flags->c)
		return (handle_c(args, flags));
	if (flags->d)
		return (handle_d(flags, args));
	if (flags->s)
		return (handle_s(args, flags));
	if (flags->u)
		return (handle_u(args, flags));
	if (flags->x)
		return (handle_x(args, flags));
	if (flags->X)
		return (handle_X(args, flags));
	if (flags->p)
		return (handle_p(args, flags));
	else
		return (0);
}

int			fill_flags(int *rt, va_list args, char *string, int i, t_flags *flags)
{
	int index;

	index = i;
	while (string[i] && !ft_isspace(string[i]))
	{
		if (string[i] == '%')
		{
			flags->percent++;
			i++;
			break ;
		}
		else if (string[i] == '-')
			flags->minus++;
		else if (string[i] == '0' && !flags->dot)
			flags->zero++;
		else if (string[i] == '*')
		{
			if (flags->dot)
				flags->precision = handle_precision(args, NULL, flags);
			else
				flags->width = handle_width(flags, args, NULL);
			flags->star++;
		}
		else if (string[i] == '.')
			flags->dot++;
		else if (ft_isdigit(string[i]))
		{
			if (!flags->dot)
				flags->width = handle_width(flags, args, (&(string[i])));
			else
				flags->precision = handle_precision(args, &(string[i]), flags);
			while (ft_isdigit(string[i + 1]))
				i++;
		}
		else if (is_convertor(string[i]))
		{
			handle_convertor(flags, string[i]);
			i++;
			break ;
		}
		i++;
	}
	*rt += handle_flags(args, flags);
	return (i);
}

int		read_str(char *string, va_list args)
{
	int		i;
	int		rt;
	t_flags	flags;

	i = 0;
	rt = 0;
	init_flags(&flags);
	while (string[i])
	{
		if (string[i] == '%' && string[i + 1])
		{
			i = fill_flags(&rt, args, string, i + 1, &flags);
			init_flags(&flags);
		}
		else
		{
			ft_putchar(string[i]);
			rt++;
			i++;
		}
	}
	return (rt);
}

int			ft_printf(const char *input, ...)
{
	va_list	args;
	char	*string;
	int		rt;

	rt = 0;
	string = ft_strdup((char*)input);
	va_start(args, input);
	rt += read_str(string, args);
	va_end(args);
	free(string);
	return (rt);
}
