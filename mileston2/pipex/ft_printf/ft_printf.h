/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:40:18 by nico              #+#    #+#             */
/*   Updated: 2024/10/08 21:00:36 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *format, ...);
void	ft_putchar(char c);
void	ft_putstr(char *s, int *cs);
void	ft_putnbr(int n, int *cs);
void	ft_putunbr(unsigned int n, int *cs);
void	ft_puthexpnbr(unsigned long long n, int *cs);
void	ft_puthexnbr(unsigned int n, int *cs);
void	ft_puthexunbr(unsigned int n, int *cs);

#endif