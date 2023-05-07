/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:05:53 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/07 17:12:19 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isdigit_pm(char *s, int (*f)(int));
static int	ft_abs(int nb);

int	check_argv(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (isdigit_pm(argv[i], ft_isdigit) == 0)
			return (WRONG_INPUT);
	i++;
	}
	return (0);
}

bool	check_duplicates(t_stack **stack)
{
	t_stack	*current_node;
	int		size;
	bool	*hash;
	int		i;

	size = 0;
	current_node = *stack;
	while (current_node->next != *stack)
	{
		current_node = current_node->next;
		size++;
	}
	hash = ft_calloc(size, sizeof(bool));
	if (hash == NULL)
		return (NULL);
	current_node = *stack;
	while (current_node->next != *stack)
	{
		i = ft_abs(current_node->val) % size;
		if (hash[i])
			return (free(hash), true);
		hash[i] = true;
		current_node = current_node->next;
	}
	return (free(hash), false);
}

static int	ft_abs(int nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (-nb);
}

static int	isdigit_pm(char *s, int (*f)(int))
{
	unsigned int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (f((s[i])) != 1)
			return (0);
		i++;
	}
	return (1);
}
