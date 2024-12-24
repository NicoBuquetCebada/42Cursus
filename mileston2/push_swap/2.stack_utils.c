/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.stack_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:04:21 by nico              #+#    #+#             */
/*   Updated: 2024/12/08 14:54:41 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*max_node(t_stack *stack)
{
	t_node	*max;
	t_node	*node;

	node = stack->top;
	max = node;
	while (node)
	{
		if (max->value < node->value)
			max = node;
		node = node->down;
	}
	return (max);
}

t_node	*min_node(t_stack *stack)
{
	t_node	*min;
	t_node	*node;

	node = stack->top;
	min = node;
	while (node)
	{
		if (min->value > node->value)
			min = node;
		node = node->down;
	}
	return (min);
}

int	nodeposition(t_node *node, t_stack *stack)
{
	int		pos;
	t_node	*n;

	pos = 0;
	n = stack->top;
	while (n)
	{
		if (n == node)
			break ;
		n = n->down;
		pos++;
	}
	return (pos);
}

t_node	*find_nb(t_node *node, t_stack *stack)
{
	t_node	*n;
	t_node	*nb;
	int		i;

	n = stack->top;
	nb = NULL;
	i = INT_MIN;
	while (n)
	{
		if (node->value > n->value)
		{
			if (n->value > i)
			{
				nb = n;
				i = nb->value;
			}
		}
		n = n->down;
	}
	if (!nb)
		return (max_node(stack));
	return (nb);
}

t_node	*find_na(t_node *node, t_stack *stack)
{
	t_node	*n;
	t_node	*nb;
	int		i;

	n = stack->top;
	nb = NULL;
	i = INT_MAX;
	while (n)
	{
		if (node->value < n->value)
		{
			if (n->value < i)
			{
				nb = n;
				i = nb->value;
			}
		}
		n = n->down;
	}
	if (!nb)
		return (min_node(stack));
	return (nb);
}
