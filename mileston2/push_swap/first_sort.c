/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:59:50 by nico              #+#    #+#             */
/*   Updated: 2024/12/14 21:11:48 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*op_prices(t_node *na, t_stack *sa, t_stack *sb)
{
	t_node	*nb;
	int		*ps;

	nb = find_nb(na, sb);
	ps = (int *)ft_calloc(4, sizeof(int));
	if (!ps)
		return (NULL);
	if (nodeposition(na, sa) == 0 && nodeposition(nb, sb) == 0)
		return (ps);
	ps[0] = nodeposition(na, sa) + (stacksize(sb) - nodeposition(nb, sb));
	ps[1] = (stacksize(sa) - nodeposition(na, sa)) + nodeposition(nb, sb);
	if (nodeposition(na, sa) - nodeposition(nb, sb) >= 0)
		ps[2] = nodeposition(na, sa);
	else
		ps[2] = nodeposition(nb, sb);
	if ((stacksize(sa) - nodeposition(na, sa))
		- (stacksize(sb) - nodeposition(nb, sb)) >= 0)
		ps[3] = stacksize(sa) - nodeposition(na, sa);
	else
		ps[3] = stacksize(sb) - nodeposition(nb, sb);
	return (ps);
}

int	*calc_price(t_node *na, t_stack *sa, t_stack *sb)
{
	int		*ps;
	size_t	i;
	int		*op;

	ps = op_prices(na, sa, sb);
	if (!ps)
		return (NULL);
	op = (int *)ft_calloc(2, sizeof(int));
	if (!op)
		return (free(ps), NULL);
	if (ps[0] == 0)
		return (op[0] = 0, op[1] = 0, free(ps), op);
	i =	0;
	op[0] = ps[i];
	while (ps[i])
	{
		if (ps[i] < op[0])
		{
			op[0] = ps[i];
			op[1] = i;
		}
		i++;
	}
	return (free(ps), op);
}

int	operation(int op, t_node *na, t_stack *sa, t_stack *sb)
{
	t_node	*nb;

	nb = find_nb(na, sb);
	if (op == 0)
		return (operation_rarrb(na, nb, sa, sb));
	if (op == 1)
		return (operation_rrarb(na, nb, sa, sb));
	if (op == 2)
	{
		if (nodeposition(na, sa) - nodeposition(nb, sb) >= 0)
			return (operation_rr_a(na, nb, sa, sb));
		else
			return (operation_rr_b(na, nb, sa, sb));
	}
	if (op == 3)
	{
		if ((stacksize(sa) - nodeposition(na, sa)) - (stacksize(sb)
				- nodeposition(nb, sb)) >= 0)
			return (operation_rrr_a(na, nb, sa, sb));
		else
			return (operation_rrr_b(na, nb, sa, sb));
	}
	return (0);
}

int	push_cheapest(t_stack *sa, t_stack *sb)
{
	t_node	*cheapest;
	t_node	*t;
	int		*cpc;
	int		*cpt;

	t = sa->top;
	cheapest = t;
	cpc = calc_price(cheapest->down, sa, sb);
	while (t)
	{
		cpt = calc_price(t, sa, sb);
		if (!cpc || !cpt)
			return (ft_freesol(cpc, cpt), 1);
		if (cpt[0] == 0)
		{
			if (push(sa, sb) == -1)
				return (ft_freesol(cpc, cpt), 1);
			return (ft_freesol(cpc, cpt), write_op("pb\n"), 0);
		}
		if (cpc[0] > cpt[0])
		{
			cheapest = t;
			free(cpc);
			cpc = cpt;
		}
		else
		free(cpt);
		t = t->down;
	}
	return (operation(ft_freeop(calc_price(cheapest, sa, sb)), cheapest, sa, sb));
}

int	first_sort(t_stack *sa, t_stack *sb)
{
	if (push(sa, sb) == -1 || push(sa, sb) == -1)
		return (1);
	write_op("pb\n");
	write_op("pb\n");
	if (stacksize(sa) == 3 && ordered(sb))
		return (swap(sb), write_op("sb\n"), 0);
	while (stacksize(sa) > 3)
	{
		if (push_cheapest(sa, sb) != 0)
			return (1);
	}
	return (0);
}
