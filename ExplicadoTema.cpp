#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<locale.h>
#include<string.h>
#define POS 40
#define COLUNAS 10000
#define MEDIA 7.000

// protótipos
void cadastrarAluno(int *controle,char alunos[POS][COLUNAS],int matriculas[POS]);
void exibeLista(int controle,char alunos[POS][COLUNAS],int matriculas[POS],float notas[POS]);
void lancarNotas(int controle,char alunos[POS][COLUNAS],int matriculas[POS],float notas[POS]);
int procurarAluno(int controle,char alunos[POS][COLUNAS],int matriculas[POS],float notas[POS],char exibe);
int mediasAlunos(int controle,char alunos[POS][COLUNAS],float notas[POS]);
void excluirAluno(int *controle,char alunos[POS][COLUNAS],int matriculas[POS],float notas[POS]);
main(){
	setlocale(LC_ALL,"portuguese");
	int menu,controle=0,retorno;
	char alunos[POS][COLUNAS]={};
	float notas[POS]={};
	int matriculas[POS]={};
	do{
		printf("\n 1 -  Cadastrar Aluno");
		printf("\n 2 -  Lançar Notas");
		printf("\n 3 -  Medias");
		printf("\n 4 -  Procurar Aluno");
		printf("\n 5 -  Exibir Todos");
		printf("\n 6 -  Excluir Aluno");
		printf("\n 0 -  Sair ==> ");
		scanf("%i",&menu);
		switch(menu){
			case 1:
				system("cls");
				cadastrarAluno(&controle,alunos,matriculas);				
			break;
			case 2:
				system("cls");
				lancarNotas(controle,alunos,matriculas,notas);
			break;
			case 3:
					retorno = mediasAlunos(controle,alunos,notas);	
					if(retorno==0) printf("\n\t==> Nenhum aprovado!\n\n");
					else printf("\n\t %i alunos foram aprovados!\n",retorno);
			break;
			case 4:
				retorno=procurarAluno(controle,alunos,matriculas,notas,'S');
				if(retorno==-1) printf("\n\t ==> Matricula não encontrada!\n\n");
				
			break;
			case 5:
				system("cls");
				exibeLista(controle,alunos,matriculas,notas);
				
			break;
			
			case 6:
				system("cls");
				excluirAluno(&controle,alunos,matriculas,notas);
				
			break;
			case 0:
				break;
			default: printf("\n\t ==> Opção Inválida!!");
		}
		
	}while(menu!=0);
}

void cadastrarAluno(int *controle,char alunos[POS][COLUNAS],int matriculas[POS]){
	int mat;
	
	if(*controle==POS){
		printf("\n\t ==> Não existem posições livres!!\n\n");
	}else{
		printf("\n\t ==> Cadastro de aluno!!\n\n");		
		printf("\n Informe a matricula do aluno ==> ");
		scanf("%i",&mat);
		if(mat>0){
			printf("\n Informe o nome do aluno ==> ");
			fflush(stdin);
			gets(alunos[*controle]);
			matriculas[*controle]=mat;
			printf("\n\t ==> Cadastro realizado com sucesso!!\n\n");
			(*controle)++;
		}else{
			printf("\n\t ==> Matrícula INválida!!!\n\n");
		}
	}
}

void exibeLista(int controle,char alunos[POS][COLUNAS],int matriculas[POS],float notas[POS]){
	if(controle==0) printf("\n\t ==> LISTA VAZIA!\n\n");
	else{
		printf("\n\t ==> Listagem de Alunos\n\n");
		for(int x=0;x<controle;x++){
			printf("\n\tNome do aluno: %s",alunos[x]);
			printf("\n\tMatricula: %i",matriculas[x]);
			printf("\n\tMédia: %.2f",notas[x]);
			printf("\n--------------------------------\n");
			
		}
	}
}

void lancarNotas(int controle,char alunos[POS][COLUNAS], int matriculas[POS],float notas[POS]){
	int indice;
	if(controle==0) printf("\n\t ==> LISTA VAZIA!\n\n");
	else{
		indice=procurarAluno(controle,alunos,matriculas,notas,'N');
		if(indice==-1){
			printf("\n\t ==> Matricula não encontrada!\n\n");
		}else{
			printf("Informe a nota do aluno ==> ");
			scanf("%f",¬as[indice]);
			printf("\n\t ==> Nota lançada com sucesso!!");
		}
	}
}

int procurarAluno(int controle,char alunos[POS][COLUNAS],int matriculas[POS],float notas[POS],char exibe){
	int mat,indice=-1;
	if(controle==0) printf("\n\t ==> LISTA VAZIA!\n\n");
	else{
		printf("Informe a matricula do aluno ==> ");
		scanf("%i",&mat);
		if(mat<=0){
			printf("\n\t ==> Matricula Inválida!!");
		}else{
			for(int x=0;x<controle;x++){
				if(mat==matriculas[x]){
					indice=x;
					if(exibe=='S'){
						printf("\n\tNome do aluno: %s",alunos[x]);
						printf("\n\tMatricula: %i",matriculas[x]);
						printf("\n\tMédia: %.2f",notas[x]);
						printf("\n--------------------------------\n\n");
					}
					break;
				}
			}
		}
	}
		return indice;
}
int mediasAlunos(int controle,char alunos[POS][COLUNAS],float notas[POS]){
	int aprovados=0;
	if(controle==0) printf("\n\t ==> LISTA VAZIA!\n\n");
	else{
		printf("\n\t ==> Listagem de Alunos\n\n");
		for(int x=0;x<controle;x++){
			if(notas[x]>=MEDIA) aprovados++;
			printf("\n\tNome do aluno: %s",alunos[x]);
			printf("\n\tMédia: %.2f",notas[x]);
			printf("\n--------------------------------\n");
			
		}
		return aprovados;	
	}
	
}

void excluirAluno(int *controle,char alunos[POS][COLUNAS],int matriculas[POS],float notas[POS]){
	int indice;
	char resposta;
	if(controle==0) printf("\n\t ==> LISTA VAZIA!\n\n");
	else{
		indice=procurarAluno(*controle,alunos,matriculas,notas,'S');
		if(indice>=0){
			printf("\n Deseja realmente excluir o aluno %s? S / N ==> ",alunos[indice]);
			fflush(stdin);
			scanf("%c",&resposta);
			
			if(toupper(resposta)=='S'){																								
				for(int x=indice;x<*controle;x++){
					strcpy(alunos[x],alunos[x+1]);
					matriculas[x]=matriculas[x+1];
					notas[x]=notas[x+1];
					
				}
				(*controle)--;
				printf("\n\t ==> Excluido com sucesso!\n\n");
			}else{
				printf("\n\t ==> Operação cancelada!\n\n");
			}
		}else{
			printf("\n\t ==> Matricula não encontrada!\n\n");
		}
	}
	
	
}

