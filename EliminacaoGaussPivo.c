#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// CIC250 – Cálculo Numérico para Computação
// Exercicio Pratico 03 – 28/04/22
// 2019005687– Matheus Martins Batista
// 2020003596 - Kaique de Souza Leal Silva
//
// Solução de sistemas lineares - Eliminação de Gauss com Pivoteamento

//Essa função imprime os elementos de uma matriz
void imprimeMatriz(int l, int c, double matriz[l][c]){
    int i,j;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("%lf\t",matriz[i][j]); // \t - tabular para garantir o alinhamento das colunas
        }
        printf("\n");
    }
}

//Lê os elementos fornecidos para o usuário e preenche a matriz
void preencheMatriz(int l, int c, double matriz[l][c]){
    int i,j;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            scanf("%lf",&matriz[i][j]);
        }
    }
}

//Essa função percorre as matrizes atribuindo os valores dos elementos de mesma posição da primeira à segunda
void copiaMatriz(int l, int c, double matriz1[l][c], double matriz2[l][c]){
    int i,j;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            matriz2[i][j]=matriz1[i][j];
        }
    }
}

//Essa função faz o escalomento e registra a solução do sistema
void eleminacaoGauss(int l, int c, double a[l][c], double* Ico){
    int i,j,k,imp=0;
    double ti;
    for(i=0;i<l-1;i++){
        //Pivoteamento
        for(k=i+1;k<l;k++){
            //Se o maior elemento em valor absoluto da coluna a ser zerada pertence a linha k, então troca-se as linhas
            if(fabs(a[i][i])<fabs(a[k][i])){
                //Troca os elementos das ambas as linhas
                for(j=0;j<c;j++){                
                    double temp;
                    temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
                printf("Troca da linha L%d pela linha L%d\n", i+1, k+1);
            }
        }
    }
    //Realizar as operações elementares nas linhas da matriz para escaloná-la - Eliminação de Gauss
    for(i=0;i<l-1;i++){
        for(k=i+1;k<l;k++){
            double  term=a[k][i]/a[i][i];
            for(j=0;j<c;j++){
              a[k][j]=a[k][j]-term*a[i][j];
          }
        }
      imprimeMatriz(l,c,a);
      printf("\n");
    }
  //Verificar se é uma matriz impossível com os elementos da diagonal principal (det=0)
    for(i=0;i<c-1;i++){
      if(a[i][i] == 0){
        printf("Sistema Impossivel\n");
          exit(1);
      }
    }
    //Calcular e guardar o valor das incógnitas
    k = c-2;
    for(i=l-1;i>=0;i--){
        ti = a[i][c-1];
        for(j=c-1;j>k;j--){
            ti -= a[i][j] * Ico[j];
        }
        Ico[k] = ti/a[i][k];
        k--;
    }
}

//Verifica se a solução encontrada condiz com o valor dos termos independentes
void verificaMatriz(int l, int c, double matriz[l][c], double* Ico){
    int i, j;
    double sum , ti;
    for(i=0;i<l;i++){
        sum = 0;
        ti = matriz[i][c-1];
        for(j=0;j<=c-2;j++){
            sum += matriz[i][j]*Ico[j];
        }
        printf("\nO termo independente e %lf e o calculo com as variaveis foi %lf", ti, sum);
    }
}

int main(){

    int l, c, i;

    printf("Para modelo A.X = B\n");
    printf("Numero de linhas:\n");
    scanf(" %d",&l);
    printf("Numero de colunas (considere a ultima coluna como a matriz dos termos independentes):\n");
    scanf(" %d",&c);
    //Declarar a matriz após a leitura das informações
    double a[l][c];
    //Outra matriz para guardar os dados durante a execução do método de Eliminação de Gauss
    double U[l][c];
    //Vetor para guardar os valores das variáveis
    double* Ico =  (double*) malloc((c-2)*sizeof(double));
    for(i=0;i<c-2;i++){
        Ico[i] = 1;
    }
    printf("\nDigite os elementos da linha da matriz (incluse o termo independente):\n");
    preencheMatriz(l,c,a);
    copiaMatriz(l,c,a,U);
    //Execução
    eleminacaoGauss(l,c,U,Ico);
    printf("\nMatriz triangular superior apos a Eliminacao de Gauss:\n\n");
    //Vizualizar o resultado
    imprimeMatriz(l,c,U);
    printf("\nA solucao do sistema:");
    for(i=0;i<c-1;i++){
        printf("X%d = %lf ", i+1, Ico[i]);
    }
    printf("\n");
    //Verificar se a solução encontrada é desejada
    verificaMatriz(l,c,a,Ico);
}