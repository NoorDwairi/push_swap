#include "push_swap.h"

void    assign_ranks(t_stack *a)
{
	t_node		*current;
	t_node		*compare;
	int		rank;
    if (!a)
        return ;
	current = a->top;
	while(current)
	{
		rank = 0;
		compare = a -> top;
		while(compare)
		{
			if(current-> value > compare-> value)
				rank++;
			compare = compare -> next;
		}
		current -> rank = rank;
		current = current -> next;
	}
}

double  compute_disorder(t_stack *a)
{
    int     mistake;
    int     total_pairs;
    t_node *current;
    t_node *compare;
    if (!a || a->size < 2)
        return (0.0);
    current = a->top;
    mistake = 0;
    total_pairs = 0;
    while(current)
    {
        compare = current->next;
        while(compare)
        {
            total_pairs += 1;
            if(current->rank > compare->rank)
                mistake +=1;
            compare = compare->next;
        }
        current = current->next;
    }
    return ((double)mistake / total_pairs);
}

char	*strategy_name(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("Simple");
	if (strategy == MEDIUM)
		return ("Medium");
	if (strategy == COMPLEX)
		return ("Complex");
	if (strategy == ADAPTIVE)
		return ("Adaptive");
	return ("invalid");
}

void    print_bench(t_stack *a)
{
    if (!a || !a->config)
        return ;
    printf(stderr, "[bench] disorder: %.2f%%\n",
        a->config->disorder * 100);
    printf(stderr, "[bench] strategy: %s\n",
        strategy_name(a->config->selected));
    printf("[bench] total_ops: %d\n",
        a->config->total_ops);
    printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
        a->config->sa, a->config->sb, a->config->ss,
        a->config->pa, a->config->pb);
    printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
        a->config->ra, a->config->rb,  a->config->rr, a->config->rra,
        a->config->rrb, a->config->rrr);
}

char *measure_complexity(t_strategy used)
{
    if (used == SIMPLE)
        return ("O(n²)");
    if (used == MEDIUM)
        return ("O(n√n)");
    if (used == COMPLEX)
        return ("O(n log n)");
    return ("Unknown");
}
