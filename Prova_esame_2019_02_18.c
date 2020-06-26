#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NCOL 2

void trasmit(int mat[][NCOL], int val, int* row, int *col);

int main(int argc, char* argv[]){
    /*assumo che la matrice sia quadrata*/
    int mat[NCOL][NCOL], row, col, val;

    mat[0][0]=1;
    mat[0][1]=2;
    mat[1][0]=3;
    mat[1][1]=4;
    val=10;

    trasmit(mat, val, &row, &col);
    printf("row:%d\ncol:%d\n", row, col);
}

void trasmit(int mat[][NCOL], int val, int* row, int *col){
    int i, j, cont;

    cont=0;
    
    for(i=0; i<NCOL && cont<=val; i++){
        for(j=0; j<NCOL && cont<=val; j++){
            cont=cont+mat[i][j];
        }
    }
    
    if(cont>val){
        *row=i-1;
        *col=j-1;
    }
    else{
        *row=-1;
        *col=-1;
    }
    return;
}