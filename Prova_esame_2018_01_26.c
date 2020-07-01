/* ES 1 */
/*
A = -58_10MS
B = +58_16MS

A)
	-A = +58_10MS = 0111010_2MS
	A = 1000110_2C2
	
B)
	B = +58_16MS = 001011000_2MS 
	B = 01011000_2C2
	
A+B)
	
	1 0 0 0 0 0 0
	1 1 0 0 0 1 1 0 +
	0 1 0 1 1 0 0 0 =
	-----------------
	0 0 0 1 1 1 1 0
	
No overflow: somma di addendi con segno opposto.

A-B)
	-B = 10101000_2C2
	
	
	0 0 0 0 0 0 0
	1 1 0 0 0 1 1 0 +
	1 0 1 0 1 0 0 0  =
	-----------------
	0 1 1 0 1 1 1 0
	
Si overflow: somma di addendi negativi non puo' dare risultato positivo.
*/

/* ES 2 */
/*
#include <stdio.h>
#include <stdlib.h>
#define NOME_FILE "ris.txt"


int main (int argc, char* argv[]){
	FILE *fp;
	int cont, i, n, resto;
	
	fp=fopen(NOME_FILE, "w");
	if(fp){
		scanf("%d", &n);
		while(n > 0){
			cont=0;
			for(i=2; i<=(n/2); i++){
				resto = n%i;
				if(resto == 0)
					cont++;
			}
			fprintf(fp, "%d %d\n", n, cont);
			scanf("%d", &n);
		}
	}
	return 0;
}
*/

/* ES 3 */
/*
#include <stdio.h>
#include <stdlib.h>
#define DIM 2

int ver (int x[][DIM]);

int main(int argc, char *argv[]){
	int mat[DIM][DIM] = {{3,6},{1,2}};
	
	printf("%d\n",ver(mat));
	return 0;
}

int ver (int mat[][DIM]){
	int i, j, prop;
	
	prop=1;
	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			if(mat[i][j]<1 || mat[i][j]>5)
				prop=0;
		}
	}
	return prop;
}
*/

/* ES 4 */
/*
#include <stdio.h>
#include <stdlib.h>
#define ZERO '0'

int checkISBN10 (char isbn[]);

int main (int argc, char* argv[]){
	char *isbn;
	
	if (argc == 2){
		isbn = argv[1];
		printf("%d\n",checkISBN10(isbn));
	}
	return 0;
}

int checkISBN10 (char isbn[]){
	int i, j, somme, sds, ris;
	
	somme=0;
	sds=0;
	for(i=0, j=0; isbn[i] != '\0'; i++){
		if(isbn[i] != '-'){
			somme+=isbn[i]-ZERO;
			sds+=somme;
		}
	}
	ris=0;
	if((sds % 11) == 0)
		ris =1;
	return ris;
}
*/

/* ES 5 */
/*
typedef struct list_s{
	int val;
	struct list_s next;
}list_t;



list_t* deletelimit (list_t* head, int val, int limit){
	int cont;
	list_t* l=head;
	
	while(l){
		if(l->val == val)
			cont++;
		l=l->next;
	}
	
	if(cont < limit)
		head=delete(head, val);
	
	return head;
}

list_t* delete (list_t* head, int val){
	list_t *l=head, *t;
	
	if(l){
		while(l->next){
			if(l->next->val == val){
				t=l->next;
				l->next == l->next->next;
				free(t);
			}
			else
				l=l->next;
		}
		if(l->val == val){
			l=NULL;
		}
		if(head->val == val){
			t=head;
			head=head->next;
			free(t);
		}
	}
	return head;
}
*/

/* ES 6 */
v		sizeof(int) * N
dv		sizeof(int) * N + int*
head	(sizeof(int) + sizeof(list*)) * N















