/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:31:29 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/25 12:14:56 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	bring_to_b(t_stack **list, t_stack **stackA,
				t_stack **stackB, int n);
static void	sort_to_a(t_stack **list, t_stack **stackA, t_stack **stackB);

/// @brief Uses mergesort to sort stack A
/// @param stackA 
/// @param stackB 
/// @param n Amount of items
void	quicksort(t_stack **list, t_stack **stackA, t_stack **stackB)
{
	bring_to_b(list, stackA, stackB, ft_circular_lstsize(*stackA));
	sort_to_a(list, stackA, stackB);
}

/// @brief Brings all below div to B
/// @param stackA 
/// @param stackB 
/// @param n amount of items in list
static void	bring_to_b(t_stack **list, t_stack **stackA,
				t_stack **stackB, int n)
{
	int	max;
	int	factor;

	max = n;
	factor = 2;
	while ((*stackA) != NULL)
	{
		while (ft_circular_lstsize(*stackA) > (n / 2))
		{
			if ((*stackA)->val == max)
			{
				stackops(list, stackA, stackB, PUSH + B);
				stackops(list, stackA, stackB, ROT + B);
			}
			else if ((*stackA)->val < max * factor / 4)
				stackops(list, stackA, stackB, PUSH + B);
			else
				stackops(list, stackA, stackB, ROT + A);
		}
		n = ft_circular_lstsize(*stackA);
		factor++;
	}
}

static void	sort_to_a(t_stack **list, t_stack **stackA, t_stack **stackB)
{
	int	temp;

	temp = 0;
	stackops(list, stackA, stackB, REV + B);
	stackops(list, stackA, stackB, PUSH + A);
	if ((*stackA)->val > (*stackA)->prev->val)
		stackops(list, stackA, stackB, ROT + A);
	while (*stackB)
	{
		temp = 0;
		while ((*stackB)->val > (*stackA)->val
			&& temp <= ft_circular_lstsize(*stackA))
		{
			stackops(list, stackA, stackB, ROT + A);
			temp++;
		}
		stackops(list, stackA, stackB, PUSH + A);
		while (temp--)
			stackops(list, stackA, stackB, REV + A);
	}
}


/*
!LOOk at this code

static int	ft_get_distance(t_stack *stack, int num)
{
	int	i;

	if (num < 0)
		return (0);
	i = -1;
	while (ft_peek(stack, ++i))
		if (*ft_peek(stack, i) == num)
			break ;
	if (i > stack->count / 2)
		return (-1 * (stack->count - i));
	return (i);
}

static int	ft_next(t_stack *stack, int num)
{
	int	next;
	int	current;
	int	i;

	if (stack->count < 1)
		return (-1);
	next = INT32_MAX;
	i = -1;
	while (ft_peek(stack, ++i))
	{
		current = *ft_peek(stack, i);
		if (current > num && current < next)
			next = current;
	}
	if (next == INT32_MAX)
		return (ft_next(stack, -1));
	return (next);
}

static int	ft_calculate_moves(t_ps *data, int current)
{
	int	moves_a;
	int	moves_b;

	moves_a = ft_get_distance(data->a, ft_next(data->a, current));
	moves_b = ft_get_distance(data->b, current);
	if ((moves_a <= 0 && moves_b >= 0) || (moves_a >= 0 && moves_b <= 0))
		return (ft_abs(moves_a - moves_b));
	if (ft_abs(moves_a) > ft_abs(moves_b))
		return (ft_abs(moves_a));
	return (ft_abs(moves_b));
}

static int	ft_get_num_lowest(t_ps *data, int chunk_start, int chunk_size)
{
	int	chunk_end;
	int	num_lowest;
	int	lowest_moves;
	int	moves;

	chunk_end = chunk_start + chunk_size;
	lowest_moves = INT32_MAX;
	num_lowest = -1;
	while (chunk_start <= chunk_end)
	{
		moves = ft_calculate_moves(data, *ft_peek(data->b, chunk_start));
		if (moves < lowest_moves)
		{
			lowest_moves = moves;
			num_lowest = *ft_peek(data->b, chunk_start);
		}
		chunk_start++;
	}
	return (num_lowest);
}

void	ft_smart_insert(t_ps *data)
{
	int	num_lowest;
	int	chunk_size;
	int	chunk;
	int	chunk_start;

	chunk = -1;
	while (data->b->count)
	{
		chunk_size = data->b->size / 4;
		if (chunk_size > data->b->count)
			chunk_size = data->b->count;
		chunk_start = (++chunk % 2) * -chunk_size;
		while (chunk_size)
		{
			num_lowest = ft_get_num_lowest(data, chunk_start, --chunk_size);
			chunk_start -= ft_get_distance(data->b, num_lowest);
			if (chunk_start < -chunk_size
				|| chunk_start + chunk_size >= data->b->count)
				chunk_start = -chunk_size;
			ft_bring_to_top(data, A, ft_next(data->a, num_lowest));
			ft_bring_to_top(data, B, num_lowest);
			ft_execute_op(data, PUSH | A);
		}
	}
}
*/