#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) (6 + 3*cos(x))
#define derivadaSegunda(x) (-3*cos(x))

// CIC250 – Cálculo Numérico para Computação
// Exercicio Pratico 09 – 28/06/22
// 2019005687 - Matheus Martins Batista
// 2018007720 - Vinícius Duarte Santiago Souza
// Cálculo de Integral pelo Método do Trapézio Generelizado

int main(){
    double a = 0, b = M_PI; //intervalo
    int subIntervalos = 6, i = 0; //qtd de subintervalos
    double h; //diferença de subintervalo
    double aux, aux2; //auxiliar para calcular o valor das funções
    double x[100]; //qtd max de pontos x para subintervalos
    double fx[100]; //qtd max de pontos f(x) para subintervalos
    double integral = 0;
    double max = 0; //Maior valor em módulo de derivada segunda da função no intervalo fornecido
    double erro;

    //printf("Intervalo [a,b]:");
    //scanf(" %lf %lf", &a, &b);
    //printf("\nQtd de subintervalos:"); //Para rodar o caso não generalizada é só colocar 1 subintervalo
    //scanf(" %d", &subIntervalos);

    h = (b - a)/subIntervalos;
    printf("h = %lf\n", h);
    //Calcular os pontos
    printf("\nTabelar os pontos usados:\n");
    printf("x \t \t f(x)\n");
    aux2 = a;
    for(aux = subIntervalos; aux >= 0; aux--){
        x[i] = aux2;
        fx[i] = f(aux2);
        printf("%lf \t %lf\n", x[i], fx[i]);
        aux2+= h;
        i++;
    }

    //Calcular a integral
    for(i = 0; i <= subIntervalos; i++){
        if(i == 0 || i == subIntervalos){
            integral += fx[i];
        }
        else{
            integral += fx[i] * 2;
        }
    }
    integral = integral * h/2;

    printf("\nO valor da integral: %lf", integral);

    //Calcular o erro
    for(i=0; i<subIntervalos+1; i++){
        aux = fabs(derivadaSegunda(x[i]));

        if(aux > max){
            max = aux;
        }
    }

    printf("\n\n|F''(x)MAX| entre [%lf,%lf] = %lf\n", a, b, max);

    if(subIntervalos == 1){
        erro = (pow(h,3)/12) * max;
        printf("\nErro = %lf \n",erro);
    }
    else{
        erro = (pow(h,2)/12) * (b - a) * max;
        printf("\nErro = %lf \n", erro);
    }
    

    return 0;
}