#include <stdio.h>
#include <stdlib.h>
#define dim 1

typedef struct list_s{
    int val;
    struct list_s *next;
}list_t;

list_t* push(list_t*, int);
list_t* append(list_t*, int);
list_t* increasing(list_t*, int);
list_t* pop(list_t*);
list_t* delete(list_t*, int);
list_t* exists(list_t*, int);
int lenght(list_t*);
int contlist(list_t*, int);
void printlist(list_t*);

int main(int argc, char* argv[]){
    list_t* l=NULL;
    int numbers[dim]={3}, i;

    for(i=0; i<dim; i++){
        l=append(l,numbers[i]);
    }
    printf("---\n%d\n---\n", contlist(l, 3));
    printlist(l);
    printf("----\n");
    l=delete(l, 3);
    printlist(l);
    return 0;
}

list_t* push(list_t* head, int i){
    list_t* el;

    el=(list_t*) malloc(sizeof(list_t));
    el->val=i;
    el->next=head;

    return el;
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

list_t* increasing(list_t* head, int i){
    list_t *el, *l=head, *temp;

    el=(list_t*) malloc(sizeof(list_t));
    el->val=i;
    el->next=NULL;

    if(l == NULL){
        head=el;
    }
    else{
        while(l->next || l->next->val<i)
           l=l->next;
        el->next=l->next;
        l->next=el;
    }
    
    return head;
}

list_t* decreasing(list_t* head, int i){
    
}

list_t* pop(list_t* head){
    list_t* t=head;
    head=head->next;
    free(t);
    return head;
}

list_t* delete(list_t* head, int i){
    list_t *l=head, *t;
    
    if(l){
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
        if(head->val==i){
            t=head;
            head=head->next;
            free(t);
        }
    }

    return head;
}

list_t* exists(list_t* head, int i){
    list_t *l=head, *el=NULL;
    
    if(l){
        while(l->next){
            if(l->next->val==i){
                el=l->next;
            }
            l=l->next;
        }
        if(l->val == i)
            el=l;
    }
    
    return el;
}

int lenght(list_t* head){
    list_t *l=head;
    int i;

    i=0;
    while(l){
        i++;
        l=l->next;
    }
    
    return i;
}

int contlist(list_t *head, int i){
    list_t *l=head;
    int cont;

    cont=0;
    while(l->next){
        if(l->val == i)
            cont++;
        l=l->next;
    }

    return cont;
}

void printlist(list_t* head){
    list_t* l=head;
    
    while(l){
        printf("%d -> ", l->val);
        l=l->next;
    }
    printf("(null)\n");
}