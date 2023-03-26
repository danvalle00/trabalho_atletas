#include "lib/function_atleta.h"

int main()
{
  carta_atleta_t *carta_atleta = malloc(TAM_deck * sizeof(carta_atleta_t));
  popular_tabela(carta_atleta, TAM_deck);
  salvar_tabela_csv(carta_atleta, TAM_deck, "lista_jogadores.csv");
  free(carta_atleta);
}