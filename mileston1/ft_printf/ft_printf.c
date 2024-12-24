/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:44:56 by nico              #+#    #+#             */
/*   Updated: 2024/10/05 15:01:11 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_side(char c, va_list args, int *cs)
{
	if (c == 'c')
	{
		ft_putchar((char)va_arg(args, int));
		(*cs)++;
	}
	else if (c == 's')
		ft_putstr(va_arg(args, char *), cs);
	else if (c == 'p')
		ft_puthexpnbr((unsigned long long)va_arg(args, void *), cs);
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(args, int), cs);
	else if (c == 'u')
		ft_putunbr(va_arg(args, unsigned int), cs);
	else if (c == 'x')
		ft_puthexnbr(va_arg(args, unsigned int), cs);
	else if (c == 'X')
		ft_puthexunbr(va_arg(args, unsigned int), cs);
	else if (c == '%')
	{
		ft_putchar('%');
		(*cs)++;
	}
}

int	ft_printf(char const *format, ...)
{
	va_list			args;
	int				cs;
	size_t			i;

	va_start(args, format);
	cs = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_side(format[i], args, &cs);
		}
		else
		{
			ft_putchar(format[i]);
			cs++;
		}
	}
	va_end(args);
	return (cs);
}
