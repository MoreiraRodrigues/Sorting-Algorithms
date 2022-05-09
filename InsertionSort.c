#include<stdio.h>
#include<stdlib.h>

void insertion_sort (int vetor [], int tam)
{
    int i, j, key;
    for (i = 1; i < tam; i++)
    {
        key = vetor [i];
        j = i - 1;

        while ((j >= 0) && (vetor[j] > key)) 
        {
            vetor [j+1] = vetor [j];
            j --;
        }

        vetor [j+1] = key;
    }
}
int main ()
{
    int vetor [6] = {5, 4, 3, 8, 17, 1};

    insertion_sort(vetor, 6);

    for (int i = 0; i < 6; i++)
    {
        printf ("%d\n", vetor[i]);
    }

    return 0;
}