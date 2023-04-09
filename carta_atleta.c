#include "lib/function_atleta.h"

// TODO: Implementar uma função de sort da lista encadeada, organizar a lista antes de gerar os 100 extras. Assim, gerar os 100 e manter ordenado.

int main()
{
  node_t *head = NULL;

  carta_atleta_t *carta_atleta = malloc(TAM_deck * sizeof(carta_atleta_t));
  carta_atleta_t *atleta_extras = malloc(EXTRA_deck * sizeof(carta_atleta_t));
  jogador_csv_t *jogador_csv = malloc(TAM_deck * sizeof(jogador_csv_t));

  gerar_jogador(carta_atleta, TAM_deck);
  gerar_jogador_extra(atleta_extras, EXTRA_deck);

  salvar_tabela_csv(carta_atleta, TAM_deck, "lista_jogadores.csv");
  extrair_jogador_csv("lista_jogadores.csv", jogador_csv, TAM_deck);

  free(jogador_csv);
  free(atleta_extras);
  free(carta_atleta);
  free(head);
}