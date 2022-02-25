#include "push_swap.h"

void    min_in_top(t_stack **stack, t_size **stack_size)
{
    int min;
    int size;

    size = (*stack_size)->size;
    min = min_stack((*stack), size);
    if (min == 1)
        return ;
    if (min < size / 2)
    {
        while (min--)
        {
            ft_rotate_a(stack, stack_size);
        }
    }
    else
    {
        while (size >= min)
        {
            ft_reverse_rotate_a(stack, stack_size);
            size--;
        }
    }
}
int LSI_start(int *tab, int max)
{
    int i;
    int j;

    i = 0;
    j = max - 1;
    while (i < max)
    {
        j = tab[j];
        i++;
    }
    return (j);
}

void    calculate_LIS(t_stack **stack, int size)
{
    int i;
    int *res;
    int j;
    t_stack *tmp_stack;
    int max;

    tmp_stack = (*stack);
    res = LSI_PosInStack(stack, size, &max, j);
    
    j = LSI_start(res, max);
    i = 0;
    while (i < size)
    {
        if (tmp_stack->number == res[j])
        {
            tmp_stack->lis = 1;
            j++;
        }
        tmp_stack = tmp_stack->next;
        i++;
    }
}

int main(int ac, char **av)
{
    t_stack *stack;
    t_stack *stack2;
    t_stack *tmp_stack;
    t_size  *stack_size;
    t_size  *stack_size2;
    int i; 
    int value;
    int *tab;

    i = 1;
    if (ac > 2)
    {
        stack = initialiser();
        stack2 = initialiser();
        stack_size = malloc(sizeof(t_size));
        stack_size2 = malloc(sizeof(t_size));
        stack_size->size = 0;
        stack_size2->size = 0;
        while(av[i])
        {
            if (check_number(av[i]) == 0)
            {
                value = fill_stack(&stack, av[i], &stack_size);
                if (i > 1)
                {
                    if(check_duplicate(stack, value))
                        ft_error();
                }
            }
            i++;
        }
        if (stack_is_sorted(stack) == 0)
            exit(0);
        ft_sort_five(&stack, &stack2, &stack_size, &stack_size2);
        tmp_stack = stack;
        while (tmp_stack)
        {
            printf("%d \n",tmp_stack->number);
            tmp_stack = tmp_stack->next;
        }
    }
    return (0);
}





        // min_in_top(&stack , &stack_size);
        // // printf("%d\n", stack_size->size);
        // value = 0;
        // calculate_LIS(&stack, stack_size->size);
        // tmp_stack = stack;
        // // printf("%d\n", value);
        // while (tmp_stack)
        // {
        //     printf("%d\n",tmp_stack->lis);
        //     tmp_stack = tmp_stack->next;
        // }
        // // i = 0;
        // // while (i < stack_size->size)
        // // {
        // //     printf("%d ", tab[i]);
        // //     i++;
        // // }