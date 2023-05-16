/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:08:25 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/16 17:27:01 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;

	first_node = (*stack);
	second_node = (*stack)->next;
	first_node->next = second_node->next;
	second_node->next->prev = first_node;
	second_node->prev = first_node->prev;
	first_node->prev->next = second_node;
	first_node->prev = second_node;
	second_node->next = first_node;
	*stack = second_node;
	return (0);
}
