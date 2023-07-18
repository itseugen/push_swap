/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onetilln.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:43:45 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/18 10:55:16 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	convertone(t_stack *stack);

/**
 * @brief Converts a list of ints to their respective value from 1 till n
 * @param *stack The list to modify
 * @return 0 if the program succeeds, -1 if memory allocation fails.
*/
int	convertvals(t_stack *stack)
{
	t_stack	*current;
	int		*temp;
	int		lstsize;
	int		i;

	i = 0;
	lstsize = ft_circular_lstsize(stack);
	temp = malloc(lstsize * sizeof(int));
	if (temp == NULL)
		return (ALLOC_FAIL);
	current = stack;
	while (i < lstsize)
	{
		temp[i] = convertone(current);
		current = current->next;
		i++;
	}
	i = 0;
	while (i < lstsize)
	{
		current->val = temp[i];
		current = current->next;
		i++;
	}
	free(temp);
	return (0);
}

/// @brief Compares one element of the list with every
/// other element and returns the relative value
/// @param stack the list to modify on the
/// position of the element to give a new value
/// @return The value to assigne to the node
static int	convertone(t_stack *stack)
{
	t_stack	*current;
	int		i;

	i = 1;
	current = stack->next;
	while (current != stack)
	{
		if (current->val < stack->val)
			i++;
		current = current->next;
	}
	return (i);
}
