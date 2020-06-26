#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dim 30
#define lenght 11

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
list_t* pop(list_t*);
list_t* delete(list_t*, int);
void printlist(list_t*);



int main(int argc, char* argv[]){
    list_t* l=NULL;
    int numbers[lenght]={1,7,1,2,4,3,5,3,5,4,4}, i;

    for(i=0; i<lenght; i++){
        l=append(l,numbers[i]);
    }
    printlist(l);
    printf("-----\n");
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
            printf("%d: %d\n", l->val, contlist(l, l->val));
            head=delete(l, l->val);
            l=head;
        }
        else
            l=l->next;
        printlist(head);
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
    if(l->val == n)
        cont++;
    return cont;
}

list_t* delete(list_t* head, int i){
    list_t *l=head, *t=NULL;
    
    if(l){
        while(l->next){
            if(l->next->val==i){
                t=l->next;
                l->next=l->next->next;
                free(t);
            }
            l=l->next;
        }
        if(l->val == i)
            l=NULL;
        if(head->val == i){
            head=pop(head);
        }
    }

    return head;
}

list_t* pop(list_t* head){
    list_t* t=head;
    head=head->next;
    free(t);
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
        printf("%d -> ", l->val);
        l=l->next;
    }
    printf("null\n");
}