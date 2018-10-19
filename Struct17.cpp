#include <stdio.h>
#include <stdlib.h>
#define TAM 2

struct comercio{
    int codigo;
    int quantidade;
    char nome[16];
    float valor;
};
comercio Produto[TAM];

void LeituraProduto(struct comercio Produto[]);
void VendaProduto(struct comercio Produto[]);

int main(){
    
       
    LeituraProduto(Produto);
    VendaProduto(Produto);
    
    return 0;
}

void LeituraProduto(struct comercio Produto[]){
    
    for(int i = 0;i < TAM;i++){
        system("cls");
        printf("\t\tInforme as caracteristicas do novo produto\n");
        printf("Nome: ");
        fflush(stdin);
        fgets(Produto[i].nome,15,stdin);
        printf("Codigo do produto: ");
        scanf("%d",&Produto[i].codigo);
        printf("Quatidade: ");
        scanf("%d",&Produto[i].quantidade);
        printf("Preco do produto: ");
        scanf("%f",&Produto[i].valor);
        printf("\n\t\tProduto cadastrado com sucesso\n");
        system("pause");
    }
}

void VendaProduto(struct comercio Produto[]){
    int compra;
    int pecas;
        
    inicio:
        system("cls");
        printf("Informe o codigo do produto que deseja comprar:\n");
        scanf("%d",&compra);
        printf("Quantidade do produto desejado: ");
        scanf("%d",&pecas);
        for(int i = 0;i < TAM;i++){
            if(Produto[i].codigo == compra){
                if(pecas > Produto[i].quantidade){
                    printf("\n\t\tNao ha essa quantidade de %s no estoque!\n",Produto[i].nome);
                    printf("Ha apenas %d unidades de %s\n\n",Produto[i].quantidade,Produto[i].nome);
                }else{
                    printf("\n\t\t\tSua compra deu %.2f\n\n",Produto[i].valor * Produto[i].quantidade);
                }
            }
        }
        system("pause");
    goto inicio;
}
