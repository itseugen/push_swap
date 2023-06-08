/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:31:29 by eweiberl          #+#    #+#             */
/*   Updated: 2023/06/08 17:30:06 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	bring_to_b(t_stack **list, t_stack **stackA,
				t_stack **stackB, int n);
static void	sort_to_a(t_stack **list, t_stack **stackA, t_stack **stackB);
static int	best_way(t_stack **stackA, int n);

/// @brief Uses mergesort to sort stack A
/// @param stackA 
/// @param stackB 
/// @param n Amount of items
void	quicksort(t_stack **list, t_stack **stackA, t_stack **stackB, int n)
{
	bring_to_b(list, stackA, stackB, n);
	sort_to_a(list, stackA, stackB);
}

/// !6 for 100 is sweet spot, 12 for 500
/// @brief Brings all below div to B
/// @param stackA 
/// @param stackB 
/// @param n amount of items in list
/// @param div 4, 2, 1.5, 1 depending on what part we want to bring to b
static void	bring_to_b(t_stack **list, t_stack **stackA,
				t_stack **stackB, int n)
{
	int	i;
	int	q1;
	int	factor;

	factor = 2;
	i = 0;
	q1 = n / 12;
	while (i < q1)
	{
		if ((*stackA)->val == n)
		{
			stackops(list, stackA, stackB, PUSH + B);
			stackops(list, stackA, stackB, ROT + B);
			i++;
		}
		else if ((*stackA)->val <= q1)
		{
			stackops(list, stackA, stackB, PUSH + B);
			i++;
		}
		else
			stackops(list, stackA, stackB, ROT + A);
		if (i == q1 && i != n)
		{
			q1 = n * factor / 12;
			factor++;
		}
	}
}

static void	sort_to_a(t_stack **list, t_stack **stackA, t_stack **stackB)
{
	int	temp;
	int	bway;

	temp = 0;
	stackops(list, stackA, stackB, REV + B);
	stackops(list, stackA, stackB, PUSH + A);
	while (*stackB)
	{
		temp = 0;
		if ((*stackB)->val > (*stackA)->val)
			bway = best_way(stackA, (*stackB)->val);
		while ((*stackB)->val > (*stackA)->val)
		{
			if (bway == ROT + A)
				stackops(list, stackA, stackB, ROT + A);
			else if (bway == REV + A)
				stackops(list, stackA, stackB, REV + A);
			temp++;
		}
		stackops(list, stackA, stackB, PUSH + A);
		while (temp--)
		{
			if (bway == ROT + A)
				stackops(list, stackA, stackB, REV + A);
			else if (bway == REV + A)
				stackops(list, stackA, stackB, ROT + A);
		}
	}
}

static int	best_way(t_stack **stackA, int n)
{
	t_stack	*current;
	int		ra;
	int		rra;

	ra = 1;
	rra = 1;
	current = (*stackA)->next;
	while (current->val < n && current != *stackA)
	{
		ra++;
		current = current->next;
	}
	current = (*stackA)->prev;
	while (current->val < n && current != *stackA)
	{
		rra++;
		current = current->prev;
	}
	if (rra < ra)
		return (REV + A);
	return (ROT + A);
}
