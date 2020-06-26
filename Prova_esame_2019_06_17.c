#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dim 30
#define lenght 10

typedef struct list_s{
    int val;
    struct list_s *next;
}list_t;

int numberCount(int);
int contaPrimi(int);
void leggiFile();
void leggiFile(char*, char*);
list_t* append(list_t*, int);
int contlist(list_t*, int);
list_t *delfromlist(list_t*, int);
list_t* delete(list_t*, int);
void printlist(list_t*);



int main(int argc, char* argv[]){
    list_t* l=NULL;
    int numbers[lenght]={3,3,1,2,4,3,5,3,5,4}, i;

    for(i=0; i<lenght; i++){
        l=append(l,numbers[i]);
    }
    printlist(l);
    printf("-----");
    l=delfromlist(l,3);
    printlist(l);
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

void leggiFile(char *nomefileR, char *nomefileW){
    FILE *read, *write;
    int x;
    
    read=fopen(nomefileR, "r");
    
    write=fopen(nomefileW, "w");
    if(read && write){
        fscanf(read ,"%d", &x);
        while(!feof(read)){
            fprintf(write, "%d %d\n", x, contaPrimi(x));
            fscanf(read ,"%d", &x);
        }
    }
}

list_t *delfromlist(list_t *head, int x){
    list_t *l=head;

    while(l->next){
        if(contlist(l, l->val) >= x){
            
            l=delete(l, l->val);
            //printlist(l);
        }
        else
            l=l->next;
    }

    return head;
}

int contlist(list_t *head, int n){
    list_t *l=head;
    int cont;

    cont=0;
    while(l->next){
        if(l->val == n)
            cont++;
        l=l->next;
    }
    //printf("%d: %d\n", n, cont);
    return cont;
}

list_t* delete(list_t* head, int i){
    list_t *l=head, *t;
    
    if(l){
        if(l->val == i){
            t=l;
            l=l->next;
            free(t);
        }
        while(l->next){
            if(l->next->val==i){
                t=l->next;
                l->next=l->next->next;
                free(t);
            }
            else
                l=l->next;
        }
        if(l->val == i)
            l=NULL;
    }
    
    return head;
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
        printf("%d\n", l->val);
        l=l->next;
    }
}