/* ES 1 */
/*
A = -95_16MS
B = -95_10MS

A)
	-A = +95_16MS = 010010101_2MS
	A = 101101011_2C2
	
B)
	-B = +95_10MS = 01011111_2MS
	B = 10100001_2C2
	
A+B)
	
	1 1 1 0 0 0 1 1
	1 0 1 1 0 1 0 1 1 +
	1 1 0 1 0 0 0 0 1 =
	-------------------
	1 0 0 0 0 1 1 0 0
	
	Overflow??
	
A-B)

	A+(-B)
	
	-B = 01011111_2C2
	
	0 1 1 1 1 1 1 1
	1 0 1 1 0 1 0 1 1 +
	0 0 1 0 1 1 1 1 1 =
	-------------------
	1 1 1 0 0 1 0 1 0
	
	No overflow poiche' somma di addendi con segno opposto non da mai overflow
*/

/* ES 2 */




/* ES 3 */
/*
#include <stdio.h>
#include <stdlib.h>

#define DIM 5

float* med(int x[], int n, int dim);

int main (int argc, char* argv[]){
	int x[DIM] = {10, 2, 3, 13, 101}, i;
	float *medie;
	
	medie=med(x, 3, DIM);
	
	for(i=0;i<DIM;i++){
		printf("%f\n", *(medie+i));
	}
	
	return 0;
}

float* med(int x[], int n, int dim){
	int i, j, somma, naddendi;
	float *medie;

	medie=(float*)malloc(sizeof(int)*dim);
	
	for(i=0; i<dim; i++){
		somma=0;
		naddendi=0;
		if(i<n)
			j=0;
		else
			j=i-n+1;
		for(j; j<=i;j++){
				somma+=x[j];
				naddendi++;
			}
		*(medie+i)=(float)somma/naddendi;
	}
	return medie;
}
*/

/* ES 4 */
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 500

int main(int argc, char* argv[]){
	char s[LEN+1] = "aabchhhhhpppzzzzz", c;
	int i, cont;
	
	
	i=strlen(s) - 1;
	for(i; i>=0;i--){
		cont=1;
		c=s[i];
		while(s[i-1]==c){
			cont++;
			i--;
		}
		printf("%c%d", c, cont);
	}
	printf("\n");
	
	return 0;
}
*/

/* ES 6 */

typedef struct term_s {
	int c; /* coefficiente */
	int p; /* potenza */
	struct term_s * next;
} term_t;

term_t* sum(term_t* h1, term_t* h2){
	term_t *ris=NULL, *l1=h1, *l2=h2, *temp;
	
	
	while(l1){
		ris = insord(ris, l1->c, l1->p)		/* assumo che il sottoprogramma insord sia stato 
											modificato per poter gestire elementi di struttura 
											term_t */
		l1=l1->next;
	}
	while(l2){
		temp = esiste(ris, l2->c, l2->p)	/* assumo che il sottoprogramma insord sia stato 
											modificato per poter gestire elementi di struttura 
											term_t */
		if(temp)
			temp->c+=l2->c
		else
			ris = insord(ris, l2->c, l2->p)		
		l2=l2->next;
	}
	
	return ris;
}

term_t *prod(term_t* h1, term_t* h2){
	term_t *ris=NULL, *l1=h1, *l2=h2, *temp;
	
	
	
	
	
	
	
}


































