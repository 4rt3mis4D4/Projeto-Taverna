#include<stdio.h>
#include<stdlib.h>
//menu primeira ver
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
