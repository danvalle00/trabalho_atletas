#include "lib/function_atleta.h"

int main()
{
  node_t *head = NULL;
  carta_atleta_t *carta_atleta = malloc(TAM_deck * sizeof(carta_atleta_t));
  popular_tabela(carta_atleta, TAM_deck);
  salvar_tabela_csv(carta_atleta, TAM_deck, "lista_jogadores.csv");

  for (int i = 0; i < TAM_deck; i++)
  {
    add_node_last(&head, &carta_atleta[i]);
  }
  printar_node(head);
  free(carta_atleta);
  free(head);
}