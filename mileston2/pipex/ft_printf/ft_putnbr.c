/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:49:09 by nico              #+#    #+#             */
/*   Updated: 2024/10/04 20:35:26 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_recursivewrite(int n, int *cs)
{
	char	r;

	if (n == 0)
		return ;
	ft_recursivewrite(n / 10, cs);
	r = (n % 10) + '0';
	write(1, &r, 1);
	(*cs)++;
}

void	ft_putnbr(int n, int *cs)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*cs) += 11;
	}
	else if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		(*cs)++;
		ft_recursivewrite(n, cs);
	}
	else if (n == 0)
	{
		write(1, "0", 1);
		(*cs)++;
	}
	else
		ft_recursivewrite(n, cs);
}
