/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:31:29 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/26 11:33:54 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// static void	bring_to_b(t_stack **list, t_stack **stackA,
// 				t_stack **stackB, int n);
// static void	sort_to_a(t_stack **list, t_stack **stackA, t_stack **stackB);

// /// @brief Uses mergesort to sort stack A
// /// @param stackA 
// /// @param stackB 
// /// @param n Amount of items
// void	quicksort(t_stack **list, t_stack **stackA, t_stack **stackB)
// {
// 	bring_to_b(list, stackA, stackB, ft_circular_lstsize(*stackA));
// 	sort_to_a(list, stackA, stackB);
// }

// /// @brief Brings all below div to B
// /// @param stackA 
// /// @param stackB 
// /// @param n amount of items in list
// static void	bring_to_b(t_stack **list, t_stack **stackA,
// 				t_stack **stackB, int n)
// {
// 	int	max;
// 	int	factor;

// 	max = n;
// 	factor = 2;
// 	while ((*stackA) != NULL)
// 	{
// 		while (ft_circular_lstsize(*stackA) > (n / 2))
// 		{
// 			if ((*stackA)->val == max)
// 			{
// 				stackops(list, stackA, stackB, PUSH + B);
// 				stackops(list, stackA, stackB, ROT + B);
// 			}
// 			else if ((*stackA)->val < max * factor / 4)
// 				stackops(list, stackA, stackB, PUSH + B);
// 			else
// 				stackops(list, stackA, stackB, ROT + A);
// 		}
// 		n = ft_circular_lstsize(*stackA);
// 		factor++;
// 	}
// }

// static void	sort_to_a(t_stack **list, t_stack **stackA, t_stack **stackB)
// {
// 	int	temp;

// 	temp = 0;
// 	stackops(list, stackA, stackB, REV + B);
// 	stackops(list, stackA, stackB, PUSH + A);
// 	if ((*stackA)->val > (*stackA)->prev->val)
// 		stackops(list, stackA, stackB, ROT + A);
// 	while (*stackB)
// 	{
// 		temp = 0;
// 		while ((*stackB)->val > (*stackA)->val
// 			&& temp <= ft_circular_lstsize(*stackA))
// 		{
// 			stackops(list, stackA, stackB, ROT + A);
// 			temp++;
// 		}
// 		stackops(list, stackA, stackB, PUSH + A);
// 		while (temp--)
// 			stackops(list, stackA, stackB, REV + A);
// 	}
// }
