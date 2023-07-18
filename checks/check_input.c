/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:05:53 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/18 15:26:06 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	isdigit_pm(char *s, int (*f)(int));
static int	sum(int n);

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
//!Make size the next prime >size!!!d

int	check_duplicates(t_stack *stack)
{
	int		lstsize;
	t_stack	*current;
	int		i;
	int		stack_sum;

	i = 0;
	stack_sum = 0;
	current = stack;
	lstsize = ft_circular_lstsize(stack);
	while (i < lstsize)
	{
		stack_sum = stack_sum + current->val;
		current = current->next;
		i++;
	}
	if (stack_sum == sum(lstsize))
		return (SUCCESS);
	return (WRONG_INPUT);
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

static int	sum(int n)
{
	int	i;
	int	sum;

	i = 1;
	sum = 0;
	while (i <= n)
	{
		sum = sum + i;
		i++;
	}
	return (sum);
}
