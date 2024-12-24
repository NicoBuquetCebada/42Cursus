/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:20:47 by nbuquet-          #+#    #+#             */
/*   Updated: 2024/12/14 17:49:14 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *nb, int *error)
{
	int		i;
	long	num;
	int		n;

	n = 1;
	num = 0;
	i = 0;
	while (nb[i] == '\n' || nb[i] == '\t' || nb[i] == '\f' || nb[i] == '\r'
		|| nb[i] == '\v' || nb[i] == ' ')
		i++;
	if (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			n = -1;
		i++;
	}
	while (nb[i])
	{
		if (nb[i] < '0' || nb[i] > '9')
			return (*error = -1, 0);
		num = num * 10 + (nb[i++] - '0');
	}
	num *= n;
	return (num);
}

int	check_lenght(char *nb)
{
	size_t	i;
	int		l;

	i = 0;
	l = 0;
	while (nb[i] == '\n' || nb[i] == '\t' || nb[i] == '\f' || nb[i] == '\r'
		|| nb[i] == '\v' || nb[i] == ' ')
		i++;
	if (nb[i] == '-' || nb[i] == '+')
		i++;
	while (nb[i] == '0')
		i++;
	while (nb[i])
	{
		if (nb[i] < '0' || nb[i] > '9')
			return (1);
		i++;
		l++;
	}
	if (l > 10)
		return (1);
	return (0);
}

t_stack	*push_parsed(int argc, char **argv, int *error)
{
	size_t	i;
	t_stack	*stack;
	int		parsed;

	i = argc - 1;
	stack = new_stack();
	if (!stack)
		return (NULL);
	while (i > 0)
	{
		if (is_empty(argv[i]))
			return (ft_stackclear(stack), NULL);
		if (check_lenght(argv[i]))
			return (ft_stackclear(stack), NULL);
		parsed = (int)ft_atoi(argv[i], error);
		if (*error == -1)
			return (ft_stackclear(stack), NULL);
		if (ft_atoi(argv[i], error) > INT_MAX || ft_atoi(argv[i],
				error) < INT_MIN)
			return (ft_stackclear(stack), NULL);
		if (push_node(stack, parsed) == -1)
			return (ft_stackclear(stack), NULL);
		i--;
	}
	return (stack);
}

int	appear_twice(t_stack *stack)
{
	t_node	*aux;
	t_node	*node;

	node = stack->top;
	while (node)
	{
		aux = node->down;
		while (aux)
		{
			if (node->value == aux->value)
				return (1);
			aux = aux->down;
		}
		node = node->down;
	}
	return (0);
}

t_stack	*parser(int argc, char **argv)
{
	t_stack	*stack;
	int		*error;

	error = malloc(1 * sizeof(int));
	if (!error)
		return (NULL);
	*error = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (NULL);
		argc = ft_arraylen(argv);
		stack = push_parsed_string(argc, argv, error);
		ft_freesplit(argv);
	}
	else
		stack = push_parsed(argc, argv, error);
	if (!stack)
		return (free(error), NULL);
	if (appear_twice(stack))
		return (free(error), ft_stackclear(stack), NULL);
	return (free(error), stack);
}
