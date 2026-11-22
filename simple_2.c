/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 13:00:03 by dlababne          #+#    #+#             */
/*   Updated: 2026/11/22 13:00:06 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	update_min_cost(int cost, int min_cost)
{
	if (cost < min_cost)
		return (cost);
	return (min_cost);
}

int	calculate_rotation_cases(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
	int	cost;
	int	min_cost;

	if (pos_a < 0 || pos_b < 0)
		return (-1);
	if (pos_a > pos_b)
		min_cost = pos_a;
	else
		min_cost = pos_b;
	if (pos_a == 0)
		cost = 0;
	else
		cost = a->size - pos_a;
	if (pos_b != 0 && b->size - pos_b > cost)
		cost = b->size - pos_b;
	min_cost = update_min_cost(cost, min_cost);
	if (pos_b == 0)
		cost = pos_a;
	else
		cost = pos_a + (b->size - pos_b);
	min_cost = update_min_cost(cost, min_cost);
	if (pos_a == 0)
		cost = pos_b;
	else
		cost = (a->size - pos_a) + pos_b;
	return (update_min_cost(cost, min_cost));
}

int	calculate_rotation_cost(t_stack *a, t_stack *b, t_node *candidate)
{
	t_node	*target;
	int		pos_a;
	int		pos_b;
	int		min_cost;

	if (!a || !b || !candidate || !a->top || !b->top)
		return (-1);
	target = find_target_position(b, candidate->rank);
	if (!target)
		return (-1);
	pos_a = get_position(a, candidate);
	pos_b = get_position(b, target);
	if (pos_a < 0 || pos_b < 0)
		return (-1);
	min_cost = calculate_rotation_cases(a, b, pos_a, pos_b);
	return (min_cost);
}

t_node	*find_cheapest_move(t_stack *a, t_stack *b)
{
	t_node	*current;
	t_node	*cheapest_node;
	int		cost;
	int		min_cost;

	current = a->top;
	min_cost = INT_MAX;
	cheapest_node = NULL;
	while (current)
	{
		cost = calculate_rotation_cost(a, b, current);
		if (cost >= 0 && cost < min_cost)
		{
			min_cost = cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	return (cheapest_node);
}
