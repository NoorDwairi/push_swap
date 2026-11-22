/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 13:00:14 by dlababne          #+#    #+#             */
/*   Updated: 2026/11/22 13:00:16 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rotate_forward(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
	while (pos_a > 0 && pos_b > 0)
	{
		rr(a, b);
		pos_a--;
		pos_b--;
	}
	while (pos_a-- > 0)
		ra(a);
	while (pos_b-- > 0)
		rb(b);
}

void	rotate_backward(t_stack *a, t_stack *b, int back_a, int back_b)
{
	while (back_a > 0 && back_b > 0)
	{
		rrr(a, b);
		back_a--;
		back_b--;
	}
	while (back_a-- > 0)
		rra(a);
	while (back_b-- > 0)
		rrb(b);
}

void	rotate_mixed(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
	int	back_a;
	int	back_b;

	back_a = a->size - pos_a;
	back_b = b->size - pos_b;
	if (pos_a <= back_a)
	{
		while (pos_a-- > 0)
			ra(a);
		while (back_b-- > 0)
			rrb(b);
	}
	else
	{
		while (back_a-- > 0)
			rra(a);
		while (pos_b-- > 0)
			rb(b);
	}
}

void	execute_move(t_stack *a, t_stack *b, t_node *candidate)
{
	t_node	*target;
	int		pos_a;
	int		pos_b;
	int		back_a;
	int		back_b;

	if (!a || !b || !candidate || !a->top || !b->top)
		return ;
	target = find_target_position(b, candidate->rank);
	pos_a = get_position(a, candidate);
	pos_b = get_position(b, target);
	if (!target || pos_a < 0 || pos_b < 0)
		return ;
	back_a = (pos_a == 0) ? 0 : a->size - pos_a;
	back_b = (pos_b == 0) ? 0 : b->size - pos_b;
	if (pos_a <= back_a && pos_b <= back_b)
		rotate_forward(a, b, pos_a, pos_b);
	else if (pos_a > back_a && pos_b > back_b)
		rotate_backward(a, b, back_a, back_b);
	else
		rotate_mixed(a, b, pos_a, pos_b);
	if (a->top == candidate && b->top == target)
		pb(a, b);
}

t_node	*find_target_in_a(t_stack *a, int rank)
{
	t_node	*current;
	t_node	*target;
	t_node	*min_node;

	if (!a || !a->top)
		return (NULL);
	current = a->top;
	target = NULL;
	min_node = current;
	while (current)
	{
		if (current->rank < min_node->rank)
			min_node = current;
		if (current->rank > rank)
			if (!target || current->rank < target->rank)
				target = current;
		current = current->next;
	}
	if (target)
		return (target);
	return (min_node);
}
