#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 10
#define X 'x'

typedef struct point_s
{
    int x;
    int y;
} point_t;

int regolare(point_t mat[][N]);
void genera(char string[]);
int strfind(char string[], char val);

int main(int argc, char *argv[])
{
    if (argc == 2)
        genera(argv[1]);
}

/*int regolare(point_t mat[][N])
{
    int diagonale, l, i, j, regolare;

    regolare = 1;
    diagonale = 0;

    for (i = 1; i < N; i++)
    {
        diagonale = diagonale + dist(mat[i - 1][i - 1], mat[i][i]);
    }
    /*row
    for (i = 1; i < N && regolare; i++)
    {
        l = 0;
        for (j = 1; j < N && regolare; j++)
        {
            l = l + dist(mat[i - 1][j - 1], mat[i - 1][j]);
        }
        if (l > diagonale)
            regolare = 0;
    }
    /*col
    for (i = 1; i < N && regolare; i++)
    {
        l = 0;
        for (j = 1; j < N && regolare; j++)
        {
            l = l + dist(mat[j - 1][i - 1], mat[j - 1][i]);
        }
        if (l > diagonale)
            regolare = 0;
    }

    return regolare;
}*/

void genera(char string[])
{
    int x;
    char *string0, *string1;

    string0 = malloc(sizeof(char)*strlen(string));
    string1 = malloc(sizeof(char)*strlen(string));
    strcpy(string0, string);
    strcpy(string1, string);
    x = strfind(string, X);
    if (x != -1)
    {   
        string0[x] = '0';
        string1[x] = '1';
        genera(string0);
        genera(string1);
    }
    else
        printf("%s\n", string);
}

int strfind(char string[], char val)
{
    int i, res;

    res = -1;

    for (i = 0; string[i] != '\0'; i++)
        if (string[i] == val)
            res = i;

    return res;
}