#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int atual;

int achaPos (char *infixa , char caracter)
{
   int i , tam = strlen(infixa);
   for(i=0;i<tam;i++)
   {
      if(infixa[i]==caracter)
        return i;
   }
   return -1;
}

void Posfixa(char* prefixa, char* infixa, int i, int j)
{
    int pos;
    if (i <= j)
    {
        atual++;
        pos = achaPos(infixa,prefixa[atual]);
        Posfixa(prefixa, infixa, i, pos-1);
        Posfixa(prefixa, infixa, pos+1, j);
        printf("%c", infixa[pos]);
    }
}

int main()
{
    int n;
    char pre[53] , in[53];
    while(scanf("%s %s", pre , in) != EOF)
    {
      atual = -1;
      n = strlen(pre)-1;
      Posfixa(pre,in,0,n);
      printf("\n");
    }

}