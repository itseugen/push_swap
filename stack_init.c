/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:36:07 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/05 18:42:23 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*init_split(char *str);

t_stack	*init_stack(int argc, char *argv[])
{
	int		i;
	t_stack	*stack;

	stack = NULL;
	i = 1;
	if (argc == 2 && ft_strchr(argv[1], ' '))
		return (init_split(argv[1]));
	if (argc == 2)
		return (NULL);
	if (check_argv(argc, argv) == WRONG_INPUT)
		return (NULL);
	while (i < argc)
	{
		if (push(&stack, ft_atoi(argv[i])) == ALLOC_FAIL)
			return (free_list(&stack), NULL);
		i++;
	}
	return (stack);
}

static t_stack	*init_split(char *str)
{
	char	**nbrs;
	int		i;
	int		size;
	t_stack	*stack;

	stack = NULL;
	i = 0;
	size = 0;
	nbrs = ft_split(str, ' ');
	if (nbrs == NULL)
		return (NULL);
	while (nbrs[size] != NULL)
		size++;
	if (check_argv(size, nbrs) == WRONG_INPUT)
		return (free(nbrs), NULL);
	while (i < size)
	{
		if (push(&stack, ft_atoi(nbrs[i])) == ALLOC_FAIL)
			return (free_list(&stack), NULL);
		i++;
	}
	free(nbrs);
	return (stack);
}
