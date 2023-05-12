/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:47:46 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/12 17:54:19 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(t_stack **stack)
{
	int		i;
	int		lstsize;
	t_stack	*current;

	i = 0;
	lstsize = ft_circular_lstsize(*stack);
	current = (*stack)->next;
	while (current->val > current->prev->val && i < lstsize)
	{
		i++;
		current = current->next;
	}
	if (i == lstsize - 1)
		return (FINISHED);
	return (1);
}
