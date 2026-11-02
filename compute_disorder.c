#include "push_swap.h"

void    assign_ranks(t_stack *a)
{
	t_node		*current;
	t_node		*compare;
	int		rank;

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
// 5 ->67 ->82 -> 9
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
// the below function checks what strategy to use and return it 
// so i can decide which strategy to call
t_strategy get_strategy(char *arg)
{
    if (ft_strncmp(arg, "--simple", 9) == 0)
        return (SIMPLE);
    if (ft_strncmp(arg, "--medium", 9) == 0)
        return (MEDIUM);
    if (ft_strncmp(arg, "--complex", 10) == 0)
        return (COMPLEX);
    if (ft_strncmp(arg, "--adaptive", 11) == 0)
        return (ADAPTIVE);
    return (ADAPTIVE);
}

void    print_bench(t_bench *bench, t_stack *a, )
{
    printf("[bench] disorder: %.2f%%", (compute_disorder(&a)*100));
    printf("[bench] strategy: %s / O(n√n)", get_strategy(arg));
}