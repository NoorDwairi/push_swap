/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 08:56:08 by ndwairi           #+#    #+#             */
/*   Updated: 2026/10/20 09:33:25 by ndwairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_node
{
	int value;
	int rank;
	struct s_node *next;
} t_node;
typedef struct s_stack
{
	t_node *top;
	int size;
}t_stack;

