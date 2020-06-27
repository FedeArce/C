#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NCOL 2
#define DIM 25
#define NOME_FILE "dizionario.txt"

typedef struct list_s{
    int val;
    struct list_s *next;
}list_t;

void trasmit(int mat[][NCOL], int val, int* row, int *col);
int findletter(char string[], char c);
int dimmianagrammi(char string[]);
int isanagramma(char string[], char anagramma[]);
int dimmianagrammiint(int n);
list_t* append(list_t*, int);
list_t* int2list(int n);
void printlist(list_t* head);

int main(int argc, char* argv[]){
    /*assumo che la matrice sia quadrata*/
    /*int mat[NCOL][NCOL], row, col, val;

    mat[0][0]=1;
    mat[0][1]=2;
    mat[1][0]=3;
    mat[1][1]=4;
    val=10;

    trasmit(mat, val, &row, &col);
    printf("row:%d\ncol:%d\n", row, col);*/
    /*printf("%d\n",dimmianagrammiint(3790));*/

    list_t *l;
    int x;

    if(argc==2){
        sscanf(argv[1], "%d", &x);
        l=int2list(x);
    printlist(l);
    }

    
    
}

/*es 3*/
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

/*es 4*/
int dimmianagrammiint(int n){
    char string[DIM];
    int x;

    sprintf(string, "%d", n);
    x=dimmianagrammi(string);

    return x;
}

int dimmianagrammi(char string[]){
    FILE *f;
    char anagramma[DIM];
    int count;

    count=0;
    f=fopen(NOME_FILE, "r");
    if(f){
        fscanf(f,"%s", anagramma);
        while(!feof(f)){
            if(isanagramma(string, anagramma))
                count++;
            fscanf(f,"%s", anagramma);
        }
    }
    else{
        count=-1;
    }
    return count;
}

int isanagramma(char string[], char anagramma[]){
    int isan, i;

    isan=1;
    if(strlen(string)==strlen(anagramma)){
        for(i=0; string[i]!= '\0'; i++){
            if(findletter(string, anagramma[i])==0){
                isan=0;
            }
            if(findletter(anagramma, string[i])==0){
                isan=0;
            }
        }
    }
    else{
        isan=0;
    }
    if(isan==1)
        printf("%s\n", anagramma);
    return isan;
}

int findletter(char string[], char c){
    int i, res;

    res=0;
    for(i=0; string[i]!= '\0' && res==0; i++){
        if(string[i]==c)
            res=1;
    }
    return res;
}

/*es 5*/
list_t* int2list(int n){
    list_t* l=NULL;
    int t, m, x, i, ndigits;
    
    t=n;
    while(t<0){
        m=-t;
        x=m%10;
        for(i=0; i<x; i++){
            l=append(l, x);
        }
        t=t/10;
    }
    while(t>0){
        ndigits = floor(log10(abs(t))) + 1;
        x=t/pow(10, ndigits-1);
        for(i=0; i<x; i++){
            l=append(l, x);
        }
        t=t%(int)pow(10, ndigits-1);
    }

    return l;
}

list_t* append(list_t* head, int i){
    list_t *el, *l=head;
    el=(list_t*) malloc(sizeof(list_t));
    el->val=i;
    el->next=NULL;

    if(head == NULL){
        head=el;
    }
    else{
        while(l->next)
           l=l->next;
        l->next=el;
    }
    
    return head;
}

void printlist(list_t* head){
    list_t* l=head;
    
    while(l){
        printf("%d -> ", l->val);
        l=l->next;
    }
    printf("(null)\n");
}