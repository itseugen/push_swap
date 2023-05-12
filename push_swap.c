/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:49:42 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/12 17:54:04 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
**
* You have 2 stacks named a and b.
* ◦ At the beginning: The stack a contains a random amount of negative
* and/or positive numbers which cannot be duplicated.
* ◦ The stack b is empty.

* • The goal is to sort in ascending order numbers into stack a.
* To do so you have the following operations at your disposal:
TODO: sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
TODO: sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
TODO: ss : sa and sb at the same time.
*DONE: pa (push a): Take the first element at the top of b
* and put it at the top of a.
Do nothing if b is empty.
*DONE: pb (push b): Take the first element at the top of a
* and put it at the top of b.
Do nothing if a is empty.
*DONE: ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
*DONE: rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
*DONE: rr : ra and rb at the same time.
*DONE: rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
*DONE: rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
*DONE: rrr : rra and rrb at the same time.
**
*/
/*
! Allowed
*read
*write
*malloc
*free
*exit
*/

int	main(int argc, char *argv[])
{
	t_stack	*stack1;
	t_stack	*stack2;

	stack1 = NULL;
	stack2 = NULL;
	if (argc <= 1 || (argc == 2 && check_argv(2, argv) != WRONG_INPUT))
		return (FINISHED);
	stack1 = init_stack(argc, argv);
	if (stack1 == NULL)
		return (ft_printf("Error\n"), WRONG_INPUT);
	if (convertvals(stack1) == ALLOC_FAIL)
		return (free_list(&stack1), ft_printf("Error\n"), 1);
	if (check_duplicates(stack1) == WRONG_INPUT)
		return (purple(), ft_printf("Error\n"), WRONG_INPUT);
	if (issorted(&stack1) == FINISHED)
		return (free_list(&stack1), free_list(&stack2), FINISHED);
	merge_sort(&stack1, &stack2, ft_circular_lstsize(stack1));
	free_list(&stack1);
	free_list(&stack2);
	return (FINISHED);
}
