/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:48:11 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/16 18:09:36 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_three(t_stack **list, t_stack **stackA, t_stack **stackB);
static void	sort_five(t_stack **list, t_stack **stackA, t_stack **stackB);

void	sorting(t_stack **stack1, t_stack **stack2)
{
	t_stack	*list;
	int		lstsize;

	lstsize = ft_circular_lstsize(*stack1);
	list = NULL;
	if (lstsize == 2)
		stackops(&list, stack1, stack2, ROT + A);
	if (lstsize == 3)
		sort_three(&list, stack1, stack2);
	if (lstsize == 5)
		sort_five(&list, stack1, stack2);
	else
		merge_sort(&list, stack1, stack2, lstsize);
	clean_list(&list);
	print_list_str(list);
	free_list(&list);
}

static void	sort_three(t_stack **list, t_stack **stackA, t_stack **stackB)
{
	if ((*stackA)->val == 3)
		stackops(list, stackA, stackB, ROT + A);
	if (issorted(stackA) != FINISHED && (*stackA)->val > (*stackA)->next->val)
		stackops(list, stackA, stackB, SWAP + A);
	if (issorted(stackA) != FINISHED)
		stackops(list, stackA, stackB, REV + A);
	if (issorted(stackA) != FINISHED)
		stackops(list, stackA, stackB, SWAP + A);
}

static void	sort_five(t_stack **list, t_stack **stackA, t_stack **stackB)
{
	while (ft_circular_lstsize(*stackA) > 3)
	{
		if ((*stackA)->val == 2 || (*stackA)->val == 1)
			stackops(list, stackA, stackB, PUSH + B);
		else
			stackops(list, stackA, stackB, ROT + A);
	}
	sort_three(list, stackA, stackB);
	if ((*stackB)->val == 1)
	{
		stackops(list, stackA, stackB, SWAP + B);
		stackops(list, stackA, stackB, PUSH + A);
		stackops(list, stackA, stackB, PUSH + A);
	}
	else
	{
		stackops(list, stackA, stackB, PUSH + A);
		stackops(list, stackA, stackB, PUSH + A);
	}
}
