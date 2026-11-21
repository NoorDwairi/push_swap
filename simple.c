/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <deema.lababneh@learner.42.tech>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 14:54:54 by dlababne          #+#    #+#             */
/*   Updated: 2026/11/21 22:51:44 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//simple_sort()
//find_target_position()
//find_cheapest_move()
//calculate_rotation_cost()
//execute_move()
//sort_three()
//move_back_to_a()
//rotate_min_to_top()


void sort_three( t_stack * a)
{
    t_node *max_node;
    if(!a || a-> size != 3)
    return;
    max_node = a-> top;
    if(max_node ->rank < a->top ->next->rank)
        max_node = a->top ->next;

    if(max_node ->rank < a->top ->next->next->rank)
       max_node = a->top ->next->next;
    if (max_node == a->top)
       ra(a);
    else if (max_node ==a->top->next)
       rra(a);
    if (a->top->rank > a->top->next->rank)
		sa(a);
}

t_node  *find_target_position(t_stack *b, int rank)
{
    t_node *current;
    t_node *target;
    t_node *max_node;
    
    if (!b || !b->top)
        return (NULL);
    current = b->top;
    target = NULL;
    max_node = current;
    while(current)
    {
        if(current->rank > max_node->rank)
            max_node= current;
        if(current->rank < rank)
            if(!target || current->rank > target->rank)
                target = current;
        current = current->next;
    }
     if (target)
        return (target);
    return (max_node);
}

int     get_position(t_stack *b, t_node *target)
{
    t_node *current;
    int pos;

    pos = 0;
    if(!b || !target || !b->top)
        return(-1);
    current = b->top ;
    while(current)
    {
        if (target->value == current->value && target->rank == current->rank)
            return(pos);
        current = current->next;
        pos++;
    }
    return(-1);
}

bool    is_sorted(t_stack *a)
{
    if (!a || !a->top)
        return (true);
    t_node *current;
    current = a->top;
    while(current->next)
    {
        if (current->rank > current->next->rank)
            return(false);
        current = current->next;
    }
    return(true);
}

int max(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}

t_node *find_cheapest_move(t_stack *a, t_stack *b)
{
    t_node *current;
    t_node *cheapest_node;
    int cost;
    int min_cost;

    current = a->top;
    min_cost = INT_MAX;
    cheapest_node = NULL;
    while(current)
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

void rotate_forward(t_stack *a, t_stack *b, int pos_a, int pos_b)
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

void rotate_backward(t_stack *a, t_stack *b, int back_a, int back_b)
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

void rotate_mixed(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
    int back_a;
    int back_b;

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

void execute_move(t_stack *a, t_stack *b, t_node *candidate)
{
    t_node  *target;
    int     pos_a;
    int     pos_b;
    int     back_a;
    int     back_b;

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
    if(a->top == candidate && b->top == target)
        pb(a, b);
}

////////calculate the cheapest rotations needed to bring the target and candidate to the top of stacks a and b
int	update_min_cost(int cost, int min_cost)
{
	if (cost < min_cost)
		return (cost);
	return (min_cost);
}

int calculate_rotation_cases(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
    int cost;
    int min_cost;

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
    int     min_cost;

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
////////
void    simple_sort(t_stack *a, t_stack *b)
{
    t_node *target;

    if (is_sorted(a))
        return;
    if (a->size <= 3)
    {
        sort_three(a);
        return ;
    }
    pb(a, b);
    pb(a, b);
    //b->size >= 2 && in the condition below is for checking weather I am trying to access a valid nodes 
    if (b->size >= 2 && b->top->rank < b->top->next->rank)
        rb(b);
    while(a->size > 3)  
    {
        find_cheapest_move(a,b);
        //|-- Execute cheapest move
        execute_move(a, b);
    }
    sort_three(a);
    move_back_to_a(b, a);
    //rotate a until the smallest element is at the top
    rotate_min_to_top(a);
}
if(a->size <= 3)
    sort_three(a);