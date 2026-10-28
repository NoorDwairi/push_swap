/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:35:45 by dlababne          #+#    #+#             */
/*   Updated: 2026/10/22 10:41:24 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**arr;

	arr = set_arr(argv);
	init_stack(&a);
	init_stack(&b);
	if (validation == 0)
		return (0);
	if(!build_stack(arr))
		return(0);
	// split ✅
	// char **res = save the result of splitting args into array✅
	// check wether there is anything wrong , leave the program✅
	// atoi✅
	// make the stack✅
	// save the numbers into nodes✅
	// we must check if the argv is empty or not at the beginning✅
}
