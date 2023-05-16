/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:42:37 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/16 15:02:54 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_ops(t_stack **list, t_stack **stackA,
				t_stack **stackB, char *str);
static void	do_ops(t_stack **list, t_stack **stackA, t_stack **stackB, int id);

/*
 * Maybe add write/printf fail protection
*/
int	stackops(t_stack **list, t_stack **stackA, t_stack **stackB, int id)
{
	do_ops(list, stackA, stackB, id);
	return (SUCCESS);
}

static int	get_ops(t_stack **list, t_stack **stackA,
		t_stack **stackB, char *str)
{
	if (add_back_str(list, str) == ALLOC_FAIL)
	{
		free_list(stackA);
		free_list(stackB);
		free_list(list);
		exit(1);
	}
	return (0);
}

static void	do_ops(t_stack **list, t_stack **stackA, t_stack **stackB, int id)
{
	if (id == (PUSH + A))
		push_ab(stackA, stackB, 'a');
	if (id == (PUSH + B))
		push_ab(stackA, stackB, 'b');
	if (id == ROT + A)
		rotate(stackA, 'a');
	if (id == ROT + B)
		rotate(stackB, 'b');
	if (id == REV + A)
		rev_rotate(stackA, 'a');
	if (id == REV + B)
		rev_rotate(stackB, 'b');
	if (id == (PUSH + A))
		get_ops(list, stackA, stackB, "pa");
	if (id == (PUSH + B))
		get_ops(list, stackA, stackB, "pb");
	if (id == ROT + A)
		get_ops(list, stackA, stackB, "ra");
	if (id == ROT + B)
		get_ops(list, stackA, stackB, "rb");
	if (id == REV + A)
		get_ops(list, stackA, stackB, "rra");
	if (id == REV + B)
		get_ops(list, stackA, stackB, "rrb");
}

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
		if (ft_strncmp("rra", current->str, 3) == 0
			&& ft_strncmp("ra", current->next->str, 2) == 0)
		{
			current = current->prev;
			pop_next_two(&current);
		}
		else
			current = current->next;
	}
}
