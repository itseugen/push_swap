/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:36:25 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/17 13:13:48 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// @brief Adds item to top of stack
/// @param stack the stack
/// @param value value of the new item
/// @return 1 if succes, -1 if malloc fail
int	push(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (ALLOC_FAIL);
	new_node->val = value;
	if (*stack == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*stack = new_node;
	}
	else
	{
		last_node = (*stack)->prev;
		new_node->next = *stack;
		new_node->prev = last_node;
		last_node->next = new_node;
		(*stack)->prev = new_node;
	}
	return (1);
}

/// @brief Removes the top element of the stack
/// @param stack the stack
/// @return the removed value
int	pop(t_stack **stack)
{
	t_stack	*last_node;
	int		value;

	if (*stack == NULL)
		return (0);
	last_node = (*stack)->prev;
	value = (*stack)->val;
	if (*stack == last_node)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		free(*stack);
		*stack = (*stack)->next;
		(*stack)->prev = last_node;
		last_node->next = *stack;
	}
	return (value);
}

void	free_list(t_stack **stack)
{
	t_stack	*current_node;
	t_stack	*next_node;

	if (*stack == NULL)
		return ;
	current_node = *stack;
	while (current_node->next != *stack)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	free(current_node);
	*stack = NULL;
}
