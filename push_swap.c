#include "push_swap.h"

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
    }
    return (0);
}