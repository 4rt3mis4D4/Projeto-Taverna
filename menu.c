#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
//	Protótipos
void telaSemiCheia();
void menu();
//	Funçãozinha p abrir em tela semi cheia
void telaSemiCheia(){
    #ifdef _WIN32
        system("mode con cols=200 lines=48");  // Define tamanho no Windows
    #elif __linux__
        printf("\e[8;40;150t");  // Define tamanho no Linux (funciona em alguns terminais)
    #endif
}
//	Menu
void menu(){
	int opcao = 0;
	//	Letreiro grandão
	printf("                                          ______  ___  __ __  ____ ____  __  __  ___       ___  ____    ___   ______ ______   ___  \n"); 
    printf("                                          | || | // \\\\ || || ||    || \\\\ ||\\ || // \\\\     // \\\\ || \\\\  // \\\\  | || | | || |  // \\\\ \n");
    printf("                                            ||   ||=|| \\\\ // ||==  ||_// ||\\\\|| ||=||    (( ___ ||_// ((   ))   ||     ||   ((   ))\n");
    printf("                                            ||   || ||  \\V/  ||___ || \\\\ || \\|| || ||     \\\\_|| || \\\\  \\\\_//    ||     ||    \\\\_// \n");
    printf("                                                                                                                                   \n");
	//	Tem que arrumar isso aq ainda
	printf("|****************************************|\n");
	printf("|*        [1]cadastrar novo cliente     *|\n");
	printf("|*        [2]listar clientes            *|\n");
	printf("|*        [3]consultar cliente por cpf  *|\n");
	printf("|*        [4]desativar cliente          *|\n");
	printf("|*        [5]excluir cliente            *|\n");
	printf("|*        [6]vender                     *|\n");
	printf("|*        [7]assistente                 *|\n");
	printf("|*        [8]sair                       *|\n");
	printf("|****************************************|\n");
	printf("|*          selecione um opc            *|\n");
	printf("|****************************************|\n");
	scanf("%d", &opcao);
	
	
	switch (opcao){
	case 1:
	//	cadastrar();
	break;
	case 2:
	//	clientes();
	break;
	case 3:
	//	consultar();
	break;
	case 4:
	//	desativar();
	break;
	case 5:
	//	excluir();
	break;
	case 6:
	//	vender();
	break;
	case 7:
	//	assistente();
	printf("change da world, my final message, goodbye... ");
	exit(69);
	break;
	case 8:
	//	sair();
	break;
	
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese_Brazil");
	telaSemiCheia();
	menu();
	return 0;
}  
