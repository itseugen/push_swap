/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:20:01 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/10 11:34:05 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
