#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct regNo{
	struct regNo *esq;
	char info;
	struct regNo *dir;
	int n, valor;
	struct regNo *pRaiz;
};
typedef struct regNo TNo;
typedef struct{TNo *raiz;}TDesc;
TNo *AchaPai( TNo *r, int n );
TNo *MaiorDireita(TNo **no);
void remover(TNo **pRaiz, int n);
int pesquisanum(int, TNo *);
void inicializa(TDesc *);
void ImprimeArvorePre(TNo *r, int n);
void ImprimeArvoreIn(TNo *r, int n);
void ImprimeArvorePost(TNo *r, int n);

int Saida,v;

int main()
{
	TNo *raiz = NULL, *aux, *pai;
	char opcao[8];
	int num;
	TDesc d;
	inicializa(&d);
	
	while(scanf("%s", opcao) != EOF)
	{
		if(strcmp(opcao,"P")==0)
		{
			scanf("%d", &num);
			if(pesquisanum(num, raiz)>=1)
				printf("%d existe\n", num);
			else
				printf("%d nao existe\n", num);
		}
		else
			if(strcmp(opcao,"R")==0)
			{
				scanf("%d", &num);
				remover( &raiz, num );
			}
		else
			if(strcmp(opcao,"I")==0)
			{
				scanf("%d", &num);
				aux = (TNo *) malloc( sizeof(TNo) );
				aux->valor = num;
				aux->dir = NULL;
				aux->esq = NULL;
				pai = AchaPai( raiz, num );
				if( pai == NULL )
					raiz = aux;
					
				else
					if( num <= pai->valor )
						pai->esq = aux;
					else
						pai->dir = aux;
			}
		else
		{
			if(strcmp(opcao,"INFIXA")==0)
			{
				ImprimeArvoreIn(raiz,0);
			}
				if(strcmp(opcao,"PREFIXA")==0)
				{
					ImprimeArvorePre(raiz,0);
				}
			if(strcmp(opcao,"POSFIXA")==0)
			{
				ImprimeArvorePost(raiz,0);
			}
			printf("\n");
			Saida=0;
		}
	}
	
	return 0;
}

TNo *AchaPai( TNo *r, int n )
{
	if( r == NULL )
		return NULL;
	else
		if( n <= r->valor )
		if( r->esq == NULL )
			return r;
		else
			return AchaPai( r->esq, n );
		
		else
		if( r->dir == NULL )
			return r;
		else
			return AchaPai( r->dir, n );
}

TNo *MaiorDireita(TNo **no){
    if((*no)->dir != NULL) 
       return MaiorDireita(&(*no)->dir);
    else{
       TNo *aux = *no;
       if((*no)->esq != NULL)
          *no = (*no)->esq;
       else
          *no = NULL;
       return aux;
       }
}

void remover(TNo **pRaiz, int valor){
    if(*pRaiz == NULL){   
       getchar();
       return;
    }
    if(valor < (*pRaiz)->valor)
       remover(&(*pRaiz)->esq, valor);
    else 
       if(valor > (*pRaiz)->valor)
          remover(&(*pRaiz)->dir, valor);
       else{    
          TNo *pAux = *pRaiz;
          if (((*pRaiz)->esq == NULL) && ((*pRaiz)->dir == NULL)){         
                free(pAux);
                (*pRaiz) = NULL; 
               }
          else{
             if ((*pRaiz)->esq == NULL){
                (*pRaiz) = (*pRaiz)->dir;
                pAux->dir = NULL;
                free(pAux); pAux = NULL;
                }
             else{            
                if ((*pRaiz)->dir == NULL){
                    (*pRaiz) = (*pRaiz)->esq;
                    pAux->esq = NULL;
                    free(pAux); pAux = NULL;
                    }
                else{   
                   pAux = MaiorDireita(&(*pRaiz)->esq); 
                   pAux->esq = (*pRaiz)->esq;     
                   pAux->dir = (*pRaiz)->dir;
                   (*pRaiz)->esq = (*pRaiz)->dir = NULL;
                   free((*pRaiz));  *pRaiz = pAux;  pAux = NULL;   
                   }
                }
             }
          }
}

void ImprimeArvorePre(TNo *r, int n)
{
	int c;
	if( r != NULL )
	{
		if(Saida)
			printf(" %d", r->valor);
		else
		{
			printf("%d", r->valor);
			Saida++;
		}
		ImprimeArvorePre(r->esq, n+1);
		ImprimeArvorePre(r->dir, n+1);
	}
}

void ImprimeArvoreIn(TNo *r, int n)
{
	int c;
	if( r != NULL )
	{
		ImprimeArvoreIn(r->esq, n+1);
		if(Saida)
			printf(" %d", r->valor);
		else
		{
			printf("%d", r->valor);
			Saida++;
		}
		ImprimeArvoreIn(r->dir, n+1);
	}
}

void ImprimeArvorePost(TNo *r, int n)
{
	int c;
	if( r != NULL )
	{
		ImprimeArvorePost(r->esq, n+1);
		ImprimeArvorePost(r->dir, n+1);
		if(Saida)
			printf(" %d", r->valor);
		else
		{
			printf("%d", r->valor);
			Saida++;
		}
	}
}

void inicializa(TDesc *d){
	d->raiz = NULL;
	Saida=0;
}

int pesquisanum(int num, TNo *r){
	int axou;
	if(r != NULL){
		if(r->valor == num)
			return 1;
		else
		{
			axou=pesquisanum(num, r->esq);
			axou=pesquisanum(num, r->dir)+axou;
			return axou;
		}
			
	}
	else
		return 0;
}