/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:00:21 by nico              #+#    #+#             */
/*   Updated: 2024/12/14 17:16:47 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_three(t_stack *sa)
{
	t_node	*max;
	t_node	*min;

	min = min_node(sa);
	max = max_node(sa);
	if (nodeposition(min, sa) == 0 && nodeposition(max, sa) == 2)
		return ;
	if (nodeposition(min, sa) == 0)
		return (swap(sa), rotate(sa), write_op("sa\n")
			, write_op("ra\n"));
	if (nodeposition(max, sa) == 0 && nodeposition(min, sa) == 2)
		return (rotate(sa), swap(sa), write_op("ra\n")
			, write_op("sa\n"));
	if (nodeposition(max, sa) == 0)
		return (rotate(sa), write_op("ra\n"));
	if (nodeposition(max, sa) == 1)
		return (rotate_reverse(sa), write_op("rra\n"));
	if (nodeposition(max, sa) == 2)
		return (swap(sa), write_op("sa\n"));
}

void	rotate_stack(t_node *nb, t_stack *sa)
{
	t_node	*na;
	int		pos;
	int		size;

	na = find_na(nb, sa);
	pos = nodeposition(na, sa);
	size = stacksize(sa);
	while (sa->top != na)
	{
		if (pos > pos - size)
		{
			rotate_reverse(sa);
			write_op("rra\n");
		}
		else
		{
			rotate(sa);
			write_op("ra\n");
		}
	}
}

void	push_back(t_stack *sa, t_stack *sb)
{
	t_node	*node;

	node = sb->top;
	while (node)
	{
		rotate_stack(node, sa);
		node = node->down;
		push(sb, sa);
		write_op("pa\n");
	}
}

void	final_rotation(t_stack *sa)
{
	t_node	*min;
	int		pos;
	int		size;

	min = min_node(sa);
	pos = nodeposition(min, sa);
	size = stacksize(sa);
	while (sa->top != min)
	{
		if (pos > pos - size)
		{
			rotate_reverse(sa);
			write_op("rra\n");
		}
		else
		{
			rotate(sa);
			write_op("ra\n");
		}
	}
}

int	push_swap(t_stack *sa, t_stack *sb)
{
	if (stacksize(sa) == 2)
		return (ft_stackclear(sb), swap(sa), write_op("sa\n"), 0);
	if (stacksize(sa) == 3)
		return (ft_stackclear(sb), last_three(sa), final_rotation(sa), 0);
	if (stacksize(sa) == 4)
		return (push(sa, sb), write_op("pb\n"), last_three(sa)
			, push_back(sa, sb), final_rotation(sa), 0);
	if (first_sort(sa, sb) == 1)
		return (1);
	last_three(sa);
	push_back(sa, sb);
	final_rotation(sa);
	return(0);
}
