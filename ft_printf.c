/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:09:31 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/23 11:16:58 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->dot = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->percent = 0;
	flags->done = 0;
	flags->space = 0;
	flags->c = 0;
	flags->d = 0;
	flags->s = 0;
	flags->u = 0;
	flags->x = 0;
	flags->x_maj = 0;
	flags->p = 0;
}

int		handle_flags(va_list args, t_flags *flags)
{
	if (flags->percent)
		return (ft_putstr_ret("%\0"));
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
	if (flags->x_maj)
		return (handle_x_maj(args, flags));
	if (flags->p)
		return (handle_p(args, flags));
	else
		return (0);
}

void	fill_flags(int *rt, va_list args, char **string, t_flags *flags)
{
	while (**string && !flags->done)
	{
		if (**string == '.')
			flags->dot++;
		else if (**string == '-')
			flags->minus++;
		else if (**string == '0' && !flags->dot)
			flags->zero++;
		else if (**string == '*')
			handle_star(flags, args);
		else if (ft_isdigit(**string))
			*string += handle_digit(flags, args, *string);
		else if (**string == '%')
			handle_percent(flags);
		else if (is_convertor(**string))
			handle_convertor(flags, **string);
		else if (ft_isspace(**string))
			flags->space++;
		(*string)++;
	}
	*rt += handle_flags(args, flags);
}

int		read_str(char *string, va_list args)
{
	int		rt;
	t_flags	flags;

	rt = 0;
	init_flags(&flags);
	while (*string)
		if (*string == '%' && *(string + 1))
		{
			string++;
			fill_flags(&rt, args, &string, &flags);
			init_flags(&flags);
		}
		else
		{
			ft_putchar(*string);
			rt++;
			string++;
		}
	return (rt);
}

int		ft_printf(const char *input, ...)
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
