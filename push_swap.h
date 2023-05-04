/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:18:34 by eweiberl          #+#    #+#             */
/*   Updated: 2023/05/04 15:51:47 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# ifndef FINISHED
#  define FINISHED 0
# endif

# ifndef WRONG_INPUT
#  define WRONG_INPUT 1
# endif

# ifndef ALLOC_FAIL
#  define ALLOC_FAIL -1
# endif

int	check_argv(int argc, char *argv[]);
int	isdigit_pm(char *s, int (*f)(int));

#endif