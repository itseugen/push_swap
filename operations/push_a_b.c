/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:37:08 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/16 16:43:22 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	push_pop_stack(t_stack **stack1, t_stack **stack2);
static void	pop_stack1(t_stack **stack1);

/**
 * @brief Takes the top of one stack and puts it on top of the other
 * @param *stack Pointer to both stacks and char 'a' or 'b'
 * identifing what stack to push to
 * @return 0 if the stack to push from is empty or value of action performed
*/
int	push_ab(t_stack **stackA, t_stack **stackB, char id)
{
	if (id == 'b')
	{
		if (push_pop_stack(stackA, stackB) == SUCCESS)
			return (PUSH + B);
	}
	if (id == 'a')
	{
		if (push_pop_stack(stackB, stackA) == SUCCESS)
			return (PUSH + A);
	}
	return (0);
}

/**
 * @brief Puts the top of stack1 to the top of stack2
 * @param stack1 and stack2 to pop and push from
 * @return -1 if stack1 is empty (no operation possible) or 0
*/
static int	push_pop_stack(t_stack **stack1, t_stack **stack2)
{
	t_stack	*last_node;
	t_stack	*push_node;

	if (*stack1 == NULL)
		return (EMPTY);
	push_node = *stack1;
	pop_stack1(stack1);
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
		*stack2 = push_node;
	}
	return (SUCCESS);
}

static void	pop_stack1(t_stack **stack1)
{
	t_stack	*last_node;

	last_node = (*stack1)->prev;
	if (*stack1 == last_node)
		*stack1 = NULL;
	else
	{
		*stack1 = (*stack1)->next;
		(*stack1)->prev = last_node;
		last_node->next = *stack1;
	}
}
