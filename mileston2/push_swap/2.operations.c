/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:20:47 by nbuquet-          #+#    #+#             */
/*   Updated: 2024/12/13 22:47:33 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operation_rr_a(t_node *na, t_node *nb, t_stack *sa, t_stack *sb)
{
	int	r;
	int	rr;

	r = nodeposition(na, sa) - nodeposition(nb, sb);
	rr = nodeposition(na, sa) - r;
	while (rr > 0)
	{
		rotate(sa);
		rotate(sb);
		write_op("rr\n");
		rr--;
	}
	while (r > 0)
	{
		rotate(sa);
		write_op("ra\n");
		r--;
	}
	if (push(sa, sb) == -1)
		return (-1);
	write_op("pb\n");
	return (0);
}

int	operation_rr_b(t_node *na, t_node *nb, t_stack *sa, t_stack *sb)
{
	int	r;
	int	rr;

	r = nodeposition(nb, sb) - nodeposition(na, sa);
	rr = nodeposition(nb, sb) - r;
	while (rr > 0)
	{
		rotate(sa);
		rotate(sb);
		write_op("rr\n");
		rr--;
	}
	while (r > 0)
	{
		rotate(sb);
		write_op("rb\n");
		r--;
	}
	if (push(sa, sb) == -1)
		return (-1);
	write_op("pb\n");
	return (0);
}

int	operation_rrr_a(t_node *na, t_node *nb, t_stack *sa, t_stack *sb)
{
	int	r;
	int	rrr;

	r = (stacksize(sa) - nodeposition(na, sa)) - (stacksize(sb)
			- nodeposition(nb, sb));
	rrr = (stacksize(sa) - nodeposition(na, sa)) - r;
	while (rrr > 0)
	{
		rotate_reverse(sa);
		rotate_reverse(sb);
		write_op("rrr\n");
		rrr--;
	}
	while (r > 0)
	{
		rotate_reverse(sa);
		write_op("rra\n");
		r--;
	}
	if (push(sa, sb) == -1)
		return (-1);
	write_op("pb\n");
	return (0);
}

int	operation_rrr_b(t_node *na, t_node *nb, t_stack *sa, t_stack *sb)
{
	int	r;
	int	rrr;

	r = (stacksize(sb) - nodeposition(nb, sb)) - (stacksize(sa)
			- nodeposition(na, sa));
	rrr = (stacksize(sb) - nodeposition(nb, sb)) - r;
	while (rrr > 0)
	{
		rotate_reverse(sa);
		rotate_reverse(sb);
		write_op("rrr\n");
		rrr--;
	}
	while (r > 0)
	{
		rotate_reverse(sb);
		write_op("rrb\n");
		r--;
	}
	if (push(sa, sb) == -1)
		return (-1);
	write_op("pb\n");
	return (0);
}
