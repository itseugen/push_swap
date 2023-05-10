/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:37:08 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/10 09:10:40 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_ab(t_stack **stackA, t_stack **stackB, char id)
{
	if (id == 'a')
	{
		return (PUSH + A);
	}
	if (id == 'b')
	return (0);
}
//!Think about just changing pointers -> less systemcalls and memory leaks

/// @brief Move the top of stack 1 to the top of stack 2
/// @param stack1 
/// @param stack2 
static int	push_pop_stack(t_stack **stack1, t_stack **stack2)
{
	t_stack	*last_node;
	t_stack	*push_node;

	if (*stack1 == NULL)
		return (EMPTY);
	push_node = *stack1;
	last_node = (*stack1)->prev;
	if (*stack1 == last_node)
		*stack1 = NULL;
	else
	{
		*stack1 = (*stack1)->next;
		(*stack1)->prev = last_node;
		last_node->next = *stack1;
	}
	if (*stack2 == NULL)
	{
		push_node->next = push_node;
		push_node->prev = push_node;
		*stack2 = push_node;
	}
	else
	{
		last_node = (*stack2)->prev;
		push_node->next = *stack2;
		push_node->prev = last_node;
		last_node->next = push_node;
		(*stack2)->prev = push_node;
	}
	return (SUCCESS);
}
