/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:05:53 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/07 18:24:13 by eweiberl         ###   ########.fr       */
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

// if random fail, make sure calloc is size * 2 +1 and is a prime
// and do it out of the calloc since we do modulo size
//!maybe convert to 1 - n before using
//!Make size the next prime >size!!!
bool	check_duplicates(t_stack **stack, int size)
{
	t_stack	*current_node;
	bool	*hash;
	int		i;

	current_node = *stack;
	while (current_node->next != *stack)
	{
		current_node = current_node->next;
		size++;
	}
	size = size + 1;
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
