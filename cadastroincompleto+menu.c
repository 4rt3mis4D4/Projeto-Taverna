#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct {
    char cpf[12];     
    char nome[50];      
    int idade;           
    float fiado;
	bool ativo;
}clientes;
	
void cadastrar();
void cadastrar(){
	int menuop = 0;
 clientes novoCliente;

printf("digite o cpf 11 digitos: \n");
 scanf("%s", novoCliente.cpf);
printf("nome do cliente: \n");
 scanf(" %[^\n]", novoCliente.nome);  
printf("idade do cliente: \n");
 scanf("%d", &novoCliente.idade);
printf("digite o valor de fiado: \n");
 scanf("%f", &novoCliente.fiado);

    novoCliente.ativo = true;
    
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



void menu();
void menu(){
int opcao = 0;
//menu primeira ver
//impresao do bagulho da pra deixar mais bonito dps, mas tem q ver como as outras pessoas fizeram no exemplo,
//medo de achar que a gente kibar o bagulho dos cara sem querer
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
//func do bagulho cadastrar()
cadastrar();
break;
case 2:
//func do bagulho clientes()
break;
case 3:
//func do bagulho desativar()
break;
case 4:
//func do bagulho excluir()
break;
case 5:
//func do bagulho vender()
break;
case 6:
//func do bagulho assistente()
break;
case 7:
printf("change da world, my final message, goodbye... ");
exit(69);
//func do bagulho sair
break;
case 8:
//func do bagulho esquecidebotarodecpflaemcimamasvailaemcima();
break;

}


//fazer chamada recursiva do meno depois de sair de qualquer opcao mais tarde eu achp
// da pra trocar a fita de vc escolher seu funcionario por tipo uma assistente virtual pro dating sim
}


int main(){
menu();
return 69;
}
