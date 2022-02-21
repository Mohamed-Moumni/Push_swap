#include "push_swap.h"


void    print_s(t_stack *stack)
{
    t_stack *tmp;
    
    tmp = stack;
    while (tmp)
    {
        printf("%d\n",tmp->number);
        tmp = tmp->next;
    }
}
int main(int ac, char **av)
{
    t_stack *stack;
    int i;
    int value;

    i = 1;
    if (ac > 2)
    {
        stack = initialiser();
        while(av[i])
        {
            if (check_number(av[i]) == 0)
            {
                value = fill_stack(&stack, av[i]);
                if (i > 1)
                {
                    if(check_duplicate(stack, value))
                        ft_error();
                }
            }
            i++;
        }
        ft_sort_three(&stack);
        print_s(stack);
    }
    return (0);
}