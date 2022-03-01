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

int main(int ac, char **av)
{
    t_stack *stack;
    t_stack *stack2;
    t_stack *tmp_stack;
    t_size  *stack_size;
    t_size  *stack_size2;
    int i;
    int j;
    int value;

    j = ac - 2;
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
                stack->length = 1;
                stack->prev = -1;
                stack->index = j;
            }
            j--;
            i++;
        }
        LIS_in_stack(&stack, stack_size->size);
        get_LIS(&stack);
        A_to_B(&stack, &stack2, &stack_size, &stack_size2);
        // best_elem(&stack,&stack2);
        // printf("here\n");
        // if (stack_is_sorted(stack) == 0)
        //     exit(0);
        // ft_sort_five(&stack, &stack2, &stack_size, &stack_size2);
        // // ft_sort_three(&stack, &stack_size);
        // tmp_stack = stack;
        // while (tmp_stack)
        // {
        //     printf("%d ",tmp_stack->index);
        //     // printf("%d \n",tmp_stack->prev);
        //     tmp_stack = tmp_stack->next;
        // }
        // printf("\n");
        // tmp_stack = stack;
        // while (tmp_stack)
        // {
        //     // printf("%d \n",tmp_stack->length);
        //     printf("%d --- %d\n",tmp_stack->lis, tmp_stack->number);
        //     tmp_stack = tmp_stack->next;
        // }
        // tmp_stack = stack;
        // // printf("%s\n",tmp_stack);
        // while (tmp_stack)
        // {
        //     // printf("%d ", tmp_stack->prev);
        //     printf("%d ",tmp_stack->number);
        //     tmp_stack = tmp_stack->next;
        // }
        // printf("\n");
        tmp_stack = stack2;
        printf("The Stack B:\n");
        while (tmp_stack)
        {
            // printf("%d ", tmp_stack->prev);
            printf("%d ",tmp_stack->number);
            tmp_stack = tmp_stack->next;
        }
        tmp_stack = stack;
        printf("\nThe Stack A:\n");
        while(tmp_stack)
        {
            printf("%d ", tmp_stack->number);
            tmp_stack = tmp_stack->next;
        }
    }
    return (0);
}