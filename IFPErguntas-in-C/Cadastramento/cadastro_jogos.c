#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
	char pergunta[500];
	char alternativa_A[250];
	char alternativa_B[250];
	char alternativa_C[250];
	char alternativa_D[250];
	int pontuacao;
	char alternativa_correta;
}Pergunta;

//variáveis globais
char nome_arquivo_faceis[30] = "jogos_faceis.txt";
char nome_arquivo_medias[30] = "jogos_medias.txt";
char nome_arquivo_dificeis[30] = "jogos_dificeis.txt";
char nome_arquivo_muito_dificeis[40] = "jogos_muito_dificeis.txt";
Pergunta faceis[20];
Pergunta medias[20];
Pergunta dificeis[20];
Pergunta muito_dificeis[15];

void cadastrar_faceis(){
	int pontuacao = 20;
	//Pergunta 1
	strcpy(faceis[0].pergunta,"Qual o protagonista principal na série Lengend of Zelda?");
	strcpy(faceis[0].alternativa_A,"Link");
	strcpy(faceis[0].alternativa_B,"Zelda");
	strcpy(faceis[0].alternativa_C,"Ganondorf");
	strcpy(faceis[0].alternativa_D,"Anju");
	faceis[0].pontuacao = pontuacao;
	//Pergunta 2
	strcpy(faceis[1].pergunta,"Quem e é heroi do Devil May Cry");
	strcpy(faceis[1].alternativa_A,"Dante");
	strcpy(faceis[1].alternativa_B,"Axel");
	strcpy(faceis[1].alternativa_C,"Mundus");
	strcpy(faceis[1].alternativa_D,"Vergil");
	faceis[1].pontuacao = pontuacao;
	//Pergunta 3
	strcpy(faceis[2].pergunta,"Qual é o mamífero azul capaz de correr pela tela em uma velocidade extremamente alta?");
	strcpy(faceis[2].alternativa_A,"Sonic");
	strcpy(faceis[2].alternativa_B,"Mega Man");
	strcpy(faceis[2].alternativa_C,"Ligeirinho");
	strcpy(faceis[2].alternativa_D,"Ace lightning");
	faceis[2].pontuacao = pontuacao;
	//Pergunta 4
	strcpy(faceis[3].pergunta,"Mortal Kombat é um jogo de que tipo?");
	strcpy(faceis[3].alternativa_A,"Luta");
	strcpy(faceis[3].alternativa_B,"Adventure");
	strcpy(faceis[3].alternativa_C,"Moba");
	strcpy(faceis[3].alternativa_D,"Esportes");
	faceis[3].pontuacao = pontuacao;
	//Pergunta 5
	strcpy(faceis[4].pergunta,"Qual jogador de futebol argentino está na capa do jogo Fifa 13 e Fifa 14?");
	strcpy(faceis[4].alternativa_A,"Messi");
	strcpy(faceis[4].alternativa_B,"Neymar");
	strcpy(faceis[4].alternativa_C,"Aguero");
	strcpy(faceis[4].alternativa_D,"Cristiano Ronaldo");
	faceis[4].pontuacao = pontuacao;
	//Pergunta 6
	strcpy(faceis[5].pergunta,"Wario land foi o terceiro jogo de que série de Mario para Nintendo game boy?");
	strcpy(faceis[5].alternativa_A,"Super Mario Land");
	strcpy(faceis[5].alternativa_B,"Mario Kart");
	strcpy(faceis[5].alternativa_C,"Super Mario World");
	strcpy(faceis[5].alternativa_D,"Super Mario Bross");
	faceis[5].pontuacao = pontuacao;	
	//Pergunta 7
	strcpy(faceis[6].pergunta,"Qual jogo da série Need for Speed o corredor adquire territórios, vencendo corridas contra o chefe do mesmo?");
	strcpy(faceis[6].alternativa_A,"Need For Speed: Carbon");
	strcpy(faceis[6].alternativa_B,"Need For Speed: Underground");
	strcpy(faceis[6].alternativa_C,"Need For Speed:	Hot Pursuit");
	strcpy(faceis[6].alternativa_D,"Need For Speed II");
	faceis[6].pontuacao = pontuacao;
	//Pergunta 8
	strcpy(faceis[7].pergunta,"Qual é o maior inimigo do Mario (Super Mario Bros.)?");
	strcpy(faceis[7].alternativa_A,"Bowser");
	strcpy(faceis[7].alternativa_B,"Browser");
	strcpy(faceis[7].alternativa_C,"Wario");
	strcpy(faceis[7].alternativa_D,"Luigi");
	faceis[7].pontuacao = pontuacao;
	//Pergunta 9
	strcpy(faceis[8].pergunta,"Qual era o nome antigo do Mario?");
	strcpy(faceis[8].alternativa_A,"Jumpman");
	strcpy(faceis[8].alternativa_B,"Sempre foi Mario");
	strcpy(faceis[8].alternativa_C,"Shigeru");
	strcpy(faceis[8].alternativa_D,"Luigi");
	faceis[8].pontuacao = pontuacao;
	//Pergunta 10
	strcpy(faceis[9].pergunta,"Qual é o protagonista do GTA San Andreas?");
	strcpy(faceis[9].alternativa_A,"CJ");
	strcpy(faceis[9].alternativa_B,"Niko Belic");
	strcpy(faceis[9].alternativa_C,"O usuario escolhe o nome dele");
	strcpy(faceis[9].alternativa_D,"Trevor");
	faceis[9].pontuacao = pontuacao;
	//Pergunta 11
	strcpy(faceis[10].pergunta,"Qual desses monstros não pega fogo de dia no Minecraft e pode aparecer a qualquer momento?");
	strcpy(faceis[10].alternativa_A,"Creeper");
	strcpy(faceis[10].alternativa_B,"Esqueleto");
	strcpy(faceis[10].alternativa_C,"Zumbi");
	strcpy(faceis[10].alternativa_D,"Homem urso porco");
	faceis[10].pontuacao = pontuacao;
	//Pergunta 12
	strcpy(faceis[11].pergunta,"Em Obscure 1, Kenny sumiu em que local da escola?");
	strcpy(faceis[11].alternativa_A,"No porão da escola");
	strcpy(faceis[11].alternativa_B,"No sótão da escola");
	strcpy(faceis[11].alternativa_C,"Em uma sala secreta na biblioteca");
	strcpy(faceis[11].alternativa_D,"No terraço do 'Mundo alternativo' da escola");
	faceis[11].pontuacao = pontuacao;
	//Pergunta 13
	strcpy(faceis[12].pergunta,"Qual o nome da empresa em que Gordon Freeman trabalhou em Half Life 1?");
	strcpy(faceis[12].alternativa_A,"Black Mesa");
	strcpy(faceis[12].alternativa_B,"Corporação Anti-Alien");
	strcpy(faceis[12].alternativa_C,"Umbrella");
	strcpy(faceis[12].alternativa_D,"Combine");
	faceis[12].pontuacao = pontuacao;	
	//Pergunta 14
	strcpy(faceis[13].pergunta,"Qual dos jogos abaixo é do gênero FPS?");
	strcpy(faceis[13].alternativa_A,"Doom II: Hell on Eart");
	strcpy(faceis[13].alternativa_B,"Mid Night Club");
	strcpy(faceis[13].alternativa_C,"Van Helsing");
	strcpy(faceis[13].alternativa_D,"God Of War");
	faceis[13].pontuacao = pontuacao;
	//Pergunta 15
	strcpy(faceis[14].pergunta,"O que é a Black Mesa (Half Life)?");
	strcpy(faceis[14].alternativa_A,"Uma Empresa");
	strcpy(faceis[14].alternativa_B,"Tipo de Zumbi");
	strcpy(faceis[14].alternativa_C,"Alienígena");
	strcpy(faceis[14].alternativa_D,"Um tipo de mesa inventada pelo Dr. Kleiner");
	faceis[14].pontuacao = pontuacao;
	//Pergunta 16
	strcpy(faceis[15].pergunta,"Quem é o protagonista do Resident Evil 4?");
	strcpy(faceis[15].alternativa_A,"Leon S. Kennedy");
	strcpy(faceis[15].alternativa_B,"Sheva Alomar");
	strcpy(faceis[15].alternativa_C,"Chris Redfield");
	strcpy(faceis[15].alternativa_D,"Leon Davis Smith");
	faceis[15].pontuacao = pontuacao;
	//Pergunta 17
	strcpy(faceis[16].pergunta,"Quem é o protagonista do God of War?");
	strcpy(faceis[16].alternativa_A,"Kratos");
	strcpy(faceis[16].alternativa_B,"Zeus");
	strcpy(faceis[16].alternativa_C,"Hades");
	strcpy(faceis[16].alternativa_D,"Ares");
	faceis[16].pontuacao = pontuacao;
	//Pergunta 18
	strcpy(faceis[17].pergunta,"Quem é o protagonista do Darksiders 2?");
	strcpy(faceis[17].alternativa_A,"Morte");
	strcpy(faceis[17].alternativa_B,"Guerra");
	strcpy(faceis[17].alternativa_C,"Fome");
	strcpy(faceis[17].alternativa_D,"Peste");
	faceis[17].pontuacao = pontuacao;
	//Pergunta 19
	strcpy(faceis[18].pergunta,"Onde fica a relíquia de número 1 em Far Cry 3?");
	strcpy(faceis[18].alternativa_A,"Na caverna dos amigos");
	strcpy(faceis[18].alternativa_B,"Atrás da cachoeira");
	strcpy(faceis[18].alternativa_C,"Em um avião");
	strcpy(faceis[18].alternativa_D,"Em um acampamento");
	faceis[18].pontuacao = pontuacao;
	//Pergunta 20
	strcpy(faceis[19].pergunta,"Em que cidade se passa o GTA IV?");
	strcpy(faceis[19].alternativa_A,"New York");
	strcpy(faceis[19].alternativa_B,"Los Angeles");
	strcpy(faceis[19].alternativa_C,"Las Vegas");
	strcpy(faceis[19].alternativa_D,"San Andreas");
	faceis[19].pontuacao = pontuacao;
	
	
//=====================NÃO MEXER NESSE CÓDIGO=====================
	FILE *p;
	p = fopen(nome_arquivo_faceis, "r+");//ABRE O ARQUIVO PARA LEITURA E ESCRITA
	if(p == NULL){
		p = fopen(nome_arquivo_faceis, "w");//CRIA O ARQUIVO CASO NÃO EXISTA
		if(p == NULL){
			printf("O arquivo não pôde ser criado\n");
		}
	}
	fwrite(&faceis, sizeof(faceis), 1, p);
	int fechou = fclose(p);
	if(fechou != 0){
		printf("O arquivo não pôde ser fechado\n");
	}else{
		printf("Cadastro de perguntas fáceis realizado com sucesso\n");
	}
//=====================NÃO MEXER NESSE CÓDIGO=====================
}

void cadastrar_medias(){
	int pontuacao = 50;
	//Pergunta 1
	strcpy(medias[0].pergunta,"No inicio do jogo 'Assassin's Creed III',  Haytham Kenway se infiltra em uma ópera a fim de roubar um certo objeto, que objeto era esse?");
	strcpy(medias[0].alternativa_A,"Um medalhão Maia");
	strcpy(medias[0].alternativa_B,"Uma chave de ouro");
	strcpy(medias[0].alternativa_C,"Uma Pedra");
	strcpy(medias[0].alternativa_D,"Um Diário");
	medias[0].pontuacao = pontuacao;
	//Pergunta 2
	strcpy(medias[1].pergunta,"Quem narra o jogo 'Fifa 14' no idioma Português do Brasil?");
	strcpy(medias[1].alternativa_A,"Tiago Leifert");
	strcpy(medias[1].alternativa_B,"Alex Escobar");
	strcpy(medias[1].alternativa_C,"Gauvão Bueno");
	strcpy(medias[1].alternativa_D,"Silvio Luis");
	medias[1].pontuacao = pontuacao;
	//Pergunta 3
	strcpy(medias[2].pergunta,"Qual o nome do irmão de Dante, protagonista da série de jogos 'Devil may cry'?");
	strcpy(medias[2].alternativa_A,"Vergil");
	strcpy(medias[2].alternativa_B,"Felix");
	strcpy(medias[2].alternativa_C,"Kratos");
	strcpy(medias[2].alternativa_D,"Wayne");
	medias[2].pontuacao = pontuacao;
	//Pergunta 4
	strcpy(medias[3].pergunta,"Quantos deuses Kratos aniquila no decorrer do jogo God of War III?");
	strcpy(medias[3].alternativa_A,"Mais de cinco");
	strcpy(medias[3].alternativa_B,"Quatro");
	strcpy(medias[3].alternativa_C,"Três");
	strcpy(medias[3].alternativa_D,"Dois");
	medias[3].pontuacao = pontuacao;
	//Pergunta 5
	strcpy(medias[4].pergunta,"Qual o nome da cidade que se passa o 'Left 4 dead 2'?");
	strcpy(medias[4].alternativa_A,"New Jersey");
	strcpy(medias[4].alternativa_B,"New York");
	strcpy(medias[4].alternativa_C,"San Francisco");
	strcpy(medias[4].alternativa_D,"London");
	medias[4].pontuacao = pontuacao;
	//Pergunta 6
	strcpy(medias[5].pergunta,"Por que, em 'Shadow of the Colossus', Wander precisa derrotar os colossos?");
	strcpy(medias[5].alternativa_A,"Para ressucitar sua amada");
	strcpy(medias[5].alternativa_B,"Para acabar com o mundo");
	strcpy(medias[5].alternativa_C,"Para se tornar um Deus");
	strcpy(medias[5].alternativa_D,"Para se divertir");
	medias[5].pontuacao = pontuacao;
	//Pergunta 7
	strcpy(medias[6].pergunta,"Em que país se passa o jogo 'Resident Evil 4'?");
	strcpy(medias[6].alternativa_A,"Espanha");
	strcpy(medias[6].alternativa_B,"Alemanha");
	strcpy(medias[6].alternativa_C,"Catar");
	strcpy(medias[6].alternativa_D,"Estados Unidos");
	medias[6].pontuacao = pontuacao;
	//Pergunta 8
	strcpy(medias[7].pergunta,"Em 'Tomb Raider: Underworld', o que Lara Croft usa para enfrentar Natta?");
	strcpy(medias[7].alternativa_A,"O martelo de Thor");
	strcpy(medias[7].alternativa_B,"Uma faca");
	strcpy(medias[7].alternativa_C,"Uma pistola");
	strcpy(medias[7].alternativa_D,"Blade of chaos");
	medias[7].pontuacao = pontuacao;
	//Pergunta 9
	strcpy(medias[8].pergunta,"Em Watch Dogs, qual parte do corpo Damien quebrou?");
	strcpy(medias[8].alternativa_A,"Perna");
	strcpy(medias[8].alternativa_B,"Bacia");
	strcpy(medias[8].alternativa_C,"Braço");
	strcpy(medias[8].alternativa_D,"Espinha");
	medias[8].pontuacao = pontuacao;
	//Pergunta 10
	strcpy(medias[9].pergunta,"Em The Witcher, qual missão dada a Geralt de Rivia no inicio do jogo?");
	strcpy(medias[9].alternativa_A,"Curar a filha do rei Foltest");
	strcpy(medias[9].alternativa_B,"Encontrar a feiticeira Triss Merigold");
	strcpy(medias[9].alternativa_C,"Não recebe nenhuma missão, o jogo é mundo livre");
	strcpy(medias[9].alternativa_D,"Acabar com a gangue Salamandra");
	medias[9].pontuacao = pontuacao;
	//Pergunta 11
	strcpy(medias[10].pergunta,"Em The Order: 1886, Ao fugir de onde estava, Grayson é encurralado. Como faz fugir?");
	strcpy(medias[10].alternativa_A,"Ele pula da torre");
	strcpy(medias[10].alternativa_B,"Ele recebe ajuda de um amigo da ordem");
	strcpy(medias[10].alternativa_C,"Ele atira no chefe");
	strcpy(medias[10].alternativa_D,"Ele usa uma amiga como refém");
	medias[10].pontuacao = pontuacao;
	//Pergunta 12
	strcpy(medias[11].pergunta,"Em The Order: 1886, Que cientista aparece no decorrer do jogo?");
	strcpy(medias[11].alternativa_A,"Nikola Tesla");
	strcpy(medias[11].alternativa_B,"Leonardo Da Vinci");
	strcpy(medias[11].alternativa_C,"Albert Einstein ");
	strcpy(medias[11].alternativa_D,"Isaac Newton");
	medias[11].pontuacao = pontuacao;
	//Pergunta 13
	strcpy(medias[12].pergunta,"Quando jogamos Clash of Clans, qual é o primeiro guerreiro que ganhamos?");
	strcpy(medias[12].alternativa_A,"Bárbaro");
	strcpy(medias[12].alternativa_B,"Arqueiro");
	strcpy(medias[12].alternativa_C,"Bárbaro arqueiro gigante");
	strcpy(medias[12].alternativa_D,"Gigante");
	medias[12].pontuacao = pontuacao;
	//Pergunta 14
	strcpy(medias[13].pergunta,"Em Batman: Arkham Asylum, Quando o Coringa é levado ao Asilo Arkham quem o ajuda a escapar?");
	strcpy(medias[13].alternativa_A,"Arlequina");
	strcpy(medias[13].alternativa_B,"Charada");
	strcpy(medias[13].alternativa_C,"Bane");
	strcpy(medias[13].alternativa_D,"Espantalho");
	medias[13].pontuacao = pontuacao;
	//Pergunta 15
	strcpy(medias[14].pergunta,"Em qual game da franquia Zelda, começa a contar a história toda?");
	strcpy(medias[14].alternativa_A,"Skyward Swards");
	strcpy(medias[14].alternativa_B,"O primeiro Zelda");
	strcpy(medias[14].alternativa_C,"Ocarina Of Time");
	strcpy(medias[14].alternativa_D,"Majora Mask");
	medias[14].pontuacao = pontuacao;
	//Pergunta 16
	strcpy(medias[15].pergunta,"Qual desses elementos não existe em Minecraft?");
	strcpy(medias[15].alternativa_A,"Barbante");
	strcpy(medias[15].alternativa_B,"Esmeralda");
	strcpy(medias[15].alternativa_C,"Obsidiana");
	strcpy(medias[15].alternativa_D,"Polvora");
	medias[15].pontuacao = pontuacao;
	//Pergunta 17
	strcpy(medias[16].pergunta,"Em Half-Life, quem é o melhor amigo do Gordon?");
	strcpy(medias[16].alternativa_A,"Barney Calhoun ");
	strcpy(medias[16].alternativa_B,"Alyx Vance");
	strcpy(medias[16].alternativa_C,"Dr. Isaac Kleiner");
	strcpy(medias[16].alternativa_D,"Gina Cross");
	medias[16].pontuacao = pontuacao;
	//Pergunta 18
	strcpy(medias[17].pergunta,"Qual jogo se passa no mesmo universo que Half-Life2?");
	strcpy(medias[17].alternativa_A,"Portal");
	strcpy(medias[17].alternativa_B,"Left 4 dead 2");
	strcpy(medias[17].alternativa_C,"Team Fortress 2");
	strcpy(medias[17].alternativa_D,"Call of Duty");
	medias[17].pontuacao = pontuacao;
	//Pergunta 19
	strcpy(medias[18].pergunta,"Quando acontece a Guerra das 7 horas?");
	strcpy(medias[18].alternativa_A,"Entre Half-Life 1 e 2");
	strcpy(medias[18].alternativa_B,"Half-Life 1");
	strcpy(medias[18].alternativa_C,"Half-Life 2");
	strcpy(medias[18].alternativa_D,"Half-Life Before");
	medias[18].pontuacao = pontuacao;
	//Pergunta 20
	strcpy(medias[19].pergunta,"Qual é o vilão principal do Mega Man X5?");
	strcpy(medias[19].alternativa_A,"Sigma");
	strcpy(medias[19].alternativa_B,"Shadow Devil");
	strcpy(medias[19].alternativa_C,"Zero");
	strcpy(medias[19].alternativa_D,"Dr. Wily");
	medias[19].pontuacao = pontuacao;
	

//=====================NÃO MEXER NESSE CÓDIGO=====================
	FILE *p;
	p = fopen(nome_arquivo_medias, "r+");//ABRE O ARQUIVO PARA LEITURA E ESCRITA
	if(p == NULL){
		p = fopen(nome_arquivo_medias, "w");//CRIA O ARQUIVO CASO NÃO EXISTA
		if(p == NULL){
			printf("O arquivo não pôde ser criado\n");
		}
	}
	fwrite(&medias, sizeof(medias), 1, p);
	int fechou = fclose(p);
	if(fechou != 0){
		printf("O arquivo não pôde ser fechado\n");
	}else{
		printf("Cadastro de perguntas medias realizado com sucesso\n");
	}
//=====================NÃO MEXER NESSE CÓDIGO=====================
}

void cadastrar_dificeis(){
	int pontuacao = 100;
	//Pergunta 1
	strcpy(dificeis[0].pergunta,"Qual é o nome real do Blanka do Street Fighter?");
	strcpy(dificeis[0].alternativa_A,"Jimmy");
	strcpy(dificeis[0].alternativa_B,"Jin");
	strcpy(dificeis[0].alternativa_C,"Jonh");
	strcpy(dificeis[0].alternativa_D,"Jonny");
	dificeis[0].pontuacao = pontuacao;
	//Pergunta 2
	strcpy(dificeis[1].pergunta,"Em Halo 3, quem mata Johnson?");
	strcpy(dificeis[1].alternativa_A,"O monitor");
	strcpy(dificeis[1].alternativa_B,"Os Covenants");
	strcpy(dificeis[1].alternativa_C,"Ele nem morre no jogo");
	strcpy(dificeis[1].alternativa_D,"Ele se mata");
	dificeis[1].pontuacao = pontuacao;
	//Pergunta 3
	strcpy(dificeis[2].pergunta,"Qual é a ultima palavra dita em Call Of Duty Ghosts?");
	strcpy(dificeis[2].alternativa_A,"'Logan'");
	strcpy(dificeis[2].alternativa_B,"'Ghosts'");
	strcpy(dificeis[2].alternativa_C,"'Obrigado'");
	strcpy(dificeis[2].alternativa_D,"'Conseguiu'");
	dificeis[2].pontuacao = pontuacao;
	//Pergunta 4
	strcpy(dificeis[3].pergunta,"No jogo The Godfather 2 (O poderoso chefão 2), quantas evoluções uma arma pode ter após sua fase inicial?");
	strcpy(dificeis[3].alternativa_A,"2");
	strcpy(dificeis[3].alternativa_B,"3");
	strcpy(dificeis[3].alternativa_C,"4");
	strcpy(dificeis[3].alternativa_D,"1");
	dificeis[3].pontuacao = pontuacao;
	//Pergunta 5
	strcpy(dificeis[4].pergunta,"(Street Fighter) Complete: Ryu é órfão e foi adotado por_____________.");
	strcpy(dificeis[4].alternativa_A,"Gouken");
	strcpy(dificeis[4].alternativa_B,"Akuma");
	strcpy(dificeis[4].alternativa_C,"Zangief");
	strcpy(dificeis[4].alternativa_D,"Gen");
	dificeis[4].pontuacao = pontuacao;
	//Pergunta 6
	strcpy(dificeis[5].pergunta,"Qual era o subtítulo do jogo de RPG 'Shadowgate 64' para Nintendo 64?");
	strcpy(dificeis[5].alternativa_A,"Trials of the Four Towers");
	strcpy(dificeis[5].alternativa_B,"As duas torres");
	strcpy(dificeis[5].alternativa_C,"Circle os Twelve");
	strcpy(dificeis[5].alternativa_D,"Ocarina Of Time");
	dificeis[5].pontuacao = pontuacao;
	//Pergunta 7
	strcpy(dificeis[6].pergunta,"'War. War never changes' é uma citação famosa de qual série de jogos?");
	strcpy(dificeis[6].alternativa_A,"Fallout");
	strcpy(dificeis[6].alternativa_B,"Borderlands");
	strcpy(dificeis[6].alternativa_C,"Tetris");
	strcpy(dificeis[6].alternativa_D,"Mario Kart");
	dificeis[6].pontuacao = pontuacao;
	//Pergunta 8
	strcpy(dificeis[7].pergunta,"Em qual videogame de estilo 'Construa você mesmo' Se pode jogar com o personagem Sackboy?");
	strcpy(dificeis[7].alternativa_A,"LittleBigPlanet");
	strcpy(dificeis[7].alternativa_B,"Tales of monkey island");
	strcpy(dificeis[7].alternativa_C,"Banjo-Kazooie");
	strcpy(dificeis[7].alternativa_D,"Sly cooper");
	dificeis[7].pontuacao = pontuacao;
	//Pergunta 9
	strcpy(dificeis[8].pergunta,"Em Street Fighter, quem matou Gouken?");
	strcpy(dificeis[8].alternativa_A,"Akuma");
	strcpy(dificeis[8].alternativa_B,"M. Bison");
	strcpy(dificeis[8].alternativa_C,"Sagat");
	strcpy(dificeis[8].alternativa_D,"Blanka");
	dificeis[8].pontuacao = pontuacao;
	//Pergunta 10
	strcpy(dificeis[9].pergunta,"Quantos estádios possui o jogo International Super Star Soccer Deluxe?");
	strcpy(dificeis[9].alternativa_A,"8");
	strcpy(dificeis[9].alternativa_B,"6");
	strcpy(dificeis[9].alternativa_C,"4");
	strcpy(dificeis[9].alternativa_D,"2");
	dificeis[9].pontuacao = pontuacao;
	//Pergunta 11
	strcpy(dificeis[10].pergunta,"Em que ano a história de BioShock decorre?");
	strcpy(dificeis[10].alternativa_A,"1960");
	strcpy(dificeis[10].alternativa_B,"1961");
	strcpy(dificeis[10].alternativa_C,"4000 a.c");
	strcpy(dificeis[10].alternativa_D,"Ano 0");
	dificeis[10].pontuacao = pontuacao;
	//Pergunta 12
	strcpy(dificeis[11].pergunta,"Em que cidade se passa o jogo Bloodborne?");
	strcpy(dificeis[11].alternativa_A,"Yharnam");
	strcpy(dificeis[11].alternativa_B,"Bloodborne");
	strcpy(dificeis[11].alternativa_C,"Londres");
	strcpy(dificeis[11].alternativa_D,"Vancouver");
	dificeis[11].pontuacao = pontuacao;
	//Pergunta 13
	strcpy(dificeis[12].pergunta,"Em Fatal Frame 2, quem Miu Amakura seguiu ate desaparecer na floresta?");
	strcpy(dificeis[12].alternativa_A,"Sua irmã ");
	strcpy(dificeis[12].alternativa_B,"Sua tia");
	strcpy(dificeis[12].alternativa_C,"Sua mãe");
	strcpy(dificeis[12].alternativa_D,"Sua avó");
	dificeis[12].pontuacao = pontuacao;
	//Pergunta 14
	strcpy(dificeis[13].pergunta,"Em Metroid, qual o nome da colônia em que Samus vivia com os pais quando criança?");
	strcpy(dificeis[13].alternativa_A,"K-2L");
	strcpy(dificeis[13].alternativa_B,"SR-388");
	strcpy(dificeis[13].alternativa_C,"Terra");
	strcpy(dificeis[13].alternativa_D,"Zebes");
	dificeis[13].pontuacao = pontuacao;
	//Pergunta 15
	strcpy(dificeis[14].pergunta,"Em Donkey Kong Country, pra que serve o barril 'DK'?");
	strcpy(dificeis[14].alternativa_A,"Ganha um parceiro");
	strcpy(dificeis[14].alternativa_B,"Ganha Bananas");
	strcpy(dificeis[14].alternativa_C,"Te teletransporta pro final da fase");
	strcpy(dificeis[14].alternativa_D,"Ganha Vida");
	dificeis[14].pontuacao = pontuacao;
	//Pergunta 16
	strcpy(dificeis[15].pergunta,"Em Donkey Kong Country 1, 2 e 3. Como se chama o nome do peixe?");
	strcpy(dificeis[15].alternativa_A,"Enguarde");
	strcpy(dificeis[15].alternativa_B,"Peixe");
	strcpy(dificeis[15].alternativa_C,"Rambi");
	strcpy(dificeis[15].alternativa_D,"Tuba");
	dificeis[15].pontuacao = pontuacao;
	//Pergunta 17
	strcpy(dificeis[16].pergunta,"Qual o gênero é o jogo Geometry Dash?");
	strcpy(dificeis[16].alternativa_A,"Running");
	strcpy(dificeis[16].alternativa_B,"Ação");
	strcpy(dificeis[16].alternativa_C,"Corrida");
	strcpy(dificeis[16].alternativa_D,"Arcade");
	dificeis[16].pontuacao = pontuacao;
	//Pergunta 18
	strcpy(dificeis[17].pergunta,"Em Dark Souls, chegamos em um dos mapas mais conhecidos da franquia. Qual o nome desse mapa?");
	strcpy(dificeis[17].alternativa_A,"Undead  Asylum ");
	strcpy(dificeis[17].alternativa_B,"Northern Undead Asylum ");
	strcpy(dificeis[17].alternativa_C,"Lordran Asylum");
	strcpy(dificeis[17].alternativa_D,"Zombie Asylum");
	dificeis[17].pontuacao = pontuacao;
	//Pergunta 19
	strcpy(dificeis[18].pergunta,"No jogo Lucius, Quem é Lucius?");
	strcpy(dificeis[18].alternativa_A,"Um menino de 6 anos que é filho do diabo ");
	strcpy(dificeis[18].alternativa_B,"Um simples menino de 6 anos");
	strcpy(dificeis[18].alternativa_C,"Lucius não é uma pessoa e sim um lugar");
	strcpy(dificeis[18].alternativa_D,"Um urso de pelúcia");
	dificeis[18].pontuacao = pontuacao;
	//Pergunta 20
	strcpy(dificeis[19].pergunta,"Qual é a empresa dona do Casttevania?");
	strcpy(dificeis[19].alternativa_A,"Konami");
	strcpy(dificeis[19].alternativa_B,"Capcom");
	strcpy(dificeis[19].alternativa_C,"Nintendo");
	strcpy(dificeis[19].alternativa_D,"Microsoft");
	dificeis[19].pontuacao = pontuacao;
	

	
//=====================NÃO MEXER NESSE CÓDIGO=====================
	FILE *p;
	p = fopen(nome_arquivo_dificeis, "r+");//ABRE O ARQUIVO PARA LEITURA E ESCRITA
	if(p == NULL){
		p = fopen(nome_arquivo_dificeis, "w");//CRIA O ARQUIVO CASO NÃO EXISTA
		if(p == NULL){
			printf("O arquivo não pôde ser criado\n");
		}
	}
	fwrite(&dificeis, sizeof(dificeis), 1, p);
	int fechou = fclose(p);
	if(fechou != 0){
		printf("O arquivo não pôde ser fechado\n");
	}else{
		printf("Cadastro de perguntas difíceis realizado com sucesso\n");
	}
//=====================NÃO MEXER NESSE CÓDIGO=====================
}

void cadastrar_muito_dificeis(){
	int pontuacao = 200;
	//Pergunta 1
	strcpy(muito_dificeis[0].pergunta,"(Left 4 Dead 2) Ao total, quantas campanhas há na série?");
	strcpy(muito_dificeis[0].alternativa_A,"10");
	strcpy(muito_dificeis[0].alternativa_B,"9");
	strcpy(muito_dificeis[0].alternativa_C,"8");
	strcpy(muito_dificeis[0].alternativa_D,"5");
	muito_dificeis[0].pontuacao = pontuacao;
	//Pergunta 2
	strcpy(muito_dificeis[1].pergunta,"(Bully) Qual a cor da camisa do uniforme de Jimmy?");
	strcpy(muito_dificeis[1].alternativa_A,"Azul");
	strcpy(muito_dificeis[1].alternativa_B,"Amarela");
	strcpy(muito_dificeis[1].alternativa_C,"Verde");
	strcpy(muito_dificeis[1].alternativa_D,"Vermelha");
	muito_dificeis[1].pontuacao = pontuacao;
	//Pergunta 3
	strcpy(muito_dificeis[2].pergunta,"Quais são os 3 personagens que tem o final secreto no King Of Fighters 1997 conhecidos como o Sidekick Team?");
	strcpy(muito_dificeis[2].alternativa_A,"Kim, Benimaru e Joe");
	strcpy(muito_dificeis[2].alternativa_B,"Shingo, Chin e Daimon");
	strcpy(muito_dificeis[2].alternativa_C,"Andy, Robert e Iori");
	strcpy(muito_dificeis[2].alternativa_D,"Terry, Ryo e Kyo");
	muito_dificeis[2].pontuacao = pontuacao;
	//Pergunta 4
	strcpy(muito_dificeis[3].pergunta,"(Tekken 5) Qual é o objetivo de Roger Jr.?");
	strcpy(muito_dificeis[3].alternativa_A,"Ganhar a competição para resgatar Rojer (pai de Rojer Jr.)");
	strcpy(muito_dificeis[3].alternativa_B,"Para lutar contra o mokujin");
	strcpy(muito_dificeis[3].alternativa_C,"Para proteger o mundo");
	strcpy(muito_dificeis[3].alternativa_D,"Só ganhar a competição");
	muito_dificeis[3].pontuacao = pontuacao;
	//Pergunta 5
	strcpy(muito_dificeis[4].pergunta,"(StarCraft II: Wings of Liberty e a sua expansão StarCraft II: Heart of the Swarm) Qual é a capital da Supremacia terrana?");
	strcpy(muito_dificeis[4].alternativa_A,"Korhal");
	strcpy(muito_dificeis[4].alternativa_B,"Shakuras");
	strcpy(muito_dificeis[4].alternativa_C,"Umoja");
	strcpy(muito_dificeis[4].alternativa_D,"Tyrador");
	muito_dificeis[4].pontuacao = pontuacao;
	//Pergunta 6
	strcpy(muito_dificeis[5].pergunta,"(RuneScape) Qual anel é adquirido quando completado lista de tarefas de lumbridge?");
	strcpy(muito_dificeis[5].alternativa_A,"Anel do explorador");
	strcpy(muito_dificeis[5].alternativa_B,"Anel de diamante");
	strcpy(muito_dificeis[5].alternativa_C,"Anel da vida");
	strcpy(muito_dificeis[5].alternativa_D,"Anel de safira");
	muito_dificeis[5].pontuacao = pontuacao;
	//Pergunta 7
	strcpy(muito_dificeis[6].pergunta,"(Priston Tale) Certas classes podem 'sumonar' alguns monstros. Sendo assim, quais são essas classes?");
	strcpy(muito_dificeis[6].alternativa_A,"Mecanico, Sacerdotiza , Arqueira , Mago");
	strcpy(muito_dificeis[6].alternativa_B,"Mecanico , Sacerdotiza, Cavaleiro , Lutador");
	strcpy(muito_dificeis[6].alternativa_C,"Pikeman , Lutador, Sacerdotiza , Cavaleiro");
	strcpy(muito_dificeis[6].alternativa_D,"Lutador, Atalanta , Mago , Mecanico");
	muito_dificeis[6].pontuacao = pontuacao;
	//Pergunta 8
	strcpy(muito_dificeis[7].pergunta,"(Grand Chase) O que na realidade Mari Onnete é?");
	strcpy(muito_dificeis[7].alternativa_A,"Uma robô");
	strcpy(muito_dificeis[7].alternativa_B,"Uma pessoa heterocromática");
	strcpy(muito_dificeis[7].alternativa_C,"Um núcleo");
	strcpy(muito_dificeis[7].alternativa_D,"Uma morta-viva");
	muito_dificeis[7].pontuacao = pontuacao;
	//Pergunta 9
	strcpy(muito_dificeis[8].pergunta,"No God Of War 3, qual é a chave que desbloqueia o labirinto?");
	strcpy(muito_dificeis[8].alternativa_A,"Gelo de bórias");
	strcpy(muito_dificeis[8].alternativa_B,"Capacete de Hades");
	strcpy(muito_dificeis[8].alternativa_C,"Moeda de Hermes");
	strcpy(muito_dificeis[8].alternativa_D,"Cálice de Hera");
	muito_dificeis[8].pontuacao = pontuacao;
	//Pergunta 10
	strcpy(muito_dificeis[9].pergunta,"(Haunting Ground) Quem é a personagem principal?");
	strcpy(muito_dificeis[9].alternativa_A,"Fiona");
	strcpy(muito_dificeis[9].alternativa_B,"Daniella");
	strcpy(muito_dificeis[9].alternativa_C,"Dorothy");
	strcpy(muito_dificeis[9].alternativa_D,"Jennifer");
	muito_dificeis[9].pontuacao = pontuacao;
	//Pergunta 11
	strcpy(muito_dificeis[10].pergunta,"Qual é a cor do vestido de Kairi em 'Kingdom Hearts II'?");
	strcpy(muito_dificeis[10].alternativa_A,"Rosa");
	strcpy(muito_dificeis[10].alternativa_B,"Verde");
	strcpy(muito_dificeis[10].alternativa_C,"Azul");
	strcpy(muito_dificeis[10].alternativa_D,"Vermelho");
	muito_dificeis[10].pontuacao = pontuacao;
	//Pergunta 12
	strcpy(muito_dificeis[11].pergunta,"(Plants vs Zombies) O Zumbi com Jornal fica irado ao perder o jornal, pois estava terminando o quê?");
	strcpy(muito_dificeis[11].alternativa_A,"Seu Sudoku");
	strcpy(muito_dificeis[11].alternativa_B,"Uma charada");
	strcpy(muito_dificeis[11].alternativa_C,"Um problema de lógica");
	strcpy(muito_dificeis[11].alternativa_D,"Palavras Cruzadas");
	muito_dificeis[11].pontuacao = pontuacao;
	//Pergunta 13
	strcpy(muito_dificeis[12].pergunta,"Senhor morte, é o apelido de qual personagem de Resident Evil? Por quê?");
	strcpy(muito_dificeis[12].alternativa_A,"Hunk, por ser duas vezes o único sobrevivente do esquadrão enviado pela Umbrella, por motivos específicos");
	strcpy(muito_dificeis[12].alternativa_B,"Hunk, porque matou vários membros dos S.T.A.R.S");
	strcpy(muito_dificeis[12].alternativa_C,"Leon, por ser um dos poucos sobreviventes à Racoon City");
	strcpy(muito_dificeis[12].alternativa_D,"Carlos Oliveira, por ter sido um mercenário sanguinário contratado pela Umbrella");
	muito_dificeis[12].pontuacao = pontuacao;
	//Pergunta 14
	strcpy(muito_dificeis[13].pergunta,"Em que lugar começa o Assassin's Creed Revelations?");
	strcpy(muito_dificeis[13].alternativa_A,"Masyaf");
	strcpy(muito_dificeis[13].alternativa_B,"Roma");
	strcpy(muito_dificeis[13].alternativa_C,"Constantinopla");
	strcpy(muito_dificeis[13].alternativa_D,"Boston");
	muito_dificeis[13].pontuacao = pontuacao;
	//Pergunta 15
	strcpy(muito_dificeis[14].pergunta,"(Silent Hill) O que acontece quando a tal famosa sirene é disparada no decorrer da história do jogo?");
	strcpy(muito_dificeis[14].alternativa_A,"Transição de mundos paralelos");
	strcpy(muito_dificeis[14].alternativa_B,"Toque de recolher");
	strcpy(muito_dificeis[14].alternativa_C,"Acidente nuclear");
	strcpy(muito_dificeis[14].alternativa_D,"Para informar que os bombeiros estavam chegando");
	muito_dificeis[14].pontuacao = pontuacao;
	
	
//=====================NÃO MEXER NESSE CÓDIGO=====================
	FILE *p;
	p = fopen(nome_arquivo_muito_dificeis, "r+");//ABRE O ARQUIVO PARA LEITURA E ESCRITA
	if(p == NULL){
		p = fopen(nome_arquivo_muito_dificeis, "w");//CRIA O ARQUIVO CASO NÃO EXISTA
		if(p == NULL){
			printf("O arquivo não pôde ser criado\n");
		}
	}
	fwrite(&muito_dificeis, sizeof(muito_dificeis), 1, p);
	int fechou = fclose(p);
	if(fechou != 0){
		printf("O arquivo não pôde ser fechado\n");
	}else{
		printf("Cadastro de perguntas muito difíceis realizado com sucesso\n");
	}
//=====================NÃO MEXER NESSE CÓDIGO=====================
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	cadastrar_faceis();
	cadastrar_medias();
	cadastrar_dificeis();	
	cadastrar_muito_dificeis();
	return 0;
}
