/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:33:02 by nico              #+#    #+#             */
/*   Updated: 2024/10/05 14:58:05 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

int	main(void)
{
	//const char	s1[] = "123213";
	//const char	s2[] = "123";
	//printf("%s", ft_strtrim(s1, s2));
	//char		**s2 = ft_split(s1, 120);
	//const char s2[] = " ";
	//char	*s1 = ft_itoa(32);

	//printf("%s", s1);
	/*while (*s2)
	{
		printf("|%s|\n", *s2);
		s2++;
	}*/
	// DEFINIR LISTA
	/*t_list	*lst;
	int x;
	int y;

	y = 0;
	x = 1;
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(&y));
	ft_lstadd_back(&lst, ft_lstnew(&x));
	printf("%i\n", ft_lstsize(lst));
	int	*c = ft_lstlast(lst) -> content;
	printf ("%i\n", *c);

	t_list *list;
	t_list *frst;

	list = ft_lstnew(&x);
	list -> next = ft_lstnew(&x);
	frst = list;
	list = list -> next;
	list -> next = ft_lstnew(&x);
	list = list -> next;
	list -> next = ft_lstnew(&x);
	list = list -> next;
	list -> next = ft_lstnew(&y);
	printf("%i\n", ft_lstsize(frst));*/
	//int	*c = ft_lstlast(frst) -> content;
	//printf ("%i\n", *c);

	//PRINTF
	//char c	= 'a';
	char *s	= NULL;
	int i = 0;
	void *x = &i;

	int res = ft_printf("ft_printf: %p\n", x);
	int ros = printf("sy_printf: %p\n", x);
	printf("resultado: %i\n", res);
	printf("resultado: %i\n", ros);
	res = ft_printf("ft_printf: %s\n", s);
	ros = printf("sy_printf: %s\n", s);
	printf("resultado: %i\n", res);
	printf("resultado: %i\n", ros);
}	