#include <stdio.h>
#include <stdlib.h>

int main(){
   FILE * fp;
   int cont=1,aux=0,maiorcont=0,maior=0,contmax=0;
   char ch;
	
   fp = fopen ("base.txt", "r");
   while((ch=fgetc(fp)) != EOF){
   	   contmax++;
	   if(ch != '.'){
		   if(ch!='\n')
			aux++;
		}	
	   else{
	   		if(aux+1 > maior){
	   			maior = aux+1;
	   			maiorcont= cont;
	   		}
			printf("%d° sentenca tem %d caracteres\n",cont,aux+1);
			aux = 0;
			cont++;
			
		}	
   
   }
   printf("A maior sentenca esta na linha %d e tem %d caracteres\n",maiorcont,maior);
   printf("O numero total de caracteres e %d",contmax);
   fclose(fp);
   
   return(0);
}