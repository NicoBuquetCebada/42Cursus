/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:53:12 by nico              #+#    #+#             */
/*   Updated: 2024/10/05 14:58:48 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexpnbr(unsigned long long n, int *cs)
{
	char	r;

	r = (n % 16);
	if (r < 10)
		r += '0';
	else
		r += 'a' - 10;
	if (!n)
	{
		write(1, "(nil)", 5);
		(*cs) += 5;
		return ;
	}
	if (n > 0 && n < 16)
	{
		write(1, "0x", 2);
		write(1, &r, 1);
		(*cs) += 3;
		return ;
	}
	ft_puthexpnbr(n / 16, cs);
	(*cs)++;
	write(1, &r, 1);
}

void	ft_recursivehexwrite(unsigned int n, int *cs)
{
	char	r;

	if (n == 0)
		return ;
	ft_recursivehexwrite(n / 16, cs);
	r = (n % 16);
	if (r < 10)
		r += '0';
	else
		r += 'a' - 10;
	write(1, &r, 1);
	(*cs)++;
}

void	ft_puthexnbr(unsigned int n, int *cs)
{
	if (n == 0)
	{
		write(1, "0", 1);
		(*cs)++;
	}
	else
		ft_recursivehexwrite(n, cs);
}

void	ft_recursivehexuwrite(unsigned int n, int *cs)
{
	char	r;

	if (n == 0)
		return ;
	ft_recursivehexuwrite(n / 16, cs);
	r = (n % 16);
	if (r < 10)
		r += '0';
	else
		r += 'A' - 10;
	write(1, &r, 1);
	(*cs)++;
}

void	ft_puthexunbr(unsigned int n, int *cs)
{
	if (n == 0)
	{
		write(1, "0", 1);
		(*cs)++;
	}
	else
		ft_recursivehexuwrite(n, cs);
}
