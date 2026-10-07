//tad da lista estatica sequencial!!

#ifndef LISTA_H
#define LISTA_H

#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int chave;
    char nome[50];
} tipo_elem;

typedef struct
{
    tipo_elem dados[MAX];
    int n;
} lista;

// operações

void iniciar (lista *l);
void destruir (lista *l);
int vazia (lista *l);

int inserir_inicio (lista *l, tipo_elem v);
int inserir_final (lista *l, tipo_elem v);
int inserir_ord (lista *l, tipo_elem v);

int remover (lista *l, int chave);
int remover_inicio (lista *l);
int remover_final (lista *l);

void exibir (lista *l);
int buscar (lista *l, int chave, tipo_elem *v);

// operações auxiliares (extras)

int buscar_rec (lista *l, int n, int chave, tipo_elem *v);
int tamanho (lista *l);
int tamanho_rec (lista *l);
void exibir_rec (lista *l);
void exibir_inverso_rec (lista *l);
int contar_maiores (lista *l, int chave);
int contar_maiores_rec (lista *l, int chave);

#endif