/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onetilln.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:43:45 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/09 13:10:24 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	convertone(t_stack *stack);

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
	return (0);
}

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
