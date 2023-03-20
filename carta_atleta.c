#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM_name 20
#define QTD_name 35
#define QTD_time 20
#define TAM_deck 500
#define range_random 100
#define max_age 40
#define min_age 16
#define max_value 10000
#define min_value 1000

typedef enum
{
    Gol,
    Defesa,
    Meio,
    Ataque,
    Libero
} posicao;

typedef struct
{
    int id;
    char nome[TAM_name];
    char sobrenome[TAM_name];
    int idade;
    char time[TAM_name];
    int valor;
    int forca;
    int velocidade;
    int resistencia;
    int forca_vontade;
    int criatividade;
    bool lideranca;
    bool machucado;
    posicao posicao;
    int meses_recuperacao;
} carta_atleta_t;

// TODO: Colocar o gerador de cartas_atleta numa função
// Consertar a repetição de ID's, para cada carta ter um ID único
// Obs: Machucado ser Bool e se for Sim gerar um numero random de 1-7 pra recuperação

void popular_tabela(carta_atleta_t *carta_atleta, int tamanho) {
  srand(time(NULL));

  char nomes[QTD_name][TAM_name] = {"Miguel", "Davi", "Gabriel", "Arthur", "Lucas", "Matheus", "Pedro", "Guilherme", "Gustavo", "Rafael", "Felipe", "Bernardo", "Enzo", "Nicolas", "João Pedro", "Cauã", "Vitor", "Eduardo", "Daniel", "Henrique", "Murilo", "Vinicius", "Samuel", "Pietro", "João Vitor", "Leonardo", "Caio", "Heitor", "Lorenzo", "Isaac", "Lucca", "Thiago", "João Gabriel", "João", "Marcos"};

  char sobrenomes[QTD_name][TAM_name] = {"Silva", "Santos", "Oliveira", "Souza", "Rodrigues", "Ferreira", "Alves", "Pereira", "Lima", "Gomes", "Costa", "Ribeiro", "Martins", "Carvalho", "Almeida", "Lopes", "Soares", "Fernandes", "Vieira", "Barbosa", "Rocha", "Dias", "Nascimento", "Andrade", "Moreira", "Nunes", "Marques", "Machado", "Mendes", "Freitas", "Cardoso", "Ramos", "Gonçalves", "Santana", "Teixeira"};

  char times[QTD_time][TAM_name] = {"América-MG", "Athletico-PR", "Atlético-MG", "Bahia", "Botafogo", "Bragantino", "Corinthians", "Coritiba", "Cruzeiro", "Cuiabá", "Flamengo", "Fluminense", "Fortaleza", "Goiás", "Grêmio", "Internacional", "Palmeiras", "Santos", "São Paulo", "Vasco"};

  // char *posicoes[5] = {"Gol", "Defesa", "Meio", "Ataque", "Libero"};



  for (int i = 0; i < tamanho; i++)
  {
      int nome_index = rand() % QTD_name;
      int sobrenome_index = rand() % QTD_name;
      int time_index = rand() % QTD_time;

      carta_atleta[i].id = i;
      strcpy(carta_atleta[i].nome, nomes[nome_index]);
      strcpy(carta_atleta[i].sobrenome, sobrenomes[sobrenome_index]);
      carta_atleta[i].idade = (rand() % (max_age - min_age + 1)) + min_age;
      strcpy(carta_atleta[i].time, times[time_index]);
      carta_atleta[i].valor = (rand() % (max_value - min_value + 1)) + min_value;
      carta_atleta[i].forca = rand() % range_random + 1;
      carta_atleta[i].velocidade = rand() % range_random + 1;
      carta_atleta[i].resistencia = rand() % range_random + 1;
      carta_atleta[i].forca_vontade = rand() % range_random + 1;
      carta_atleta[i].criatividade = rand() % range_random + 1;
      carta_atleta[i].lideranca = rand() % 2;
      carta_atleta[i].machucado = rand() % range_random + 1;
      carta_atleta[i].posicao = rand() % 5;
      if (carta_atleta[i].machucado == true) {
        carta_atleta[i].meses_recuperacao = 1 + rand() % 12;
      } else {
        carta_atleta[i].meses_recuperacao = 0;
      }
  }

  for (int i = 0; i < tamanho; i++)
    {

        printf("\nindex: %d\nnome: %s\nsobrenome: %s\n", carta_atleta[i].id + 1, carta_atleta[i].nome, carta_atleta[i].sobrenome);
        printf("idade: %d\ntime: %s\nvalor: %i\n", carta_atleta[i].idade, carta_atleta[i].time, carta_atleta[i].valor);
        printf("Overall: %d\n", (carta_atleta[i].forca + carta_atleta[i].forca_vontade + carta_atleta[i].velocidade + carta_atleta[i].criatividade + carta_atleta[i].resistencia)/5);
        printf("forca: %d\nvelocidade: %d\nforca_vontade: %d\nresistencia: %d\n", carta_atleta[i].forca, carta_atleta[i].velocidade, carta_atleta[i].forca_vontade, carta_atleta[i].resistencia);
        printf("criatividade: %d\n", carta_atleta[i].criatividade);
        printf("machucado: %s\n", carta_atleta[i].machucado ? "Sim" : "Não");
        // printf("posicao: %s\n", posicoes[carta_atleta[i].posicao]);
        printf("Liderança: %s\n", carta_atleta[i].lideranca ? "Sim" : "Não");
        printf("Tempo de Recuperação: %d\n", carta_atleta[i].meses_recuperacao);
    }
}

int comparar_pessoas_por_nome(const void *p1, const void *p2) {
    const carta_atleta_t *a = p1;
    const carta_atleta_t *b = p2;
    return strcmp(a->nome, b->nome);
}

void salvar_tabela_csv(carta_atleta_t *carta_atleta, int tamanho, const char *nome_arquivo) {
  char *posicoes[5] = {"Gol", "Defesa", "Meio", "Ataque", "Libero"};

  FILE *arquivo = fopen(nome_arquivo, "w");

  qsort(carta_atleta, tamanho, sizeof(carta_atleta_t), comparar_pessoas_por_nome);

  if (arquivo != NULL) {
    fprintf(arquivo, "ID,Nome,Sobrenome,Idade,Time,Valor,Overall,Força,Resistencia,Velocidade,Força de vontade,Criatividade,Machucado,Posição,Liderança,Tempo De Recuperação\n");
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d,%s,%s,%d,%s,%d,%d,%d,%d,%d,%d,%d,%s,%s,%s,%d\n", carta_atleta[i].id, carta_atleta[i].nome, carta_atleta[i].sobrenome, carta_atleta[i].idade, carta_atleta[i].time, carta_atleta[i].valor, (carta_atleta[i].forca + carta_atleta[i].forca_vontade + carta_atleta[i].velocidade + carta_atleta[i].criatividade + carta_atleta[i].resistencia)/5, carta_atleta[i].forca, carta_atleta[i].resistencia, carta_atleta[i].velocidade, carta_atleta[i].forca_vontade, carta_atleta[i].criatividade, carta_atleta[i].machucado ? "Sim" : "Não", posicoes[carta_atleta[i].posicao], carta_atleta[i].lideranca ? "Sim" : "Não", carta_atleta[i].meses_recuperacao);
    }
    fclose(arquivo);
  }
}

int main()
{
  carta_atleta_t *carta_atleta = malloc(TAM_deck * sizeof(carta_atleta_t));

  popular_tabela(carta_atleta, TAM_deck);

  salvar_tabela_csv(carta_atleta, TAM_deck, "lista_jogadores.csv");

  free(carta_atleta);
}
