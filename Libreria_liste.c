#include <stdio.h>
#include <stdlib.h>
#define dim 10
typedef struct list_s{
    int val;
    struct list_s *next;
}list_t;

list_t* push(list_t*, int);
list_t* append(list_t*, int);
list_t* increasing(list_t*, int);
list_t* pop(list_t*);
list_t* delete(list_t* head, int i);
list_t* exists(list_t* head, int i);
int lenght(list_t* head);
void printlist(list_t*);

int main(int argc, char* argv[]){
    list_t* l=NULL;
    int numbers[dim]={1,2,3,4,5,6,7,8,3,0}, i;

    for(i=0; i<dim; i++){
        l=append(l,numbers[i]);
    }
    l=pop(l);
    l=delete(l, 3);
    printf("---\n%d\n---\n", lenght(l));
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
    head=head->next;

    return head;
}

list_t* delete(list_t* head, int i){
    list_t *l=head;
    
    if(l){
        while(l->next){
            if(l->next->val==i){
                l->next=l->next->next;
            }
            else
                l=l->next;
        }
        if(l->val == i)
            l=NULL;
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

void printlist(list_t* head){
    list_t* l=head;
    
    while(l){
        printf("%d\n", l->val);
        l=l->next;
    }
}