#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap (int *vetor, int *aux)
{
    int temp = *vetor;
    *vetor = *aux;
    *aux = temp;
}

void quick_sort (int *v, int size)
{
    if (size <= 1)
    {
        return;
    }
    else
    {
        int pivot = v[size/2];
        int a = 0;
        int b = size - 1;

        while (a < b)
        {
            while (v[a] <= pivot) a++;
            while (v[b] > pivot) b--;
            if (a <= b)
            {
                swap(&v[a], &v[b]);
            }
        }
        quick_sort(v, b);
        quick_sort(v+a, size - a);
    }

}

void leitura (int *vetor, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        scanf ("%d", &vetor[i]);
    }
}

void print (int *vetor, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (i == 0) printf ("\n----------\n");
        printf ("%d\n", vetor[i]);
    }
}

int main ()
{

    int *vetor = malloc(6*sizeof(int));

    leitura (vetor, 6);

    quick_sort(vetor, 6);

    print (vetor, 6);

    free (vetor);

    return 0;
}