/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:20:47 by nbuquet-          #+#    #+#             */
/*   Updated: 2024/12/13 22:46:17 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operation_rarrb(t_node *na, t_node *nb, t_stack *sa, t_stack *sb)
{
	while (sa->top != na)
	{
		rotate(sa);
		write_op("ra\n");
	}
	while (sb->top != nb)
	{
		rotate_reverse(sb);
		write_op("rrb\n");
	}
	if (push(sa, sb) == -1)
		return (-1);
	write_op("pb\n");
	return (0);
}

int	operation_rrarb(t_node *na, t_node *nb, t_stack *sa, t_stack *sb)
{
	while (sa->top != na)
	{
		rotate_reverse(sa);
		write_op("rra\n");
	}
	while (sb->top != nb)
	{
		rotate(sb);
		write_op("rb\n");
	}
	if (push(sa, sb) == -1)
		return (-1);
	write_op("pb\n");
	return (0);
}
