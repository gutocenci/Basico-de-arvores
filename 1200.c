#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct arvore {struct arvore *esq;
					   struct arvore *dir;
					   char valor;}TArvore; 
					   
int Saida;

TArvore * AchaPai(TArvore *r, int v)
{	if(r == NULL)
		return NULL;
	else
		if(v <= r->valor)
		  if(r->esq == NULL)
				return r;
			else
				return AchaPai(r->esq, v);
		else
			if(r->dir == NULL)
				return r;
			else
				return AchaPai(r->dir, v);
}


void ImprimeArvorein(TArvore*r){
	if(r != NULL){
		ImprimeArvorein(r->esq);
		if(Saida)
			printf(" %c",r->valor);
		else{
			printf("%c",r->valor);
			Saida++;
		}
		ImprimeArvorein(r->dir);
	}
}

void ImprimeArvorepre(TArvore*r){
	if(r != NULL){
		if(Saida)
			printf(" %c",r->valor);
		else{
			printf("%c",r->valor);
			Saida++;
		}
		ImprimeArvorepre(r->esq);
		ImprimeArvorepre(r->dir);
	}
}

void ImprimeArvorepos(TArvore*r){
	if(r != NULL){
		ImprimeArvorepos(r->esq);
		ImprimeArvorepos(r->dir);
		if(Saida)
			printf(" %c",r->valor);
		else{
			printf("%c",r->valor);
			Saida++;
		}
	}
}

int busca(TArvore *r, char vBusca)
{	if(r){
    if(r ->valor == vBusca)
			return 1;
    else{
		if(r ->valor < vBusca)
			return busca(r->dir, vBusca);
		else
			return busca(r->esq, vBusca);
    }
		return 0;
  }
}			   
					   
int main(){
	TArvore *raiz = NULL, *pai, *aux;
	char VArv,VBusca,opcao[8];

	
	while(scanf("%s",opcao)!=EOF){
		if(strcmp(opcao,"I")==0){
			
			scanf(" %c",&VArv);
			
			aux=(TArvore*)malloc(sizeof(TArvore));
			aux->valor=VArv;
			aux->dir=NULL;
			aux->esq=NULL;
			
			pai=AchaPai(raiz,VArv);
			if(pai==NULL)
				raiz = aux;
			else
				if(VArv <= pai->valor)
					pai->esq = aux;
				else
					pai->dir = aux;
		}
		
		else if(strcmp(opcao,"P")==0){
			scanf(" %c", &VBusca);
			if(busca(raiz,VBusca)==1)
				printf("%c existe\n", VBusca);
			else
				printf("%c nao existe\n", VBusca);
		}
		else{
			if(strcmp(opcao,"INFIXA")==0)
				ImprimeArvorein(raiz);
			
			
			if(strcmp(opcao,"PREFIXA")==0)
				ImprimeArvorepre(raiz);
			
			
			if(strcmp(opcao,"POSFIXA")==0)
				ImprimeArvorepos(raiz);

			printf("\n");
			Saida=0;
		}
	}
	return 0;
}