/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:42:37 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/12 17:44:50 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Maybe add write/printf fail protection
*/
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
	if (id == (PUSH + A))
		write(1, "pa\n", 3);
	if (id == (PUSH + B))
		write(1, "pb\n", 3);
	if (id == ROT + A)
		write(1, "ra\n", 3);
	if (id == ROT + B)
		write(1, "rb\n", 3);
	if (id == REV + A)
		write(1, "rra\n", 4);
	if (id == REV + B)
		write(1, "rrb\n", 4);
	return (SUCCESS);
}
