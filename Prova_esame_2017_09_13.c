#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define DIM 500

float varianza(int x[], int start, int end);
float *var(int x[], int n, int dim);
void vis(char str[]);

int main(int argc, char *argv[])
{
    /*float *k;
    int x[] = {10,
               2,
               3,
               13,
               101};
    k = var(x, 3, 5);*/
    vis("3333666221117777444444444444444440999");
    return 0;
}

/*es 2*/
float varianza(int x[], int start, int end)
{
    int i, somma;
    float media, varianza, sommav;

    somma = 0;
    for (i = start; i <= end; i++)
    {
        somma += x[i];
    }
    media = (float)somma / (end - start);
    sommav = 0;
    for (i = start; i <= end; i++)
    {
        sommav = (i[x] - media) * (i[x] - media);
    }
    varianza = sommav / (end - start);

    return varianza;
}

float *var(int x[], int n, int dim)
{
    int i, start;
    float *res;

    res = (float *)malloc(sizeof(float) * dim);
    if (res)
    {
        start = 0;
        for (i = 0; i < dim; i++)
        {
            if (i > n)
            {
                start = i - n;
            }
            *(res + i) = varianza(x, start, i);
            printf("%d,%d = %f\n", start, i, *(res + i));
        }
    }

    return res;
}

void vis(char str[])
{
    int i, cont;
    char c;    

    for (i=strlen(str)-1; i>=0; i--)
    {   
        c=str[i];
        cont=1;
        while(str[i-1]==c){
            cont++;
            i--;
        }
        printf("%c%d",c,cont);
    }
    printf("\n");
}