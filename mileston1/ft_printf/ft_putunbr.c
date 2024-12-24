/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:53:23 by nico              #+#    #+#             */
/*   Updated: 2024/10/04 20:39:03 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_recursiveuwrite(unsigned int n, int *cs)
{
	char	r;

	if (n == 0)
		return ;
	ft_recursiveuwrite(n / 10, cs);
	r = (n % 10) + '0';
	write(1, &r, 1);
	(*cs)++;
}

void	ft_putunbr(unsigned int n, int *cs)
{
	if (n == 0)
	{
		write(1, "0", 1);
		(*cs)++;
	}
	else
		ft_recursiveuwrite(n, cs);
}
