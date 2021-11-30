#include "push_swap.h"
#include <stdio.h>

void	free_stack(t_s_elem **first)
{
	t_s_elem	*temp;

	while (*first)
	{
		temp = *first;
		*first = (*first)->next;
		free(temp);
	}
}

int	free_all(t_s_elem **a, t_s_elem **b, int *moves, char **tab)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (moves)
		free(moves);
	if (tab)
		ft_freetab(tab);
	return (0);
}

int	check_doubles(t_s_elem **a)
{
	t_s_elem	*i;
	t_s_elem	*j;

	i = *a;
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			if (i->nbr == j->nbr)
			{
				write(1, "Error\n", 6);
				return (0);
			}
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

int	check_params(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	if (!argv)
		return (0);
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' && argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9')
			j++;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	stacks_init(char *argv[], t_s_elem **a)
{
	int			i;
	int			overflow;
	t_s_elem	*new;

	overflow = 0;
	i = 0;
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i], &overflow));
		if (new == NULL)
			return (free_all(a, NULL, NULL, NULL));
		ft_lstadd_back(a, new);
		if (overflow == -1)
		{
			write(1, "Error\n", 6);
			return (free_all(a, NULL, NULL, NULL));
		}
		i++;
	}
	if (!check_doubles(a))
		return (free_all(a, NULL, NULL, NULL));
	return (i);
}
