/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:09:38 by nico              #+#    #+#             */
/*   Updated: 2024/12/14 20:17:28 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*up;
	struct s_node	*down;
}					t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
}					t_stack;

size_t				ft_strlen(const char *s);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t n);
char				**ft_freesplit(char **dst);
unsigned int		ft_wrdcnt(const char *s, char c);
char				**ft_splitcpy(char **dst, const char *s, unsigned int start,
						unsigned int end);
char				**ft_split(char const *s, char c);
size_t				ft_arraylen(char **arr);
long				ft_atoi(const char *nb, int *error);
int					check_lenght(char *nb);
t_stack				*push_parsed(int argc, char **argv, int *error);
t_stack				*push_parsed_string(int argc, char **argv, int *error);
int					appear_twice(t_stack *stack);
t_stack				*parser(int argc, char **argv);
int					is_empty(char *str);
t_stack				*new_stack(void);
int					push_node(t_stack *stack, int value);
void				pull_node(t_stack *stack);
int					stacksize(t_stack *stack);
int					ordered(t_stack *stack);
t_node				*min_node(t_stack *stack);
t_node				*max_node(t_stack *stack);
int					nodeposition(t_node *node, t_stack *stack);
t_node				*find_nb(t_node *node, t_stack *stack);
t_node				*find_na(t_node *node, t_stack *stack);
void				swap(t_stack *s);
int					push(t_stack *fs, t_stack *ss);
void				rotate(t_stack *s);
void				rotate_reverse(t_stack *s);
void				write_op(char *op);
int					operation_rarrb(t_node *na, t_node *nb, t_stack *sa,
						t_stack *sb);
int					operation_rrarb(t_node *na, t_node *nb, t_stack *sa,
						t_stack *sb);
int					operation_rr_a(t_node *na, t_node *nb, t_stack *sa,
						t_stack *sb);
int					operation_rr_b(t_node *na, t_node *nb, t_stack *sa,
						t_stack *sb);
int					operation_rrr_a(t_node *na, t_node *nb, t_stack *sa,
						t_stack *sb);
int					operation_rrr_b(t_node *na, t_node *nb, t_stack *sa,
						t_stack *sb);
int					*op_prices(t_node *na, t_stack *sa, t_stack *sb);
int					*calc_price(t_node *na, t_stack *sa, t_stack *sb);
int					operation(int op, t_node *na, t_stack *sa, t_stack *sb);
int					push_cheapest(t_stack *sa, t_stack *sb);
int					first_sort(t_stack *sa, t_stack *sb);
void				last_three(t_stack *sa);
void				rotate_stack(t_node *nb, t_stack *sa);
void				push_back(t_stack *sa, t_stack *sb);
void				final_rotation(t_stack *sa);
int					push_swap(t_stack *sa, t_stack *sb);
void				ft_stackclear(t_stack *stack);
int					ft_freeop(int *operation);
void 				ft_freesol(int *cpc, int *cpt);

#endif