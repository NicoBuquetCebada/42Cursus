/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:55:42 by nico              #+#    #+#             */
/*   Updated: 2024/12/13 23:00:39 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s)
{
	t_node	*t;

	if (!s || !s->top || !s->top->down)
		return ;
	t = s->top->down;
	s->top->up = t;
	s->top->down = t->down;
	if (t->down)
		t->down->up = s->top;
	t->up = NULL;
	t->down = s->top;
	s->top = t;
}

int	push(t_stack *fs, t_stack *ss)
{
	if (!fs || !ss || !fs->top)
		return (-1);
	if (push_node(ss, fs->top->value) == -1)
		return (-1);
	pull_node(fs);
	return (0);
}

void	rotate(t_stack *s)
{
	t_node	*t;

	if (!s || !s->top || !s->top->down)
		return ;
	t = s->top;
	s->top = t->down;
	s->top->up = NULL;
	t->down = NULL;
	t->up = s->bottom;
	s->bottom->down = t;
	s->bottom = t;
}

void	rotate_reverse(t_stack *s)
{
	t_node	*t;

	if (!s || !s->top || !s->top->down)
		return ;
	t = s->bottom->up;
	s->bottom->down = s->top;
	s->top->up = s->bottom;
	s->bottom->up = NULL;
	if (t)
		t->down = NULL;
	s->top = s->bottom;
	s->bottom = t;
}

void	write_op(char *op)
{
	int		len;

	len = ft_strlen(op);
	write(1, op, len);
}
