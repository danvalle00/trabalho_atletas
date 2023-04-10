#include "function_atleta.h"

void gerar_jogador(carta_atleta_t *carta_atleta, int tamanho)
{
  srand(time(NULL));

  char nomes[QTD_name][TAM_name] = {NOMES_ATLETAS};
  char sobrenomes[QTD_name][TAM_name] = {SOBRENOMES_ATLETAS};
  char times[QTD_time][TAM_name] = {CLUBES};

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

node_t *criar_node(carta_atleta_t *atleta)
{
  node_t *novo_node = malloc(sizeof(node_t));
  novo_node->data_atleta = atleta;
  novo_node->proximo = NULL;
  return novo_node;
}

void add_node(node_t **head, carta_atleta_t *atleta)
{
  node_t *novo_node = criar_node(atleta);
  novo_node->proximo = *head;
  *head = novo_node;
}

void add_node_final(node_t **head, carta_atleta_t *atleta)
{
  node_t *novo_nodo = criar_node(atleta);
  node_t *proximo = *head;
  if (*head == NULL)
  {
    *head = novo_nodo;
    return;
  }
  while (proximo->proximo != NULL)
  {
    proximo = proximo->proximo;
  }
  proximo->proximo = novo_nodo;
}

void printar_node(node_t *head)
{
  node_t *atual = head;
  while (atual != NULL)
  {
    printf("[%d] - ", atual->data_atleta->id);
    printf("%s\n ", atual->data_atleta->nome_completo);

    atual = atual->proximo;
  }
}

// --> Função feita pra tirar o conflito dos ID's dos jogadores novos com os antigos.
void gerar_jogador_extra(carta_atleta_t *carta_atleta, int tamanho)
{
  srand(time(NULL));

  char nomes[QTD_name][TAM_name] = {NOMES_ATLETAS};
  char sobrenomes[QTD_name][TAM_name] = {SOBRENOMES_ATLETAS};
  char times[QTD_time][TAM_name] = {CLUBES};

  // --> O ID dos jogadores extras vão variar de 1000 - 1099
  for (int i = 0; i < tamanho; i++)
  {
    int nome_index = rand() % QTD_name;
    int sobrenome_index = rand() % QTD_name;
    int time_index = rand() % QTD_time;

    carta_atleta[i].id = (i + TAM_deck);
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

void extrair_jogador_csv(char *nome_arquivo, carta_atleta_t *jogador_csv, int tamanho)
{
  char linha[1024];
  int j = 0;

  FILE *arquivo = fopen(nome_arquivo, "r");
  fgets(linha, sizeof(linha), arquivo);

  while ((fgets(linha, sizeof(linha), arquivo)) != NULL) // le tds as linhas
  {
    char *token = strtok(linha, ",");
    jogador_csv[j].id = atoi(token);
    token = strtok(NULL, ",");
    for (int i = 0; i < 2; i++) // pula o nome e o sobrenome
    {
      token = strtok(NULL, ",");
    }

    strcpy(jogador_csv[j].nome_completo, token);

    for (int i = 0; i < 13; i++) // pulando o resto
    {
      token = strtok(NULL, ",");
    }

    j++;
  }
  fclose(arquivo);
}

void insection_sort(node_t ** head)
{
  node_t *ordenado = NULL;
  node_t *atual = *head;

  while (atual != NULL)
  {
    node_t *proximo = atual->proximo;
    if (ordenado == NULL || strcmp(ordenado->data_atleta->nome_completo, atual->data_atleta->nome_completo) > 0)
    {
      atual->proximo = ordenado;
      ordenado = atual;
    }
    else 
    {
      node_t *temp = ordenado;
      while (temp->proximo != NULL && strcmp(temp->proximo->data_atleta->nome_completo, atual->data_atleta->nome_completo) < 0)
      {
        temp = temp->proximo;
      }
      atual->proximo = temp->proximo;
      temp->proximo = atual;
    }
    atual = proximo;
  }
  *head = ordenado;
}
