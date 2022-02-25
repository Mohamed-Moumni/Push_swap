#include "push_swap.h"

int max_arr(int *tab, int size)
{
    int max;
    int i;

    i = 0;
    max = 0;
    while (i < size)
    {
        if (tab[i] >= max)
            max = tab[i];
        i++;
    }
    return (max);
}

void    array_init(int *tab, int size, int  number)
{
    int i;

    i = 0;
    while (i < size)
    {
        tab[i] = number;
        i++;
    }
}

int *LSI_PosInStack(t_stack **stack, int size, int *max, int j)
{
    t_stack *tmp1;
    t_stack *tmp2;
    int d[size];
    int *p;
    int i;

    array_init(d, size, 1);
    p = malloc(sizeof(int) * size);
    array_init(p, size, -1);
    tmp1 = *(stack);
    i = 0;
    while (i < size)
    {
        tmp2 = *(stack);
        j = 0;
        while (j < i)
        {
            if (tmp2->number < tmp1->number && d[i] <= d[j] + 1){
                d[i] = d[j] + 1;
                p[i] = j;
            }
            tmp2 = tmp2->next;
            j++;
        }
        tmp1 = tmp1->next;
        i++;
    }
    *max = max_arr(d, size);
    return (p);
}