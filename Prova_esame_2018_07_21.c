/*
Es 1

A = -15_10MS
B = +15_16MS

A)
|A| = 15_10 = 1111_2
-A  = 01111_2MS
 A  = 10001_2C2

B)
 B  = 010101_2MS
 B  = 010101_2C2

A + B)

    1 0 0 0 1
    1 1 0 0 0 1 +
    0 1 0 1 0 1 =
    -------------
    0 0 0 1 1 0
    
A + B = 0110_2C2

Addendi opposti non possono mai dare overflow

A - B)

A + (-B)

-B = 101011_2C2

    0 0 0 1 1
    1 1 0 0 0 1 +
    1 0 1 0 1 1 =
    -------------
    0 1 1 1 0 0

A - B = 011100_2C2

Si verifica overflow dato che la somma di due numeri negativi non puo' dare risultato positivo

-------------------------------------------------------------------

Es 2

typedef struct list_s{
	int day;
	int month;
	int year;
	struct list_s *next;
}list_t;

-------------------------------------------------------------------

/*Es 3*/

#include <stdio.h>
#include <stdlib.h>

/*#define DIM 30

void rot (char voc[], int n);

int main (int argc, char* argv[]){
	/*char s[DIM];
	
	if(argc == 3){
		s=argv[1];
		rot(s, atoi(argv[2]));
	}
	printf("%s", s[]);*/
	/*
	char s[DIM]="Fondamenti";
	
	rot(s, 3);
	printf("%s\n", s);
	
	return 0;
}

void rot (char voc[], int n){
	int i, j;
	char temp, prec;
	
	for(i=0; i<n; i++){
		j=1;
		prec=voc[0];
		while(voc[j] != '\0'){
			temp=voc[j];
			voc[j]=prec;
			prec=temp;
			j++;
		}
		voc[0]=prec;
	}
}

/*Es 4

#define NCOL 2

int maxdiff (int mat[][NCOL], int nrow, int ncol);

int main(int argc, char* argv[]){
	int mat[NCOL][NCOL];
	
	mat[0][0]=3;
	mat[1][0]=7;
	mat[0][1]=1;
	mat[1][1]=7;
	
	printf("%d\n", maxdiff(mat, 2, 2));
	
	return 0;
}

int maxdiff (int mat[][NCOL], int nrow, int ncol){
	int i, j, max, min, diff, index;
	
	diff=0;
	
	for(i=0; i<ncol; i++){
		max=mat[0][i];
		min=mat[0][i];
		for(j=1; j<nrow; j++){
			if(mat[j][i] > max)
				max=mat[j][i];
			else if(mat[j][i] < min)
				min=mat[j][i];
		}
		if((max-min)>diff){
			diff=(max-min);
			index=i;
		}
	}
	
	return index;
}


/*Es 5*/
#define LEN 80
#define LROW 300

int main (int argc, char* argv[]){
	char s1[LEN+1], s2[LEN+1], so[LEN+1], s[LROW];
	int i;
	FILE *f1, *f2, *fo;
	
	gets(s1);
	gets(s2);
	gets(so);
	scanf("%d", i);
	
	if(i == 1 || i == 0){
		if(i == 1){
			f1 = fopen(s1, "r");
			f2 = fopen(s2, "r");
		}
		else if (i == 0){
			f1 = fopen(s2, "r");
			f2 = fopen(s1, "r");
		}
		fo=fopen(s3, "w");
		
		if(f1 && f2 && fo){
			fscanf(f1, "%s\n", s);
			while(!feof(f1)){
				fprintf(fo, "%s\n", s);
				fscanf(f1, "%s\n", s);
			}
			fscanf(f2, "%s\n", s);
			while(!feof(f1)){
				fprintf(fo, "%s\n", s);
				fscanf(f2, "%s\n", s);
			}
		}
		
		fclose(f1);
		fclose(f2);
		fclose(fo);
	}
	
	return 0;
}



 
