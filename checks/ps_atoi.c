/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:10:01 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/24 14:40:11 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	exit_atoi(t_stack *stack, char **strings, size_t size);

int	atoi_control(char *str, t_stack *stack, char **strings, size_t size)
{
	int	i;

	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		i++;
		if (ft_strlen(str + i) > 10)
			exit_atoi(stack, strings, size);
		if (ft_strlen(str + i) == 10
			&& ft_strncmp("2147483648", (str + i), ft_strlen(str + i)) < 0)
			exit_atoi(stack, strings, size);
	}
	else
	{
		if (str[i] == '+')
			i++;
		if (ft_strlen(str + i) > 10)
			exit_atoi(stack, strings, size);
		if (ft_strlen(str + i) == 10
			&& ft_strncmp("2147483647", (str + i), ft_strlen(str + i)) < 0)
			exit_atoi(stack, strings, size);
	}
	return (ft_atoi(str));
}

static void	exit_atoi(t_stack *stack, char **strings, size_t size)
{
	free_list(&stack);
	if (strings != NULL)
		free_split(strings, size);
	ft_printf("Error\n");
	exit(1);
}
