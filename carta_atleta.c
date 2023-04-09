#include "lib/function_atleta.h"

// TODO: Fazer a função de ordenar a linkedlist.

int main()
{
  node_t *head = NULL;

  carta_atleta_t *carta_atleta = malloc(TAM_deck * sizeof(carta_atleta_t));
  carta_atleta_t *atleta_extras = malloc(EXTRA_deck * sizeof(carta_atleta_t));
  carta_atleta_t *jogador_csv = malloc(TAM_deck * sizeof(carta_atleta_t));

  gerar_jogador(carta_atleta, TAM_deck);
  gerar_jogador_extra(atleta_extras, EXTRA_deck);

  salvar_tabela_csv(carta_atleta, TAM_deck, "lista_jogadores.csv");
  extrair_jogador_csv("lista_jogadores.csv", jogador_csv, TAM_deck);

  for (int i = 0; i < TAM_deck; i++)
  {
    add_node_final(&head, &jogador_csv[i]);
  }
  // TODO: Chamar a function de ordenar aqui
  for (int i = 0; i < EXTRA_deck; i++)
  {
    add_node_final(&head, &atleta_extras[i]);
  }

  // TODO: Chamar a function de novo aqui
  printar_node(head);

  free(jogador_csv);
  free(atleta_extras);
  free(carta_atleta);
  free(head);
}