# SUGESTÕES
-> Para o menu, fazer tipo uma "casinha" ao redor do "Taverna Grotto" e do menu para ficar bonitinho.
-> Cadastrar um membro, mas poder fazer pedido em nome de alguém que não seja um membro cadastrado. Conceder descontos especiais
aos cadastrados como membros.


# LOG DE MUDANÇAS
Lanna, 04/11 19:40+ :
- Alterei o "setlocale(LC_ALL, "portuguese");" que tava em algum dos arquivos para "setlocale(LC_ALL, "Portuguese_Brazil")"; porque esse
parâmetro vem melhor formatado, só "portuguese" geralmente dá erro. Acrescentei nos outros dois arquivos tbm.
- Dei uma mexida no arquivo menu.c.
- Fiz um letreiro para a taverna.
- Coloquei uma função para abrir o executável em uma janela grande, para não desformatar o menu. Dei uma pesquisada e não tem comando para
tela cheia. Tem um para o Windows mas eu achei esse que eu coloquei mais eficiente porque ele funciona tanto para Windows quanto para Linux
e a Mariane provavelmente vai corrigir no computador dela que é Linux.
- Modifiquei a struct dos clientes e a função de cadastros. Agora tá assim a struct:

typedef struct {
    char cpf[12];     
    char nome[50];
	char especie[50];
	char classe[50];      
    int idade;           
    float divida;
	bool ativo;
}clientes;

- Formatei o código e acrescentei uns comentários.


# Observações: --
