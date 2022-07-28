#include <stdio.h>
#include <math.h>

// 2019005687– Matheus Martins Batista
// Cálculo de raízes para funções reais – Secante

//Define a função f(x)
#define f(x) (8 * sin(x) * exp(-x) -1) //Altere as funções aqui


int main() {
    double x, x0, x1, x2, E1, E2, qtd;
    int K;

    printf("Digite as aproximacoes do intervalo:");
    scanf(" %lf %lf", &x0, &x1);
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
        x2 = x1 - ((f(x1)/(f(x1) - f(x0)))*(x1 - x0));
        while(K <= qtd){ //definir o loop pela quantidade de iterações
            /*if(fabs(f(x2)) < E1 || fabs(f(x1)) < E1 || fabs(x2- x1) < E2 ){ //Garantir parada,
                printf("Precisao atingida");                                 //deve ser comentado
                break;                                                      //para iterar K vezes
            }*/
            //while (fabs(f(x2)) > E1 && fabs(x2 - x1) > E2) { //Definir loop pela precisão
            x0 = x1;
            x1 = x2;
            K++;
            x2 = x1 - ((f(x1)/(f(x1) - f(x0)))*(x1 - x0));
            printf("x2 = %lf\n", x2);
          }
        x = x2;
        printf("\nx = %lf em %d iteracoes", x, K-1);
    }

    return 0;
}