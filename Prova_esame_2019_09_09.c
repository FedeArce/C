#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct intl_s{
    int val;
    struct intl_s *next;
}intl_t;

char *crop(char*, char);
intl_t *extract (intl_t*, int);
intl_t *append (intl_t*, int);

int main (int argc, char *argv[]){
    /*char *s;
    if(argc == 3){
        s=crop(argv[1], argv[2][0]);
        printf(" %s\n", s);
    }*/
}

//es 3
char *crop(char *frase, char ch){
    char *s;
    int i, j, p[2];
    
    for(i = 0, j = 0; *(frase+i) != '\0' && j<2; i++){
        if(*(frase+i)==ch){
            p[j]=i;
            j++;
        }
    }

    if(j < 2){
        s=NULL;
    }

    else{
        s=(char*)malloc(sizeof(char)*(p[1]-p[0]));
        for(i=p[0]; i<=p[1]; i++){
            *(s+i-p[0])=*(frase+i);
        }
    }
    
    return s;
}

intl_t *extract (intl_t* head, int bit){
    intl_t *informazione, *l=head;
    int i;

    while(l){
        for(i=0; i < head->next; i++){
            informazione=append(informazione, bit);
        }
        l=l->next;
        if(bit==0)
            bit=1;
        else
            bit=0;
    }
    return informazione;
}

intl_t *append (intl_t* head, int bit){
    intl_t *el, *l=head;
    
    while(l->next)
        l=l->next;
    el=(intl_t*) malloc(sizeof(intl_t));
    el->val=bit;
    el->next=NULL;
    l->next=el;
    return head;
}