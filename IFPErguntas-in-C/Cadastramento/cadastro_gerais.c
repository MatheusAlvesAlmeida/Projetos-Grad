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
char nome_arquivo_faceis[30] = "gerais_faceis.txt";
char nome_arquivo_medias[30] = "gerais_medias.txt";
char nome_arquivo_dificeis[30] = "gerais_dificeis.txt";
char nome_arquivo_muito_dificeis[40] = "gerais_muito_dificeis.txt";
Pergunta faceis[20];
Pergunta medias[20];
Pergunta dificeis[20];
Pergunta muito_dificeis[15];

void cadastrar_faceis(){
	int pontuacao = 20;
	//Pergunta 1
	strcpy(faceis[0].pergunta,"Qual foi o estopim (fato que deu início) da Primeira Guerra Mundial?");
	strcpy(faceis[0].alternativa_A,"O assassinato de Francisco Ferdinando, príncipe do Império Austro-Húngaro");
	strcpy(faceis[0].alternativa_B,"A invasão da Polônia pelo exército alemão");
	strcpy(faceis[0].alternativa_C,"A formação do bloco militar composto por Alemanha, Itália e França");
	strcpy(faceis[0].alternativa_D,"A disputa por território no continente americano, principalmente entre Alemanha e Itália.");
	faceis[0].pontuacao = pontuacao;
	//Pergunta 2
	strcpy(faceis[1].pergunta,"Sobre o fim da Primeira Guerra Mundial é correto afirmar que:");
	strcpy(faceis[1].alternativa_A,"Os países da Tríplice Aliança saíram derrotados e foram forçados a assinarem o Tratado de Versalhes, que impôs severas punições e restrições aos derrotados, principalmente à Alemanha.");
	strcpy(faceis[1].alternativa_B,"Embora derrotados, Alemanha e Império Austro-Húngaro não sofreram punições e restrições militares.");
	strcpy(faceis[1].alternativa_C,"Os países da Tríplice Aliança venceram o conflito e retomaram o controle de diversos territórios na Europa, Ásia e África.");
	strcpy(faceis[1].alternativa_D,"Com a derrota na Primeira Guerra Mundial, os países da Tríplice Entente, principalmente Rússia e Grã-Bretanha, sofreram com uma forte crise econômica nas três décadas seguintes.");
	faceis[1].pontuacao = pontuacao;
	//Pergunta 3
	strcpy(faceis[2].pergunta,"Podemos apontar como uma das principais causas da Segunda Guerra Mundial:");
	strcpy(faceis[2].alternativa_A,"O surgimento e fortalecimento, na década de 1930, de governos totalitários na Europa, com objetivos expansionistas e militaristas.");
	strcpy(faceis[2].alternativa_B,"A rivalidade política e militar entre Alemanha e Itália no final da década de 1930.");
	strcpy(faceis[2].alternativa_C,"A política expansionista da França, que invadiu e conquistou vários territórios na Europa e na África no final da década de 1930.");
	strcpy(faceis[2].alternativa_D,"A aliança militar estabelecida por Itália, Alemanha e Estados Unidos no começo da década de 1930");
	faceis[2].pontuacao = pontuacao;
	//Pergunta 4
	strcpy(faceis[3].pergunta,"Qual das alternativas abaixo aponta o marco inicial da Segunda Guerra Mundial?");
	strcpy(faceis[3].alternativa_A,"A invasão da Polônia pelas forças armadas da Alemanha em 1º de setembro de 1939.");
	strcpy(faceis[3].alternativa_B,"O ataque do Japão à base militar norte-americana de Pearl Harbor.");
	strcpy(faceis[3].alternativa_C,"Os diversos bombardeios britânicos a várias cidades alemãs.");
	strcpy(faceis[3].alternativa_D,"O estabelecimento de acordos militares entre Alemanha, Itália e Japão.");
	faceis[3].pontuacao = pontuacao;
	//Pergunta 5
	strcpy(faceis[4].pergunta,"Sobre a crise de 29, marque a alternativa que responde qual pais ficou seriamente afetado e chegou a acusar um certo grupo por ser o culpado da crise.");
	strcpy(faceis[4].alternativa_A,"Alemanha");
	strcpy(faceis[4].alternativa_B,"Inglaterra");
	strcpy(faceis[4].alternativa_C,"França");
	strcpy(faceis[4].alternativa_D,"EUA");
	faceis[4].pontuacao = pontuacao;
	//Pergunta 6
	strcpy(faceis[5].pergunta,"Complete: Hiroshima e ___ foram as duas cidades atacadas por bombas atômicas.");
	strcpy(faceis[5].alternativa_A,"Nagasaki");
	strcpy(faceis[5].alternativa_B,"Montreal");
	strcpy(faceis[5].alternativa_C,"Hanôver");
	strcpy(faceis[5].alternativa_D,"Daegu");
	faceis[5].pontuacao = pontuacao;
	//Pergunta 7
	strcpy(faceis[6].pergunta,"Civilização cujos governantes eram conhecidos como faraós?");
	strcpy(faceis[6].alternativa_A,"Egípciai");
	strcpy(faceis[6].alternativa_B,"Indiana");
	strcpy(faceis[6].alternativa_C,"Grega");
	strcpy(faceis[6].alternativa_D,"Assíria");
	faceis[6].pontuacao = pontuacao;
	//Pergunta 8
	strcpy(faceis[7].pergunta,"Quem eram os rivais na guerra fria?");
	strcpy(faceis[7].alternativa_A,"EUA X URSS");
	strcpy(faceis[7].alternativa_B,"Inglaterra X Brasil");
	strcpy(faceis[7].alternativa_C,"EUA X Japão");
	strcpy(faceis[7].alternativa_D,"França X URSS");
	faceis[7].pontuacao = pontuacao;
	//Pergunta 9
	strcpy(faceis[8].pergunta,"O que foi a Guerra Fria?");
	strcpy(faceis[8].alternativa_A,"Momento de tensão entre os EUA e a URSS depois da 2ª Guerra Mundial");
	strcpy(faceis[8].alternativa_B,"A vingança dos Judeus");
	strcpy(faceis[8].alternativa_C,"Disputa pela Alsácia Lorena entre a Alemanha e a França");
	strcpy(faceis[8].alternativa_D,"Acerto de contas dos EUA com a Inglaterra");
	faceis[8].pontuacao = pontuacao;
	//Pergunta 10
	strcpy(faceis[9].pergunta,"Por que o nome 'Guerra Fria'?");
	strcpy(faceis[9].alternativa_A,"Porque foi um momento de tensão, entretanto sem combates");
	strcpy(faceis[9].alternativa_B,"Porque onde eles se confrontavam era muito gelado");
	strcpy(faceis[9].alternativa_C,"Porque, geralmente, os combatentes morriam de frio");
	strcpy(faceis[9].alternativa_D,"Porque aconteceu na Rússia onde é frio");
	faceis[9].pontuacao = pontuacao;
	//Pergunta 11
	strcpy(faceis[10].pergunta,"O que foi a Corrida Armamentista?");
	strcpy(faceis[10].alternativa_A,"Desenvolvimento de armas entre as duas potências (URSS e EUA)");
	strcpy(faceis[10].alternativa_B,"Corrida feita pelos norte-americanos do México até o norte do Canadá com armas");
	strcpy(faceis[10].alternativa_C,"Foi a principal guerra entre os paises");
	strcpy(faceis[10].alternativa_D,"Explosão de bombas nucleares");
	faceis[10].pontuacao = pontuacao;
	//Pergunta 12
	strcpy(faceis[11].pergunta,"Na guerra fria quem estava no lado socialista?");
	strcpy(faceis[11].alternativa_A,"União Soviética, China e Cuba");
	strcpy(faceis[11].alternativa_B,"União Soviética, China e Brasil");
	strcpy(faceis[11].alternativa_C,"Brasil, Paraguai e Argentina");
	strcpy(faceis[11].alternativa_D,"União Soviética, China e EUA");
	faceis[11].pontuacao = pontuacao;
	//Pergunta 13
	strcpy(faceis[12].pergunta,"Na guerra fria quem estava no lado capitalista?");
	strcpy(faceis[12].alternativa_A,"EUA, América Latina e Japão");
	strcpy(faceis[12].alternativa_B,"França, Coreia do Norte e Inglaterra");
	strcpy(faceis[12].alternativa_C,"América Latina, URSS e Coreia do Sul");
	strcpy(faceis[12].alternativa_D,"EUA, Brasil e Cuba");
	faceis[12].pontuacao = pontuacao;
	//Pergunta 14
	strcpy(faceis[13].pergunta,"O nazismo é uma ideologia anticomunista que além de odiarem os negros e os judeus, também odiava:");
	strcpy(faceis[13].alternativa_A,"Os homossexuais e estrangeiros");
	strcpy(faceis[13].alternativa_B,"Os fascistas e os estrangeiros");
	strcpy(faceis[13].alternativa_C,"A raça ariana e as mulheres");
	strcpy(faceis[13].alternativa_D,"Os homossexuais e os soviéticos");
	faceis[13].pontuacao = pontuacao;
	//Pergunta 15
	strcpy(faceis[14].pergunta,"A perseguição e eliminação dos judeus nos campos de concentração ficou conhecido como:");
	strcpy(faceis[14].alternativa_A,"O holocausto");
	strcpy(faceis[14].alternativa_B,"A eliminação");
	strcpy(faceis[14].alternativa_C,"O extermínio");
	strcpy(faceis[14].alternativa_D,"A purificação");
	faceis[14].pontuacao = pontuacao;
	//Pergunta 16
	strcpy(faceis[15].pergunta,"Na mitologia grega quem abaixo não era considerado um deus?");
	strcpy(faceis[15].alternativa_A,"Medusa");
	strcpy(faceis[15].alternativa_B,"Cronos");
	strcpy(faceis[15].alternativa_C,"Gaia");
	strcpy(faceis[15].alternativa_D,"Eros");
	faceis[15].pontuacao = pontuacao;
	//Pergunta 17
	strcpy(faceis[16].pergunta,"Segundo a mitologia grega quem governa o mundo dos mortos?");
	strcpy(faceis[16].alternativa_A,"Hades");
	strcpy(faceis[16].alternativa_B,"Cronos");
	strcpy(faceis[16].alternativa_C,"Gaia");
	strcpy(faceis[16].alternativa_D,"Eros");
	faceis[16].pontuacao = pontuacao;
	//Pergunta 18
	strcpy(faceis[17].pergunta,"Em que país foi aplicado o nazismo?");
	strcpy(faceis[17].alternativa_A,"Alemanha");
	strcpy(faceis[17].alternativa_B,"França");
	strcpy(faceis[17].alternativa_C,"Inglaterra");
	strcpy(faceis[17].alternativa_D,"Áustria");
	faceis[17].pontuacao = pontuacao;
	//Pergunta 19
	strcpy(faceis[18].pergunta,"Quem liderou o nazismo?");
	strcpy(faceis[18].alternativa_A,"Adolf Hitler");
	strcpy(faceis[18].alternativa_B,"Czar Nicolau II");
	strcpy(faceis[18].alternativa_C,"Getúlio Vargas");
	strcpy(faceis[18].alternativa_D,"Emílio Garrastazu Médici");
	faceis[18].pontuacao = pontuacao;
	//Pergunta 20
	strcpy(faceis[19].pergunta,"Complete: A história do Brasil compreende, tradicionalmente, a chegada dos ___.");
	strcpy(faceis[19].alternativa_A,"Portugueses");
	strcpy(faceis[19].alternativa_B,"Chineses");
	strcpy(faceis[19].alternativa_C,"Espanhóis");
	strcpy(faceis[19].alternativa_D,"Alemães");
	faceis[19].pontuacao = pontuacao;
	//...
	//Pergunta 20
	
	
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
	strcpy(medias[0].pergunta,"Um dos Pais Fundadores dos Estados Unidos, ele foi o autor da Declaração de Independência e o terceiro presidente da nação");
	strcpy(medias[0].alternativa_A,"Thomas Jefferson");
	strcpy(medias[0].alternativa_B,"John Adams ");
	strcpy(medias[0].alternativa_C,"James Madison");
	strcpy(medias[0].alternativa_D,"George Washington");
	medias[0].pontuacao = pontuacao;
	//Pergunta 2
	strcpy(medias[1].pergunta,"Físico, matemático e astrônomo que, no contexto da revolução científica da Renascença, defendeu a teoria do Heliocentrismo, elaborada antes por Nicolau Copérnico. Também descobriu as fases de Vênus e as quatro maiores luas de Júpiter");
	strcpy(medias[1].alternativa_A,"Galileu Galilei");
	strcpy(medias[1].alternativa_B,"Tycho Brahe");
	strcpy(medias[1].alternativa_C,"Isaac Newton");
	strcpy(medias[1].alternativa_D,"Johannes Kepler");
	medias[1].pontuacao = pontuacao;
	//Pergunta 3
	strcpy(medias[2].pergunta,"Considerado um dos presidentes mais autoritários da ditadura brasileira, ele acionou o Ato Institucional Cinco, reprimindo opositores com medidas violentas");
	strcpy(medias[2].alternativa_A,"Costa e Silva");
	strcpy(medias[2].alternativa_B,"Castelo Branco");
	strcpy(medias[2].alternativa_C,"Figueiredo");
	strcpy(medias[2].alternativa_D,"Geisel");
	medias[2].pontuacao = pontuacao;
	//Pergunta 4
	strcpy(medias[3].pergunta,"Qual era o Deus que os egípcios acreditavam que era responsável por conduzir os seres humanos após a morte ?");
	strcpy(medias[3].alternativa_A,"Anúbis");
	strcpy(medias[3].alternativa_B,"Ísis");
	strcpy(medias[3].alternativa_C,"Rá");
	strcpy(medias[3].alternativa_D,"Amon");
	medias[3].pontuacao = pontuacao;
	//Pergunta 5
	strcpy(medias[4].pergunta,"Nome da escrita utilizada pelos egípcios para registra textos:");
	strcpy(medias[4].alternativa_A,"Hieróglifos");
	strcpy(medias[4].alternativa_B,"Desenhos");
	strcpy(medias[4].alternativa_C,"Amurabis");
	strcpy(medias[4].alternativa_D,"Letras");
	medias[4].pontuacao = pontuacao;
	//Pergunta 6
	strcpy(medias[5].pergunta,"Complete: As ___ foram as primeiras câmaras mortuárias do Egito");
	strcpy(medias[5].alternativa_A,"Mastabas");
	strcpy(medias[5].alternativa_B,"Pirâmides");
	strcpy(medias[5].alternativa_C,"Sarcófagos");
	strcpy(medias[5].alternativa_D,"Mosteiros");
	medias[5].pontuacao = pontuacao;
	//Pergunta 7
	strcpy(medias[6].pergunta,"Dentre as alternativas a seguir, qual representa a mesma guerra?");
	strcpy(medias[6].alternativa_A,"Guerra da Secessão/Guerra Civil Americana.");
	strcpy(medias[6].alternativa_B,"Guerra dos Cem Anos/Guerra Armada Neo-Ucraniana");
	strcpy(medias[6].alternativa_C,"Segunda Guerra Mundial/Guerra Ítalo-Germânica");
	strcpy(medias[6].alternativa_D,"Guerra de Canudos/Combate Independente Mineiro");
	medias[6].pontuacao = pontuacao;
	//Pergunta 8
	strcpy(medias[7].pergunta,"Indique a alternativa correta:");
	strcpy(medias[7].alternativa_A,"A batalha dos Trezentos e Trinta e Cinco anos foi a maior batalha da história, contudo, não ouve um disparo de qualquer tipo de armas.");
	strcpy(medias[7].alternativa_B,"A batalha dos Cem Anos foi a maior batalha da história, e também a mais sangrenta. Registram-se 90 milhões de mortos");
	strcpy(medias[7].alternativa_C,"A Primeira Guerra Mundial já tinha Hitler como um dos maiores comandantes, não chegando a ser presidente (ainda).");
	strcpy(medias[7].alternativa_D,"A Guerra de Troia foi definitivamente a maior guerra da história, durando aproximadamente quatrocentos anos, e matando 38 milhões de pessoas.");
	medias[7].pontuacao = pontuacao;
	//Pergunta 9
	strcpy(medias[8].pergunta,"Quem construi o farol de alexandria?");
	strcpy(medias[8].alternativa_A,"Ptolomeu");
	strcpy(medias[8].alternativa_B,"Alexandre, o grande");
	strcpy(medias[8].alternativa_C,"Júlio Cesar");
	strcpy(medias[8].alternativa_D,"Davi");
	medias[8].pontuacao = pontuacao;
	//Pergunta 10
	strcpy(medias[9].pergunta,"Com que objetivo foram construídos os jardins suspensos?");
	strcpy(medias[9].alternativa_A,"Para homenagear a mulher de Nabucodonosor II");
	strcpy(medias[9].alternativa_B,"Para homenagear o rei");
	strcpy(medias[9].alternativa_C,"Para proclamar o poder do rei");
	strcpy(medias[9].alternativa_D,"Para lucrar com turistas ");
	medias[9].pontuacao = pontuacao;
	//Pergunta 11
	strcpy(medias[10].pergunta,"Que frase representa melhor a lei de Talião?");
	strcpy(medias[10].alternativa_A,"Olho por olho, dente por dente");
	strcpy(medias[10].alternativa_B,"Escreveu não leu, pau comeu");
	strcpy(medias[10].alternativa_C,"A tua inveja é a prova do meu sucesso");
	strcpy(medias[10].alternativa_D,"Urubu come milho, piriquito leva a culpa");
	medias[10].pontuacao = pontuacao;
	//Pergunta 12
	strcpy(medias[11].pergunta,"Qual é a única instituição do Império Romano que continua existindo até hoje?");
	strcpy(medias[11].alternativa_A,"A Igreja Católica");
	strcpy(medias[11].alternativa_B,"O Calcio");
	strcpy(medias[11].alternativa_C,"A corrida de bigas");
	strcpy(medias[11].alternativa_D,"O Coliseu");
	medias[11].pontuacao = pontuacao;
	//Pergunta 13
	strcpy(medias[12].pergunta,"Que cidade da América foi a capital de um império colonial?");
	strcpy(medias[12].alternativa_A,"Rio de Janeiro");
	strcpy(medias[12].alternativa_B,"Buenos Aires");
	strcpy(medias[12].alternativa_C,"Salvador");
	strcpy(medias[12].alternativa_D,"Cartagena");
	medias[12].pontuacao = pontuacao;
	//Pergunta 14
	strcpy(medias[13].pergunta,"Quem é conhecido por ter formulado as três leis fundamentais da mecânica celeste, conhecidas como Leis de '(seu sobrenome)'? Viveu (1571-1630)");
	strcpy(medias[13].alternativa_A,"Johannes Kepler");
	strcpy(medias[13].alternativa_B,"Tycho Brahe");
	strcpy(medias[13].alternativa_C,"Galileu Galilei");
	strcpy(medias[13].alternativa_D,"John Napier");
	medias[13].pontuacao = pontuacao;
	//Pergunta 15
	strcpy(medias[14].pergunta,"'A mudança de movimento é proporcional à força motora imprimida, e é produzida na direção de linha reta na qual aquela força é imprimida'. Qual das ' Três Leis de Newton' é essa?");
	strcpy(medias[14].alternativa_A,"Segunda - Princípio Fundamental da Dinâmica");
	strcpy(medias[14].alternativa_B,"Terceira - Motorização Vaporizada");
	strcpy(medias[14].alternativa_C,"Segunda - Ação e Reação");
	strcpy(medias[14].alternativa_D,"Terceira - Princípio Fundamental da Dinâmica");
	medias[14].pontuacao = pontuacao;
	//Pergunta 16
	strcpy(medias[15].pergunta,"Para qual Filosofo Grego o átomo era o menor componente de toda a matéria existente. Sendo, então, impossível dividi-lo em partes menores? Viveu (VII-VI a.C)");
	strcpy(medias[15].alternativa_A,"Demócrito");
	strcpy(medias[15].alternativa_B,"Pitágoras");
	strcpy(medias[15].alternativa_C,"Platão");
	strcpy(medias[15].alternativa_D,"Socrátes");
	medias[15].pontuacao = pontuacao;
	//Pergunta 17
	strcpy(medias[16].pergunta,"Qual é 'A Equação mais famosa do mundo'?");
	strcpy(medias[16].alternativa_A,"E=mc²");
	strcpy(medias[16].alternativa_B,"E=mc³");
	strcpy(medias[16].alternativa_C,"E=em²");
	strcpy(medias[16].alternativa_D,"E=mc");
	medias[16].pontuacao = pontuacao;
	//Pergunta 18
	strcpy(medias[17].pergunta,"Segundo a 'Royal Society', quem é o 'MAIOR CIENTISTA DE TODOS OS TEMPOS'?");
	strcpy(medias[17].alternativa_A,"Sir Isaac Newton");
	strcpy(medias[17].alternativa_B,"Galileu Galilei");
	strcpy(medias[17].alternativa_C,"Albert Einstein");
	strcpy(medias[17].alternativa_D,"Sir Francis Bacon");
	medias[17].pontuacao = pontuacao;
	//Pergunta 19
	strcpy(medias[18].pergunta,"Quem foi o primeiro a demonstrar que os movimentos de objetos, tanto na Terra como em outros corpos celestes, são governados pelo mesmo conjunto de leis naturais? Viveu (1643-1727)");
	strcpy(medias[18].alternativa_A,"Sir Isaac Newton");
	strcpy(medias[18].alternativa_B,"Albert Einstein");
	strcpy(medias[18].alternativa_C,"Sir Francis Bacon");
	strcpy(medias[18].alternativa_D,"Sir Charlies Darwin");
	medias[18].pontuacao = pontuacao;
	//Pergunta 20
	strcpy(medias[19].pergunta,"O que significa Filosofia?");
	strcpy(medias[19].alternativa_A,"Amor à sabedoria");
	strcpy(medias[19].alternativa_B,"Amor à liberdade");
	strcpy(medias[19].alternativa_C,"Amor ao amigo");
	strcpy(medias[19].alternativa_D,"Amor à paz");
	medias[19].pontuacao = pontuacao;
	//...
	//Pergunta 20
	
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
	strcpy(dificeis[0].pergunta,"Qual o nome do projeto que trabalhou no mapeamento do DNA humano, em 2001?");
	strcpy(dificeis[0].alternativa_A,"Projeto Genoma Humano");
	strcpy(dificeis[0].alternativa_B,"Projeto XX e XY");
	strcpy(dificeis[0].alternativa_C,"Projeto Vida");
	strcpy(dificeis[0].alternativa_D,"Projeto DNA");
	dificeis[0].pontuacao = pontuacao;
	//Pergunta 2
	strcpy(dificeis[1].pergunta,"Quem é conhecido como o 'Pai da Microbiologia'?");
	strcpy(dificeis[1].alternativa_A,"Louis Pasteur");
	strcpy(dificeis[1].alternativa_B,"Gregor Mendel");
	strcpy(dificeis[1].alternativa_C,"Robert Boyle");
	strcpy(dificeis[1].alternativa_D,"Antoine Lavoisier");
	dificeis[1].pontuacao = pontuacao;
	//Pergunta 3
	strcpy(dificeis[2].pergunta,"Quem é conhecido como 'Pai da Genética'? Viveu (1822-1884)");
	strcpy(dificeis[2].alternativa_A,"Gregor Mendel");
	strcpy(dificeis[2].alternativa_B,"Francis Collins");
	strcpy(dificeis[2].alternativa_C,"Sir Charles Darwin");
	strcpy(dificeis[2].alternativa_D,"Antoine Lavoisier");
	dificeis[2].pontuacao = pontuacao;
	//Pergunta 4
	strcpy(dificeis[3].pergunta,"Quem foi o Ilustre Diretor desse Projeto (questao 37) que marcou o inicio do Século XXI?");
	strcpy(dificeis[3].alternativa_A,"Francis Collins");
	strcpy(dificeis[3].alternativa_B,"Alan Sabagge");
	strcpy(dificeis[3].alternativa_C,"John Lennox");
	strcpy(dificeis[3].alternativa_D,"Stephen Hawking");
	dificeis[3].pontuacao = pontuacao;
	//Pergunta 5
	strcpy(dificeis[4].pergunta,"Quem criou a Teoria 'Hipótese do Átomo Primordial'?");
	strcpy(dificeis[4].alternativa_A,"George Lemaître");
	strcpy(dificeis[4].alternativa_B,"Albert Einstein");
	strcpy(dificeis[4].alternativa_C,"Sir Isaac Newton");
	strcpy(dificeis[4].alternativa_D,"Stephen Hawking");
	dificeis[4].pontuacao = pontuacao;
	//Pergunta 6
	strcpy(dificeis[5].pergunta,"Quem descobriu a lei da radiação térmica? E como ela é chamada?");
	strcpy(dificeis[5].alternativa_A,"Max Planck - Lei de Planck da Radiação");
	strcpy(dificeis[5].alternativa_B,"Max Planck - Lei de Max");
	strcpy(dificeis[5].alternativa_C,"Albert Einstein - Lei de Einstein");
	strcpy(dificeis[5].alternativa_D,"Albert Einstein - Lei Einsteniana");
	dificeis[5].pontuacao = pontuacao;
	//Pergunta 7
	strcpy(dificeis[6].pergunta,"Quem foi o químico e microbiologista que descobriu os princípios da vacinação, a fermentação microbiana e pasteurização? Viveu (1822-1895)");
	strcpy(dificeis[6].alternativa_A,"Louis Pasteur");
	strcpy(dificeis[6].alternativa_B,"George Jackson Mivart");
	strcpy(dificeis[6].alternativa_C,"John William Dawson");
	strcpy(dificeis[6].alternativa_D,"John Dalton");
	dificeis[6].pontuacao = pontuacao;
	//Pergunta 8
	strcpy(dificeis[7].pergunta,"Qual o nome da lei física que expressa a relação entre o calor gerado e a corrente elétrica que percorre um condutor em determinado tempo?");
	strcpy(dificeis[7].alternativa_A,"Lei de Joule");
	strcpy(dificeis[7].alternativa_B,"Lei de Newton");
	strcpy(dificeis[7].alternativa_C,"Lei de Atenas");
	strcpy(dificeis[7].alternativa_D,"Lei de Maxwell");
	dificeis[7].pontuacao = pontuacao;
	//Pergunta 9
	strcpy(dificeis[8].pergunta,"De quem é a frase 'Se é para o bem de todos e felicidade geral da Nação, estou pronto! Diga ao povo que fico!'?");
	strcpy(dificeis[8].alternativa_A,"Dom Pedro I");
	strcpy(dificeis[8].alternativa_B,"Dom Pedro II");
	strcpy(dificeis[8].alternativa_C,"Presidente Fernando Henrique Cardoso");
	strcpy(dificeis[8].alternativa_D,"Dilma");
	dificeis[8].pontuacao = pontuacao;
	//Pergunta 10
	strcpy(dificeis[9].pergunta,"Qual elemento está relacionado à dimensão racional?");
	strcpy(dificeis[9].alternativa_A,"Ar");
	strcpy(dificeis[9].alternativa_B,"Éter");
	strcpy(dificeis[9].alternativa_C,"Fogo");
	strcpy(dificeis[9].alternativa_D,"Terra");
	dificeis[9].pontuacao = pontuacao;
	//Pergunta 11
	strcpy(dificeis[10].pergunta,"Por que Vênus é o planeta regente de touro?");
	strcpy(dificeis[10].alternativa_A,"Porque Vênus liga a todos os prazeres e Touro é o signo fixo sensorial.");
	strcpy(dificeis[10].alternativa_B,"Porque Vênus liga aos desejos e Touro é o signo fixo de terra.");
	strcpy(dificeis[10].alternativa_C,"Porque Vênus liga aos raciocínios lógicos e Touro é o signo fixo de terra.");
	strcpy(dificeis[10].alternativa_D,"Porque Vênus liga ao inconsciente e Touro é o signo regente da nona casa.");
	dificeis[10].pontuacao = pontuacao;
	//Pergunta 12
	strcpy(dificeis[11].pergunta,"Algumas pessoas tem medo da escuridão. Qual é a fobia que elas têm?");
	strcpy(dificeis[11].alternativa_A,"Acluofobia");
	strcpy(dificeis[11].alternativa_B,"Agrafobia");
	strcpy(dificeis[11].alternativa_C,"Aletrorofobia");
	strcpy(dificeis[11].alternativa_D,"Apifobia");
	dificeis[11].pontuacao = pontuacao;
	//Pergunta 13
	strcpy(dificeis[12].pergunta,"O que é Coprofobia?");
	strcpy(dificeis[12].alternativa_A,"Medo de fezes");
	strcpy(dificeis[12].alternativa_B,"Medo de câmaras");
	strcpy(dificeis[12].alternativa_C,"Medo de ver uma pessoa sem uma parte do corpo");
	strcpy(dificeis[12].alternativa_D,"Medo de copos");
	dificeis[12].pontuacao = pontuacao;
	//Pergunta 14
	strcpy(dificeis[13].pergunta,"No Brasil, qual acidente aéreo, infelizmente, tirou a vida de mais pessoas?");
	strcpy(dificeis[13].alternativa_A,"17 de julho de 2007, São Paulo - Airbus A-320 da TAM que não conseguiu parar ao aterrissar no Aeroporto de Congonhas");
	strcpy(dificeis[13].alternativa_B,"29 de setembro de 2006, Mato Grosso - Boeing da Gol colide com um jato Legacy");
	strcpy(dificeis[13].alternativa_C,"outubro de 1996, São Paulo - Fokker-100 da TAM cai sobre o bairro do Jabaquara, Zona Sul de São Paulo");
	strcpy(dificeis[13].alternativa_D,"abril de 1980, Florianópolis - Boeing 727 da Transbrasil");
	dificeis[13].pontuacao = pontuacao;
	//Pergunta 15
	strcpy(dificeis[14].pergunta,"Qual foi a maior tragédia em estádios de futebol, matando mais pessoas que assistiam a uma simples partida?");
	strcpy(dificeis[14].alternativa_A,"PERU X ARGENTINA - Local:Lima (Peru) - Competição: Torneio Pré-Olímpico - Ano: 1964");
	strcpy(dificeis[14].alternativa_B,"HEARTS OF OAK x KUMASI ASHANTI KOTOKO - Local:Accra (Gana) - Competição:Campeonato Ganês - Ano: 2001");
	strcpy(dificeis[14].alternativa_C,"NOTTINGHAM FOREST x LIVERPOOL - Local:Sheffield (Inglaterra) - Competição:Copa da Inglaterra - Ano: 1989");
	strcpy(dificeis[14].alternativa_D,"MUKTIJODHA x JANAKPUR - Local:Katmandu (Nepal) - Competição:Amistoso - Ano: 1988");
	dificeis[14].pontuacao = pontuacao;
	//Pergunta 16
	strcpy(dificeis[15].pergunta,"Qual desses seres é responsável por mais mortes no mundo?");
	strcpy(dificeis[15].alternativa_A,"Mosquito");
	strcpy(dificeis[15].alternativa_B,"Leão");
	strcpy(dificeis[15].alternativa_C,"Elefante");
	strcpy(dificeis[15].alternativa_D,"Leopardo");
	dificeis[15].pontuacao = pontuacao;
	//Pergunta 17
	strcpy(dificeis[16].pergunta,"Em 1 de fevereiro de 2003 - Ônibus espacial carregando sete astronautas, incluindo o primeiro de Israel, desintegra-se sobre o Texas ao entrar na atmosfera, após missão de 16 dias. Qual o nome desse ônibus espacial?");
	strcpy(dificeis[16].alternativa_A,"Columbia");
	strcpy(dificeis[16].alternativa_B,"Endeavour");
	strcpy(dificeis[16].alternativa_C,"Discovery");
	strcpy(dificeis[16].alternativa_D,"Challenger");
	dificeis[16].pontuacao = pontuacao;
	//Pergunta 18
	strcpy(dificeis[17].pergunta,"Qual foi a maior tragédia ocorrida em um Metrô?");
	strcpy(dificeis[17].alternativa_A,"Baku, capital do Azerbaijão (ex-União Soviética) em consequência de um incêndio");
	strcpy(dificeis[17].alternativa_B,"Intoxicação por fumaça numa plataforma do metropolitain de Paris, em 1903");
	strcpy(dificeis[17].alternativa_C,"Colapso na obra da estação de Pinheiros, em São Paulo");
	strcpy(dificeis[17].alternativa_D,"Atentado ocorrido em Daegu, terceira maior cidade da Coréia do Sul");
	dificeis[17].pontuacao = pontuacao;
	//Pergunta 19
	strcpy(dificeis[18].pergunta,"O Golfo de Bótnia, no norte da Europa, está localizado entre dois países escandinavos. Quais são eles?");
	strcpy(dificeis[18].alternativa_A,"Finlândia e Suécia");
	strcpy(dificeis[18].alternativa_B,"Noruega e Suécia");
	strcpy(dificeis[18].alternativa_C,"Dinamarca e Islândia");
	strcpy(dificeis[18].alternativa_D,"Finlândia e Rússia");
	dificeis[18].pontuacao = pontuacao;
	//Pergunta 20
	strcpy(dificeis[19].pergunta,"Politicamente falando, a Groenlândia é:");
	strcpy(dificeis[19].alternativa_A,"Pertencente à Dinamarca");
	strcpy(dificeis[19].alternativa_B,"Território da ONU");
	strcpy(dificeis[19].alternativa_C,"Pertencente à Islândia");
	strcpy(dificeis[19].alternativa_D,"FUma República Independente");
	dificeis[19].pontuacao = pontuacao;
	//...
	//Pergunta 20
	
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
	strcpy(muito_dificeis[0].pergunta,"Assinale a alternativa que não apresenta um tipo de citoesqueleto.");
	strcpy(muito_dificeis[0].alternativa_A,"Microvilosidades");
	strcpy(muito_dificeis[0].alternativa_B,"Microtúbulos");
	strcpy(muito_dificeis[0].alternativa_C,"Filamentos Intermediário");
	strcpy(muito_dificeis[0].alternativa_D,"Nenhuma das alternativas");
	muito_dificeis[0].pontuacao = pontuacao;
	//Pergunta 2
	strcpy(muito_dificeis[1].pergunta,"Qual é o resultado do fenótipo de uma flor branca cruzada com uma vermelha?");
	strcpy(muito_dificeis[1].alternativa_A,"100% Rosa");
	strcpy(muito_dificeis[1].alternativa_B,"50% Vermelha");
	strcpy(muito_dificeis[1].alternativa_C,"75% Branca");
	strcpy(muito_dificeis[1].alternativa_D,"25% Avermelhada");
	muito_dificeis[1].pontuacao = pontuacao;
	//Pergunta 3
	strcpy(muito_dificeis[2].pergunta,"Qual é o nome científico do Zorrilho?");
	strcpy(muito_dificeis[2].alternativa_A,"Conepatus chinga");
	strcpy(muito_dificeis[2].alternativa_B,"Equus burchelli");
	strcpy(muito_dificeis[2].alternativa_C,"Cacicus cela");
	strcpy(muito_dificeis[2].alternativa_D,"Mazama americana");
	muito_dificeis[2].pontuacao = pontuacao;
	//Pergunta 4
	strcpy(muito_dificeis[3].pergunta,"Qual é o nome Científico do Calango?");
	strcpy(muito_dificeis[3].alternativa_A,"Ameiva ameiva");
	strcpy(muito_dificeis[3].alternativa_B,"Ovis aries");
	strcpy(muito_dificeis[3].alternativa_C,"Crotalus durissus");
	strcpy(muito_dificeis[3].alternativa_D,"Cavia porcellus");
	muito_dificeis[3].pontuacao = pontuacao;
	//Pergunta 5
	strcpy(muito_dificeis[4].pergunta,"Em que século o barroco passa a se expandir para os centros de produção açucareira na Bahia?");
	strcpy(muito_dificeis[4].alternativa_A,"XVII");
	strcpy(muito_dificeis[4].alternativa_B,"XVIII");
	strcpy(muito_dificeis[4].alternativa_C,"XX");
	strcpy(muito_dificeis[4].alternativa_D,"XV");
	muito_dificeis[4].pontuacao = pontuacao;
	//Pergunta 6
	strcpy(muito_dificeis[5].pergunta,"Marque a alternativa que contém um metal alcalino e dois elementos de transição externa:");
	strcpy(muito_dificeis[5].alternativa_A,"Rb-Rubídio, Y, Pt");
	strcpy(muito_dificeis[5].alternativa_B,"K-Potássio, Au, Br");
	strcpy(muito_dificeis[5].alternativa_C,"Po-Platina, Ds, Te");
	strcpy(muito_dificeis[5].alternativa_D,"B-Boro, Sb, Te");
	muito_dificeis[5].pontuacao = pontuacao;
	//Pergunta 7
	strcpy(muito_dificeis[6].pergunta,"Assinale a alternativa que apresente o nome de um elemento químico cujo número atômico é 35:");
	strcpy(muito_dificeis[6].alternativa_A,"Bromo");
	strcpy(muito_dificeis[6].alternativa_B,"Cobre");
	strcpy(muito_dificeis[6].alternativa_C,"Zinco");
	strcpy(muito_dificeis[6].alternativa_D,"Selênio");
	muito_dificeis[6].pontuacao = pontuacao;
	//Pergunta 8
	strcpy(muito_dificeis[7].pergunta,"O número atômico do ouro é:");
	strcpy(muito_dificeis[7].alternativa_A,"79");
	strcpy(muito_dificeis[7].alternativa_B,"59");
	strcpy(muito_dificeis[7].alternativa_C,"49 ");
	strcpy(muito_dificeis[7].alternativa_D,"60");
	muito_dificeis[7].pontuacao = pontuacao;
	//Pergunta 9
	strcpy(muito_dificeis[8].pergunta,"Qual o nome do sal formado pela reação de neutralização do ácido clórico pelo hidróxido de alumínio?");
	strcpy(muito_dificeis[8].alternativa_A,"Clorato de alumínio");
	strcpy(muito_dificeis[8].alternativa_B,"Cloreto de alumínio");
	strcpy(muito_dificeis[8].alternativa_C,"Clórico de alumínio");
	strcpy(muito_dificeis[8].alternativa_D,"Clorito de alumínio");
	muito_dificeis[8].pontuacao = pontuacao;
	//Pergunta 10
	strcpy(muito_dificeis[9].pergunta,"Quando o sulfito de sódio reage com ácido clorídrico obtém-se respectivamente:");
	strcpy(muito_dificeis[9].alternativa_A,"Sal de cozinha, água e dióxido de enxofre.");
	strcpy(muito_dificeis[9].alternativa_B,"Sal marinho, água e dióxido de enxofre.");
	strcpy(muito_dificeis[9].alternativa_C,"Sal marinho, água e dióxido de cloro.");
	strcpy(muito_dificeis[9].alternativa_D,"Sal de cozinha, água e dióxido de cloro.");
	muito_dificeis[9].pontuacao = pontuacao;
	//Pergunta 11
	strcpy(muito_dificeis[10].pergunta,"O sangue do diabo é um líquido vermelho que logo se descora ao ser aspergido sobre um tecido branco. Para prepará-lo, adiciona-se NH4OH em água, contendo algumas gotas de fenolftaleína. A cor desaparece porque:");
	strcpy(muito_dificeis[10].alternativa_A,"O NH3 logo evapora.");
	strcpy(muito_dificeis[10].alternativa_B,"A solução é assim denominada devida à sua alta viscosidade.");
	strcpy(muito_dificeis[10].alternativa_C,"A fenolftaleína reage rapidamente com o NH4OH.");
	strcpy(muito_dificeis[10].alternativa_D,"A fenolftaleína evapora.");
	muito_dificeis[10].pontuacao = pontuacao;
	//Pergunta 12
	strcpy(muito_dificeis[11].pergunta,"Qual o único exemplo que não é classificado como uma nuvem eletrônica?");
	strcpy(muito_dificeis[11].alternativa_A,"Ligação covalente tetraétrica");
	strcpy(muito_dificeis[11].alternativa_B,"Ligação covalente dativa");
	strcpy(muito_dificeis[11].alternativa_C,"Ligação covalente dupla");
	strcpy(muito_dificeis[11].alternativa_D,"Par de elétron não ligante");
	muito_dificeis[11].pontuacao = pontuacao;
	//Pergunta 13
	strcpy(muito_dificeis[12].pergunta,"Assinale a única alternativa que não contém o exemplo correto de geometria molecular em moléculas polares.");
	strcpy(muito_dificeis[12].alternativa_A,"Trigonal plana");
	strcpy(muito_dificeis[12].alternativa_B,"Tetraédica");
	strcpy(muito_dificeis[12].alternativa_C,"Angular");
	strcpy(muito_dificeis[12].alternativa_D,"Piramidal");
	muito_dificeis[12].pontuacao = pontuacao;
	//Pergunta 14
	strcpy(muito_dificeis[13].pergunta,"O leite é uma(o) :");
	strcpy(muito_dificeis[13].alternativa_A,"Mistura heterogênea");
	strcpy(muito_dificeis[13].alternativa_B,"Ácido");
	strcpy(muito_dificeis[13].alternativa_C,"Mistura homogênea");
	strcpy(muito_dificeis[13].alternativa_D,"Substância simples");
	muito_dificeis[13].pontuacao = pontuacao;
	//Pergunta 15
	strcpy(muito_dificeis[14].pergunta,"Segundo a teoria atômica de Dalton, é correto afirmar:");
	strcpy(muito_dificeis[14].alternativa_A,"A combinação de átomos de elementos diferentes, numa proporção de números inteiros, origina substâncias diferentes");
	strcpy(muito_dificeis[14].alternativa_B,"Os átomos não são criads nem destruídos; são simplesmente rearranjados, formando as mesmas substâncias");
	strcpy(muito_dificeis[14].alternativa_C,"Elementos químicos iguais apresentam átomos com massa, tamanho e propriedades diferentes");
	strcpy(muito_dificeis[14].alternativa_D,"A matéria é constituida de partículas esféricas maciças e divisíveis chamado de elemento químico");
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
