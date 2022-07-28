#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// CIC250 – Cálculo Numérico para Computação
// Exercicio Pratico 01 – 07/04/22
// 2019005687– Matheus Martins Batista
//
// Cálculo de raízes para funções reais – Bissecção

#define f(x) (x*x*x - 9*x + 3) 

int main(){

    double a,b,precisao,x,M;
    int c;   //numero de iterações

    printf("Digite o valor para A e B: ");
    scanf("%lf %lf",&a,&b);
    printf("Digite a precisao: ");
    scanf("%lf",&precisao);
    printf("\n\n");

    if (f(a) * f(b) > 0){
        printf("Nao eh possível calcular a raiz!\n"); //não existe um ponto entre a e b que é zero de f(x)
        return 0;
    }
    else{
     c = 1;
     while(c < 51){ //um dos casos de parada é que o número de iteração tem que ser menor que 51
        M = funcao(a);
        x = (a + b)/2;   //calcula o ponto médio de a e b

         if(M * f(x) > 0){
            a = x;  //se f(a) (ou M) multiplicado pela funcao(x) for maior que zero, 'a' recebe o valor de X
         }else{
            b = x;
         }
        //printf("C = %d; A = %lf\n",c,a);    //mostra a raiz a cada iteração

        if(fabs(b - a) < precisao){
            break;  //se o valor absoluto de b - a for menor que a precisão, sair do while
        }

         c++;  //soma mais um na quantidade de iteração
     }
    }

    printf("Numero de iteracoes: %d\nRaiz encontrada em: %lf\n",c,(a+b)/2);
    return (EXIT_SUCCESS);
}


