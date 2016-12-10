#include <string.h>
#include <stdio.h>

int flag;

int ViraPos (char *,char);
void Posfixa(char*,char*,int,int);
void Prefixa(char*, char*,int,int);


int main(){
    int Qtde, aux;
    char prefix[1001] , infix[1001];
    scanf("%d", &Qtde);
    while(scanf("%s %s", prefix , infix) != EOF){
        aux=strlen(prefix)-1;
		flag = -1;
        Posfixa(prefix, infix, 0, aux);
        printf("\n");
    }
}

int ViraPos (char *infixa , char caracter){
   int aux=0,tamanho;
   tamanho = strlen(infixa);
   
   if(aux<tamanho){
	   while(aux<tamanho){
		  if(infixa[aux]==caracter)
		  return aux;
		  aux++;
	   }
   }else{
   return -1;
   }
}

void Posfixa(char* prefixa, char* infixa, int aux, int j){
    int pos;
    if (aux <= j)
    {
        flag++;
        pos = ViraPos(infixa,prefixa[flag]);
        Posfixa(prefixa, infixa, aux, pos-1);
        Posfixa(prefixa, infixa, pos+1, j);
        printf("%c", infixa[pos]);
    }
}