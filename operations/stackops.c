/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:42:37 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/16 17:15:59 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_ops(t_stack **list, t_stack **stackA,
				t_stack **stackB, char *str);
static void	do_ops(t_stack **list, t_stack **stackA, t_stack **stackB, int id);
static void	do_ops2(t_stack **list, t_stack **stackA, t_stack **stackB, int id);

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
	if (id == SWAP + A)
		swap(stackA);
	if (id == SWAP + B)
		swap(stackB);
	do_ops2(list, stackA, stackB, id);
}

static void	do_ops2(t_stack **list, t_stack **stackA, t_stack **stackB, int id)
{
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
	if (id == SWAP + A)
		get_ops(list, stackA, stackB, "sa");
	if (id == SWAP + B)
		get_ops(list, stackA, stackB, "sb");
}
