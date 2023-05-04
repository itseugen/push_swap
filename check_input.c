/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:05:53 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/04 15:52:03 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_argv(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc == 2)
		return (0); //temp, add split here
	while (i < argc)
	{
		if (isdigit_pm(argv[i], ft_isdigit) == 0)
			return (WRONG_INPUT);
	i++;
	}
	return (0);
}

int	isdigit_pm(char *s, int (*f)(int))
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
