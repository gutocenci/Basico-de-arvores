#include <string.h>
#include <stdio.h>

int flag;

int ViraPos (char *,char);
void Posfixa(char*,char*,int,int);
void Prefixa(char*, char*,int,int);


int main(){
    int Qtde , c , QtdeIn;
    char prefix[1001] , infix[1001];
    scanf("%d", &Qtde);
    while (Qtde--){
        flag = -1;
        scanf("%d %s %s", &QtdeIn , prefix , infix);
        Posfixa(prefix, infix, 0, QtdeIn-1);
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