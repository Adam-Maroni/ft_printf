/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 08:36:48 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/18 10:13:59 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int handle_d(t_flags *flags, va_list args)
{
  int printed;
  char *str;
  char *temp;
  int n;
  n = va_arg(args, int);
  printed = 0;
  if (flags->preci == 0 && n == 0)
    str = ft_strdup("");
  else  
    str = ft_itoa(n);
// ICI SOIT TU precise_int() SOIT TU zero_pad_int() 
// PARCE QUE LA PRECISION EXCLUE LE FLAG 0
  temp = str;
  str = (flags->zero == 0) ? precise_int(str, flags) : zero_pad_int(flags, str);
  free(temp);
// ICI SOIT TU PAD AVANT (flags->minus == 0 && flags->zero == 0) 
  printed = ft_putstr_ret(str);
// SOIT TU PAD APRES (flags->minus == 1 && flags->zero == 0)
  free(str);
  return (printed); 
}
