#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) pow(14, (2 * x))
#define derivadaQuarta(x) (16 * (pow(14, (2 * x)) * pow(log(14), 4)))

// CIC250 – Cálculo Numérico para Computação
// Exercicio Pratico 10 – 08/07/22
// 2019005687 - Matheus Martins Batista
// 2020001519 - Mateus de Freitas Bonette
// Cálculo de Integral pelo Método de 1/3 de Simpsom

int main(){
    double a, b; //intervalo
    int subIntervalos, i = 0; //qtd de subintervalos
    double h; //diferença de subintervalo
    double aux, aux2; //auxiliar para calcular o valor das funções
    double x[100]; //qtd max de pontos x para subintervalos
    double fx[100]; //qtd max de pontos f(x) para subintervalos
    double integral = 0;
    double max = 0; //Maior valor em módulo de derivada segunda da função no intervalo fornecido
    double erro;

    printf("Intervalo [a,b]:");
    scanf(" %lf %lf", &a, &b);
    printf("\nQtd PAR de subintervalos:"); //Para rodar o caso não generalizada é só colocar 1 subintervalo
    scanf(" %d", &subIntervalos);
    if(subIntervalos % 2 != 0){
        printf("Qtd impar!");
        return 1;
    }
    else{
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
                if((i + 1) %2 == 0){ // Pontos de índice par NA TABELA são multiplicados por 2 e ímpares por 4, a tabela não começa com índice 0
                    integral += fx[i] * 4; 
                }
                else{
                    integral += fx[i] * 2; 
                }
            }
        }
        integral = integral * h/3;

        printf("\nO valor da integral: %lf", integral);

        //Calcular o erro
        for(i=0; i<subIntervalos+1; i++){
            aux = fabs(derivadaQuarta(x[i]));

            if(aux > max){
                max = aux;
            }
        }

        printf("\n\n|F''(x)MAX| entre [%lf,%lf] = %lf\n", a, b, max);

        erro = (pow(h,4)/180) * (b - a) * max;
        printf("\nErro = %lf \n", erro);
    }

    return 0;
}