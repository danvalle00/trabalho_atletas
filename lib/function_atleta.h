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
#define TAM_deck 1000
#define EXTRA_deck 100
#define range_random 100
#define max_age 40
#define min_age 16
#define max_value 10000
#define min_value 1000
#define FILE_HEADER "ID,Nome,Sobrenome,Nome Completo,Idade,Time,Valor,Overall,Força,Resistencia,Velocidade,Força de vontade,Criatividade,Machucado,Posição,Liderança,Tempo De Recuperação\n"
#define FILE_FORMAT "%d,%s,%s,%s,%d,%s,%d,%d,%d,%d,%d,%d,%d,%s,%s,%s,%d\n"
#define NOMES_ATLETAS "Miguel", "Davi", "Gabriel", "Arthur", "Lucas", "Matheus", "Pedro", "Guilherme", "Gustavo", "Rafael", "Felipe", "Bernardo", "Enzo", "Nicolas", "João Pedro", "Cauã", "Vitor", "Eduardo", "Daniel", "Henrique", "Murilo", "Vinicius", "Samuel", "Pietro", "João Vitor", "Leonardo", "Caio", "Heitor", "Lorenzo", "Isaac", "Lucca", "Thiago", "João Gabriel", "João", "Marcos"
#define SOBRENOMES_ATLETAS " Silva", " Santos", " Oliveira", " Souza", " Rodrigues", " Ferreira", " Alves", " Pereira", " Lima", " Gomes", " Costa", " Ribeiro", " Martins", " Carvalho", " Almeida", " Lopes", " Soares", " Fernandes", " Vieira", " Barbosa", " Rocha", " Dias", " Nascimento", " Andrade", " Moreira", " Nunes", " Marques", " Machado", " Mendes", " Freitas", " Cardoso", " Ramos", " Gonçalves", " Santana", " Teixeira"
#define CLUBES "América-MG", "Athletico-PR", "Atlético-MG", "Bahia", "Botafogo", "Bragantino", "Corinthians", "Coritiba", "Cruzeiro", "Cuiabá", "Flamengo", "Fluminense", "Fortaleza", "Goiás", "Grêmio", "Internacional", "Palmeiras", "Santos", "São Paulo", "Vasco"

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

typedef struct node
{
    carta_atleta_t *data_atleta;
    struct node *proximo;
} node_t;

typedef struct jogador_csv
{
    int id;
    char nome_completo[TAM_name * 2];
} jogador_csv_t;

void gerar_jogador(carta_atleta_t *carta_atleta, int tamanho);

void gerar_jogador_extra(carta_atleta_t *carta_atleta, int tamanho);

void salvar_tabela_csv(carta_atleta_t *carta_atleta, int tamanho, const char *nome_arquivo);

void add_node(node_t **head, carta_atleta_t *atleta);

void add_node_final(node_t **head, carta_atleta_t *atleta);

void printar_node(node_t *head);

void extrair_jogador_csv(char *nome_arquivo, carta_atleta_t *jogador_csv, int tamanho);

#endif