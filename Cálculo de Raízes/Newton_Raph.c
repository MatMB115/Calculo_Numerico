#include <stdio.h>
#include <math.h>

// 2019005687– Matheus Martins Batista
// Cálculo de raízes para funções reais – Newton-Raphson

//Define a função f(x)
#define f(x) (pow((x - 2), 4)) //Altere as funções aqui
//Define a função f'(x)
#define df(x) (4*pow((x - 2), 3)) //Altere a derivada aqui 
//Define a função f''(x)
#define dupdf(x)


int main() {
    double x, x0, x1, E1, E2, qtd;
    int K;
    
    printf("Digite a aproximacao 1:");
    scanf(" %lf", &x0);
    printf("Digite a precisao E1:");
    scanf(" %lf", &E1);
    printf("Digite a precisao E2:");
    scanf(" %lf", &E2);
    printf("Digite a quantidade de iteracoes:");
    scanf(" %lf", &qtd);
    
    if(fabs(f(x0)) < E1){
        x = x0;
        printf("x = %lf", x);
    }
    else {
        K = 1;
        x1 = x0 - f(x0) / df(x0);
        //while(K <= qtd){ //definir o loop pela quantidade de iterações
            /*if(fabs(f(x1)) < E1 || fabs(f(x0)) < E1 || fabs(x1 - x0) < E2 ){ //Essa condição é um critério de parada para precisão no modo de iterações K vezez
                printf("Precisao atingida");
                break;
            }*/
        while (fabs(f(x1)) > E1 && fabs(x1 - x0) > E2) { //Definir pela precisão
            x0 = x1;
            K++;
            x1 = x0 - f(x0) / df(x0);
            printf("x1 = %lf\n", x1);
        }
        x = x1;
        printf("\nx = %lf em %d iteracoes", x, K-1);
    }
    
    return 0;
}

