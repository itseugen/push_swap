/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oplist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:03:32 by eweiberl          #+#    #+#             */
/*   Updated: 2023/06/10 17:44:50 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	replacetwo(t_stack **stack, char *op);
static int	comparetwo(t_stack **stack, char *op1, char *op2);

static void	pop_next_two(t_stack **stack)
{
	t_stack	*free1;
	t_stack	*free2;

	free1 = (*stack)->next;
	free2 = (*stack)->next->next;
	(*stack)->next = free2->next;
	free(free1);
	free(free2);
}

void	clean_list(t_stack **stack)
{
	t_stack	*current;
	int		doonce;

	doonce = 1;
	current = *stack;
	if (current == NULL)
		return ;
	while (doonce == 1 || (current->next != *stack && current != NULL))
	{
		doonce = 0;
		if (comparetwo(&current, "ra", "rra") == SUCCESS)
		{
			current = current->prev;
			pop_next_two(&current);
		}
		else if (comparetwo(&current, "ra", "rb") == SUCCESS)
			replacetwo(&current, "rr");
		else if (comparetwo(&current, "rra", "rrb") == SUCCESS)
			replacetwo(&current, "rrr");
		else
			current = current->next;
	}
}

static int	comparetwo(t_stack **stack, char *op1, char *op2)
{
	if ((ft_strncmp(op1, (*stack)->str, ft_strlen(op1)) == 0
			&& ft_strncmp(op2, (*stack)->next->str, ft_strlen(op2)) == 0)
		|| (ft_strncmp(op2, (*stack)->str, ft_strlen(op2)) == 0
			&& ft_strncmp(op1, (*stack)->next->str, ft_strlen(op1)) == 0))
		return (SUCCESS);
	else
		return (1);
}

static void	replacetwo(t_stack **stack, char *op)
{
	t_stack	*freeit;

	freeit = (*stack)->next;
	(*stack)->next = freeit->next;
	(*stack)->next->prev = (*stack);
	free(freeit);
	(*stack)->str = op;
}

int	add_back_str(t_stack **stack, char *str)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (ALLOC_FAIL);
	new_node->str = str;
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
