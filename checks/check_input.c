/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:05:53 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/20 12:33:35 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	isdigit_pm(char *s, int (*f)(int));
static int	sum(int n);

/// @brief checks if all args are digits
/// @param argc 
/// @param argv 
/// @return 0 on correct input, 1 on wrong input
int	check_argv(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (isdigit_pm(argv[i], ft_isdigit) == 0
			&& ft_strchr(argv[i], ' ') == NULL)
			return (WRONG_INPUT);
		i++;
	}
	return (0);
}

/// @brief Checks for duplicates in the numbers
/// @param stack the stack to check
/// @return 0 on success, 1 on duplicates
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

/// @brief checks if all inputs are digits, considering one =/-
/// @param s the string to check
/// @param f the function to check it with (could be reused with is alpha p. e)
/// @return 1 if it isnt a digit, 0 if it is
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

int	check_argv_split(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (isdigit_pm(argv[i], ft_isdigit) == 0
			&& ft_strchr(argv[i], ' ') == NULL)
			return (WRONG_INPUT);
		i++;
	}
	return (0);
}
