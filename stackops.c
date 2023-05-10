/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:42:37 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/10 17:11:53 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stackops(t_stack **stackA, t_stack **stackB, int id)
{
	if (id == (PUSH + A))
		push_ab(stackA, stackB, 'a');
	if (id == (PUSH + B))
		push_ab(stackA, stackB, 'b');
	if (id == ROT + A)
		rotate(stackA, 'a');
	if (id == ROT + B)
		rotate(stackB, 'b');
	if (id == REV + A)
		rev_rotate(stackA, 'a');
	if (id == REV + B)
		rev_rotate(stackB, 'b');
	return (SUCCESS);
}
