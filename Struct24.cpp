#include <stdio.h>

int verifica_data (int,int,int);
int distancia (int,int,int,int,int,int); //calcula a distancia de dias
int meses (int,int);

int main (){
	int d,m,a;
	int D,M,A;
	int dias=0;
	
	printf ("Insira a data no formato DD/MM/AA\n");
	printf ("Data 1: ");
	scanf ("%d/%d/%d",&d,&m,&a);
	
	while (verifica_data (d,m,a)==-1){
		printf ("Data invalida\n");
		printf ("Insira a data no formato DD/MM/AA\n");
		scanf ("%d/%d/%d",&d,&m,&a);
	}
	
	printf ("Data 2: ");
	scanf ("%d/%d/%d",&D,&M,&A);
	
	while (verifica_data (D,M,A)==-1){
		printf ("Data invalida\n");
		printf ("Insira a data no formato DD/MM/AA\n");
		scanf ("%d/%d/%d",&D,&M,&A);
	}
	
	printf ("Distancia de %d dias",distancia(d,m,a,D,M,A));
	
	return 0;
}


int verifica_data(int n1,int n2,int n3){
	
	if (n3>9999)
		return -1;
	
	if(n2<1||n2>12)
		return -1;
	
	if (n3%4==0&&n3%100!=0){
		if (n1>29&&n2==2)
			return -1;
			
		return 0;	
	}
	else{
		if (n1>28&&n2==2)
			return -1;
	}
			
	if (n2==1||n2==3||n2==5||n2==7||n2==8||n2==10||n2==12){
		if (n1>31)
			return -1;
			
		else
			return 0;	
	}
	else{
		if(n1>30)
			return 0;
	}	
	
}

int distancia (int dia1,int mes1,int ano1,int dia2,int mes2,int ano2){
	int a,b,dias;
	int resp=0;
	
	if (ano1>ano2)
		return -1;
		
	while(ano2>ano1){ 
		for (a=mes1;a<=12;a++){
			resp+=meses(a,ano1);
		}
		mes1=1;
		ano1++;
	}	
	
	for (a=mes1;a<mes2;a++){
		resp+=meses(mes1,ano2);
	}
	
	resp-=dia1;
	resp+=dia2;
	
	return resp;
}

int meses (int n1,int n2){
	if (n1==2){
		if (n2 % 4==0&&n2%100!=0)
			return 29;
			
		else
			return 28;	
	}
	else{
		if (n1==1||n1==3||n1==5||n1==7||n1==8||n1==10||n1==12)
			return 31;
			
		else
			return 30;		
	
	}
}

