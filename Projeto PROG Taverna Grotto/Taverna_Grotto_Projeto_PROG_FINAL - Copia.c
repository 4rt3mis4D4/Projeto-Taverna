#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <stdbool.h>
#ifdef _WIN32 //ajuda na compatibilidade entre OSses? OS(ses)? OSes?
    #include <windows.h>
#else
    #include <unistd.h>
    #define Sleep(ms) usleep((ms) * 1000) // converte os milissegundos pra microseg
#endif

//	Struct Clientes
typedef struct{
   char *cpf;     
    char *nome;    
    char *especie;  
    char *classe;  
    int idade;
    bool ativo;
}clientes;
// Struct Pedidos
typedef struct{
	int id_alimento;
	int id_bebida;
	char opc_alimento[50];
	char opc_bebida[50];
	float valor_alimento;
	float valor_bebidas;
	int quant_alimento;
	int quant_bebida;
}pedidos;
// Struct Quartos
typedef struct{
	int id_quarto;
	char opcao_quarto[50];
	float valor_quarto;
	int tempo_hospedagem;
}alugar_quarto;
//	Prototipos
void telaSemiCheia();
void funciona();
void delayzinho();
int menuInicial();
void seletorAcao(int escolha);
int menuSecundario();
bool validarCPF(const char *cpf);
void cadastrarCliente(clientes *cliente);
void buscarClientePorCPF(const char *cpfBusca);
void listarClientes();
void desativarCliente(const char *cpfBusca);
void excluirCliente(const char *cpfBusca);
void creditos();
//	Procedimento para abrir em tela semi-cheia
void telaSemiCheia(){
    #ifdef _WIN32
        system("mode con cols=200 lines=48");  // ajusta tamanho no Windows
    #elif __linux__
        printf("\e[8;40;150t");  // ajusta tamanho no Linux
    #endif
}
//	Procedimento para o programa funcionar por completo
void funciona(){
	int opcao = 0;
	telaSemiCheia();
	do{
		menuInicial();
		scanf("%d", &opcao);
		while (opcao < 1 || opcao > 3){
    		printf ("                                                                                Insira uma opcao valida\n");
    		printf ("\n                                                                                    ");
    		scanf ("%d", &opcao);
		}
		seletorAcao(opcao);
	}while(opcao != 3);
}
//	Procedimento Delay
void delayzinho(){
	Sleep(60);
}
//	Funcao Menu Inicial
int menuInicial(){
	//	Imprime taverna
	
	printf("\n");
    printf("                                          \n");
    printf("                                        ____________________________________________________________________________________________\n"); delayzinho();
    printf("                                \\      |  ______  ___  __ __  ____ ____  __  __  ___       ___  ____    ___   ______ ______   ___   |     /\n");delayzinho();
    printf("                                 \\     |  | || | // \\\\ || || ||    || \\\\ ||\\ || // \\\\     // \\\\ || \\\\  // \\\\  | || | | || |  // \\\\  |    /\n");delayzinho();
    printf("                              ----     |    ||   ||=|| \\\\ // ||==  ||_// ||\\\\|| ||=||    (( ___ ||_// ((   ))   ||     ||   ((   )) |    ----\n");delayzinho();
    printf("                                 /     |    ||   || ||  \\V/  ||___ || \\\\ || \\|| || ||     \\\\_|| || \\\\  \\\\_//    ||     ||    \\\\_//  |    \\\n");delayzinho();
    printf("                                /      |____________________________________________________________________________________________|     \\\n");delayzinho();
    printf("\n");delayzinho();
    printf("                                         \n");delayzinho();
    printf("				                         |      |\n");delayzinho();
    printf("				                         |  ==  |\n");delayzinho();
    printf("				                   ______|      |____________________________________________________________\n");delayzinho();
    printf("			                          /                                                                          \\\n");delayzinho();
    printf("                                                 /									      \\\n");delayzinho();
    printf("				                /                                                                              \\\n");delayzinho();
    printf("                                               /                                                                                \\\n");delayzinho();
    printf("                                              /                                                                                  \\\n");delayzinho();
    printf("                                             /____________________________________________________________________________________\\\n");delayzinho();
    printf("                                              |      |            |      |        /           \\       |      |            |      |\n");delayzinho();
    printf("		    		     ( )      |      |            |      |       /  ---   ---  \\      |      |            |      |\n");delayzinho();
    printf("                                    (   )     |      |            |      |      /               \\     |      |            |      |\n");delayzinho();
    printf("                                   (     )    |      | ___    ___ |      |      |               |     |      | ___    ___ |      |\n");delayzinho();
    printf("                                  (       )   |      ||          ||      |      |               |     |      ||          ||      |\n");delayzinho();
    printf("                                  (       )   |      ||___    ___||      |      |               |     |      ||___    ___||      |\n");delayzinho();
    printf("                                    (   )     |      |            |      |      |             ? |     |      |            |      |\n");delayzinho();
    printf("                                     | |      |      |            |      |      |               |     |      |            |      |\n");delayzinho();
    printf("                                     | |      |______|____________|______|______|_______________|_____|______|____________|______|     ^^^^\n");delayzinho();
    printf("                       ^^^^\n");delayzinho();
    printf("\n");delayzinho();
    printf("                                                                                    1-> Entrar                  ^^^^\n");delayzinho();
    printf("						^^^^				    2-> Creditos\n");delayzinho();
    printf("                                                                                    3-> Sair\n");
    
    printf ("\n\n                                                                                    ");
}
//	Procedimento Seletor Pos Menu Inicial
void seletorAcao(int escolha){
	switch (escolha){
		case 1:
			//	Abre Menu Secundario
			system("cls");
			menuSecundario();
			break;
		case 2:
			//	Abre aba de creditos
			system("cls");
			creditos();
			break;
		case 3:
			//	Encerra o programa
			system("cls");
			printf("                                         ___________________________________________________________________________________________\n"); delayzinho();
			printf("                                        |                                                                                           |\n"); delayzinho();
			printf("                                        |                                           Volte                                           |\n"); delayzinho();
			printf("                                        |                                          Sempre!                                          |\n"); delayzinho();
			printf("                                        |___________________________________________________________________________________________|\n"); delayzinho();
			Sleep(1000);
			printf ("\n                                                                      Programa encerrado com sucesso!");
			exit(0);
			break;
		default:
			break;
	}
}
//	Procedimento Menu Secundario
int menuSecundario(){
	int selecao = 0;
	  do {
printf("\n\n");
    printf("\n\n");
    printf("\t\t_______________________________________________________________\n");
    printf("\t       |                                                               |\n");
    printf("\t       |                     Selecione a acao desejada                 |\n");
    printf("\t       |_______________________________________________________________|\n");
    printf("\t\t\t\t\t\t\t\t         \n");
    printf("\t\t________________________________________________________________[ ]\n");
    printf("\t       |                                                                |-|\n");
    printf("\t       | [1] Se cadastrar                                               |_|\n");
    printf("\t       | [2] Fazer um pedido                                            | |\n");
    printf("     _____     | [3] Alugar quarto                                             /   \\     .    ' .    \n");
    printf("    /.---.\\    | [4] Gerenciar clientes                                       |_____|  '  .    .  \n");
    printf("    |`````|    | [5] Gerenciar pedidos                                        | ___ |  \\~~~/  ' . \n");
    printf("    \\     /    | [6] Gerenciar quartos                                        | \\ / |   \\_/  \\~~~/\n");
    printf("     `-.-'     | [7] Voltar ao menu inicial                                   | _Y_ |    |    \\_/\n");
    printf("       |       |     ____                                                     |-----|  __|__   |\n");
    printf("       |    /\\ |___.'   /\\____________________________________________________`-----`        __|__\n");
    printf("     __|__  |K----;    |  |\n");
    printf("    `-----` \\/     '.___\\/  \n\n");
    
    printf ("\n\n                                                    ");
    
    scanf("%d", &selecao);
    	while (selecao < 1 || selecao > 7){
    		printf ("                                        Insira uma opcao valida\n");
    		printf ("\n                                                    ");
    		scanf ("%d", &selecao);
		}
	system("cls"); //Comando para Limpar o Terminal
		
	//Inicializando Struct Pedidos - Case 2
	pedidos p;
	//Inicializando Struct Alugar Quartos - Case 3
	alugar_quarto q;
	
    switch(selecao){
    	case 1:
    		// Cadastra novo cliente
    	printf("		 ____________________________________________________________________________________________\n"); delayzinho();
		printf("		|                                                                                           |\n"); delayzinho();
		printf("		|                                      Area de Cadastro:		                    |\n"); delayzinho();
		printf("		|                                      			                                    |\n"); delayzinho();
		printf("		|___________________________________________________________________________________________|\n"); delayzinho();
		printf("\n\n");
		
		{
        clientes novoCliente;  // Declaracao dentro do case
        cadastrarCliente(&novoCliente);
    	}
    		break;
    	case 2: //	Realiza um novo pedido 
    	{
    		//	Abrindo arquivo de Gerenciamento de Pedidos + teste
	    	FILE *arquivo_pedidos = fopen("pedidos.txt", "a+");  //	Abre o arquivo para adicionar dados no final
		    	
		    	if (arquivo_pedidos == NULL) {
			        printf("Erro ao abrir o arquivo: Pedidos\n");
			        return 0; 
		    	}
		    
			//	Abrindo Arquivo de Gerenciamento de Clientes + teste
			FILE *arquivo_clientes = fopen("clientes.txt", "a+");  // Abre o arquivo para adicionar dados no final
		    
			if (arquivo_clientes == NULL) {
				printf("Erro ao abrir o arquivo: Clientes\n");
				return 0; 
			}	
			
			//	opcoes de Alimentos: nome + valor
			printf("		 ____________________________________________________________________________________________\n"); delayzinho();
			printf("		|                                                                                           |\n"); delayzinho();
			printf("		|                                      	CARDAPIO                                         	|\n"); delayzinho();
			printf("		|                                      	Alimentos:                                   		|\n"); delayzinho();
			printf("		|___________________________________________________________________________________________|\n"); delayzinho();
					printf("\n +===== 1. Pao da Taverna com Queijo da Montanha =====+");
				printf("\nDescricao: \nFatias de pao rustico, levemente tostado, acompanhado de um queijo curado das montanhas distantes.");
				printf("\n\nValor: 4 dracmas");
				printf("\n\n"); 
				
					printf("\n +===== 2. Picanha do Minotauro =====+");
				printf("\nDescricao: \nEspetinhos de carne assada com temperos exoticos, acompanhados de um molho picante que desafia o paladar.");
				printf("\n\nValor: 12 dracmas");
				printf("\n\n");
				
					printf("\n +===== 3. Sopa de Cogumelos Magicos =====+");
				printf("\nDescricao: \nSopa de cogumelos raros e aromAticos, com um toque de ervas frescas e um caldo dourado que brilha levemente.");
				printf("\n\nValor: 6 dracmas");
				
				printf("\n====================================================================\n");
				
				do{
					printf("\n\nDigite o numero do alimento que deseja ou 0 caso opte por nenhum: ");
					scanf("%d", &p.id_alimento);
						if (p.id_alimento < 0 || p.id_alimento > 3){
						printf("\nOpcao inexistente!\n");	
					}
				
				} while (p.id_alimento < 0 || p.id_alimento > 3);	
				
				
				if (p.id_alimento != 0){
				printf("\nInforme a quantidade que deseja: ");
				scanf("%d", &p.quant_alimento);
				
					//	Armazenando resultado das escolhas: nome + valor
					if(p.id_alimento == 1){
						strcpy(p.opc_alimento, "Pao da Taverna com Queijo da Montanha");
						p.valor_alimento = 4 * p.quant_alimento;
					} else if(p.id_alimento == 2){
						strcpy(p.opc_alimento, "Picanha do Minotauro");
						p.valor_alimento = 12 * p.quant_alimento;
					} else if(p.id_alimento == 3){
						strcpy(p.opc_alimento, "Sopa de Cogumelos Magicos");
						p.valor_alimento = 6 * p.quant_alimento;
					}
				} else {
					strcpy(p.opc_alimento, "Nenhum");
					p.valor_alimento = 0;
					p.quant_alimento = 0;
				}
				
				system("cls"); //	Comando para Limpar o Terminal
				
				//	Opcoes de Bebida: nome + valor
				printf("		 ____________________________________________________________________________________________\n"); delayzinho();
				printf("		|                                                                                            |\n"); delayzinho();
				printf("		|                                      	CARDAPIO                                             |\n"); delayzinho();
				printf("		|                                      	Bebidas:                                             |\n"); delayzinho();
				printf("		|___________________________________________________________________________________________ |\n"); delayzinho();
					printf("\n +===== 1. Hidromel da Taverna =====+");
				printf("\nDescricao: \nHidromel dourado e espumante, servido em grandes canecos de barro.");
				printf("\n\n Valor: 4 dracmas");
				printf("\n\n");
				
					printf("\n +===== 2. Vinho Elfico da Floresta =====+");
				printf("\nDescricao: \nVinho raro, feito com uvas cultivadas nas terras Alficas, com notas frutadas e um toque de magia antiga.");
				printf("\n\n Valor: 10 dracmas");
				printf("\n\n");
				
					printf("\n +===== 3. Cerveja do Ferreiro Anao =====+");
				printf("\nDescricao: \nCerveja escura e espessa, com um sabor robusto e uma espuma cremosa.");
				printf("\n\n Valor: 5 dracmas");
				
				printf("\n\n====================================================================\n");
				
				do {
				
				printf("\n\nDigite o numero da bebida escolhida ou 0 caso opte por nenhuma: ");
				scanf("%d", &p.id_bebida);
				
					if (p.id_bebida < 0 || p.id_bebida > 3){
						printf("\nOpcaoo inexistente!\n");	
					}
				
				} while (p.id_bebida < 0 || p.id_bebida > 3);
				
				
				if (p.id_bebida != 0){
				
				printf("\nInforme a quantidade : ");
				scanf("%d", &p.quant_bebida);
				
					//	Armazenando resultado das escolhas: nome + valor
					if(p.id_bebida == 1){
						strcpy(p.opc_bebida, "Hidromel da Taverna");
						p.valor_bebidas = 4 * p.quant_bebida;
					} else if(p.id_bebida == 2){
						strcpy(p.opc_bebida, "Vinho Elfico da Floresta");
						p.valor_bebidas = 10 * p.quant_bebida;
					} else if(p.id_bebida == 3){
						strcpy(p.opc_bebida, "Cerveja do Ferreiro Anao");
						p.valor_bebidas = 5 * p.quant_bebida;
					} 
				} else {
					strcpy(p.opc_bebida, "Nenhum");
					p.valor_bebidas = 0;
					p.quant_bebida = 0;
				}
				
				
				
				//	Resultado final: opcoes escolhidas + valores (cada e total)
				printf("\n+======================================================================================================================+");
					printf("\n   Alimento: %s - Quantidade: %d - Valor: %.1f dracmas", p.opc_alimento, p.quant_alimento, p.valor_alimento);
					printf("\n   Bebida: %s - Quantidade: %d - Valor: %.1f dracmas", p.opc_bebida, p.quant_bebida, p.valor_bebidas);
					printf("\n   Valor Total: %.1f dracmas", p.valor_alimento + p.valor_bebidas);
				printf("\n+======================================================================================================================+");
				
					printf("\n   Pedido realizado com sucesso. Aperte qualquer tecla para continuar...");
					getch();
				system("cls"); //	Comando para Limpar o Terminal
	    		
	    		fprintf(arquivo_pedidos, "Alimentos: %s\tID: %d\tQuantidade: %d\tValor: %.1f Dracmas\n", p.opc_alimento, p.id_alimento, p.quant_alimento, p.valor_alimento);
	    		fprintf(arquivo_pedidos, "Bebidas: %s\tID: %d\tQuantidade: %d\tValor: %.1f Dracmas\n ", p.opc_bebida, p.id_bebida, p.quant_bebida, p.valor_bebidas);
				fprintf(arquivo_clientes, "Pedidos Feitos: %s e %s\tValor Gasto: %.1f Dracmas\n", p.opc_alimento, p.opc_bebida, p.valor_alimento+p.valor_bebidas);
				if(p.id_alimento == 0){
					fprintf(arquivo_clientes, "Pedidos Feitos: Alimento nAo solicitado e %s\tValor Gasto: %.1f Dracmas\n", p.opc_bebida, p.valor_alimento+p.valor_bebidas);
				} else if (p.id_bebida == 0){
					fprintf(arquivo_clientes, "Pedidos Feitos: %s e Bebida nAo solicitada\tValor Gasto: %.1f Dracmas\n", p.opc_alimento, p.valor_alimento+p.valor_bebidas);
				} 
				
				fclose(arquivo_pedidos);
				fclose(arquivo_clientes);
    	}
    		break;
    	case 3:
    		//	Aluga um quarto
    	{
    		//	Abrindo Arquivo de Gerenciamento de Quartos + teste
	    	FILE *arquivo_quartos = fopen("quartos.txt", "a+");  // Abre o arquivo para adicionar dados no final
	    
	    	if (arquivo_quartos == NULL) {
		        printf("Erro ao abrir o arquivo: Quartos\n");
		        return 0; 
	    	}
			
			//Abrindo Arquivo de Gerenciamento de Clientes + teste
			FILE *arquivo_clientes = fopen("clientes.txt", "a+");  // Abre o arquivo para adicionar dados no final
		    
			if (arquivo_clientes == NULL) {
				printf("Erro ao abrir o arquivo: Clientes\n");
				return 0; 
			}		
	    	
		    printf("		 ____________________________________________________________________________________________\n"); delayzinho();
			printf("		|                                                                                           |\n"); delayzinho();
			printf("		|                                    Opcoes de Hospedagem:                                |\n"); delayzinho();
			printf("		|                                      			                                    |\n"); delayzinho();
			printf("		|___________________________________________________________________________________________|\n"); delayzinho();
			
			printf("\n +===== Aventureiro Solitario =====+ \n");
				printf("Numero do quarto: 1\n");
				printf("Descricao: ");
				printf("\nQuarto simples e rustico com cama de madeira, manta de pele, lanternas de ferro e um bau.");
				printf("\nValor: 5 Dracmas por noite");
			printf("\n +===== Feiticeira Arcana =====+");
				printf("\nNumero do quarto: 2\n");
				printf("Descricao: ");
				printf("\nAmbiente mistico com velas flutuantes, cama de tecidos finos, mesa de estudo com livros e frascos de pocoes, e uma janela com vista encantada.");
				printf("\nValor: 10 Dracmas por noite");
			printf("\n +===== Barbaro Guerreiro =====+");
				printf("\nNumero do quarto: 3\n");
				printf("Descricao: ");
				printf("\nQuarto robusto com cama de peles, armaduras e armas nas paredes, lareira acesa, barris de cerveja e tapetes rusticos no chao.");
				printf("\nValor: 15 Dracmas por noite");
			
			printf("\n\n====================================================================\n");
			
			do{
				printf("\nInforme o numero do quarto que deseja ou 0 caso opte por nenhum: ");
				scanf("%d", &q.id_quarto);
				
				if (q.id_quarto < 0 || q.id_quarto > 3){
					printf("\nOpcao inexistente!.\n");	
				}	
			} while (q.id_quarto < 0 || q.id_quarto > 3);
			
			if(q.id_quarto != 0){
				printf("\nInforme a quantidade desejada de diarias: ");
				scanf("%d", &q.tempo_hospedagem);
				
				if(q.id_quarto == 1){
					strcpy(q.opcao_quarto, "Aventureiro Solitario");
					q.valor_quarto = 5;		
				} else if (q.id_quarto == 2){
					strcpy(q.opcao_quarto, "Feiticeira Arcana");
					q.valor_quarto = 10;
				} else if (q.id_quarto == 3){
					strcpy(q.opcao_quarto, "Barbaro Guerreiro");
					q.valor_quarto = 15;
				}
			} else {
				strcpy(q.opcao_quarto, "Nenhum");
				q.valor_quarto = 0;
				q.tempo_hospedagem = 0;	
			}
			
			
			printf("\n+===============================================================================================+");
				printf("\n   Quarto: %s  ID: %d", q.opcao_quarto, q.id_quarto);
				printf("\n   Valor: %.1f Dracmas Tempo: %d Noites", q.valor_quarto, q.tempo_hospedagem);
				printf("\n   Valor Total: %.1f Dracmas", q.valor_quarto * q.tempo_hospedagem);
			printf("\n+===============================================================================================+");
			
				printf("\n   Reserva feita com sucesso. Aperte qualquer tecla para continuar");
				getch();
			system("cls"); //Comando para Limpar o Terminal
			
			fprintf(arquivo_quartos, "Nome Quarto: %s\tID: %d\tValor: %.1f Dracmas por noite\n", q.opcao_quarto, q.id_quarto, q.valor_quarto);
			fprintf(arquivo_clientes, "Quarto Escolhido: %s\tID: %d\tValor Total: %.1f Dracmas\n", q.opcao_quarto, q.id_quarto, q.valor_quarto * q.tempo_hospedagem);
			
			fclose(arquivo_quartos);
			fclose(arquivo_clientes);
		}
    		break;
    	  case 4: {
    int subopcao = 0;
    do {
        printf("\t       ____________________________________________________________________________________________\n");
        printf("\t      |                                                                                           |\n");
        printf("\t      |                                    Gerenciamento de Clientes                              |\n");
        printf("\t      |___________________________________________________________________________________________|\n");
        printf("\t      |                                                                                           |\n");
        printf("\t      | [1] Listar todos os clientes                                                              |\n");
        printf("\t      | [2] Buscar cliente por CPF                                                                |\n");
        printf("\t      | [3] Desativar cliente por CPF                                                             |\n");
        printf("\t      | [4] Excluir cliente por CPF                                                               |\n");
        printf("\t      | [5] Voltar ao menu secundario                                                             |\n");
        printf("\t      |___________________________________________________________________________________________|\n");

        printf("\nDigite a opcao desejada: ");
        scanf("%d", &subopcao);
	
        switch (subopcao) {
            case 1:
                // Listar todos os clientes
                system("cls");
				listarClientes();
				system("cls");
            	break;

            case 2:
                // Buscar cliente por CPF
                {
                	system("cls");
                    char cpfBusca[12];
                    printf("\nDigite o CPF para buscar (apenas numeros): ");
                    scanf("%s", cpfBusca);
                    buscarClientePorCPF(cpfBusca);
                }
                break;

            case 3:
                // Desativar cliente por CPF
                {
                	system("cls");
                    char cpfBusca[12];
                    printf("\nDigite o CPF do cliente a ser desativado: ");
                    scanf("%s", cpfBusca);
                    desativarCliente(cpfBusca);
                    system("cls");
                }
                break;

            case 4:
                // Excluir cliente por CPF
                {
                	system("cls");
                    char cpfBusca[12];
                    printf("\nDigite o CPF do cliente a ser excluido: ");
                    scanf("%s", cpfBusca);
                    excluirCliente(cpfBusca);
                    system("cls");
                }
                break;

            case 5:
            	system("cls");
                printf("\nVoltando ao menu secundario...\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }
    } while (subopcao != 5);
	}
	break;

    	case 5:
    		//	Abre sub menu de gerenciamento de pedidos
    		printf("		 ____________________________________________________________________________________________\n"); delayzinho();
			printf("		|                                                                                           |\n"); delayzinho();
			printf("		|                                    Gerenciamento de Pedidos:                              |\n"); delayzinho();
			printf("		|                                      			                                    		|\n"); delayzinho();
			printf("		|___________________________________________________________________________________________|\n"); delayzinho();
			
			printf("\n\n");
		{
			FILE *arquivo_pedidos = fopen("pedidos.txt", "r");
		    
		    if (arquivo_pedidos == NULL) {
		        printf("Erro ao abrir o arquivo: Pedidos\n");
		        return 0; 
		    }
		    		
		    char crct_pedidos; //	Vai armazenar temporariamente o valor de cada caractere lido do arquivo    		    
		    
		    //	Le e exibe cada caractere ate ser igual a EOF (end-of-file - Fim do Arquivo)
		    while ((crct_pedidos = fgetc(arquivo_pedidos)) != EOF) {
		        putchar(crct_pedidos);  // Exibe o caractere no terminal
		    }
			
			printf("\nAperte qualquer tecla para coninuar...");
		    getch();
			
		    fclose(arquivo_pedidos); // Fecha o arquivo apos a leitura
		}
    		break;
    	case 6:
    		//	Abre sub menu de gerenciamento de quartos
    		printf("		 ____________________________________________________________________________________________\n"); delayzinho();
			printf("		|                                                                                           |\n"); delayzinho();
			printf("		|                                    Gerenciamento de Quartos:                              |\n"); delayzinho();
			printf("		|                                      			                                    		|\n"); delayzinho();
			printf("		|___________________________________________________________________________________________|\n"); delayzinho();
			
			printf("\n\n");
    	{
		    FILE *arquivo_quartos = fopen("quartos.txt", "r");
		    
		    if (arquivo_quartos == NULL) {
		        printf("Erro ao abrir o arquivo: Quartos\n");
		        return 0; 
		    }
		
		    char crct_quartos; //	Vai armazenar temporariamente o valor de cada caractere lido do arquivo
		    
		    //	Le e exibe cada caractere ate ser igual a EOF (end-of-file - Fim do Arquivo)
		    while ((crct_quartos = fgetc(arquivo_quartos)) != EOF) {
		        putchar(crct_quartos);  // Exibe o caractere no terminal
		    }
	
			printf("\nAperte qualquer tecla para coninuar...");
		    getch();
			
		    fclose(arquivo_quartos); // Fecha o arquivo apos a leitura
		}
    		break;
     case 7:
                // Voltar ao menu inicial
                printf("Voltando ao menu inicial...\n");
                break;
        }
        system("cls"); // Limpa a tela antes de voltar ao menu secundario
    } while (selecao != 7); // Fica no menu secundario atA o usuario escolher sair
}
//	Funcao para cadastrar o cliente
void cadastrarCliente(clientes *cliente) {
	FILE *arquivo_clientes = fopen("clientes.txt", "a+");  // Abre o arquivo para adicionar dados no final
		    
		if (arquivo_clientes == NULL) {
			printf("Erro ao abrir o arquivo: Clientes\n");
			return; 
		}	
		
	//	Aloca memoria dinamicamente para os campos da struct
    cliente->cpf = malloc(12 * sizeof(char));
    cliente->nome = malloc(50 * sizeof(char));
    cliente->especie = malloc(50 * sizeof(char));
    cliente->classe = malloc(50 * sizeof(char));		
	
    printf("Digite o CPF do cliente(apenas numeros): ");
    scanf("%s", cliente->cpf);

    while (!validarCPF(cliente->cpf)) {
        printf("CPF invalido! Tente novamente: ");
        scanf("%s", cliente->cpf);
    }

    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", cliente->nome);

    printf("Digite a especie do cliente: ");
    scanf(" %[^\n]", cliente->especie);

    printf("Digite a classe do cliente: ");
    scanf(" %[^\n]", cliente->classe);

    printf("Insira a idade do cliente: ");
    scanf("%d", &cliente->idade);

    cliente->ativo = true;

    printf("\nCadastro realizado com sucesso!\n");
    
    fprintf(arquivo_clientes, "Nome: %s\tCPF: %s\tEspecie: %s\tClasse: %s\tIdade: %d\n", cliente->nome, cliente->cpf, cliente->especie, cliente->classe, cliente->idade);
    
    
    fclose(arquivo_clientes);
 
 	//como a gente salva os clientes no arquivo nao e preciso manter a memoria alocada
    free(cliente->cpf);
    free(cliente->nome);
    free(cliente->especie);
    free(cliente->classe);
    
    
}
//	Funcao para validar o CPF
bool validarCPF(const char *cpf) {
    int primeiro_digV, segundo_digV;
    int num, contador, soma = 0;

    if (strlen(cpf) != 11 || strspn(cpf, "0123456789") != 11) {
        return false;
    }

    for (contador = 0; contador < 9; contador++) {
        num = cpf[contador] - '0';
        soma += (num * (10 - contador));
    }
    primeiro_digV = (soma % 11 < 2) ? 0 : (11 - (soma % 11));

    soma = 0;
    for (contador = 0; contador < 10; contador++) {
        num = cpf[contador] - '0';
        soma += (num * (11 - contador));
    }
    segundo_digV = (soma % 11 < 2) ? 0 : (11 - (soma % 11));

    return (primeiro_digV == (cpf[9] - '0')) && (segundo_digV == (cpf[10] - '0'));
}
//	Funcao para buscar cliente
void buscarClientePorCPF(const char *cpfBusca) {
    FILE *arquivo_clientes = fopen("clientes.txt", "r");
    if (arquivo_clientes == NULL) {
        printf("Erro ao abrir o arquivo: Clientes\n");
        return;
    }

    char linha[256]; //	Buffer para armazenar cada linha do arquivo
    bool encontrado = false;

    while (fgets(linha, sizeof(linha), arquivo_clientes)) {
        //	Verifica se o CPF esta na linha atual
        if (strstr(linha, cpfBusca)) {
            printf("Cliente encontrado:\n%s\n", linha);
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("Nenhum cliente com o CPF %s foi encontrado.\n", cpfBusca);
    }

    fclose(arquivo_clientes);
}
//	funcao Listar Cliente
void listarClientes() {
    FILE *arquivo_clientes = fopen("clientes.txt", "r");
    if (arquivo_clientes == NULL) {
        printf("Erro ao abrir o arquivo: Clientes\n");
        return;
    }

    char linha[256]; 
    printf("\nClientes cadastrados:\n\n");
    while (fgets(linha, sizeof(linha), arquivo_clientes)) {
        printf("%s", linha); 
    }

    fclose(arquivo_clientes);
    printf("\nListagem concluida. Pressione qualquer tecla para continuar\n");
    getch(); 
}
//	funcao desativar cliente
void desativarCliente(const char *cpfBusca) {
    FILE *arquivo_clientes = fopen("clientes.txt", "r");
    FILE *arquivo_temp = fopen("temp_clientes.txt", "w");
    if (arquivo_clientes == NULL || arquivo_temp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[256];
    bool encontrado = false;

    while (fgets(linha, sizeof(linha), arquivo_clientes)) {
        if (strstr(linha, cpfBusca)) {
            encontrado = true;
            fprintf(arquivo_temp, "%s\tAtivo: Nao\n", linha); // Marca o cliente como inativo
        } else {
            fputs(linha, arquivo_temp);
        }
    }

    fclose(arquivo_clientes);
    fclose(arquivo_temp);

    remove("clientes.txt");
    rename("temp_clientes.txt", "clientes.txt");

    if (encontrado) {
        printf("\nCliente com CPF %s desativado com sucesso.\n", cpfBusca);
    } else {
        printf("\nCliente com CPF %s nao encontrado.\n", cpfBusca);
    }
    
    printf("\nSucesso na operao. Aperte qualquer tecla para continuar...");
    getch();
}
//	funcao exlcuir cliente
void excluirCliente(const char *cpfBusca) {
    FILE *arquivo_clientes = fopen("clientes.txt", "r");
    FILE *arquivo_temp = fopen("temp_clientes.txt", "w");
    if (arquivo_clientes == NULL || arquivo_temp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[256];
    bool encontrado = false;

    while (fgets(linha, sizeof(linha), arquivo_clientes)) {
        if (strstr(linha, cpfBusca)) {
            encontrado = true; // Nao copia o cliente para o novo arquivo
        } else {
            fputs(linha, arquivo_temp);
        }
    }

    fclose(arquivo_clientes);
    fclose(arquivo_temp);

    remove("clientes.txt");
    rename("temp_clientes.txt", "clientes.txt");

    if (encontrado) {
        printf("\nCliente com CPF %s excluido com sucesso. Aperte qualquer tecla para continuar...\n", cpfBusca);
        getch();
    } else {
        printf("\nCliente com CPF %s nao encontrado.\n", cpfBusca);
    }
}
//	Procedimento Creditos
void creditos(){
	printf("                                                                      Programa desenvolvido pelos alunos:"); delayzinho();
	printf("\n\n\n\n");
	printf("                                                                      Gabriela Pedroso dos Santos Pontes\n\n"); delayzinho();
	printf("                                                                            Lanna dos Anjos Costa\n\n"); delayzinho();
	printf("                                                                  Marcos Vinicius da Rocha Schiavon Ferreira\n\n\n\n"); delayzinho();
	
	Sleep(1000);
	printf("                                                                 Pressione qualquer tecla para voltar ao menu...\n\n");
	getch();
	system("cls");
}
//	Main
int main(){
	setlocale (LC_ALL, "Portuguese_Brazil");
	funciona();
	return 0;
}
