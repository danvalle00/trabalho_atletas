#include "function_atleta.h"

void popular_tabela(carta_atleta_t *carta_atleta, int tamanho)
{
  srand(time(NULL));

  char nomes[QTD_name][TAM_name] = {"Miguel", "Davi", "Gabriel", "Arthur", "Lucas", "Matheus", "Pedro", "Guilherme", "Gustavo", "Rafael", "Felipe", "Bernardo", "Enzo", "Nicolas", "João Pedro", "Cauã", "Vitor", "Eduardo", "Daniel", "Henrique", "Murilo", "Vinicius", "Samuel", "Pietro", "João Vitor", "Leonardo", "Caio", "Heitor", "Lorenzo", "Isaac", "Lucca", "Thiago", "João Gabriel", "João", "Marcos"};

  char sobrenomes[QTD_name][TAM_name] = {" Silva", " Santos", " Oliveira", " Souza", " Rodrigues", " Ferreira", " Alves", " Pereira", " Lima", " Gomes", " Costa", " Ribeiro", " Martins", " Carvalho", " Almeida", " Lopes", " Soares", " Fernandes", " Vieira", " Barbosa", " Rocha", " Dias", " Nascimento", " Andrade", " Moreira", " Nunes", " Marques", " Machado", " Mendes", " Freitas", " Cardoso", " Ramos", " Gonçalves", " Santana", " Teixeira"};

  char times[QTD_time][TAM_name] = {"América-MG", "Athletico-PR", "Atlético-MG", "Bahia", "Botafogo", "Bragantino", "Corinthians", "Coritiba", "Cruzeiro", "Cuiabá", "Flamengo", "Fluminense", "Fortaleza", "Goiás", "Grêmio", "Internacional", "Palmeiras", "Santos", "São Paulo", "Vasco"};

  for (int i = 0; i < tamanho; i++)
  {
    int nome_index = rand() % QTD_name;
    int sobrenome_index = rand() % QTD_name;
    int time_index = rand() % QTD_time;

    carta_atleta[i].id = i;
    strcpy(carta_atleta[i].nome, nomes[nome_index]);
    strcpy(carta_atleta[i].sobrenome, sobrenomes[sobrenome_index]);
    strcpy(carta_atleta[i].nome_completo, nomes[nome_index]);
    strcpy(carta_atleta[i].nome_completo, strcat(carta_atleta[i].nome_completo, carta_atleta[i].sobrenome));
    carta_atleta[i].idade = (rand() % (max_age - min_age + 1)) + min_age;
    strcpy(carta_atleta[i].time, times[time_index]);
    carta_atleta[i].valor = (rand() % (max_value - min_value + 1)) + min_value;
    carta_atleta[i].forca = rand() % range_random + 1;
    carta_atleta[i].velocidade = rand() % range_random + 1;
    carta_atleta[i].resistencia = rand() % range_random + 1;
    carta_atleta[i].forca_vontade = rand() % range_random + 1;
    carta_atleta[i].criatividade = rand() % range_random + 1;
    carta_atleta[i].lideranca = rand() % 2;
    carta_atleta[i].machucado = rand() % 2;
    carta_atleta[i].posicao = rand() % 5;
    if (carta_atleta[i].machucado)
    {
      carta_atleta[i].meses_recuperacao = 1 + rand() % 12;
    }
    else
    {
      carta_atleta[i].meses_recuperacao = 0;
    }
  }
}

void salvar_tabela_csv(carta_atleta_t *carta_atleta, int tamanho, const char *nome_arquivo)
{
  char *posicoes[5] = {"Gol", "Defesa", "Meio", "Ataque", "Libero"};

  FILE *arquivo = fopen(nome_arquivo, "w");

  qsort(carta_atleta, tamanho, sizeof(carta_atleta_t), comparar_pessoas_por_nome);

  if (arquivo != NULL)
  {
    fprintf(arquivo, FILE_HEADER);
    for (int i = 0; i < tamanho; i++)
    {
      fprintf(arquivo, FILE_FORMAT, carta_atleta[i].id, carta_atleta[i].nome, carta_atleta[i].sobrenome, carta_atleta[i].nome_completo, carta_atleta[i].idade, carta_atleta[i].time, carta_atleta[i].valor, (carta_atleta[i].forca + carta_atleta[i].forca_vontade + carta_atleta[i].velocidade + carta_atleta[i].criatividade + carta_atleta[i].resistencia) / 5, carta_atleta[i].forca, carta_atleta[i].resistencia, carta_atleta[i].velocidade, carta_atleta[i].forca_vontade, carta_atleta[i].criatividade, carta_atleta[i].machucado ? "Sim" : "Não", posicoes[carta_atleta[i].posicao], carta_atleta[i].lideranca ? "Sim" : "Não", carta_atleta[i].meses_recuperacao);
    }
    fclose(arquivo);
  }
}

int comparar_pessoas_por_nome(const void *p1, const void *p2)
{
  const carta_atleta_t *a = p1;
  const carta_atleta_t *b = p2;
  return strcmp(a->nome_completo, b->nome_completo);
}

node_t *criar_node(carta_atleta_t *atleta)
{
  node_t *novo_node = malloc(sizeof(node_t));
  novo_node->data_atleta = atleta;
  novo_node->proximo = NULL;
  return novo_node;
}
// --> Dessa forma o printar nodo vai ser na ordem alfabética descentende;
void add_node(node_t **head, carta_atleta_t *atleta)
{
  node_t *novo_node = criar_node(atleta);
  novo_node->proximo = *head;
  *head = novo_node;
}
// --> Dessa forma o printar nodo vai ser na ordem alfabética ascendente;
void add_node_last(node_t **head, carta_atleta_t *atleta)
{
  node_t *novo_node = criar_node(atleta);
  node_t *current = *head;
  if (*head == NULL)
  {
    *head = novo_node;
    return;
  }
  while (current->proximo != NULL)
  {
    current = current->proximo;
  }
  current->proximo = novo_node;
}

void printar_node(node_t *head)
{
  node_t *atual = head;
  while (atual != NULL)
  {
    // Obs: Colocar o resto dos tipos dos jogadores para printar;
    printf("%s, ", atual->data_atleta->nome_completo);
    printf("%d\n", atual->data_atleta->id);
    atual = atual->proximo;
  }
}