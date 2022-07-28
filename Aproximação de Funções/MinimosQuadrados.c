#include <stdio.h>

// CIC250 – Cálculo Numérico para Computação
// Exercicio Pratico 07 – 07/06/22
// 2019005687 - Matheus Martins Batista
// 2021020690 - Lucas Ferreira Alves 
// Aproximação de curvas pelo método dos Mínimos Quadrados

int main(){
    double somax = 0, somay = 0, somaxx = 0, somaxy = 0, a, b;
    int n, i;
    double x[10], y[10];

    printf("Digite o valor de n:\n");
    scanf("%d", &n);

    printf("Digite os valores de x e f(x):\n");
    for(i = 0; i < n; i++) {
      scanf(" %lf %lf", &x[i], &y[i]);
      somax += x[i];
      somaxx += x[i]*x[i];
      somay += y[i];
      somaxy += x[i]*y[i];
    }

    //calculando o valor de a e b para a + bx:
    b = (n*somaxy-somax*somay)/(n*somaxx-somax*somax);
    a = (somay - b*somax)/n;

  
    //imprimindo os valores de a e b calculados:

    printf("A regressão linear tem como a e b, respectivamente:\n");
    printf("%lf\n", a);
    printf("%lf\n", b);
    
    return 0;
}