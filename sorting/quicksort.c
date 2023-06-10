/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:31:29 by eweiberl          #+#    #+#             */
/*   Updated: 2023/06/10 17:05:55 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	bring_to_b(t_stack **list, t_stack **stackA,
				t_stack **stackB, int n);
static void	sort_to_a(t_stack **list, t_stack **stackA, t_stack **stackB, int n);

//!average 831,748 mergesorttest

/// @brief Uses mergesort to sort stack A
/// @param stackA 
/// @param stackB 
/// @param n Amount of items
void	quicksort(t_stack **list, t_stack **stackA, t_stack **stackB, int n)
{
	bring_to_b(list, stackA, stackB, n);
	sort_to_a(list, stackA, stackB, n);
}

static void	bring_to_b(t_stack **list, t_stack **stackA,
				t_stack **stackB, int n)
{
	int	i;

	i = 0;
	while (i < (n / 2))
	{
		if ((*stackA)->val < n / 4)
		{
			i++;
			stackops(list, stackA, stackB, PUSH + B);
			stackops(list, stackA, stackB, ROT + B);
		}
		else if ((*stackA)->val >= n / 4 && ((*stackA)->val <= n / 2))
		{
			i++;
			stackops(list, stackA, stackB, PUSH + B);
		}
		else
			stackops(list, stackA, stackB, ROT + A);
	}
	while (ft_circular_lstsize(*stackA) > 1)
	{
		if ((*stackA)->val < n * 3 / 4)
		{
			i++;
			stackops(list, stackA, stackB, PUSH + B);
			stackops(list, stackA, stackB, ROT + B);
		}
		else if ((*stackA)->val >= n * 3 / 4 && ((*stackA)->val < n))
		{
			i++;
			stackops(list, stackA, stackB, PUSH + B);
		}
		else
			stackops(list, stackA, stackB, ROT + A);
	}
}

static void	sort_to_a(t_stack **list, t_stack **stackA, t_stack **stackB, int n)
{
	int	temp;
	int	i;

	i = 0;
	while (i < n / 4)
	{
		temp = 0;
		while ((*stackB)->val > (*stackA)->val
			&& temp <= ft_circular_lstsize(*stackA))
		{
			stackops(list, stackA, stackB, ROT + A);
			temp++;
		}
		stackops(list, stackA, stackB, PUSH + A);
		i++;
		while (temp--)
			stackops(list, stackA, stackB, REV + A);
	}
	while (i < n / 2)
	{
		temp = 0;
		stackops(list, stackA, stackB, REV + B);
		while ((*stackB)->val > (*stackA)->val
			&& temp <= ft_circular_lstsize(*stackA))
		{
			stackops(list, stackA, stackB, ROT + A);
			temp++;
		}
		stackops(list, stackA, stackB, PUSH + A);
		i++;
		while (temp--)
			stackops(list, stackA, stackB, REV + A);
	}
	while ((*stackB) != NULL)
	{
		temp = 0;
		while ((*stackB)->val > (*stackA)->val
			&& temp <= ft_circular_lstsize(*stackA))
		{
			stackops(list, stackA, stackB, ROT + A);
			temp++;
		}
		stackops(list, stackA, stackB, PUSH + A);
		i++;
		while (temp--)
			stackops(list, stackA, stackB, REV + A);
	}
}
