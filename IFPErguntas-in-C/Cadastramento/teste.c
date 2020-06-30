#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
	char pergunta[250];
	char alternativa_A[100];
	char alternativa_B[100];
	char alternativa_C[100];
	char alternativa_D[100];
	int pontuacao;
}Pergunta;

//variáveis globais
char nome_arquivo[30] = "teste.txt";
Pergunta perguntas[20];

void ler_arquivo(){
	int pontuacao = 20;
	
	FILE *arq;
	arq = fopen(nome_arquivo, "rt");//ABRE O ARQUIVO PARA LEITURA E ESCRITA
	if(arq == NULL){
		printf("O arquivo não pôde ser aberto\n");		
	}else{
		int i = 0;
		while (!feof(arq)){			
			char linha[250];
			
			char *ponteiro;
			ponteiro = fgets(linha, 250, arq);  // o 'fgets' lê até 249 caracteres ou até o '\n'
		    if (ponteiro){  // Se foi possível ler
				strcpy(perguntas[i].pergunta,linha);
			}
			
			ponteiro = fgets(linha, 100, arq);
		    if (ponteiro){
				strcpy(perguntas[i].alternativa_A,linha);
			}
			
			ponteiro = fgets(linha, 100, arq);
		    if (ponteiro){
				strcpy(perguntas[i].alternativa_B,linha);
			}
			
			ponteiro = fgets(linha, 100, arq);
		    if (ponteiro){
				strcpy(perguntas[i].alternativa_C,linha);
			}
			
			ponteiro = fgets(linha, 100, arq);
		    if (ponteiro){
				strcpy(perguntas[i].alternativa_D,linha);
			}		
			
			perguntas[i].pontuacao = pontuacao;
			
			printf("=== Pergunta %i ===\n", i + 1);
			printf("%s\n", perguntas[i].pergunta);
			printf("%s\n", perguntas[i].alternativa_A);
			printf("%s\n", perguntas[i].alternativa_B);
			printf("%s\n", perguntas[i].alternativa_C);
			printf("%s\n", perguntas[i].alternativa_D);
						
		    i++;
		  }
	}
	int fechou = fclose(arq);
	if(fechou != 0){
		printf("O arquivo não pôde ser fechado\n");
	}else{
		printf("Perguntas carregadas com sucesso\n");
	}
}


int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	ler_arquivo();
	return 0;
}
