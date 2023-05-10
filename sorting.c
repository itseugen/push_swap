/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:17:40 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/10 17:15:24 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* IDEA: Use mergesort (at least for amounts over 5)
* set numbers to 1 - amount of numbers n
* get 1 - n/2 to stack b (while doing that: 1 - n*0.25 to bottom of b)
* therefore n * 0.25 - n/2 to top of B
* add a to b (n/2 - n * 0.75 to bottom of b (bellow 1 - n *0.25))
* (n*0.75 - n to top of b)
* add from b to a (backwards from where it was added)
! If needed add other sort alghorithms for n < 6
*/

#include "push_swap.h"

static void	bring_to_b(t_stack **stackA, t_stack **stackB, int n);
static void	sort_to_a(t_stack **stackA, t_stack **stackB, int n);

/// @brief Uses mergesort to sort stack A
/// @param stackA 
/// @param stackB 
/// @param n Amount of items
void	merge_sort(t_stack **stackA, t_stack **stackB, int n)
{
	bring_to_b(stackA, stackB, n);
	sort_to_a(stackA, stackB, n);
}

/// @brief Brings all below div to B
/// @param stackA 
/// @param stackB 
/// @param n amount of items in list
/// @param div 4, 2, 1.5, 1 depending on what part we want to bring to b
static void	bring_to_b(t_stack **stackA, t_stack **stackB, int n)
{
	int	i;
	int	q1;
	int	q2;
	int	q3;

	i = 0;
	q1 = n / 4;
	q2 = n / 2;
	q3 = n * 3 / 4;
	while (i < q1)
	{
		if ((*stackA)->val <= q1)
		{
			stackops(stackA, stackB, PUSH + B);
			i++;
		}
		else
			stackops(stackA, stackB, ROT + A);
		if (i == q1)
			q1 = q2;
		if (i == q2)
			q1 = q3;
		if (i == q3)
			q1 = n;
	}
}

//!WIP
static void	sort_to_a(t_stack **stackA, t_stack **stackB, int n)
{
	int	i;
	int	q1;
	int	q2;
	int	q3;
	int	temp;

	i = 0;
	q1 = n / 4;
	q2 = n / 2;
	q3 = n * 3 / 4;
	stackops(stackA, stackB, PUSH + A);
	stackops(stackA, stackB, PUSH + A);
	while (i < q1)
	{
		temp = 0;
		while ((*stackB)->val > (*stackA)->val)
		{
			stackops(stackA, stackB, ROT + A);
			temp++;
		}
		stackops(stackA, stackB, PUSH + A);
		i++;
		while (temp--)
			stackops(stackA, stackB, REV + A);
		if (i == q1)
			q1 = q2;
		if (i == q2)
			q1 = q3;
		if (i == q3)
			q1 = n;
	}
}
