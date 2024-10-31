#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "portuguese");
	
	char cpf[12]; //Aumentando o tamanho para incluir o caractere nulo por conta do fgets
	int primeiro_digV, segundo_digV;
	int num, contador, soma = 0;
	
	printf("Digite seu CPF sem pontuação: ");
	fgets(cpf, sizeof(cpf), stdin); //fgets foi utilizado para manter maior segurança e controle sobre a entrada do usuário
	
		//Cálculo do primeiro digito verificador
	for(contador = 0; contador < 9; contador++){
		num = cpf[contador] - '0'; 
		//converte o caractere para número inteiro
		soma += (num*(10-contador));
		//Multiplica os numeros armazenados no vetor por 10 em diante
		//E soma todos os resultados
	}
	
	if (soma % 11 < 2){
		//Se o resultado da sobra da divisão for menor que 2 
		//O priemiro digito será igual a zero
		primeiro_digV = 0; 
	} else {
		//Caso o contrário o primeiro digito será
		//o resultado da subtração do valor armazenado em soma com 11
		primeiro_digV = 11 - (soma % 11);
	}
	
	soma = 0;
		//Cálculo do segundo digito verificador
	//O lopp realiza 10 interações, pois é acrescentador o resultado anterior
	for(contador = 0; contador < 10 ; contador++){ 
		num = cpf[contador] - '0';
		soma += (num*(11-contador));
	}
	
	if (soma % 11 < 2){
		segundo_digV = 0;
	} else {
		segundo_digV = 11 - (soma % 11);
	}
	
		//Validação
	//Compara se os 2 ultimos digitos estão iguais ao valor armazenados nas duas variávies
	if ((primeiro_digV == cpf[9] - '0') && (segundo_digV == cpf[10] - '0')){
		printf("\nCpf Válido.");
	} else {
		printf("\nCpf Inválido.");
	}
	
	return 0;
}
