#include <stdio.h>
#include <stdlib.h>

int a=0;

struct cad{
    char nome[30];
    char telefone[15];
    
};

struct cad cadastro[10];


void le (cad[]);
void ve (cad[]);
void menu();

int main (){
    
    menu();
    
    return 0;
}
void menu(){
    int opc;
    system ("cls");
    printf ("Digite 1 para adicionar novos dados\n");
    printf ("Digite 2 para ver a lista dos dados inseridos\n");
    printf ("Digite 3 para sair\n");
    printf ("opcao: "); scanf ("%d",&opc);
    fflush(stdin);
    
    switch (opc){
        case 1: le(cadastro); break;
        case 2: ve(cadastro); break;
        case 3: exit(0);
        default:{
            menu();
            break;
        }
    }
    
    
}

void le (cad n1[]){
    
    if (a==10){
        printf ("\nNao e possivel adicionar mais dados\n");
        system ("Pause");
        menu();
    }
    
    else{
        printf ("\n\t\tNome: ");
        fgets(n1[a].nome,30,stdin);
        fflush (stdin);
        printf ("\n\t\tTelefone: ");
        fgets(n1[a].telefone,15,stdin);
        fflush(stdin);
        a++;
        system("pause");
        menu();
    }
}

void ve (cad n1[]){
    int b;
    system ("cls");
    
    if (a==0)
        printf ("Nao exitem dados registrados\n");
    
    else{
        for (b=0;b<a;b++){
            printf ("Nome: %s",n1[b].nome);
            printf ("Telefone: %s",n1[b].telefone);
            printf ("\n");
        }        
    }
    
    system("pause");
    menu();
    
}
