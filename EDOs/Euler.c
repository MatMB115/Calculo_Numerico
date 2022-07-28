#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define df(x, y) ((pow(x,2) - 1.1) * y)
//#define segundaDerivada(x, y) ((2 * x * y))
#define df(x, y) ((1 + 2*x)*sqrt(y))
#define segundaDerivada(x, y) (2 * sqrt(y) + (x*x - 1.1)*(1 + 2*x)*sqrt(y))

// 2019005687 - Matheus Martins Batista
// Resolução de Equações Diferencias por Euler simples e estendido


int main(){
    double yAnt, xAnt, x, yN, h; //Variéveis da fórmula
    int op, subIntervalos;

    printf("Forneca as condicoes inicias conhecidas de y e x, respectivamente:\n");
    scanf(" %lf %lf", &yAnt, &xAnt);

    printf("\nQual valor limite superior para o X que se deseja encontrar?\n");
    scanf(" %lf", &x);

    printf("\nQual a qtd de subintervalos?\n");
    scanf(" %d", &subIntervalos);
    h = (x - xAnt)/subIntervalos;
    printf("\nh = %lf", h);

    printf("\nDeseja usar o metodo:");
    printf("\n1 - Simples");
    printf("\n2 - Estendido\n");
    scanf(" %d", &op);

    switch (op){
    //Método de Euler Simples
    case 1:
       
        while((float)xAnt < (float)x){ //limitar o escopo dos intervalos para float na comparação
            printf("Para y(%lf) = %lf + %lf * f(%lf, %lf)", xAnt + h, yAnt, h, xAnt, yAnt);
            yN = yAnt + h * df(xAnt,yAnt);
            printf("\ny(%lf) = %lf\n",xAnt+h,yN);

            yAnt = yN;
            xAnt += h;
        }

        printf("\nValor final de y(%lf): %lf \n", x, yN);
        break;

    //Método de Euler Estendido
    case 2:

        while((float)xAnt < (float)x){
            printf("Para y(%lf) = %lf + %lf * f(%lf, %lf) + (%lf * %lf)/2 * f''(%lf, %lf)", xAnt + h, yAnt, h, xAnt, yAnt, h, h,  xAnt, yAnt);
            yN = yAnt + h * df(xAnt,yAnt) + (pow(h,2)/2) * segundaDerivada(xAnt, yAnt);

            printf("\ny(%lf) = %lf\n",xAnt+h,yN);

            yAnt = yN;
            xAnt += h;
        }

        printf("\nValor final de y(%lf): %lf \n", x, yN);
        break;
    
    default:
        printf("Opcao inválida!");
        break;
    }
    
    return 0;
}