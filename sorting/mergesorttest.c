/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesorttest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:18:26 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/26 12:28:04 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	bring_to_b(t_stack **list, t_stack **stackA,
				t_stack **stackB, int n);
static void	sort_to_a(t_stack **list, t_stack **stackA, t_stack **stackB);

/// @brief Uses mergesort to sort stack A
/// @param stackA 
/// @param stackB 
/// @param n Amount of items
void	merge_sort_test(t_stack **list, t_stack **stackA, t_stack **stackB, int n)
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

	temp = 0;
	stackops(list, stackA, stackB, REV + B);
	stackops(list, stackA, stackB, PUSH + A);
	if ((*stackA)->val > (*stackA)->prev->val)
		stackops(list, stackA, stackB, ROT + A);
	while (*stackB)
	{
		temp = 0;
		while ((*stackB)->val > (*stackA)->val
			&& temp <= ft_circular_lstsize(*stackA))
		{
			stackops(list, stackA, stackB, ROT + A);
			temp++;
		}
		stackops(list, stackA, stackB, PUSH + A);
		while (temp--)
			stackops(list, stackA, stackB, REV + A);
	}
}
