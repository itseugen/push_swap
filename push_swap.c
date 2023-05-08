/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:49:42 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/08 16:08:26 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
TODO: pa (push a): Take the first element at the top of b
* and put it at the top of a.
Do nothing if b is empty.
TODO: pb (push b): Take the first element at the top of a
* and put it at the top of b.
Do nothing if a is empty.
TODO: ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
TODO: rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
TODO: rr : ra and rb at the same time.
TODO: rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
TODO: rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
TODO: rrr : rra and rrb at the same time.
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

/*
* IDEA: Use mergesort (at least for amounts over 5)
* set numbers to 1 - amount of numbers n
* get 1 - n/2 to stack b (while doing that: 1 - n*0.25 to bottom of b)
* therefore n * 0.25 - n/2 to top of B
* add a to b (n/2 - n * 0.75 to bottom of b (bellow 1 - n *0.25))
* (n*0.75 - n to top of b)
* add from b to a (backwards from where it was added)
! If needed add other sort alghorithms for n < 6
*/
/*
Black \033[0;30m
Red \033[0;31m
Green \033[0;32m
Yellow \033[0;33m
Blue \033[0;34m
Purple \033[0;35m
Cyan \033[0;36m
White \033[0;37m
*/


#include "push_swap.h"

int	main(int argc, char *argv[])
{
	ft_printf("argc: %d\nargv[1]: %s\n", argc, argv[1]);
	if (argc <= 1 || (argc == 2 && check_argv(2, argv) != WRONG_INPUT))
		return (FINISHED);
	// if (!ft_strchr(argv[1], ' ') && check_argv(2, argv) != WRONG_INPUT)
	// 	return (ft_printf("Error\n"), WRONG_INPUT);
	//TODO: no duplicates, no too big/small Numbers
	t_stack	*stack1 = NULL;
	stack1 = init_stack(argc, argv);
	if (stack1 == NULL)
		return (ft_printf("Error\n"), WRONG_INPUT);
	print_list(stack1);
	modify_values(stack1);
	print_list(stack1);
	// ft_printf("Listsize: %d\n", ft_circular_lstsize(stack1));
	// if (check_duplicates(&stack1, 0) == true)
	// {
	// 	purple();
	// 	return (ft_printf("Error\n"), WRONG_INPUT);
	// }
	free_list(&stack1);
	print_list(stack1);
	green();
	ft_printf("FINISHED");
	return (FINISHED);
}
