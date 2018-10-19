#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define Tvariveis 15
#define Taluno 5

struct aluno {
    char nome[Tvariveis];
    char matricula[Tvariveis];
    char curso[Tvariveis];
}cadastro[2];

void Leitura(struct aluno cadastro[]);
void Dados(struct aluno cadastro[]);

int main(){
    setlocale(LC_ALL,"Portuguese");
    int opcao;
       
    label:
        system("cls");
        
        printf("Caso teste: 0 para sair, 1 para continuar:");
        scanf("%d",&opcao);
        if(opcao == 0){
            exit(1);
        }else{
            Leitura(cadastro);          
            Dados(cadastro); 
        }
    system("pause");
    goto label;   
        
    return 0;
}

void Leitura(struct aluno cadastro[]){
    setlocale(LC_ALL,"Portuguese");
    system("cls");
    
    for(int i = 0;i < Taluno;i++){
        printf("\t\t\tDados refentes ao aluno %d\n",i+1);
        printf("Informe o nome do aluno: ");
        fflush(stdin);
        fgets(cadastro[i].nome,Tvariveis,stdin);
        printf("Informe o número do aluno: ");
        fgets(cadastro[i].matricula,Tvariveis,stdin);
        printf("Informe o nome do curso do aluno: ");
        fgets(cadastro[i].curso,Tvariveis,stdin);
        printf("\n\n");
    }
    system("pause");
    
}

void Dados(struct aluno cadastro[]){
    setlocale(LC_ALL,"portuguese");
    system("cls");
    
    for(int i = 0;i < Taluno;i++){
        printf("\t\t\tDados refentes ao aluno %d\n",i+1);
        printf("\tNome: %s",cadastro[i].nome);
        printf("\tMatrícula: %s",cadastro[i].matricula);
        printf("\tCurso: %s",cadastro[i].curso);
        printf("\n\n\n");
    }
}

