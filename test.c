#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static void test_free_stack(t_stack *a)
{
    t_node  *current;
    t_node  *next;

    current = a->top;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    a->top = NULL;
    a->size = 0;
}

static int test_build_stack(t_stack *a, int *ranks, int size)
{
    t_node  *node;
    t_node  *last;
    int     i;

    a->top = NULL;
    a->size = 0;
    last = NULL;
    i = 0;
    while (i < size)
    {
        node = malloc(sizeof(t_node));
        if (!node)
            return (0);
        node->value = ranks[i];
        node->rank = ranks[i];
        node->next = NULL;
        if (!a->top)
            a->top = node;
        else
            last->next = node;
        last = node;
        a->size++;
        i++;
    }
    return (1);
}

static void run_test(char *name, int *ranks, int size, double expected)
{
    t_stack a;
    double  result;

    if (!test_build_stack(&a, ranks, size))
    {
        test_free_stack(&a);
        printf("[ERROR] %s: allocation failed\n", name);
        return ;
    }
    result = compute_disorder(&a);
    if (result - expected < 0.0001 && expected - result < 0.0001)
        printf("[PASS] %s: %.2f\n", name, result);
    else
        printf("[FAIL] %s: got %.2f, expected %.2f\n",
            name, result, expected);
    test_free_stack(&a);
}

int main(void)
{
    int sorted[] = {0, 1, 2, 3, 4};
    int reversed[] = {4, 3, 2, 1, 0};
    int random[] = {4, 1, 3, 0, 2};
    int two[] = {2, 1};
    int one[] = {5};
    t_stack empty;

    printf("\n--- DISORDER TESTS ---\n");
    run_test("Already sorted", sorted, 5, 0.0);
    run_test("Reverse sorted", reversed, 5, 1.0);
    run_test("Random order", random, 5, 0.7);
    run_test("Two reversed elements", two, 2, 1.0);
    run_test("Single element", one, 1, 0.0);
    empty.top = NULL;
    empty.size = 0;
    printf("[PASS] Empty stack: %.2f\n", compute_disorder(&empty));
    printf("[PASS] NULL stack: %.2f\n", compute_disorder(NULL));
    printf("----------------------\n");
    return (0);
}