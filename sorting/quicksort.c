/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:31:29 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/24 14:01:16 by eweiberl         ###   ########.fr       */
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
void	quicksort(t_stack **list, t_stack **stackA, t_stack **stackB)
{
	bring_to_b(list, stackA, stackB, ft_circular_lstsize(*stackA));
	sort_to_a(list, stackA, stackB);
}

/// @brief Brings all below div to B
/// @param stackA 
/// @param stackB 
/// @param n amount of items in list
/// @param div 4, 2, 1.5, 1 depending on what part we want to bring to b
static void	bring_to_b(t_stack **list, t_stack **stackA,
				t_stack **stackB, int n)
{
	int	i;

	i = 0;
	while (i < n * 2 / 3)
	{
		if ((*stackA)->val >= n / 3 && (*stackA)->val < n * 2 / 3)
		{
			stackops(list, stackA, stackB, PUSH + B);
			i++;
		}
		else if ((*stackA)->val >= n * 2 / 3)
		{
			stackops(list, stackA, stackB, PUSH + B);
			stackops(list, stackA, stackB, ROT + B);
			i++;
		}
		else
			stackops(list, stackA, stackB, ROT + A);
	}
	while (*stackA)
		stackops(list, stackA, stackB, PUSH + B);
}

static void	sort_to_a(t_stack **list, t_stack **stackA, t_stack **stackB)
{
	int	temp;

	temp = 0;
	stackops(list, stackA, stackB, PUSH + A);
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
