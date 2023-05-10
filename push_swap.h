/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:18:34 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/10 09:00:24 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/*                                Libraries                                   */
/* ************************************************************************** */

# include "libft/libft.h"

/* ************************************************************************** */
/*                               Return values                                */
/* ************************************************************************** */

# define FINISHED 0
# define SUCCESS 0
# define WRONG_INPUT 1
# define ALLOC_FAIL -1
# define EMPTY -1

# define A 1
# define B 2
# define SWAP 4
# define PUSH 8
# define ROT 16
# define REV 32

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
int		ft_circular_lstsize(t_stack *lst);

/* ************************************************************************** */
/*                              Stack functions                               */
/* ************************************************************************** */

t_stack	*init_stack(int argc, char *argv[]);
int		convertvals(t_stack *stack);

/* ************************************************************************** */
/*                              Check functions                               */
/* ************************************************************************** */

int		check_argv(int argc, char *argv[]);
int		check_duplicates(t_stack *stack);

/* ************************************************************************** */
/*                                 Push_swap                                  */
/* ************************************************************************** */

#endif