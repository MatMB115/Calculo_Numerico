#include<stdio.h>

// CIC250 – Cálculo Numérico para Computação
// Exercicio Pratico 05 – 17/05/22
// 2019005687– Matheus Martins Batista
// 2020003596- Kaique de Souza Leal Silva
// Aproximação de funções por Lagrange

int main(){
    double x[100],y[100],a,s=1,t=1,k=0;
    int n,i,j;
    //double c=1,b=1;
    char flag = {'V'};
    printf("Entre com o numero de termos da tabela: ");
    scanf("%d",&n);
    printf("Entre com os valores de x e y: \n");
    for(i=0; i<n; i++)
    {
        scanf (" %lf",&x[i]);
        scanf(" %lf",&y[i]);
    }
    while( flag == 'V'){
        printf("Entre com o valor de x para achar o seu y:");
        scanf(" %lf",&a);
        for(i=0; i<n; i++)
        {
            s=1;
            t=1;
            for(j=0; j<n; j++)
            {
                if(j!=i)
                {
                    s=s*(a-x[j]);
                    t=t*(x[i]-x[j]);
                }
            }
            k=k+((s/t)*y[i]);
        }

        printf("\nO valor de y encontrado para x foi: %f\n",k);

        printf("\nDeseja continuar execucao (V/F)?");
        scanf(" %c", &flag);
        k = 0;
    }
    return 0;
}
