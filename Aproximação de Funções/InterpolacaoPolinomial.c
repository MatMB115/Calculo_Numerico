#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define l 3        //define as linhas
#define c 4         //define as colunas

// CIC250 – Cálculo Numérico para Computação
// Exercicio Pratico 05 – 17/05/22
// 2019005687– Matheus Martins Batista
// 2020003596- Kaique de Souza Leal Silva
// Aproximação de funções por Interpolação polinomial


void imprimeFormula(double a[l]){
    int i;
    char flag = {'F'};
    double k = 1,z=0;

    printf("Formula de Interpolacao Polinomial: \n\n");
    printf("g(x) = ");

    for(i=0;i<l;i++){
        if(i==0){
            printf("%lf",a[i]);
        }else{
            if(a[i] > 0){
              printf(" + %lf x^%d" ,a[i],i);
            }else{
              printf(" %lf x^%d" ,a[i],i);
            }
        }
    }
    printf("\nVerificacao da formula\n");
    while(flag == 'F'){
        printf("\nDigite o valor de x para encontrar y\n");
        scanf("%lf",&k);

        for(i=0;i<l;i++){
            if(i==0){
                z += a[i];
            }else{
                z += a[i] * pow(k,i);
            }
        }

        printf("O valor de y eh: %lf\n\n",z);
        z = 0;
        printf("Deseja sair do programa (V/F)?");
        scanf(" %c", &flag);
    }
}

void imprimeResultados(double M[l][c]){
    int i, j, k;
    double a[l], s;

    a[l-1] = M[l-1][c-1]/ M[l-1][l-1];  //calcula o valor da variavel x[l-1] (ultima linha da matriz) e salva no vetor

    printf("Resolucao do sistema: \n\n");

    for(k = l - 1; k >= 0; k--){    //essa funcao tem como objetivo calcular o valor das outras variaveis entre x[l-2] a x[0]
        s = 0;
        for(j= k + 1; j < l; j++){
            s = s + M[k][j] * a[j];
            a[k] = ((M[k][j + 1] - s)/(M[k][k]));  //calcula e armazena o valor da variavel x[i] (x0,x1, etc..) no seu respectivo
        }                                          //lugar 'i' no vetor x
    }


    for(i=0;i<l;i++){
        printf("a%d = %lf\n",i,a[i]);       //imprime o valor das variaveis
    }

    printf("\n\n");
    imprimeFormula(a);
    printf("\n\n");
}


void imprimeMatriz(double M[l][c]){
    int i,j;

    for(i=0;i<l;i++){ 
        printf("\n");
        for(j=0;j<c;j++){
            printf("%lf ",M[i][j]);
      }
    }
}

void EliminacaoGauss(double M[l][c]){

    int k, i, j;
    int aux1;
    double m, M2[l];

    for(aux1 = 0; aux1 < l ; aux1++){
        M2[aux1] = M[aux1][c-1];       //separa os coeficientes livres em um vetor
    }

    imprimeMatriz(M);
    printf("\n\n");

    for(k = 0; k < c; k++){
        for(i = k + 1; i < l; i++){

            m = (M[i][k]/M[k][k]);  //calcula o multiplicador
            M[i][k] = 0;  //zera o valor de a[i][k]
            for(j = k + 1; j < c; j++){
                M[i][j] = M[i][j] - (m * M[k][j]);
                M2[j] = M2[j] - (m * M2[k]);
            }

            imprimeMatriz(M);  //imprime a matriz a cada etapa realizada
            printf("\n\n");
        }
    }
    imprimeMatriz(M);  //imprime a matriz a cada etapa realizada
    printf("\n\n");

    imprimeResultados(M);   //chama a funcao de imprimir os resultados da vari�vel x

}

void preencheMatriz(){
    double M[l][c];
    int i,j;

    for(i=0;i<l;i++){                       //Colhe os elementos da matriz
        for(j=0;j<c;j++){
            scanf("%lf",&M[i][j]);
        }
    }

    EliminacaoGauss(M);  //chama a função para escalonar

}


int main()
{
    preencheMatriz(); //chama a funcao de preencher a matriz
    return(EXIT_SUCCESS);
    printf("\n\n");
}
