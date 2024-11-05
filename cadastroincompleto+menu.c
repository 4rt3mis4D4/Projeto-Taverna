#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
//	Struct Clientes
typedef struct {
    char cpf[12];     
    char nome[50];
	char especie[50];
	char classe[50];      
    int idade;           
    float divida;
	bool ativo;
}clientes;
//	Protótipos
void cadastrar();
void menu();	
//	Função de Cadastro
void cadastrar(){
	int menuop = 0;
	clientes novoCliente;
	
	printf("Insira o nome do cliente: ");
	scanf(" %[^\n]", novoCliente.nome);  
	printf("Insira o CPF do cliente: ");
	scanf("%s", novoCliente.cpf);
	printf("Insira a idade do cliente: ");
	scanf("%d", &novoCliente.idade);
	printf("Insira a espécie do cliente: ");
	scanf(" %[^\n]", novoCliente.especie);
	printf("Insira a classe do cliente: "); //	Classe de RPG
	scanf(" %[^\n]", novoCliente.classe);
	
	//	aq acho q dá p tirar e fazer tipo uma divida acumulativa, conforme vai cadastrando pedido não pago no nome do cliente
	printf("digite o valor de fiado: \n");
	scanf("%f", &novoCliente.divida);

    novoCliente.ativo = true;
    
    //	aq acho uma boa trocar por "aperte qualquer tecla p voltar ao menu" pq pela lógica vc tem q cadastrar a pessoa e aí
    //	atender ela, dificil acontecer de ter q cadastrar dois de uma vez
    printf("deseja fazer o que? \n voltar ao menu [1] \n cadastrar novo cliente [2] \n");
    scanf("%d", &menuop);
	if (menuop == 1) {
        menu();  
	} else if (menuop == 2) {
        cadastrar(); 
	} else {
        printf("Opção inválida. Retornando ao menu.\n");
        menu();
	}
}
//	Menu
//	Tem que mudar dps pro menu certo
void menu(){
	int opcao = 0;

	printf("esse é o prototipo de um menu pra taverna, probido dar o cuzinho em hora de trabalho\n\n\n");
	
	printf("|****************************************|\n");
	printf("|*                                      *|\n");
	printf("|*         ISSO E UM MENU MAL FEITO     *|\n");
	printf("|*                                      *|\n");
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
//	Main
int main(){
	setlocale(LC_ALL, "Portuguese_Brazil");
	menu();
	return 0;
}
