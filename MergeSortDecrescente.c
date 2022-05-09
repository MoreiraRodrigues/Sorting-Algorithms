#include<stdio.h>
#include<stdlib.h>
#include <math.h>

void merge (int vetor [], int inicio, int meio, int fim)
{
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;

    tamanho = fim - inicio + 1;

    p1 = inicio;
    p2 = meio + 1;

    temp = (int *) malloc(tamanho*sizeof(int));

    if (temp != NULL)
    {
        for (i = 0; i < tamanho; i++)
        {
            if (!fim1 && !fim2)
            {
                if (vetor [p1] > vetor[p2])
                {
                    temp [i] = vetor [p1 ++]; //Combinar ordenando

                }
                    
                else
                {
                    temp[i] = vetor [p2++];
                }
                if (p1 > meio) fim1 = 1;    //Vetor já acabou???
                if (p2 > fim) fim2 = 1;

            }
            else
            {
                if (!fim1)
                {
                    temp[i] = vetor[p1++];
                }
                else                        //Copia o que sobrar
                {
                    temp[i] = vetor[p2++];
                }
            }
        }

        
    }

    for (j = 0, k = inicio; j < tamanho; j++, k ++)
    {
        vetor [k] = temp[j];
    }

    free (temp);

}

void merge_sort (int vetor [], int inicio, int fim)
{
    int meio;

    if (inicio < fim) 
    {
        meio = floor ((inicio + fim) / 2);
        // Divide em duas metades
        merge_sort (vetor, inicio, meio);
        merge_sort (vetor, meio + 1, fim);

        merge (vetor, inicio, meio, fim); // Combina as duas metades
    }
}

int main ()
{
    int vetor [6] = {5, 4, 3, 8, 17, 1};

    merge_sort(vetor, 0, 5);

    for (int i = 0; i < 6; i++)
    {
        printf ("%d\n", vetor[i]);
    }

    return 0;
}