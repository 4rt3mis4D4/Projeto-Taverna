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
	system("cls"); //Comando para Limpar o Terminal

	//Variáveis Opção Vender()
		int hospitalidade = 0;
		int hospedagem = 0;
		int alimento = 0, bebida = 0;
		char opt_alimento[50], opt_bebida[50];
		float valor = 0, valor_alimento = 0, valor_bebida = 0;
		int opcao_vender = 0;

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
	
	//Realiza um loop até o usuário querer sair
	while (opcao_vender == 0){
	
	//Texto de Boas-Vindas + Opções de Venda
	printf("Bem-Vindo!O que voce deseja?\n");
	printf("Digite [1] para Hospedagem ou [2] para Restaurante: ");
	scanf("%d", &hospitalidade);
	
	//Opção Hospedagem
	if(hospitalidade == 1){
		printf("Opções de Hospedagem: \n");
		printf("\n1. Aventureiro Solitário \n Descrição: Quarto simples e rústico com cama de madeira, manta de pele, lanternas de ferro e um báu");
		printf("\n\n2. Feiticeira Arcana \n Descrição: Ambiente místico com velas flutuantes, cama com tecidos finos, mesa de estudo com livros e frascos de poções, e uma janela com vista encantada.");
		printf("\n\n3. Bárbaro Guerreiro \n Descrição: Quarto robusto com cama de peles, armaduras e armas nas paredes, lareira acesa, barris de cerveja e tapetes rústicos no chão.");
		printf("\n\nDigite o numero da hospedagem que deseja: ");
		scanf("%d", &hospedagem);
		
		system("cls"); //Comando para Limpar o Terminal
		
		if(hospedagem == 1){
			valor = 5; //Valor da Hospedagem: Aventureiro Solitário
			printf("\n+=======================================+");
			printf("\n   Quarto Escolhido: Aventureiro Solitário");
			printf("\n   Valor: %.1f dracmas por noite", valor);
			printf("\n+=======================================+");
		} else if (hospedagem == 2){
			valor = 15; //Valor da Hospedagem: Feiticeira Arcana
			printf("\n+=======================================+");
			printf("\n   Quarto Escolhido: Feiticeira Arcana");
			printf("\n   Valor: %.1f dracmas por noite", valor);
			printf("\n+=======================================+");
		} else {
			valor = 10; //Valor da Hospedagem: Bárbaro Guerreiro
			printf("\n+=======================================+");
			printf("\n   Quarto Escolhido: Bárbaro Guerreiro");
			printf("\n   Valor: %.1f dracmas por noite", valor);
			printf("\n+=======================================+");
		}
		
	} else /*Opção Restaurante*/ {
		printf("Opções do Cardápio: \n");
		
		//Opções de Alimento: nome+valor
		printf("\n===== ALIMENTOS =====\n");
			printf("\n1. Pão da Taverna com Queijo da Montanha");
		printf("\nDescrição: \nFatias de pão rústico de trigo, levemente tostado, acompanhado de um queijo curado das montanhas distantes.");
		printf("\n\n Valor: 4 dracmas");
		printf("\n\n"); 
		
			printf("\n\n2. Picanha do Minotauro");
		printf("\nDescrição: \nEspetinhos de carne assada com temperos exóticos, acompanhados de um molho picante que desafia o paladar.");
		printf("\n\n Valor: 12 dracmas");
		printf("\n\n");
		
			printf("\n\n3. Sopa de Cogumelos Mágicos");
		printf("\nDescrição: \nSopa de cogumelos raros e aromáticos, com um toque de ervas frescas e um caldo dourado que brilha levemente.");
		printf("\n\n Valor: 6 dracmas");
		printf("\n\n");
		
		printf("\nDigite o numero do alimento que deseja: ");
		scanf("%d", &alimento);
		
		if(alimento == 1){
			strcpy(opt_alimento, "Pão da Taverna com Queijo da Montanha");
			valor_alimento = 4;
		} else if(alimento == 2){
			strcpy(opt_alimento, "Picanha do Minotauro");
			valor_alimento = 12;
		} else {
			strcpy(opt_alimento, "Sopa de Cogumelos Mágicos");
			valor_alimento = 6;
		}
		
		system("cls"); //Comando para Limpar o Terminal
		
		//Opções de Bebida: nome+valor
		printf("\n===== BEBIDAS =====\n");
			printf("\n1. Hidromel da Taverna");
		printf("\nDescrição: \nHidromel dourado e espumante, servido em grandes canecos de barro.");
		printf("\n\n Valor: 4 dracmas");
		
			printf("\n\n2. Vinho Elfico da Floresta");
		printf("\nDescrição: \nVinho raro, feito com uvas cultivadas nas terras élficas, com notas frutadas e um toque de magia antiga.");
		printf("\n\n Valor: 10 dracmas");
		
			printf("\n\n3. Cerveja do Ferreiro Anão");
		printf("\nDescrição: \nCerveja escura e espessa, com um sabor robusto e uma espuma cremosa.");
		printf("\n\n Valor: 5 dracmas");
		
		printf("\n\nDigite o numero da bebida que deseja: ");
		scanf("%d", &bebida);
		
		if(bebida == 1){
			strcpy(opt_bebida, "Hidromel da Taverna");
			valor_bebida = 4;
		} else if(alimento == 2){
			strcpy(opt_bebida, "Vinho Elfico da Floresta");
			valor_bebida = 10;
		} else {
			strcpy(opt_bebida, "Cerveja do Ferreiro Anão");
			valor_bebida = 5;
		}
		
		system("cls"); //Comando para Limpar o Terminal
		
		//Resultado final: opções escolhidas + valores (cada e total)
		printf("\n+===============================================================================================+");
			printf("\n   Alimento: %s  Valor: %.1f dracmas", opt_alimento, valor_alimento);
			printf("\n   Bebida: %s Valor: %.1f dracmas", opt_bebida, valor_bebida);
			printf("\n   Valor Total: %.1f dracmas", valor_alimento+valor_bebida);
		printf("\n+===============================================================================================+");
	}
	
		//Pergunta ao usuário se deseja continuar ou sair das opções
		printf("\n\nDeseja retornar para as opções de venda (Digite 0) ou sair (Digite 1)? ");
		scanf("%d", &opcao_vender);
		
		system("cls"); //Comando para Limpar o Terminal
	}	
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
