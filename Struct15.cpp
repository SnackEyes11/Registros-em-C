#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 2

struct COMPROMISSO{
    char nota[61];        
};

struct DATA{
    int dia;
    int mes;
    int ano;
    COMPROMISSO compromisso[TAM];
};

DATA data[TAM];
int verificacao = 0;

void Menu(struct DATA data[]);
void LerCompromisso(struct DATA data[]);
void InformarCompromisso(struct DATA data[]);

int main(){
    Menu(data);
    return 0;
}

void LerCompromisso(struct DATA data[]){
    setlocale (LC_ALL,"Portuguese");
    verificacao++;
    for(int i = 0;i < TAM;i++){
        system("cls");
        printf("Informe a data do compromisso:(dd mm aaaa)\n");
        scanf("%d %d %d", &data[i].dia, &data[i].mes, &data[i].ano);
        printf("\n\t\tVocê pode informar no maximo %d compromissos por dia:",TAM);
        for(int j = 0;j < TAM;j++){
            printf("\nCompromisso %d:\n",j+1);
            fflush(stdin);
            fgets(data[i].compromisso[j].nota,60,stdin);     
        }
    }
    Menu(data);
}

void InformarCompromisso(struct DATA data[]){
    setlocale (LC_ALL,"Portuguese");
    if(verificacao == 0){
        system("cls");
        printf("\t\tNenhum compromisso foi informado até agora\n");
        system("pause");
        Menu(data);
    }
    int AuxMes;
    int AuxAno;
    int check = 0;
    int z = 0 ;
    int j = 0;
    
    check = 0;
    system("cls");
    printf("\t\tINFORME O MÊS E O ANO QUE VOCÊ QUER VERIFICAR OS COMPROMISSOS:  (digite 0 no mês se quiser parar o programa!):\n");
    printf("mm aaaa: ");
    scanf("%d %d",&AuxMes,&AuxAno);
    if(AuxMes == 0)
        exit(1);
    printf("\t\tCompromissos do Mes %d e Ano %d\n",AuxMes,AuxAno);
    for(j = 0;j < TAM;j++){
        if((AuxMes == data[j].mes) && (AuxAno == data[j].ano)){
            for(z = 0;z < TAM;z++)
                printf("Compromisso: %s\n\n",data[j].compromisso[z].nota);
            z = 0;
            check++;
        }
    }   
    if(check == 0)
        printf("Não há nenhum compromisso para esse dia!");
    printf("\n\n");
    system("pause");    
    Menu(data);
}

void Menu(struct DATA data[]){
    setlocale(LC_ALL,"portuguese");
    int opcao;
    
    system("cls");
    printf("\t\t\tAgenda Pessoal\n");
    printf("(1)-Informar Compromissos(você exluiu todos os antigos compromissos com esta,     ação para poder informar novos)\n");
    printf("(2)-Ver Compromisso\n");
    printf("(0)-Sair do Programa\n");
    printf("opcao: ");
    label:
    scanf("%d",&opcao);
    switch(opcao){
        case (1): LerCompromisso(data);
        case (2): InformarCompromisso(data);
        case (0): exit(1);
        default:{
            printf("\nInforme uma opcão válida");
            goto label;
        }
    }
}
