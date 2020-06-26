#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dim 30

int numberCount(int);
int contaPrimi(int);
void leggiFile();

int main(int argc, char* argv[]){
    leggiFile();
}

/*es3*/
int numberCount(int n){
    int t, i, x;

    t=n;
    i=0;

    while(t>0){
        x=t%10;
        if(x != 0){
            if(t%x == 0){
                i++;
            }
        }
        t=t/10;
    }

    return i;
}

/*es4*/
int contaPrimi(int n){
    int i, j, cont, primo;
    
    cont=0;
    for(i=2; i<=n; i++){
        primo=0;
        for(j=2; j<=(i/2) && primo==0; j++){
            if(i%j == 0){
                primo=1;
            }
        }
        /*printf("%d -> %d\n", i, primo);*/
        if(primo == 0)
            cont++;
    }
    return cont;
}

void leggiFile(){
    char nomefileR[dim], nomefileW[dim]="primi.txt";
    FILE *read, *write;
    int x;

    scanf("%s", nomefileR);

    read=fopen(nomefileR, "r");
    write=fopen(nomefileW, "w");

    fscanf(read ,"%d", &x);
    while(!feof(read)){
        fprintf(write, "%d %d\n", x, contaPrimi(x));
        fscanf(read ,"%d", &x);
    }

}