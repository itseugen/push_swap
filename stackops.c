/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:37:08 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/09 13:52:55 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_ab(t_stack *stackA, t_stack *stackB, char *id)
{
	int	val;

	if (id == "pa")
	{
		val = pop(&stackB);
		if (val == 0)
			return (0); //DO NOTHING
		if (push(&stackA, val) == ALLOC_FAIL)
			return (ALLOC_FAIL); //!ADD EXIt fUNCtion HERE
		return (9);
	}
	if (id == "pa")
	{
		val = pop(&stackA);
		if (val == 0)
			return (0); //DO NOTHING
		if (push(&stackB, val) == ALLOC_FAIL)
			return (ALLOC_FAIL); //!ADD EXIt fUNCtion HERE
		return (10);
	}
}
//!Think about just changing pointers -> less systemcalls and memory leaks