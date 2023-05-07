/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:18:34 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/07 18:10:22 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/*                                Libraries                                   */
/* ************************************************************************** */

# include <stdbool.h>
# include "libft/libft.h"


/* ************************************************************************** */
/*                               Return values                                */
/* ************************************************************************** */


# ifndef FINISHED
#  define FINISHED 0
# endif

# ifndef WRONG_INPUT
#  define WRONG_INPUT 1
# endif

# ifndef ALLOC_FAIL
#  define ALLOC_FAIL -1
# endif

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* ************************************************************************** */
/*                               List functions                               */
/* ************************************************************************** */

int		push(t_stack **stack, int value);
int		pop(t_stack **stack);
void	print_list(t_stack *head);
void	free_list(t_stack **stack);

/* ************************************************************************** */
/*                              Stack functions                               */
/* ************************************************************************** */

t_stack	*init_stack(int argc, char *argv[]);

/* ************************************************************************** */
/*                              Check functions                               */
/* ************************************************************************** */

int		check_argv(int argc, char *argv[]);
bool	check_duplicates(t_stack **stack, int size);

#endif