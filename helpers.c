/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:19:25 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/08 14:25:16 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_circular_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*current;

	if (lst == NULL)
		return (0);
	i = 0;
	current = lst;
	while (i == 0 || current != lst)
	{
		i++;
		current = current->next;
	}
	return (i);
}
