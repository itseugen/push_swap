/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:48:11 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/19 16:06:02 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_three(t_stack **list, t_stack **stackA, t_stack **stackB);
static void	sort_four(t_stack **list, t_stack **stackA, t_stack **stackB);
static void	sort_five(t_stack **list, t_stack **stackA, t_stack **stackB);

/// @brief Chooses the sorting alg, frees the memory
/// @param stack1 
/// @param stack2 
void	sorting(t_stack **stack1, t_stack **stack2)
{
	t_stack	*list;
	int		lstsize;

	lstsize = ft_circular_lstsize(*stack1);
	list = NULL;
	if (lstsize == 2)
		stackops(&list, stack1, stack2, ROT + A);
	else if (lstsize == 3)
		sort_three(&list, stack1, stack2);
	else if (lstsize == 4)
		sort_four(&list, stack1, stack2);
	else if (lstsize == 5)
		sort_five(&list, stack1, stack2);
	else if (lstsize < 16)
		merge_sort(&list, stack1, stack2, lstsize);
	else if (lstsize <= 260)
		merge_sort_large(&list, stack1, stack2, 6);
	else
		merge_sort_large(&list, stack1, stack2, 12);
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

static void	sort_four(t_stack **list, t_stack **stackA, t_stack **stackB)
{
	if ((*stackA)->prev->val == 1)
		stackops(list, stackA, stackB, REV + A);
	else if ((*stackA)->prev->prev->val == 1)
	{
		stackops(list, stackA, stackB, REV + A);
		stackops(list, stackA, stackB, REV + A);
	}
	else if ((*stackA)->next->val == 1)
		stackops(list, stackA, stackB, ROT + A);
	stackops(list, stackA, stackB, PUSH + B);
	sort_three(list, stackA, stackB);
	stackops(list, stackA, stackB, PUSH + A);
}
