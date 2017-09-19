#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 10
#define PATH ""



typedef struct asd {
	char tipo;
	size_t qtde;
} STR;
0

/*typedef struct _node{
	char data;
	struct _node * esq
	struct _node * dir;	
}NODE;*/

typedef struct No{
	int dado;
	struct No * esq;
	struct No * dir;
}No;

typedef struct abb
{
	struct No *raiz;
}abb;

void quickSort(STR  * vet, int ini, int fim) {
	int ph = ini, i, i2;
	STR * pt = vet, k;

	for (i = ini + 1; i <= fim; i++) {
		i2 = i;
		if (pt[i2].qtde < pt[ph].qtde) {
			k = pt[i2];
			while (i2 > ph) {
				pt[i2] = pt[i2 - 1];
				i2--;
			}
			pt[i2] = k;
			ph++;
		}

		if (ph - 1 >= ini)
			quickSort(pt, ini, ph - 1);
		if (ph + 1 <= fim)
			quickSort(pt, ph + 1, fim);
	}
}
/**NODE * create_node(char dado){
	NODE * res = NULL;
	 res = (NODE *) malloc(sizeof(NODE));
	 
	 if(res == NULL){
	 	printf("BO NO MALLOC");
	 	exit(1);
	 }
	 
	 res -> data = dado;
	 return res;
	*/


No *insere_elemento(abb *arvore, int e){
	No *p = (No*)malloc(sizeof(No));
	No *q = arvore->raiz;
	No *pai;

	if(arvore->raiz == NULL)
	{
		
printf("AQUI");
		p->dado = e;
		p->dir = NULL;
		p->esq = NULL;
		arvore->raiz = p;
		return 0;
	}else{
		while(q != NULL){
			pai = q;
			if(e < q->dado)	
				q = q->esq;	
			else
				q = q->dir;
		
		}
		
		if(e < pai->dado)
		{
			p->dir = NULL;
			p->esq = NULL;
			pai->esq = p;
			p->dado = e;
		}
		else
		{	
			p->dir = NULL;
			p->esq = NULL;
			pai->dir = p;	
			p->dado = e;
		}
	}
	
	return 0;
}void print2DUtil(No *root, int space){
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->dir, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->dado);
 
    // Process left child
    print2DUtil(root->esq, space);
}

void imprime_preordem(No *raiz){
	if(raiz != NULL)
	{
		printf("  %c  ",raiz->dado);
		imprime_preordem(raiz->esq);
		imprime_preordem(raiz->dir);
	}
}


int main() {
	int * aparicoes = (int *) calloc(255 , sizeof(int));
	STR * liso;
	FILE * file = fopen(PATH, "rb");
	char * TESTE_STRING = "6AAAAAA 8BBBBBBBB 9CCCCCCCCC 3EEE 2KK 1A";
	int i = 0, j = 0, k = 0;
	abb  arvore;
	
	for (i = 0; i < strlen(TESTE_STRING); i++) 
		aparicoes[TESTE_STRING[i]]++;
	

	for (i = 0; i < 255; i++)
		if (aparicoes[i] != 0)
			j++;

	liso = (STR * ) malloc(sizeof(STR) * j);
	if (liso == NULL)
		printf("ERRO NO MALLOC");
	for (i = 0; i < 256; i++) {
		if (aparicoes[i] != 0) {
			liso[k].tipo = (char) i;
			liso[k].qtde = aparicoes[i];
			k++;
		}
	}

	for (i = 0; i < j; i++) {
		printf("tipo: %c, qtde: %d\n", liso[i].tipo, liso[i].qtde);
	}

	quickSort(liso, 0, j);

	
printf("\n\nAFTER quicksort\n\n"); 
	for (i = 0; i < j; i++) {
		printf("tipo: %c, qtde: %d\n", liso[i].tipo, liso[i].qtde);
	}
	
	for(i = j - 1; i>=0;i--){
		printf("I: %d, DADO: %c\n", i, liso[i].tipo);
		insere_elemento(&arvore, (int)liso[i].tipo);
	} 
//	printf("AAAA: %c", arvore.raiz.dado);
	printf("ARVORE INICIALIZADA:\n\n");
	imprime_preordem(arvore. raiz);
	
	system("PAUSE");
	return 0;

}




