#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

//===Estruturas===//
typedef struct{
	char nome[300];
	char telefone[300];
	char escola[300];
	char serie[20];
	int pontuacao;
	float tempo;
}Jogador;

typedef struct{
	char pergunta[500];
	char alternativa_A[250];
	char alternativa_B[250];
	char alternativa_C[250];
	char alternativa_D[250];
	int pontuacao;
	char alternativa_correta;
}Pergunta;

typedef struct{
	Jogador jogadores_salvos[1000];
	int quantidade;
}Jogadores_salvos;

//===Variáveis Globais===//
Jogador jogador;
Jogadores_salvos jogadores_salvos_partida;
Jogadores_salvos jogadores_salvos_geral;

Pergunta geral_faceis[20];
Pergunta geral_medias[20];
Pergunta geral_dificeis[20];
Pergunta geral_muito_dificeis[15];
Pergunta filmes_faceis[60];
Pergunta filmes_medias[60];
Pergunta filmes_dificeis[60];
Pergunta filmes_muito_dificeis[15];
Pergunta jogos_faceis[20];
Pergunta jogos_medias[20];
Pergunta jogos_dificeis[20];
Pergunta jogos_muito_dificeis[15];
Pergunta esportes_faceis[20];
Pergunta esportes_medias[20];
Pergunta esportes_dificeis[20];
Pergunta esportes_muito_dificeis[15];
Pergunta series_faceis[25];
Pergunta series_medias[27];
Pergunta series_dificeis[23];
Pergunta series_muito_dificeis[15];

char nome_arquivo_esportes_faceis[50] = "esportes_faceis.txt";
char nome_arquivo_esportes_medias[50] = "esportes_medias.txt";
char nome_arquivo_esportes_dificeis[50] = "esportes_dificeis.txt";
char nome_arquivo_esportes_muito_dificeis[50] = "esportes_muito_dificeis.txt";

char nome_arquivo_gerais_faceis[50] = "gerais_faceis.txt";
char nome_arquivo_gerais_medias[50] = "gerais_medias.txt";
char nome_arquivo_gerais_dificeis[50] = "gerais_dificeis.txt";
char nome_arquivo_gerais_muito_dificeis[50] = "gerais_muito_dificeis.txt";

char nome_arquivo_jogos_faceis[50] = "jogos_faceis.txt";
char nome_arquivo_jogos_medias[50] = "jogos_medias.txt";
char nome_arquivo_jogos_dificeis[50] = "jogos_dificeis.txt";
char nome_arquivo_jogos_muito_dificeis[50] = "jogos_muito_dificeis.txt";

char nome_arquivo_filmes_faceis[50] = "filmes_faceis.txt";
char nome_arquivo_filmes_medias[50] = "filmes_medias.txt";
char nome_arquivo_filmes_dificeis[50] = "filmes_dificeis.txt";
char nome_arquivo_filmes_muito_dificeis[50] = "filmes_muito_dificeis.txt";

char nome_arquivo_series_faceis[50] = "series_faceis.txt";
char nome_arquivo_series_medias[50] = "series_medias.txt";
char nome_arquivo_series_dificeis[50] = "series_dificeis.txt";
char nome_arquivo_series_muito_dificeis[50] = "series_muito_dificeis.txt";

char nome_arquivo_ranking_partida[50] = "ranking_partida.arq";
char nome_arquivo_ranking_geral[50] = "ranking_geral.arq";

//===Funções===//

void tela_de_boas_vindas(){
	system("cls");
	printf("Jogo de Perguntas\n\n");
	printf("Jogo desenvolvido por: Fábio Vinícius\n");
	printf("                       Gabriel Gomes\n");
	printf("                       Gabriel Nogueira\n");
	printf("                       Patriota Neto\n");
	printf("                       Matheus Alves\n\n");
	printf("Supervisão:            Professor Diego Rodrigues\n\n\n");
	system("pause");
}

void carregar(char nome_arquivo[30], char tema, char nivel){
	FILE *p;
	p = fopen(nome_arquivo, "r");//ABRE O ARQUIVO PARA LEITURA E ESCRITA
	if(p == NULL){
		printf("O arquivo não pôde ser aberto\n");		
	}else{
		if(tema == 'g'){
			if(nivel == 'f'){
				fread(&geral_faceis, sizeof(geral_faceis), 1, p);
			}else if(nivel == 'm'){
				fread(&geral_medias, sizeof(geral_medias), 1, p);
			}else if(nivel == 'd'){
				fread(&geral_dificeis, sizeof(geral_dificeis), 1, p);
			}else if(nivel == 'x'){
				fread(&geral_muito_dificeis, sizeof(geral_muito_dificeis), 1, p);
			}
		}else if(tema == 'f'){
			if(nivel == 'f'){
				fread(&filmes_faceis, sizeof(filmes_faceis), 1, p);
			}else if(nivel == 'm'){
				fread(&filmes_medias, sizeof(filmes_medias), 1, p);
			}else if(nivel == 'd'){
				fread(&filmes_dificeis, sizeof(filmes_dificeis), 1, p);
			}else if(nivel == 'x'){
				fread(&filmes_muito_dificeis, sizeof(filmes_muito_dificeis), 1, p);
			}
		}else if(tema == 'j'){
			if(nivel == 'f'){
				fread(&jogos_faceis, sizeof(jogos_faceis), 1, p);
			}else if(nivel == 'm'){
				fread(&jogos_medias, sizeof(jogos_medias), 1, p);
			}else if(nivel == 'd'){
				fread(&jogos_dificeis, sizeof(jogos_dificeis), 1, p);
			}else if(nivel == 'x'){
				fread(&jogos_muito_dificeis, sizeof(jogos_muito_dificeis), 1, p);
			}
		}else if(tema == 'e'){
			if(nivel == 'f'){
				fread(&esportes_faceis, sizeof(esportes_faceis), 1, p);
			}else if(nivel == 'm'){
				fread(&esportes_medias, sizeof(esportes_medias), 1, p);
			}else if(nivel == 'd'){
				fread(&esportes_dificeis, sizeof(esportes_dificeis), 1, p);
			}else if(nivel == 'x'){
				fread(&esportes_muito_dificeis, sizeof(esportes_muito_dificeis), 1, p);
			}
		}else if(tema == 's'){
			if(nivel == 'f'){
				fread(&series_faceis, sizeof(series_faceis), 1, p);
			}else if(nivel == 'm'){
				fread(&series_medias, sizeof(series_medias), 1, p);
			}else if(nivel == 'd'){
				fread(&series_dificeis, sizeof(series_dificeis), 1, p);
			}else if(nivel == 'x'){
				fread(&series_muito_dificeis, sizeof(series_muito_dificeis), 1, p);				
			}
		}		
		//printf("O arquivo %s foi carregado com sucesso\n", nome_arquivo);
	}
	int fechou = fclose(p);
	if(fechou != 0){
		printf("O arquivo não pôde ser fechado\n");
	}
}

void carregar_gerais(){
	carregar(nome_arquivo_gerais_faceis, 'g', 'f');
	carregar(nome_arquivo_gerais_medias, 'g', 'm');
	carregar(nome_arquivo_gerais_dificeis, 'g', 'd');
	carregar(nome_arquivo_gerais_muito_dificeis, 'g', 'x');
}

void carregar_filmes(){
	carregar(nome_arquivo_filmes_faceis, 'f', 'f');
	carregar(nome_arquivo_filmes_medias, 'f', 'm');
	carregar(nome_arquivo_filmes_dificeis, 'f', 'd');
	carregar(nome_arquivo_filmes_muito_dificeis, 'f', 'x');
}

void carregar_jogos(){
	carregar(nome_arquivo_jogos_faceis, 'j', 'f');
	carregar(nome_arquivo_jogos_medias, 'j', 'm');
	carregar(nome_arquivo_jogos_dificeis, 'j', 'd');
	carregar(nome_arquivo_jogos_muito_dificeis, 'j', 'x');
}

void carregar_esportes(){
	carregar(nome_arquivo_esportes_faceis, 'e', 'f');
	carregar(nome_arquivo_esportes_medias, 'e', 'm');
	carregar(nome_arquivo_esportes_dificeis, 'e', 'd');
	carregar(nome_arquivo_esportes_muito_dificeis, 'e', 'x');
}
	
void carregar_series(){
	carregar(nome_arquivo_series_faceis, 's', 'f');
	carregar(nome_arquivo_series_medias, 's', 'm');
	carregar(nome_arquivo_series_dificeis, 's', 'd');
	carregar(nome_arquivo_series_muito_dificeis, 's', 'x');
}

void carregar_ranking_partida(){
	FILE *p;
	p = fopen(nome_arquivo_ranking_partida, "r+");//ABRE O ARQUIVO PARA LEITURA E ESCRITA
	if(p == NULL){
			p = fopen(nome_arquivo_ranking_partida, "w");//CRIA O ARQUIVO
	}else{
		fread(&jogadores_salvos_partida, sizeof(jogadores_salvos_partida), 1, p);
	}
	int fechou = fclose(p);
	if(fechou != 0){
		printf("O arquivo não pôde ser fechado\n");
	}
}

void carregar_perguntas(){
	carregar_gerais();
	carregar_filmes();
	carregar_jogos();
	carregar_esportes();
	carregar_series();
}

int jogador_ja_cadastrado(char nome[300]){
	int i;
	for(i = 0; i < jogadores_salvos_partida.quantidade; i++){
		if(strcmpi(nome,jogadores_salvos_partida.jogadores_salvos[i].nome) == 0){
			return 1;
		}
	}
	return 0;
}

void tela_cadastro_jogador(){
	int repetido;
	do{
		system("cls");
		printf("Cadastro de Jogador\n\n");
		printf("Digite o nome: ");
		fflush(stdin);
		gets(jogador.nome);
		repetido = jogador_ja_cadastrado(jogador.nome);
		if(repetido == 1){
			printf("Jogador já cadastrado\n");
			system("pause");
		}
	}while(repetido == 1);	
	printf("Digite o telefone: ");
	fflush(stdin);
	gets(jogador.telefone);
	printf("Digite a escola: ");
	fflush(stdin);
	gets(jogador.escola);
	printf("Digite a série: ");
	fflush(stdin);
	gets(jogador.serie);
	jogador.pontuacao = 0;
	system("pause");
}

int tela_de_temas(){
	int tema;
	do{
		system("cls");
		printf("1 - Geral\n");
		printf("2 - Filmes\n");
		printf("3 - Jogos\n");
		printf("4 - Esportes\n");
		printf("5 - Séries\n\n");
		printf("Tema: ");
		scanf("%i", &tema);
	}while(tema < 1 || tema > 5);
	return tema;	
}

void imprimir_pergunta(Pergunta p){
	printf("Pergunta: %s\n\n", p.pergunta);
	printf("A: %s\n\n", p.alternativa_A);
	printf("B: %s\n\n", p.alternativa_B);
	printf("C: %s\n\n", p.alternativa_C);
	printf("D: %s\n\n", p.alternativa_D);
}

void sortear_perguntas(Pergunta sorteadas[3], Pergunta perguntas[60], int tamanho){
	int indice1, indice2, indice3;
	do{		
		indice1 = rand() % tamanho;
		indice2 = rand() % tamanho;
		indice3 = rand() % tamanho;		
	}while(indice1 == indice2 || indice1 == indice3 || indice2 == indice3);
	sorteadas[0] = perguntas[indice1];
	sorteadas[1] = perguntas[indice2];
	sorteadas[2] = perguntas[indice3];
	int i;
	char auxiliar[250];
	for(i = 0; i < 3; i++){
		int alternativa_correta = rand() % 4;
		//imprimir_pergunta(sorteadas[i]);
		switch(alternativa_correta){
			case 0:{
				sorteadas[i].alternativa_correta = 'A';
				break;
			}
			case 1:{
				sorteadas[i].alternativa_correta = 'B';
				strcpy(auxiliar, sorteadas[i].alternativa_A);
				strcpy(sorteadas[i].alternativa_A, sorteadas[i].alternativa_B);
				strcpy(sorteadas[i].alternativa_B, auxiliar);
				break;
			}
			case 2:{				
				sorteadas[i].alternativa_correta = 'C';
				strcpy(auxiliar, sorteadas[i].alternativa_A);
				strcpy(sorteadas[i].alternativa_A, sorteadas[i].alternativa_C);
				strcpy(sorteadas[i].alternativa_C, auxiliar);
				break;
			}
			case 3:{				
				sorteadas[i].alternativa_correta = 'D';
				strcpy(auxiliar, sorteadas[i].alternativa_A);
				strcpy(sorteadas[i].alternativa_A, sorteadas[i].alternativa_D);
				strcpy(sorteadas[i].alternativa_D, auxiliar);
				break;
			}
		}
	}	
}

void jogar_partida(Pergunta perguntas[3], int perder_pontuacao){
	char resposta;
	int i;
	for(i = 0; i < 3; i++){
		system("cls");
		//printf("Valor de i = %i\n", i);
		printf("Pontuação: %i\n\n", jogador.pontuacao);
		printf("Pergunta: %s\n\n", perguntas[i].pergunta);
		printf("A: %s\n\n", perguntas[i].alternativa_A);
		printf("B: %s\n\n", perguntas[i].alternativa_B);
		printf("C: %s\n\n", perguntas[i].alternativa_C);
		printf("D: %s\n\n\n", perguntas[i].alternativa_D);
		//printf("Alternativa correta: %c\n\n\n", perguntas[i].alternativa_correta);
		do{
			printf("Resposta: ");
			fflush(stdin);
			scanf("%c", &resposta);
			resposta = toupper(resposta);
		}while(resposta != 'A' && resposta != 'B' && resposta != 'C' && resposta != 'D');
		if(resposta == toupper(perguntas[i].alternativa_correta)){
			printf("Você acertou\n");
			jogador.pontuacao = jogador.pontuacao + perguntas[i].pontuacao;
		}else{
			if(perder_pontuacao == 1){//CONDIÇÃO PARA TIRAR PONTOS
				if(jogador.pontuacao < 200){
					jogador.pontuacao = 0;
				}else{
					jogador.pontuacao = jogador.pontuacao - perguntas[i].pontuacao;
				}
				
			}
			printf("Você errou\n");
		}
		system("pause");
	}
}

char perguntar_continuar(){
	char resposta;
	do{
		system("cls");
		printf("As próximas 3 perguntas são consideradas muito difíceis\n\n");
		printf("Respostas corretas somam 200 na sua pontuação\n");		
		printf("Respostas erradas diminuem 200 na sua pontuação\n\n");
		printf("Deseja continuar? Digite s ou n\n");
		printf("Resposta: ");
		fflush(stdin);
		scanf("%c", &resposta);
	}while(resposta != 'n' && resposta != 's');
	return resposta;
}



void salvar_dados(){
	FILE *p;
	p = fopen(nome_arquivo_ranking_partida, "r+");//ABRE O ARQUIVO PARA LEITURA E ESCRITA
	if(p == NULL){
		printf("O arquivo não pôde ser aberto\n");
	}
	int i;
	for(i = jogadores_salvos_partida.quantidade - 1; i >= 0; i--){
		if(jogadores_salvos_partida.jogadores_salvos[i].pontuacao < jogador.pontuacao){
			jogadores_salvos_partida.jogadores_salvos[i + 1] = jogadores_salvos_partida.jogadores_salvos[i];
		}else if(jogadores_salvos_partida.jogadores_salvos[i].pontuacao == jogador.pontuacao){
			if(jogadores_salvos_partida.jogadores_salvos[i].tempo > jogador.tempo){
				jogadores_salvos_partida.jogadores_salvos[i + 1] = jogadores_salvos_partida.jogadores_salvos[i];
			}else{
				break;
			}			
		}else{
			break;
		}	
	}
	jogadores_salvos_partida.jogadores_salvos[i + 1] = jogador;
	jogadores_salvos_partida.quantidade++;
	fwrite(&jogadores_salvos_partida, sizeof(jogadores_salvos_partida), 1, p);	
	int fechou = fclose(p);
	if(fechou != 0){
		printf("O arquivo não pôde ser fechado\n");
	}
}

void mostrar_ranking_atual(){
	int i;
	printf("\nRanking Atual\n");
	for(i = 0; i < jogadores_salvos_partida.quantidade; i++){
		printf("%i - Pontuação: %i --- Nome: %s --- Tempo: %.3f segundos\n", i + 1, jogadores_salvos_partida.jogadores_salvos[i].pontuacao, jogadores_salvos_partida.jogadores_salvos[i].nome, jogadores_salvos_partida.jogadores_salvos[i].tempo);
	}
}

void mostrar_ranking_geral(){
	int i;
	printf("\nRanking Geral\n");
	for(i = 0; i < jogadores_salvos_geral.quantidade; i++){
		printf("%i - Pontuação: %i --- Nome: %s --- Tempo: %.3f segundos\n", i + 1, jogadores_salvos_geral.jogadores_salvos[i].pontuacao, jogadores_salvos_geral.jogadores_salvos[i].nome, jogadores_salvos_geral.jogadores_salvos[i].tempo);
	}
}

void carregar_ranking_geral(){
	FILE *p;
	p = fopen(nome_arquivo_ranking_geral, "r+");//ABRE O ARQUIVO PARA LEITURA E ESCRITA
	if(p == NULL){
		p = fopen(nome_arquivo_ranking_geral, "w");//CRIA O ARQUIVO
		if(p == NULL){
			printf("O arquivo de ranking geral não pôde ser criado\n");
			system("pause");
		}
	}else{
		fread(&jogadores_salvos_geral, sizeof(jogadores_salvos_geral), 1, p);
	}
	
	int fechou = fclose(p);
	if(fechou != 0){
		printf("O arquivo não pôde ser fechado\n");
	}
}

void zerar_ranking_partida(){
	FILE *p;
	p = fopen(nome_arquivo_ranking_partida, "w");//CRIA O ARQUIVO
	if(p == NULL){
		printf("O arquivo não pôde ser criado\n");
	}else{
		fread(&jogadores_salvos_partida, sizeof(jogadores_salvos_partida), 1, p);
		jogadores_salvos_partida.quantidade = 0;
	}
	int fechou = fclose(p);
	if(fechou != 0){
		printf("O arquivo não pôde ser fechado\n");
	}
}

void copiar_ranking_atual_para_geral(){	
	int i, j;
	for(i = 0; i < jogadores_salvos_partida.quantidade; i++){
		Jogador jogador_partida = jogadores_salvos_partida.jogadores_salvos[i];
		for(j = jogadores_salvos_geral.quantidade - 1; j >= 0; j--){
			if(jogadores_salvos_geral.jogadores_salvos[j].pontuacao < jogador_partida.pontuacao){
				jogadores_salvos_geral.jogadores_salvos[j + 1] = jogadores_salvos_geral.jogadores_salvos[j];
			}else if(jogadores_salvos_geral.jogadores_salvos[j].pontuacao == jogador_partida.pontuacao){
				if(jogadores_salvos_geral.jogadores_salvos[j].tempo > jogador_partida.tempo){
					jogadores_salvos_geral.jogadores_salvos[j + 1] = jogadores_salvos_geral.jogadores_salvos[j];
				}else{
					break;
				}			
			}else{
				break;
			}	
		}
		jogadores_salvos_geral.jogadores_salvos[j + 1] = jogador_partida;
		jogadores_salvos_geral.quantidade++;
	}	
	
	FILE *p;
	p = fopen(nome_arquivo_ranking_geral, "r+");//ABRE O ARQUIVO PARA LEITURA E ESCRITA
	if(p == NULL){
		printf("O arquivo não pôde ser aberto\n");
	}else{
		fwrite(&jogadores_salvos_geral, sizeof(jogadores_salvos_geral), 1, p);	
	}	
	
	int fechou = fclose(p);
	if(fechou != 0){
		printf("O arquivo não pôde ser fechado\n");
	}
	
	zerar_ranking_partida();
	
}

void sortear_perguntas_do_tema(Pergunta faceis[3], Pergunta medias[3], Pergunta dificeis[3], Pergunta muito_dificeis[3]){
	int tema = tela_de_temas();	
	switch(tema){
		case 1:{					
			sortear_perguntas(faceis, geral_faceis, 20);				
			sortear_perguntas(medias, geral_medias, 20);						
			sortear_perguntas(dificeis, geral_dificeis, 20);
			sortear_perguntas(muito_dificeis, geral_muito_dificeis, 15);
			break;
		}
		case 2:{		
			sortear_perguntas(faceis, filmes_faceis, 60);
			sortear_perguntas(medias, filmes_medias, 60);
			sortear_perguntas(dificeis, filmes_dificeis, 60);
			sortear_perguntas(muito_dificeis, filmes_muito_dificeis, 15);
			break;
		}
		case 3:{
			sortear_perguntas(faceis, jogos_faceis, 20);
			sortear_perguntas(medias, jogos_medias, 20);
			sortear_perguntas(dificeis, jogos_dificeis, 20);
			sortear_perguntas(muito_dificeis, jogos_muito_dificeis, 15);
			break;
		}
		case 4:{
			sortear_perguntas(faceis, esportes_faceis, 20);
			sortear_perguntas(medias, esportes_medias, 20);
			sortear_perguntas(dificeis, esportes_dificeis, 20);
			sortear_perguntas(muito_dificeis, esportes_muito_dificeis, 15);
			break;
		}
		case 5:{
			sortear_perguntas(faceis, series_faceis, 25);
			sortear_perguntas(medias, series_medias, 27);
			sortear_perguntas(dificeis, series_dificeis, 23);
			sortear_perguntas(muito_dificeis, series_muito_dificeis, 15);
			break;
		}
	}
}

void mostrar_cadastro(){
	system("cls");
	char nome[300];
	printf("Digite um nome: ");
	fflush(stdin);
	gets(nome);
	int i;
	int encontrado = 0;
	//Buscando no ranking geral
	for(i = 0; i < jogadores_salvos_geral.quantidade; i++){
		if(strcmpi(jogadores_salvos_geral.jogadores_salvos[i].nome, nome) == 0){
			system("cls");
			printf("Nome: %s\n", jogadores_salvos_geral.jogadores_salvos[i].nome);
			printf("Telefone: %s\n", jogadores_salvos_geral.jogadores_salvos[i].telefone);
			printf("Escola: %s\n", jogadores_salvos_geral.jogadores_salvos[i].escola);
			printf("Serie: %s\n", jogadores_salvos_geral.jogadores_salvos[i].serie);
			printf("Pontuação: %i\n", jogadores_salvos_geral.jogadores_salvos[i].pontuacao);
			printf("Tempo: %.3f\n", jogadores_salvos_geral.jogadores_salvos[i].tempo);
			encontrado = 1;
			return;
		}
	}
	
	//Buscando no ranking atual
	
	for(i = 0; i < jogadores_salvos_partida.quantidade; i++){
		if(strcmpi(jogadores_salvos_partida.jogadores_salvos[i].nome, nome) == 0){
			system("cls");
			printf("Nome: %s\n", jogadores_salvos_partida.jogadores_salvos[i].nome);
			printf("Telefone: %s\n", jogadores_salvos_partida.jogadores_salvos[i].telefone);
			printf("Escola: %s\n", jogadores_salvos_partida.jogadores_salvos[i].escola);
			printf("Serie: %s\n", jogadores_salvos_partida.jogadores_salvos[i].serie);
			printf("Pontuação: %i\n", jogadores_salvos_partida.jogadores_salvos[i].pontuacao);
			printf("Tempo: %.3f\n", jogadores_salvos_partida.jogadores_salvos[i].tempo);
			encontrado = 1;
			return;
		}
	}	
	
	if(encontrado == 0){
		printf("%s não cadastrado\n", nome);
	}
	system("pause");
}

void exibir_tela_configuracoes(){
	int opcao;
	do{
		system("cls");
		printf("Escolha uma opção\n");
		printf("1 - Ver Ranking Atual\n");
		printf("2 - Ver Ranking Geral\n");
		printf("3 - Ver Cadastro\n");
		printf("4 - Iniciar Nova Rodada de Perguntas\n");
		printf("5 - Retornar ao menu inicial\n");
		printf("Opção: ");
		scanf("%i", &opcao);
	}while(opcao < 0 || opcao > 5);
	system("cls");
	switch(opcao){
		case 1:{
			mostrar_ranking_atual();
			break;
		}
		case 2:{
			mostrar_ranking_geral();
			break;
		}
		case 3:{
			mostrar_cadastro();
			break;
		}
		case 4:{
			copiar_ranking_atual_para_geral();
			break;
		}
		case 5:{
			return;
		}
	}
	system("pause");
	exibir_tela_configuracoes();	
}

void exibir_tela_senha(){	
	int i;
	int total_letras = 0;
	char senha_digitada[11];
	int contador = 0;
	while(contador < 3){
		//DIGITANDO A SENHA
		system("cls");
		printf("\nDIGITE A SENHA: ");
	    fflush(stdin);
		for (i=0;;i++){//FOR que executa para sempre
	    	senha_digitada[i]=getch();
	        if(senha_digitada[i]==13 && total_letras != 0){//IF para verificar se o enter foi pressionado
	        	break;//Break interrompe o FOR
	        }        
	        printf("*");
	        total_letras++;
	    }
	    senha_digitada[i] = '\0';
	    	    
	    if(strcmpi(senha_digitada, "SNCT2015") == 0){
	    	printf("\n");
	    	exibir_tela_configuracoes();
	    	break;
	    }else{
	    	contador++;
			printf("\n\nSenha incorreta!!!\n");	    	
	    	if(contador < 3){
	    		printf("Tente novamente\n");
	    	}else{
	    		printf("Você excedeu o limite de tentativas\n");				
		    }
	    	system("pause");
	    }
	}	
}

void exibir_menu_inicial(){	
	int opcao;
	do{
		tela_de_boas_vindas();
		system("cls");
		printf("Escolha uma opção\n");
		printf("1 - Jogar\n");
		printf("2 - Configurações\n");
		printf("3 - Finalizar Programa\n\n");
		printf("Opção: ");
		scanf("%i", &opcao);
	}while(opcao < 0 || opcao > 3);
	system("cls");
	switch(opcao){
		case 1:{
			jogar();
			break;		
		}
		case 2:{
			exibir_tela_senha();
			break;
		}		
		case 3:{
			printf("\nPrograma Finalizado\n");
			exit(0);
			break;
		}
	}
	
	system("pause");
}

void carregar_arquivos(){
	jogadores_salvos_partida.quantidade = 0;
	carregar_ranking_geral();	
	carregar_ranking_partida();	
	carregar_perguntas();	
}

void jogar(){
	system("cls");		
	tela_cadastro_jogador();
	Pergunta faceis[3];	
	Pergunta medias[3];	
	Pergunta dificeis[3];
	Pergunta muito_dificeis[3];
	sortear_perguntas_do_tema(faceis, medias, dificeis, muito_dificeis);
	jogador.pontuacao = 0;
	float inicio, fim, tempo;
	inicio = GetTickCount();//Iniciar cronômetro	
	jogar_partida(faceis, 0);
	jogar_partida(medias, 0);
	jogar_partida(dificeis, 0);	
	
	char resposta = perguntar_continuar();
	if(resposta == 's'){
		jogar_partida(muito_dificeis, 1);	
	}
	
	fim = GetTickCount();//Parar cronômetro
	tempo = (fim - inicio)/1000;//Passando de milisegundos para segundos
	jogador.tempo = tempo;
	system("cls");
	printf("O jogo demorou %.3f segundos\n", tempo);
	printf("Você fez %i pontos\n", jogador.pontuacao);
	salvar_dados();
	mostrar_ranking_atual();
	//mostrar_ranking_geral();
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	srand((unsigned)time(NULL));
	int finalizar_programa = 1;
	carregar_arquivos();
	while(finalizar_programa == 1){		
		exibir_menu_inicial();
	}	
	return 0;
}


/*
	O que falta fazer
	1 - Melhorar as telas de boas vindas e de ranking
	
*/
