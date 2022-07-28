#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 2019005687– Matheus Martins Batista
// Cálculo de raízes para funções reais – Limite sup, inf e passo

#define f(x) (x*x + 1.95*x - 2.09) //alterar a função aqui

int main(){
	
	float lsup, linf, passo;

	scanf(" %f", &lsup);
  scanf(" %f", &linf);
  scanf(" %f", &passo);

	float ant;

	for (float i = linf; i <= lsup; i++){
		if(i != linf){
      
			if(f(i) * f(ant) < 0) 
				printf("%f %f\n", i, ant);
		}
    
		ant = i;
	}
  
}