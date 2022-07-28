#include<stdio.h>

// 2019005687 - Matheus Martins Batista
// Interpolação Polinomial pelo Método de Newton

int main(){
    int i, j, n, a;
    char flag = 'T';
    int ordem, linha, aux = 0;
    double f0, f1, f2, k;
    double f[10][10]; //Guarda os pontos de x e respectivo f(x)
    double p[10][10]; //Guarda a tabela de diferenças divididas
    double x[10], y[10], poli[10]; //Calcular um valor de f(x) para um determina x

    for (i=0;i<10;i++){ //Inicializar os espaços de memória alocados
        for (j=0; j<10; j++){
            p[i][j]= -1000;
        }  
    }
    for (i=0;i<2;i++){ //Inicializar os espaços de memória alocados
        for (j=0; j<10; j++){
            p[i][j]= -1000;
        }  
    }
    
    printf("Digite o valor de n:");
    scanf(" %d", &n);

    printf("Forneca o valor x e f(x) respectivamente para os %d pontos:", n);
    for(i=0;i<n;i++){
        printf("\nValor X[%d] = ", i);
        scanf(" %lf", &f[0][i]);
        printf("Valor F(X%d) = ", i);
        scanf(" %lf", &f[1][i]);
    }

    for (i=0;i<n;i++){
        p[i][0] = f[1][i];
    }
    linha = n;
    
    for (ordem = 1; ordem < n; ordem++){
        linha--;
        aux = ordem;
        for (j=0;j<linha;j++){
            p[j][ordem] = (p[j+1][ordem-1]-p[j][ordem-1])/(f[0][aux]-f[0][j]);
            aux++;
        }
    }

    printf("Tabela de ODD\n");
    for(i = 0; i < n; i++){
        printf("\nOrdem[%d]", i);
        for(j = 0; j < n; j++){
            if(p[j][i] != -1000){
                printf("\nlinha[%d] = %lf", j, p[j][i]);
            }
        }
    }
    a = n;
    while(flag != 'F'){
        n = a;
        for(i = 0; i < n; i++){ //Copia as informações da matriz para os vetores de conta
            x[i+1] = f[0][i];
            y[i+1] = f[1][i];
        }
        //Reiniciar os fatores de conta
        f0 = y[1];
        f1 = 1;
        f2 = 0;
        j = 1;
        printf("\nForneca o valor x para obter f(x) respectivo\n");
        scanf(" %lf", &k);

        while(n!=1){
            for (i=1;i<=n-1;i++){
                poli[i] = ((y[i+1]-y[i])/(x[i+j]-x[i]));
                y[i] = poli[i];
            }
            f1=1;
            for(i=1;i<=j;i++){
                f1*=(k-x[i]);
            }
            f2+=(y[1]*f1);
            n--;
            j++;
        }

        f0+=f2;
        printf("f(%lf) = %lf\n", k , f0);
        printf("V - Calcular novo x\nF - Sair do programa\n");
        scanf(" %c", &flag);
    }
    return 0;
}
