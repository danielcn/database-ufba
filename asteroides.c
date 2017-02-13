
#include <stdio.h>
#include <stdlib.h>

int main(){
   FILE * fp;
   int cont=0,aux=0,i,j;
   char info[160],id[5];
	
   fp = fopen ("base2.txt", "r");
   while((fgets(info, sizeof(info), fp)) != NULL){
		for(i=0;i<160;i++){
			if(cont == 11){
				
				if(info[i] == ')'){
					printf("ID do asteroide = ");
					for(j=0;j<5;j++){
						if(id[j] != 'x')
							printf("%c",id[j]);
						id[j] = 'x';	
					}
					printf("\n");	
					aux = 0;
				}
				
				else{					
					id[aux] = info[i];
					aux++;
				}
			}
			
			if(info[i] == '('){
				cont = 0;
			}
			
			if(cont == 1 && info[i-1] != '(')
				cont = 0;
			
			if(info[i] == '(' || info[i] == 'a' || info[i] == 's' || info[i] == 't' || info[i] == 'e' || info[i] == 'r' || info[i] == 'o' || info[i] == 'i' || info[i] == 'd' || info[i] == 'e' || info[i] == ' '){
					cont++;	
			}
			
			else if(aux == 0)
				cont = 0;
			
		}
	   
   
   }
   fclose(fp);
   
   return(0);
}
