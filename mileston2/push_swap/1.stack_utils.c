/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.stack_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:05:45 by nico              #+#    #+#             */
/*   Updated: 2024/12/13 22:39:01 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(void)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top = NULL;
	s->bottom = NULL;
	return (s);
}

int	push_node(t_stack *stack, int value)
{
	t_node	*n;

	if (!stack)
		return (-1);
	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (-1);
	n->value = value;
	n->up = NULL;
	if (!stack->top)
	{
		n->down = NULL;
		stack->bottom = n;
	}
	else
	{
		n->down = stack->top;
		stack->top->up = n;
	}
	stack->top = n;
	return (0);
}

void	pull_node(t_stack *stack)
{
	t_node	*t;

	if (!stack || !stack->top)
		return ;
	t = stack->top;
	if (!stack->top->down)
	{
		stack->top = NULL;
		stack->bottom = NULL;
		free(t);
		return ;
	}
	stack->top->down->up = NULL;
	stack->top = stack->top->down;
	free(t);
}

int	stacksize(t_stack *stack)
{
	int		cntr;
	t_node	*n;

	cntr = 0;
	n = stack->top;
	while (n)
	{
		n = n->down;
		cntr++;
	}
	return (cntr);
}

int	ordered(t_stack *stack)
{
	t_node	*node;
	int		nb;
	int		aux;

	node = stack->top;
	while (node->down)
	{
		nb = node->value;
		node = node->down;
		aux = node->value;
		if (nb > aux)
			return (0);
	}
	return (1);
}
