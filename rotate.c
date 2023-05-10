/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:20:01 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/10 14:34:24 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotates the stack (first becomes last)
 * @param *stack and id telling what stack was rotated
 * @return 0 if the stack is empty, 17 if A and 18 if B was rotated
*/
int	rotate(t_stack **stack, char id)
{
	if (*stack == NULL)
		return (0);
	*stack = (*stack)->next;
	if (id == 'a')
		return (ROT + A);
	else
		return (ROT + B);
}

/**
 * @brief reverse rotates the stack (last becomes first)
 * @param *stack and id telling what stack was rotated
 * @return 0 if the stack is empty, 17 if A and 18 if B was rotated
*/
int	rev_rotate(t_stack **stack, char id)
{
	if (*stack == NULL)
		return (0);
	*stack = (*stack)->prev;
	if (id == 'a')
		return (REV + A);
	else
		return (REV + B);
}
