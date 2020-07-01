/* ES 1 */
/*
A = +57_10MS
B = +3A_16MS

A)
	A = 0111001_2MS = 0111001_2C2
	
B)
	B = 000111010_2MS = 0111010_2C2
	
A+B)
	
	1 1 1 0 0 0
	0 1 1 1 0 0 1 +
	0 1 1 1 0 1 0 =
	--------------
	1 1 1 0 0 1 1
	
	A+B = 10011_2C2
	
	Overflow: somma di addendi positivi non puo' dare risultato negativo
	
A-B)

	-B = 1000110_2C2

	0 0 0 0 0 0
	0 1 1 1 0 0 1 +
	1 0 0 0 1 1 0 =
	--------------
	1 1 1 1 1 1 1
	
	A-B = 1_2C2
	
	Non overflow: somma di addendi opposti
*/
/* ES 2 */
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100

int main (int argc, char* argv[]){
	FILE *fp;
	char *nomefile, s[DIM], lunga[DIM];
	int righe, max, tot, i, cont;
	float media;
	
	if(argc == 2){
		nomefile = argv[1];
		if(fp=fopen(nomefile, "r")){
			fgets(s, DIM, fp);
			righe=0;
			max=0;
			tot=0;
			while(!feof(fp)){
				cont=0;
				for(i=0; s[i] != '\0'; i++){
					if(s[i] != ' ' && s[i] != '\n'){
						printf("%c", s[i]);
						cont++;
					}
				}
				
				printf("\n");
				if(cont>max){
					strcpy(lunga, s);
					max = cont;
				}
				tot+=cont;
				righe++;
				fgets(s, DIM, fp);
			}
			media = (float)tot/righe;
			printf("%d\n%d\n%d %f\n%s\n", righe, tot, max, media, lunga);
		}
		else
			printf("errore apertura file\n");
	}
	else
		printf("non hai inserito il nome del file\n");
	
	return 0;
}
*/

/* ES 3 */
/*
#include <stdio.h>
#include <stdlib.h>

int findmax(int x);

int main (int argc, char* argv[]){
	int n=12837491;
	
	printf("%d\n", findmax(n));
}

int findmax(int x){
	int n;
	
	if(x/10 != 0){
		n=findmax(x/10);
		x=x%10;
		if(x < n)
			x=n;
		}
	return x;
}
*/
/*
1232
123
12
1
x<n
2<1 no allora ritorna 2
3<2 no allora ritorna 3
2<3 si allora ritorna 3*/


/* ES 4 */
/*

#include <stdio.h>
#include <stdlib.h>

typedef struct list_s{
	int val;
	struct list_s* next;
}list_t;

list_t* alterna(list_t* h1, list_t* h2);
list_t* append(list_t* head, int val);
void printlist(list_t* head);

int main(int argc, char* argv[]){
	int n1[]={1, 3, 5, 7, 9, 11}, n2[]={2, 4, 6, 8}, i;
	list_t *l1=NULL, *l2=NULL, *ris=NULL;
	
	for(i=0; i<6; i++){
		l1=append(l1, n1[i]);
	}
	for(i=0; i<4; i++){
		l2=append(l2, n2[i]);
	}
	printlist(l1);
	printlist(l2);
	ris=alterna(l1,l2);
	printlist(ris);
}



list_t* alterna(list_t* h1, list_t* h2){
	list_t *l1=h1, *l2=h2, *ris=NULL;
	
	while(l1 && l2){
		ris=append(ris, l1->val);
		ris=append(ris, l2->val);
		l1=l1->next;
		l2=l2->next;
	}
	while(l1){
		ris=append(ris, l1->val);
		l1=l1->next;
	}
	while(l2){
		ris=append(ris, l2->val);
		l2=l2->next;
	}
	
	return ris;
}

list_t* append(list_t* head, int val){
	list_t *l=head, *el;
	
	el=(list_t*)malloc(sizeof(list_t));
	el->val=val;
	el->next=NULL;
	
	if(l){
		while(l->next)
			l=l->next;
		l->next=el;
	}
	else
		head=el;
		
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
*/

/* ES 5 */

#define DIM 10


int check(int a1[], int a2[], int dim){
	int ax[DIM], i, equals;
	
	equals = 0;
	
	for(i=0; i<dim; i++)
		ax[i]=a2[i];
		
	for(i=0; i<dim && !equals; i++){
		equals = equals(a1, ax, dim);
		ax = scorri(ax, dim);
	}
	
	return equals;
}

int* scorri(int x[], int dim){
	int i, prec, t;
	
	prec=x[0];
	for(i=1; i<dim; i++){
		t=x[i];
		x[i]=prec;
		prec=t;
	}
	x[0]=prec;
	
	return x;
}

int equals(int x1[], int x2[], int dim){
	int i, equals;
	
	equals = 1
	for(i=0; i<dim && equals; i++){
		if(x1[i] != x2[i])
			equals=0;
	}
	
	return equals;
}









