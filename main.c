#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
/* 
@Author: Paulo Vitor Carvalho
@Contribuitor: Renan Marques de Oliveira Almeida

## SOFTWARE LIVRE ##

*/

struct Cliente{
	int id;
	char nome[50];
	int idade;
};
struct Categoria{
	int id;
	char sistema[50];
};

//PROTOTIPOS
void alterarCatgoria(struct Categoria lista_categoria[100]);
void alterarCliente(struct Cliente lista_cliente[100]);
void login();
//variaveis global
int qtd_cli, qtd_cat;
int opcaoPrincipal;
int opcaoCadastro;

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"portuguese");
	login();
	struct Cliente lista_cliente[100];
	struct Categoria lista_categoria[100];
	
do{
opcaoPrincipal=menu_principal();
	switch(opcaoPrincipal){
		
		case 1:
		system("cls");
		
		do{
			opcaoCadastro=menu_cadastrar();
			
		    switch(opcaoCadastro){
		    	
		    	case 1:
		   			 cadastrarCliente(lista_cliente);
						break;
				case 2:
					cadastrarCategoria(lista_categoria);
						break;
				case 3:
					break;
			default : 
				system("cls");
				printf("\n\t******OPCÃO INVALIDA TENTE NOVAMENTE********\n\n");
				getch();
				system("cls");
				break;				
			}
			}while(opcaoCadastro!=3);
				break;
		
	case 2: 
	system("cls");
	
	do{
		opcaoCadastro=menu_consultar();
		
			switch(opcaoCadastro){
			
			case 1:
				consultarCliente(lista_cliente);
					break;		
			case 2:
				consultarCategoria(lista_categoria);
					break;	
			case 3:	
				break;
			
			default :
				system("cls");
			printf("\n\t******OPCÃO INVALIDA TENTE NOVAMENTE********\n\n");	
			getch();
				system("cls");
					break;
			}
		}while(opcaoCadastro!=3);
			break;
			
	case 3:
	system("cls");
	
		do{
			opcaoCadastro=menu_alterar();
			
				switch(opcaoCadastro){
			
			case 1:
				alterarCliente(lista_cliente);
					break;
			case 2: 
				alterarCategoria(lista_categoria);
					break;
			case 3:
				break;
				
			default:
				system("cls");
			printf("\n\t******OPCÃO INVALIDA TENTE NOVAMENTE********\n\n");	
			getch();
				system("cls");	
					break;
			}
		}while(opcaoCadastro!=3);	
			break;	
					
	case 4:
		system("cls");
		printf("\n\n\t******SISTEMA FINALIZADO********\n\nSaindo.......");
		exit(0);
		
		default : 
			system("cls");
		printf("\n\t******OPCÃO INVALIDA TENTE NOVAMENTE********\n\n");
		getch();
			system("cls");
			break;				
	}		
}while(opcaoPrincipal!=5);
	
	return 0;
}

void login(){
	setlocale(LC_ALL,"portuguse");
		system("color 1f");
	char login[100], password[100];
	int i,a=1,b=1;
	
	for(i=0;i<=3;i++){
		if(i<3){
			
	printf("\n\t====================TELA DE LOGIN=====================\t\n\n\n");
	
	printf("\nLogin: ");
	fflush(stdin);
	gets(login);
	
	printf("Password: ");
	fflush(stdin);
	gets(password);
	system("cls");
		printf("\n\n\n\tVERIFICANDO USUÁRIO.....");
		Sleep(2000);
	a=strcmp(login,"admin");
	b=strcmp(password,"admin");
	if(a==0 && b==0){
		system("cls");
		break;
	}else{
		system("cls");
		printf("\n\n\n\tVERIFICANDO USUÁRIO.....");
		Sleep(2000);
		system("cls");
		printf("\t***USUÁRIO INCORRETO\n *** TENTE NOVAMENTE***\n");
		
 }
}else{
	system("cls");
		printf("\n\n\n\tVERIFICANDO USUÁRIO.....");
		Sleep(2000);
	system("cls");
	printf("\n\n\t=================SISTEMA BLOQUEADO=================\t\n\n");
	exit(0);
		}	
	}	
}



menu_principal(){
  int opcaoPrincipal;
	system("cls");
	printf("\n\t====================SOFTWARE LIVRE=====================\t\n\n\n");
	printf("\n1-CADASTRAR");
	printf("\n2-CONSULTAR");
	printf("\n3-ALTERAR");
	printf("\n4-SAIR");
	printf("\n\nOpção: ");
	scanf("%d",&opcaoPrincipal);
	
	return opcaoPrincipal;
}

menu_cadastrar(){
  int aux;
	system("cls");
	printf("\n\t====================TELA DE CADASTRO=====================\t\n\n\n");
	printf("\n1-Cliente");
	printf("\n2-Categoria");
	printf("\n3-Voltar ao menu principal");
	printf("\n\nopcao: ");
	scanf("%d",&aux);
	
	return aux;
}

menu_consultar(){
int aux;
system("cls");
printf("\n\t====================TELA DE CONSULTA=====================\t\n\n\n");
printf("\n1-Consultar Clientes");
printf("\n2-Consultar Categorias");
printf("\n3-Voltar ao menu principal");
printf("\n\nOpção: ");
scanf("%d",&aux);
	return aux;
}

menu_alterar(){
	int aux;
	system("cls");
	printf("\n\t====================TELA DE ALTERAÇÃO=====================\t\n\n\n");
	printf("\n1-Alterar Cliente");
	printf("\n2-Alterar Categoria");
	printf("\n3-Voltar ao munu principal");
	printf("\n\nOpção: ");
	scanf("%d",&aux);
		return aux;
}

cadastrarCliente(struct Cliente lista_cliente[100]){
	int i;
	char aux;
		
	for(i=qtd_cli; ;i++){
		system("cls");
		printf("\n\t====================CADASTRO DE CLIENTE=====================\t\n\n\n");
		
	printf("\nNome Completo: ");
		fflush(stdin);
			gets(lista_cliente[i].nome);
	printf("Idade: ");	
		scanf("%d",&lista_cliente[i].idade);
	
	lista_cliente[i].id = i+1;
		qtd_cli++;
	system("cls");	
		
	printf("\n\t====================CADASTRO DE CLIENTE=====================\t\n\n\n");	
	printf("\nID: %i\nNome: %s\nIdade: %d",lista_cliente[i].id,lista_cliente[i].nome,lista_cliente[i].idade);	
		printf("\n\n\tCadastro realizado com sucesso...");
	printf("\n\nDeseja cadastrar outro cliente (s/n): ");
	fflush(stdin);
	scanf("%c",&aux);
	if(aux =='n')
	break;
	}
}
cadastrarCategoria(struct Categoria lista_categoria[100]){
	int i;
	char aux;
	for(i=qtd_cat;i<=100;i++){
	system("cls");	
		printf("\n\t====================CADASTRO DE CATEGORIA=====================\t\n\n\n");		
		
	printf("\nSOFTWARE LIVRE: Linux - debian,Ubuntu,Mint,fedora,Mandriva,SuSe,gentoo\n\n");
		printf("\nCategoria S.O: ");
			fflush(stdin);
				gets(lista_categoria[i].sistema);	
				
	lista_categoria[i].id = i+1;
		qtd_cat++;
	system("cls");
	
	printf("\n\t====================CADASTRO DE CATEGORIA=====================\t\n\n\n");	
		printf("\nID:%i\nCategoria:%s",lista_categoria[i].id,lista_categoria[i].sistema);
			printf("\n\n\tCadastro realizado com sucesso...");
			
		printf("\n\nDeseja cadastrar outra categoria (s/n): ");
			fflush(stdin);
				scanf("%c",&aux);
		if(aux=='n')
			break;
	}
}
consultarCliente(struct Cliente lista_cliente[100]){
	int i;
	system("cls");
		printf("\n\t====================CONSULTA DE CLIENTE=====================\t\n\n\n");
		
	for(i=0;i<qtd_cli;i++){
		printf("\n\nID: %d",lista_cliente[i].id);
		printf("\nNome: %s",lista_cliente[i].nome);
		printf("\nIdade: %d",lista_cliente[i].idade);
	}
	if(qtd_cli<1){
		system("cls");
		printf("\n\n*****Não ah clientes no Banco de Dados******");
	}	
	
		printf("\n\nPressione ENTER para voltar ao menu de consulta...\n");
		getch();
	
}
consultarCategoria(struct Categoria lista_categoria[100]){
	
	int i;
	system("cls");
		printf("\n\t====================CONSULTA DE CATEGORIA S.O=====================\t\n\n\n");
	for(i=0;i<qtd_cat;i++){
		printf("\n\nID: %i",lista_categoria[i].id);
		printf("\nCategoria S.O: %s",lista_categoria[i].sistema);	
	}
	if(qtd_cat<1){
		system("cls");
	printf("\n\n*****Não ah Categoria no Banco de Dados******");
	}	
		printf("\n\nPressione ENTER para voltar ao menu de consulta...\n");
		getch();
	
}
void alterarCliente(struct Cliente lista_cliente[100]){
	int i, id;
	char aux;
	system("cls");
	
	printf("\n\t====================ALTERAÇÃO DE CLIENTE=====================\t\n\n\n");
		fflush(stdin);
	printf("Informe ID do Cliente: ");
	scanf("%d",&id);
	
	for(i=0;i<qtd_cli;i++){
		if(id==lista_cliente[i].id){
	printf("\n\nID: %d",lista_cliente[i].id);		
	printf("\nNome: %s",lista_cliente[i].nome);
	printf("\nIdade: %d",lista_cliente[i].idade);	

	printf("\n\nDejesa alterar dados (s/n): ");
		fflush(stdin);
		scanf("%c",&aux);	
			if(aux == 'n'){
				break;
	}else{
		if(id==lista_cliente[i].id);{
		
		printf("Novo Nome: ");
			fflush(stdin);
				gets(lista_cliente[i].nome);
		printf("Nova Idade: ");
		scanf("%d",&lista_cliente[i].idade);
			}
		}
		printf("\n\n\tCliente alterado com sucesso\n");
		printf("\n\nPressione ENTER para voltar ao menu de consulta...\n");
		getch();
		}
	}
	if(id>qtd_cli){
		system("cls");
	printf("\n\n*****Cliente não encontrado******");
	printf("\n\nPressione ENTER para voltar ao menu de consulta...\n");
	getch();
	}
}
void alterarCategoria(struct Categoria lista_categoria[100]){
	int i,id;
	char aux;
	system("cls");
	
	printf("\n\t====================ALTERAÇÃO DE CATEGORIA=====================\t\n\n\n");
		fflush(stdin);
	printf("\n\nInforme ID da categoria: ");
		scanf("%d",&id);
		
		
	for(i=0;i<qtd_cat;i++){
		if(id==lista_categoria[i].id){
			
	printf("\n\nID: %d",lista_categoria[i].id);
	printf("\nCategoria S.O: %s",lista_categoria[i].sistema);		
		
	printf("\n\nDeseja alterar Categoria (s/n): ");
		fflush(stdin);
			scanf("%d",&aux);
	if(aux == 'n'){
		break;
	}else{
		if(id==lista_categoria[i].sistema);{
	printf("\nSOFTWARE LIVRE: Linux - debian,Ubuntu,Mint,fedora,Mandriva,SuSe,gentoo\n\n");		
	printf("Nova Categoria S.O: ");
		fflush(stdin);
			gets(lista_categoria[i].sistema);
		}		
	}	
	printf("\n\nCategoria alterada com sucesso\n");
		printf("\n\n\tPressione ENTER para voltar ao menu alterar...");
			getch();	
		}
	}
	if(id>qtd_cat){
		system("cls");
	printf("\n\n*****Categoria não encontrado******");
		printf("\n\n\tPressione ENTER para voltar ao menu alterar...");
		getch();
	}
}











