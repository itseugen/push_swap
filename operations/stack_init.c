/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:36:07 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/18 15:36:33 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*init_split(char *str);

/// @brief Puts the values into the stack
/// @param argc 
/// @param argv 
/// @return the finished stack
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
		if (push(&stack, atoi_control(argv[i], stack, NULL, 0)) == ALLOC_FAIL)
			return (free_list(&stack), NULL);
		i++;
	}
	return (stack);
}

/// @brief Puts the values in the stack if argc=1
/// @param str 
/// @return returns the stack
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
		if (push(&stack,
				atoi_control(nbrs[i], stack, nbrs, size)) == ALLOC_FAIL)
			return (free_split(nbrs, size), free_list(&stack), NULL);
		i++;
	}
	free_split(nbrs, size);
	return (stack);
}

/// @brief frees the array of strings
/// @param strings 
/// @param size 
void	free_split(char **strings, size_t size)
{
	size_t	i;

	i = 0;
	while (i <= size)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}
