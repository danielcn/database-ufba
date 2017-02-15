#include <stdio.h>
#include <stdlib.h>

int main(){
   FILE * fp;
   int cont=1,aux=0,aux2=0,maiorcont=0,maior=0,contmax=0, vetor[200],digit=0;
   char ch, string[5];
	
   fp = fopen ("base.txt", "r");
   while((ch=fgetc(fp)) != EOF){
   	   contmax++;
	   if(ch != '.'){
		   if(ch!='\n'){
			aux++;
			}
		}	
	   else{
	   		if(aux+1 > maior){
	   			maior = aux+1;
	   			maiorcont= cont;
	   		}
			printf("%d° sentenca tem %d caracteres e %d palavras\n",cont,aux+1, aux2+1);
			aux = aux2 = 0;
			cont++;
			
		}	
		if (ch == ' ')
			aux2++;
		
   }
   printf("A maior sentenca esta na linha %d e tem %d caracteres\n",maiorcont,maior);
   printf("O numero total de caracteres e %d",contmax);
   fclose(fp);
   
   return(0);
}