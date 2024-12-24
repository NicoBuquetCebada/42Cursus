/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:21:10 by nico              #+#    #+#             */
/*   Updated: 2024/12/14 21:02:31 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
		ptr[i++] = '\0';
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void	ft_stackclear(t_stack *stack)
{
	t_node	*t1;
	t_node	*t2;

	if (!stack)
		return ;
	t1 = stack->top;
	while (t1)
	{
		t2 = t1->down;
		free(t1);
		t1 = t2;
	}
	free(stack);
}

int	ft_freeop(int *operation)
{
	int	op;

	op = operation[1];
	free(operation);
	return (op);
}

void ft_freesol(int *cpc, int *cpt)
{
	if (!cpc && !cpt)
		return ;
	if (!cpc)
		return (free(cpt));
	if (!cpt)
		return (free(cpc));
	if (cpc == cpt)
		return(free(cpt));
	else
	{
		free(cpt);
	}
}
