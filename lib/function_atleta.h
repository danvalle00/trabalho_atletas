#ifndef FUNCTION_ATLETA_H
#define FUNCTION_ATLETA_H

// Bibliotecas Padroes Usadas no carta_atleta.c
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Usados pelo carta_atleta.c
#define TAM_name 20
#define QTD_name 35
#define QTD_time 20
#define TAM_deck 100
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
    char nome_completo[TAM_name * 2];
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

void popular_tabela(carta_atleta_t *carta_atleta, int tamanho);
void salvar_tabela_csv(carta_atleta_t *carta_atleta, int tamanho, const char *nome_arquivo);
int comparar_pessoas_por_nome(const void *p1, const void *p2);

#endif