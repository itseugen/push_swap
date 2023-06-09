/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:38:50 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/15 12:35:02 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list_int(t_stack *head)
{
	t_stack	*current;
	int		doonce;

	doonce = 1;
	current = head;
	if (current == NULL)
	{
		red();
		ft_printf("The list is empty\n");
		return ;
	}
	white();
	ft_printf("The list:\n");
	while (doonce == 1 || current != head)
	{
		doonce = 0;
		green();
		ft_printf("Value: %d\n", current->val);
		current = current->next;
	}
}

void	print_list_str(t_stack *head)
{
	t_stack	*current;
	int		doonce;

	doonce = 1;
	current = head;
	if (current == NULL)
	{
		ft_printf("ERROR\n");
		return ;
	}
	while (doonce == 1 || current != head)
	{
		doonce = 0;
		ft_printf("%s\n", current->str);
		current = current->next;
	}
}
