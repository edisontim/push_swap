/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:50:39 by tedison           #+#    #+#             */
/*   Updated: 2021/06/19 12:37:53 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_s_elem{
	long long int		nbr;
	struct s_s_elem		*next;
}				t_s_elem;

typedef struct s_s_info{
	int		stack_size_a;
	int		stack_size_b;
	int		*chunks;
	int		chunk_size;
	int		num_chunk;
	int		*m;
}				t_s_info;

typedef struct s_med{
	int	h_f;
	int	h_s;
	int	i;
}				t_med;

void			ft_lstadd_back(t_s_elem **alst, t_s_elem *new);
void			ft_lstadd_front(t_s_elem **alst, t_s_elem *new);
t_s_elem		*ft_lstlast(t_s_elem *lst);
t_s_elem		*ft_lstnew(long long int nbr);
long long int	ft_atoi(const char *str, int *overflow);
void			ft_bzero(void *s, int n);
void			sa(t_s_elem **first, int y);
void			sb(t_s_elem **first, int y);
void			ss(t_s_elem **a, t_s_elem **b, int y);
void			pa(t_s_elem **a, t_s_elem **b, int y);
void			pb(t_s_elem **a, t_s_elem **b, int y);
void			ra(t_s_elem **a, int y);
void			rb(t_s_elem **b, int y);
void			rra(t_s_elem **a, int y);
void			rrb(t_s_elem **b, int y);
void			rrr(t_s_elem **a, t_s_elem **b, int y);
int				stacks_init(char *argv[], t_s_elem **a);
int				check_params(char *argv[]);
int				check_doubles(t_s_elem **a);
void			sa_a(t_s_info *info);
void			sb_a(t_s_info *info);
void			ss_a(t_s_info *info);
void			pa_a(t_s_info *info);
void			pb_a(t_s_info *info);
void			ra_a(t_s_info *info);
void			rb_a(t_s_info *info);
void			rr_a(t_s_info *info);
void			rra_a(t_s_info *info);
void			rrb_a(t_s_info *info);
void			rrr_a(t_s_info *info);
int				free_all(t_s_elem **a, t_s_elem **b, int *moves, char **tab);
char			**check_arg(char *argv_1);
char			**ft_split(char *s, char c);
char			*ft_substr(char *s, int start, int len);
int				is_sorted(t_s_elem **a);
void			write_moves(t_s_info *info);
void			write_more(t_s_info *info, int i);
void			opti_moves(t_s_info *info);
void			opti_rec_one(t_s_info *i, int i_l, int i_h);
void			opti_rec_two(t_s_info *i, int i_l, int i_h);
int				sort_m_l(t_s_elem **a, t_s_elem **b, t_s_info *info, int n_m);
void			sort_m(t_s_elem **a, t_s_elem **b, t_s_info *info, t_med *med);
void			empty_b(t_s_elem **a, t_s_elem **b, t_s_info *info);
int				moves_to_top(t_s_info *info, int nbr);
void			move_closer_inferior(t_s_elem **first, t_s_info *info, int nbr);
void			sort_three(t_s_elem **a);
int				stack_size(t_s_elem **first);
int				min(t_s_elem **first);
void			sort_small(t_s_elem **a, t_s_elem **b, t_s_info *info);
int				max_value(t_s_elem **first);
int				max_index(t_s_elem **first);
int				min_value(t_s_elem **first);
int				min_index(t_s_elem **first);
int				fill_chunk(t_s_elem **a, t_s_info *info);
void			swap(int *a, int *b);
void			sort_chunk(t_s_info *info);
int				get_index(t_s_elem **first, int nbr);
int				is_in_chunk(t_s_info *info, int num, int iter);
int				chunk_init(t_s_elem **a, t_s_info *info);
int				sc_top(int *hold_first, t_s_elem **first, \
				t_s_info *info, int iter);
int				sc_bott(int *h_s, t_s_elem **f, t_s_info *info, int iter);
void			bring_top_one(t_s_elem **f, t_s_info *info, int index, char c);
void			bring_top(t_s_elem **f, t_s_info *info, int index, char c);
int				is_smaller(t_s_elem **first, int nbr);
int				index_closest_inferior(t_s_elem **first, int nbr);
int				sort_two(t_s_elem **a);
int				push_swap(t_s_elem **a, t_s_elem **b, t_s_info *info);
int				ft_push_swap_string(t_s_elem **a, char **args, t_s_info *info);
int				push_swap_start(t_s_elem **a, t_s_elem **b, t_s_info *info);
char			**ft_freetab(char **tab);

#endif
