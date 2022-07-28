#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define f(x, y) (1 + (y*y))
//#define f(x, y) (1/(1 + (x*x)))
//#define f(x, y) (1 - (2*x*y))
//#define f(x, y) ((2*y) - (2*(x*x)) - 3)
#define f(x, y) ((y * pow(x,2)) + ((- 1.1) * y))

// 2019005687 - Matheus Martins Batista
// Resolução de Equações Diferencias pelo método de RungeKutta de Ordem 2 e 4


int main(){
    double yAnt, xAnt, a, b, yN, h, K1, K2, K3, K4; //Variéveis da fórmula
    int op, subIntervalos, i;

    printf("Forneca as condicoes inicias conhecidas de y e x, respectivamente:\n");
    scanf(" %lf %lf", &yAnt, &xAnt);

    printf("\nForneca o intervalo [a,b]:\n");
    scanf(" %lf %lf", &a, &b);

    printf("\nQual a qtd de subintervalos?\n");
    scanf(" %d", &subIntervalos);
    h = (b - a)/subIntervalos;
    printf("h = %lf", h);

    printf("\nDeseja usar o metodo:");
    printf("\n2 - Ordem 2");
    printf("\n4 - Ordem 4\n");
    scanf(" %d", &op);
    i = 0;
    switch (op){
    //RungeKutta Ordem 2
    case 2:
       
        while(i < subIntervalos){ //limitar o escopo dos intervalos para float na comparação
            printf("Para y(%lf) = %lf + %lf * (f(%lf, %lf) + (f(%lf + %lf, %lf + %lf * f(%lf, %lf))))", 
                        xAnt + h, yAnt, h/2, xAnt, yAnt, xAnt, h, yAnt, h, xAnt, yAnt);

            yN = yAnt + ((h/2) * (f(xAnt , yAnt) + f((xAnt + h), (yAnt + (h * f(xAnt, yAnt))))));
            printf("\ny(%lf) = %lf\n",xAnt+h,yN);

            yAnt = yN;
            xAnt += h;
            i++;
        }

        printf("\nValor final de y(%lf): %lf \n", xAnt, yN);
        break;

    //RungeKutta Ordem 4
    case 4:

        while(i < subIntervalos){
            K1 = f(xAnt, yAnt);
            K2 = f((xAnt + (0.5 * h)), (yAnt + ((0.5 * h) * K1)));
            K3 = f((xAnt + (0.5 * h)), (yAnt + ((0.5 * h) * K2)));
            K4 = f((xAnt + h), (yAnt + (h * K3)));

            printf("Para y(%lf) = %lf + %lf * (%lf + 2*%lf + 2*%lf + %lf)", xAnt + h, yAnt, h/6, K1, K2, K3, K4);
            yN = yAnt + ((h/6) * (K1 + (2 * K2) + (2 * K3) + K4));

            printf("\ny(%lf) = %lf\n",xAnt+h,yN);

            yAnt = yN;
            xAnt += h;
            i++;
        }

        printf("\nValor final de y(%lf): %lf \n", xAnt, yN);
        break;
    
    default:
        printf("Opcao inválida!");
        break;
    }
    
    return 0;
}