/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:07:45 by nico              #+#    #+#             */
/*   Updated: 2024/12/14 16:37:52 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(char *str)
{
	size_t	i;
	size_t	len;

	if (!str)
		return (1);
	i = 0;
	len = ft_strlen(str);
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == ' '
		|| str[i] == '-' || str[i] == '+')
		i++;
	if (len == i)
		return (1);
	return (0);
}

size_t	ft_arraylen(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

t_stack	*push_parsed_string(int argc, char **argv, int *error)
{
	int		i;
	t_stack	*stack;
	int		parsed;

	if (argc == 0)
		return (NULL);
	i = argc - 1;
	stack = new_stack();
	if (!stack)
		return (NULL);
	while (i >= 0)
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
