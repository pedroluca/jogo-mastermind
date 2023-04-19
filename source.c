//Desenvolvedores: Lucas Cãndido e Pedro Luca Prates
//Turma: 1ADS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#define alt 100
#define lar 16
#define pin 8

int repetirCaracter = 0, modoJogadores = 1, quantCores = 8, quantPinos = 6, quantTentativas = 14, tentativaAtual, vitoria = 0, pinosB = 0, pinosP = 0, placar[2], quantPartidas, jogadorDaVez = 0, proxJogador = 1, partidaIniciada = 0, partidaAtual = 1, aux, auxPinos, larguraLinha[3] = {29, 37, 42}, larguraLinhaMenor[3] = {22, 27, 32}, larguraLinhaSenha[3] = {8, 11, 11};
char tabuleiro[alt][lar], senha[pin], nomeJogador[2][50], caracteresValidos[8] = {'V', 'M', 'A', 'L', 'R', 'C', 'B', 'P'};

char imprimirTabuleiro();
int menu();
int limparTabuleiro();
int verificaSequencia();
int multiplayer();
void creditos();
void iniciarJogo();
void instrucoes();
void configuracoes();
void finalizarJogo();

int main() {
  setlocale(LC_ALL, "");
  system("cls || clear");
  printf("<<== = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = ==>>\n");
  printf("  ||                                                                                         ||\n");
  printf("  || |----\\    /----|  |----------|  |----------|  |----------|  |----------|  |----------|  ||\n");
  printf("  || |     \\  /     |  |    __    |  |   _______|  |___    ___|  |    ______|  |    __    |  ||\n");
  printf("  || |  |\\  \\/  /|  |  |   |__|   |  |   |_______      |  |      |   |______   |   |__|   |  ||\n");
  printf("  || |  | \\    / |  |  |          |  |_______   |      |  |      |          |  |   __   __|  ||\n");
  printf("  || |  |  \\  /  |  |  |  |____|  |         |   |      |  |      |   |------   |   | \\  \\    ||\n");
  printf("  || |  |   \\/   |  |  |  |    |  |  |-------   |      |  |      |   |------|  |   |  \\  \\   ||\n");
  printf("  || |__|        |__|  |__|    |__|  |__________|      |__|      |__________|  |___|   \\__|  ||\n");
  printf("  ||                                                                                         ||\n");
  printf("  ||                  |----\\    /----|  |---|  |-----\\   |---|  |-------\\                    ||\n");
  printf("  ||                  |     \\  /     |  |   |  |      \\  |   |  |    __  \\                   ||\n");
  printf("  ||                  |  |\\  \\/  /|  |  |   |  |   |\\  \\ |   |  |   |  \\  \\                  ||\n");
  printf("  ||                  |  | \\    / |  |  |   |  |   | \\  \\|   |  |   |  /   |                 ||\n");
  printf("  ||                  |  |  \\  /  |  |  |   |  |   |  \\      |  |   |_/   /                  ||\n");
  printf("  ||                  |  |   \\/   |  |  |   |  |   |   \\     |  |        /                   ||\n");
  printf("  ||                  |__|        |__|  |___|  |___|    \\____|  |_______/                    ||\n");
  printf("  ||                                                                                  v5.1.4 ||\n");
  printf("<<== = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = ==>>\n");
  printf("Enter para iniciar\n");
  system("pause || read -p '' var");
  menu();
}

int menu() {
  int option;
  system("cls || clear");
  printf("<<== = = =& M E N U &= = = ==>>\n");
  printf("  || 1- Iniciar jogo       ||\n");
  printf("  || 2- Instruções         ||\n");
  printf("  || 3- Configurações      ||\n");
  printf("  || 4- Créditos           ||\n");
  printf("  || 5- Fechar jogo        ||\n");
  printf("<<== = = = = = = = = = = = ==>>\n");
  printf("Escolha uma opção: ");
  scanf("%d", &option);
  while (option > 5 || option < 0) {
    printf("\nInforme uma opção válida!\nOpção: ");
    scanf("%d", &option);
  }
  switch (option) {
    case 1:
    limparTabuleiro();
    iniciarJogo();
    break;
    case 2:
    instrucoes();
    break;
    case 3:
    configuracoes();
    break;
    case 4:
    creditos();
    break;
    case 5:
    system("cls || clear");
    exit(0);
    break;
  }
}

void creditos() {
  system("cls || clear");
  printf("Jogo MasterMind\n\nDesenvolvido por:\n- Lucas Cândido Cotrim\n\n- Pedro Luca Prates / pedroluca.epizy.com\n\nAperte enter para retornar!\n");
  system("pause || read -p '' var");
  menu();
}

char imprimirTabuleiro() {
  for (int i = 0; i < quantTentativas; i++) {
    printf("  ||");
    for (int i = 0; i < larguraLinha[quantPinos - 4]; i++) printf("-");
    printf("||\n  || ");
    for (int k = 0; k < quantPinos; k++) printf(" (% c) ", tabuleiro[i][k]);
    printf(" |");
    if (quantPinos % 2 == 0) auxPinos = quantPinos / 2;
    else auxPinos = (quantPinos / 2) + 1;
    for (int k = 0; k < auxPinos; k++) printf(" % c ", tabuleiro[i][k + quantPinos]);
    printf("||\n  ||");
    for (int i = 0; i < larguraLinhaMenor[quantPinos - 4]; i++) printf(" ");
    printf("|");
    if (quantPinos % 2 == 0) auxPinos = quantPinos / 2;
    else auxPinos = (quantPinos / 2) + 1;
    for (int k = auxPinos; k < (auxPinos * 2); k++) {
      if (quantPinos == 5) tabuleiro[i][(auxPinos - 1) + quantPinos] = ' ';
      printf(" % c ", tabuleiro[i][k + quantPinos]);
    }
    printf("||\n");
  }
}

void iniciarJogo() {
  int numeroRandom, senhaCorretaEmInt[pin], cor = 0, autencadorNumSenha = 0;
  char stringSenha[quantPinos];
  tentativaAtual = quantTentativas;
  vitoria = 0;
  for (int i = 0; i < quantPinos; i++) senhaCorretaEmInt[i] = 0;
  if (modoJogadores == 1) { //Geração de senha aleatória
    srand((unsigned)time(NULL));
    for (int i = 0; i < quantPinos; i++) {
      numeroRandom = rand() % quantCores + 1;
      if (repetirCaracter == 0) {
        for (int k = 0; k < quantPinos; k++) {
          if (numeroRandom == senhaCorretaEmInt[k]) {
            i--;
            autencadorNumSenha = 1;
            break;
          }
        }
      }
      if (autencadorNumSenha != 1) {
        senhaCorretaEmInt[i] = numeroRandom;
        senha[i] = caracteresValidos[numeroRandom - 1];
      }
      autencadorNumSenha = 0;
    }
  } else if (modoJogadores == 2) multiplayer();
  while (tentativaAtual > 0) { 
    system("cls || clear");
    printf("<<==");
    for (int i = 0; i < (larguraLinha[quantPinos - 4] / 2); i++) printf(" =");
    printf("==>>\n  || ");
    for (int i = 0; i < quantPinos; i++) printf(" (X) ");
    for( int i = 0; i < larguraLinhaSenha[quantPinos - 4]; i++) printf(" ");
    printf("||\n");
    imprimirTabuleiro();
    printf("<<== = = = = = = = = = = = == = = = = = = = = = = ==>>\n");
    printf("  || Legenda:                                     ||\n");
    printf("  ||   V - vermelho    M - marrom   A - amarelo   ||\n");
    printf("  ||   L - laranja     R - rosa     C - cinza     ||\n");
    printf("  ||   B - branco      P - preto                  ||\n");
    printf("<<== = = = = = = = = = = = == = = = = = = = = = = ==>>");
    if (modoJogadores == 2) printf("\n  Jogador: %s | Pontuação atual: %d | Partida atual: %d | restantes: %d", nomeJogador[jogadorDaVez], placar[jogadorDaVez], partidaAtual, partidaIniciada - 1);
    printf("\n  Cores disponíveis:");
    for (int i = 0; i < quantCores; i++) printf(" % c ", caracteresValidos[i]);
    do {
      printf("\n\n  Informe a sequência: ");
      scanf("%s", &stringSenha);
      for (int i = 0; i < quantPinos; i++) stringSenha[i] = toupper(stringSenha[i]);
    } while (validaTentativa(stringSenha) == 0);
    if (verificaSequencia(stringSenha) == 1) {
      vitoria = 1;
      finalizarJogo();
    }
  }
  finalizarJogo();
}

int validaTentativa(char senhaDigitada[quantPinos]) {
  int auxSenha = 1, countDiferenca = 0;
  while (auxSenha == 1) {
    for (int j = 0; j < quantPinos; j++) {
      senhaDigitada[j] = toupper(senhaDigitada[j]);
      if (!senhaDigitada[j]) return 0;
      else {
        for (int j = 0; j < quantPinos; j++) {
          for (int i = 0; i < quantPinos; i++) if (senhaDigitada[j] != caracteresValidos[i]) countDiferenca++;
        } 
        if (countDiferenca == 0) return 0;
        else return 1;
      }
    }
  }  
}

void instrucoes() {
  system("cls || clear");
  printf("Classificação dos pinos:\n\n");
  printf("• Pino branco (B): indica que a cor de um dos pinos colocados pelo desafiado\n coincide com a cor de um dos pinos da senha, mas a sua posição não está correta;\n");
  printf("• Pino preto (P): indica que um dos pinos colocados pelo desafiado coincide \ncom um dos pinos da senha, em cor e posição;\n");
  printf("• Nenhum pino (x): significa que nem a cor e nem a posição então corretas.\n\n\n");
  printf("Regras gerais:\n\n");
  printf("- O jogador desafiado terá uma quantidade x de tentativas para descobrir a  \nsenha de caracteres, efetuando chutes e recebendo marcações de pinos (citados acima), tendo que deduzir onde e quais pinos estão corretos.\n");
  printf("- Não existe ordem para a colocação dos pinos brancos e pretos. O sistema não\n informa a cor nem a posição correspondente ao pino branco, ao preto ou ao espaço vazio. É nessa colocação aleatória dos pinos brancos e pretos que está o verdadeiro \ndesafio do jogo, pois o desafiado tentará deduzir, por suas jogadas anteriores, qual é a sequência correta da senha.\n");
  printf("- Quando o desafiado reproduzir a sequência exata, o sistema revelará a senha.\n\n\n");
  printf("Modo Singleplayer:\n\n");
  printf("- O sistema irá gerar uma senha aleatória sem a necessidade de um jogador digitar nada.\n\n\n");
  printf("Modo Multiplayer:\n\n");
  printf("- Antes de jogar, os jogadores decidem o número de partidas que vão jogar,\n considerando que é preciso jogar um número par de partidas para que os dois jogadores tenham o mesmo número de oportunidade como desafiante e desafiado.\n");
  printf("- O primeiro a jogar como desafiante digita uma senha. A senha pode ser \nformada por qualquer combinação de pinos coloridos representados por letras. Os jogadores decidem, com antecedência, se é permitido repetir cores na senha. Note que isso \naumenta a dificuldade do jogo. Após digitar a senha e o sistema escondê-la, o outro jogador, o desafiado, pode iniciar o jogo e tentar acertar a combinação.\n");
  printf("\nAperte enter para retornar!\n");
  system("pause || read -p '' var");
  menu();
}

void configuracoes() {
  int option;
  char dificuldade[10];
  system("cls || clear");
  printf("<<== = = = = = = = = = == = = = = = = = = = ==>>\n");
  printf("  || 1- Mudar quantidade de jogadores: %d    ||\n", modoJogadores);
  switch (quantCores) {
    case 6:
    printf("  || 2- Mudar dificuldade de jogo: Fácil    ||\n");
    break;
    case 7:
    printf("  || 2- Mudar dificuldade de jogo: Médio    ||\n");
    break;
    case 8:
    printf("  || 2- Mudar dificuldade de jogo: Difícil  ||\n");
    break;
  }
  if (repetirCaracter == 1) printf("  || 3- Repetição de caracter: Ativado      ||\n");
  else printf("  || 3- Repetição de caracter: Desativado   ||\n");
  printf("  || 4- Voltar                              ||\n");
  printf("<<== = = = = = = = = = == = = = = = = = = = ==>>\n");
  printf("Escolha uma opção: ");
  scanf("%d", &option);
  while (option <= 0 || option > 4) {
    printf("\nInforme uma opção válida!\nOpção: ");
    scanf("%d", &option);
  }
  switch (option) {
    case 1:
    system("cls || clear");
    printf("<<== = = = = = = = = = = = ==>>\n");
    printf("  || 1- Jogador vs Máquina ||\n");
    printf("  || 2- Jogador vs Jogador ||\n");
    printf("  || 3- Voltar             ||\n");
    printf("<<== = = = = = = = = = = = ==>>\n");
    printf("Opção: ");
    scanf("%d", &option);
    if (option == 1) modoJogadores = 1;
    else if (option == 2) modoJogadores = 2;
    else configuracoes();
    printf("Configuração alterada!\n");
    system("pause || read -p '' var");
    configuracoes();
    break;
    case 2:
    system("cls || clear");
    printf("<<== = = = = = = = = = = = ==>>\n");
    printf("  || 1- Modo fácil         ||\n");
    printf("  || 2- Modo médio         ||\n");
    printf("  || 3- Modo difícil       ||\n");
    printf("  || 4- Voltar             ||\n");
    printf("<<== = = = = = = = = = = = ==>>\n");
    printf("Opção: ");
    scanf("%d", &option);
    if (option == 1) {
      quantCores = 6;
      quantTentativas = 10;
    } else if (option == 2) {
      quantCores = 7;
      quantTentativas = 12;
    } else if (option == 3) {
      quantCores = 8;
      quantTentativas = 14;
    } else configuracoes();
    quantPinos = quantCores - 2;
    printf("Configuração alterada!\n");
    system("pause || read -p '' var");
    configuracoes();
    break;
    case 3:
    if (repetirCaracter == 0) repetirCaracter = 1;
    else repetirCaracter = 0;
    printf("Configuração alterada!\n");
    system("pause || read -p '' var");
    configuracoes();
    break;
    case 4:
    menu();
    break;
  }
}

int verificaSequencia(char senhaTentativa[quantPinos]) {
  pinosB = 0, pinosP = 0;
  for (int i = 0; i < quantPinos; i++) {
    for (int k = 0; k < quantPinos; k++) {
      if (senhaTentativa[i] == senha[k]) {
        if (i == k) pinosP++;
        else if (i != k) pinosB++; 
      }
    }
  }
  int pinosPretos = pinosP;
  for (int i = 0; i < lar; i++) {
    if (i < quantPinos) tabuleiro[tentativaAtual - 1][i] = senhaTentativa[i];
    else if (i >= quantPinos) {
      if (pinosP > 0) {
        tabuleiro[tentativaAtual - 1][i] = 'P';
        pinosP--;
      } else if (pinosP <= 0) {
        if (pinosB > 0) {
          tabuleiro[tentativaAtual - 1][i] = 'B';
          pinosB--;
        }
      }
    }
  }
  tentativaAtual--;
  if (pinosPretos == quantPinos) return 1;
  else return 0;
}

int limparTabuleiro() {
  for (int i = 0; i < alt; i++) {
    for (int k = 0; k < lar; k++) {
      tabuleiro[i][k] = '_';
      if (k >= quantPinos) tabuleiro[i][k] = 'X';
    }
  }
  return 0;
}

void finalizarJogo() {
  system("cls || clear");
  printf("<<==");
  for (int i = 0; i < (larguraLinha[quantPinos - 4] / 2); i++) printf(" =");
  printf("==>>\n  || ");
  for (int i = 0; i < quantPinos; i++) printf(" (% c) ", senha[i]);
  for( int i = 0; i < larguraLinhaSenha[quantPinos - 4]; i++) printf(" ");
  printf("||\n");
  imprimirTabuleiro();
  printf("<<==");
  for (int i = 0; i < (larguraLinha[quantPinos - 4] / 2); i++) printf(" =");
  printf("==>>\n");
  if (vitoria == 1) {
    printf("\nPARABÉNS!! VOCÊ VENCEU O JOGO!\nTentativas restantes: %d\n\nAperte enter para retornar ao Menu\n", tentativaAtual);
    if (modoJogadores == 2) placar[jogadorDaVez]++;
  } else printf("POXA, NÃO FOI DESSA VEZ!\n\nAperte enter para retornar ao Menu\n");
  if (modoJogadores == 2) {
    aux = jogadorDaVez;
    jogadorDaVez = proxJogador;
    proxJogador = aux;
    partidaIniciada--;
    limparTabuleiro();
  }
  system("pause || read -p '' var");
  if (modoJogadores == 2 && partidaIniciada > 0) {
    partidaAtual++;
    iniciarJogo();
  } else if (modoJogadores == 2 && partidaIniciada == 0) {
    system("cls || clear");
    printf("\nPartidas finalizadas!\nO placar foi de :\n%s: %d x %d :%s\n", nomeJogador[0], placar[0], placar[1], nomeJogador[1]);
    if (placar[0] == placar[1]) printf("\nTire par ou ímpar para desempatar ;)\n");
    printf("Aperte enter para retornar ao Menu\n");
    system("pause || read -p '' var");
  }
  partidaIniciada = 0;
  partidaAtual = 1;
  placar[0] = 0;
  placar[1] = 0;
  vitoria = 0;
  menu();
}

int multiplayer() {
  int partidas;
  char stringSenha[quantPinos];
  system("cls || clear");
  if (partidaIniciada == 0) {
    printf("Informe o nome dos 2 jogadores: (obs: sem espaços)\n");
    for (int i = 0; i < 2; i++) {
      printf("Jogador %d: ", i + 1);
      scanf("%s", &nomeJogador[i]);
    }
    do {
      printf("\nQuantas partidas irão jogar?\n P: ");
      scanf("%d", &partidas);
    } while (partidas % 2 != 0);
    quantPartidas = partidas;
    partidaIniciada = partidas;
  }
  printf("\nO jogador %d (%s) irá iniciar escolhendo a senha secreta, e o jogador %d (%s) deverá advinhá-la!\n", jogadorDaVez + 1, nomeJogador[jogadorDaVez], proxJogador + 1, nomeJogador[proxJogador]);
  system("pause || read -p '' var");
  do {
    system("cls || clear");
    printf("Caracteres válidos: ");
    for (int i = 0; i < quantCores; i++) printf(" % c", caracteresValidos[i]);
    printf("\nJogador %d, digite a senha secreta: \n", jogadorDaVez + 1);
    scanf("%s", &stringSenha);
    for (int i = 0; i < quantPinos; i++) stringSenha[i] = toupper(stringSenha[i]);
  } while (validaTentativa(stringSenha) == 0);
  printf("A senha digitada foi: %s\nPressione enter para prosseguir e iniciar a partida\n", stringSenha);
  system("pause || read -p '' var");
  return 0;
}
