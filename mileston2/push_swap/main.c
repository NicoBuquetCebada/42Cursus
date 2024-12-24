/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:57:03 by nico              #+#    #+#             */
/*   Updated: 2024/12/14 17:27:26 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*sa;
	t_stack	*sb;
	char	**splited;

	if (argc == 1)
		return (0);
	splited = ft_split(argv[1], ' ');
	if (!splited)
		return (write(2, "Error\n", 6), 1);
	if (argc == 2 && ft_arraylen(splited) == 1
			&& !is_empty(splited[0]))
		return (ft_freesplit(splited), 0);
	sa = parser(argc, argv);
	sb = new_stack();
	if (!sa || !sb)
		return (ft_freesplit(splited), ft_stackclear(sa)
			, ft_stackclear(sb), write(2, "Error\n", 6), 1);
	if (ordered(sa))
		return (ft_freesplit(splited), ft_stackclear(sa)
			, ft_stackclear(sb), 0);
	if (push_swap(sa, sb) == 1)
		return (ft_freesplit(splited), ft_stackclear(sa)
			, ft_stackclear(sb), 1);
	return (ft_freesplit(splited), ft_stackclear(sb), ft_stackclear(sa), 0);
}
