#include "push_swap.h"

void    min_in_top(t_stack **stack, t_size **stack_size)
{
    t_stack *tmp_stack;
    int     min;
    int     middle;
    tmp_stack = min_elem(*stack, (*stack_size)->size);
    // printf("%d\n", tmp_stack->number);

    min = tmp_stack->index;
    middle = (*stack_size)->size / 2;
    if (min > (middle))
    {
        min = (*stack_size)->size - (tmp_stack->index + 1) + 1;
    while (min--)
    {
        ft_reverse_rotate_a(stack, stack_size);
    }
    }
    else
    {
        while (min--)
        {
            ft_rotate_a(stack, stack_size);
        }
    }
}

int main(int ac, char **av)
{
    t_stack *stack;
    t_stack *stack2;
    t_stack *tmp_stack;
    t_stack *tmp_stack2;
    t_size  *stack_size;
    t_size  *stack_size2;
    int i;
    int j;
    int value;

    j = ac - 2;
    i = ac - 1;
    if (ac > 2)
    {
        stack = initialiser();
        stack2 = initialiser();
        stack_size = malloc(sizeof(t_size));
        stack_size2 = malloc(sizeof(t_size));

        stack_size->size = 0;
        stack_size2->size = 0;
        while(i > 0)
        {
            if (check_number(av[i]) == 0)
            {
                value = fill_stack(&stack, av[i], &stack_size);
                // if (i > 1)
                // {
                //     if(check_duplicate(stack, value))
                //         ft_error();
                // }
                stack->length = 1;
                stack->prev = -1;
                stack->index = j;
            }
            j--;
            i--;
        }
        index_stack(&stack);
        LIS_in_stack(&stack, stack_size->size);
        get_LIS(&stack, &stack_size);
        A_to_B(&stack, &stack2, &stack_size, &stack_size2);
        B_to_A(&stack, &stack2, &stack_size, &stack_size2);
        index_stack(&stack);
        min_in_top(&stack, &stack_size);
        print_stack(stack);
        // printf("\nstack A: ");
        // while (tmp_stack)
        // {
        //     printf("%d \n", tmp_stack->number);
        //     tmp_stack = tmp_stack->next;
        // }
        // tmp_stack = stack2;
        // printf("\nstack B: ");
        // while (tmp_stack)
        // {
        //     printf("%d ", tmp_stack->number);
        //     tmp_stack = tmp_stack->next;
        // }
        // tmp_stack = stack2;
        // while (tmp_stack)
        // {
        //     printf("prev[%d ] ", tmp_stack->prev);
        //     printf("lis[%d ] ", tmp_stack->lis);
        //     printf("\n");
        //     tmp_stack = tmp_stack->next;
        // }
        // printf("stack A: ");
        // tmp_stack = stack2;
        // while (tmp_stack)
        // {
        //     printf("[%d] [%d] \n", tmp_stack->index, tmp_stack->number);
        //     tmp_stack = tmp_stack->next;
        // }
        //indexation
        // printf("\n");
        // while (tmp_stack)
        // {
        //     printf("index [%d] elem[%d] prev [%d] lis [%d] length[%d]\n", tmp_stack->index,tmp_stack->number, tmp_stack->prev, tmp_stack->lis, tmp_stack->length);
        //     tmp_stack = tmp_stack->next;
        // }
        // // printf("here2\n");
        // printf("here3\n");
    }
    return (0);
}