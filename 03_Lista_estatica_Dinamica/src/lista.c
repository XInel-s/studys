#include "lista.h"

void iniciar(lista *l)
{
    l->head = NULL;
}

void destruir (lista *l)
{
    No *aux;

    while (l->head != NULL)
    {
        aux = l->head;
        l->head = l->head->prox;
        free(aux);
    }
}

int vazia (lista *l)
{
    return l->head == NULL;
}

int inserir_inicio (lista *l, tipo_elem v)
{
    No *novo = (No *)malloc(sizeof(No));

    if (novo == NULL)
        return 0;

    novo->info = v;
    novo->prox = l->head;
    l->head = novo;

    return 1;
}

int inserir_final (lista *l, tipo_elem v)
{
    No *novo;
    No *aux;

    novo = (No *)malloc(sizeof(No));

    if (novo == NULL)
        return 0;

    novo->info = v;
    novo->prox = NULL;

    if (l->head == NULL)
    {
        l->head = novo;
        return 1;
    }

    aux = l->head;

    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }

    aux->prox = novo;

    return 1;
}
int inserir_ord (lista *l, tipo_elem v)
{
    No *novo;
    No *aux;

    novo = (No *)malloc(sizeof(No));

    if (novo == NULL)
        return 0;

    novo->info = v;

    if (l->head == NULL || l->head->info.chave > v.chave) 
    { 
        novo->prox = l->head; 
        l->head = novo; 
        return 1; 
    } 
    aux = l->head; 
    
    while (aux->prox != NULL && aux->prox->info.chave <= v.chave) 
    { 
        aux = aux->prox; 
    } 
    novo->prox = aux->prox; 
    aux->prox = novo; 
    
    return 1;
}

int remover (lista *l, int chave)
{
    No *aux;
    No *anterior;

    if (l->head == NULL)
        return 0;

    aux = l->head;

    if (aux->info.chave == chave)
    {
        l->head = aux->prox;
        free(aux);

        return 1;
    }

    anterior = aux;
    aux = aux->prox;

    while (aux != NULL)
    {
        if (aux->info.chave == chave)
        {
            anterior->prox = aux->prox;
            free(aux);

            return 1;
        }

        anterior = aux;
        aux = aux->prox;
    }

    return 0;
}

int remover_inicio (lista *l)
{
    No *aux;

    if (l->head == NULL)
        return 0;

    aux = l->head;
    l->head = l->head->prox;

    free(aux);

    return 1;
}

int remover_final (lista *l)
{
    No *aux;
    No *ant;

    if (l->head == NULL)
        return 0;

    aux = l->head;

    if (aux->prox == NULL)
    {
        free(aux);
        l->head = NULL;

        return 1;
    }

    ant = NULL;

    while (aux->prox != NULL)
    {
        ant = aux;
        aux = aux->prox;
    }

    ant->prox = NULL;

    free(aux);

    return 1;
}

void exibir (lista *l)
{
    No *aux;

    if (l->head == NULL)
    {
        printf("Erro: Lista sem elementos\n");
        return;
    }

    aux = l->head;

    while (aux != NULL)
    {
        printf("Chave: %d | Nome: %s\n",
               aux->info.chave,
               aux->info.nome);

        aux = aux->prox;
    }
}

int buscar (lista *l, int chave, tipo_elem *v)
{
    No *aux;

    aux = l->head;

    while (aux != NULL)
    {
        if (aux->info.chave == chave)
        {
            *v = aux->info;
            return 1;
        }

        aux = aux->prox;
    }

    return 0;
}

int aux_buscar_rec (No *p, int chave, tipo_elem *v)
{
    if (p == NULL)
        return 0;

    if (p->info.chave == chave)
    {
        *v = p->info;
        return 1;
    }

    return aux_buscar_rec(p->prox, chave, v);
}

int buscar_rec (lista *l, int chave, tipo_elem *v)
{
    return aux_buscar_rec(l->head, chave, v);
}

int tamanho (lista *l)
{
    int cont = 0;
    No *aux;

    aux = l->head;

    while (aux != NULL)
    {
        cont++;
        aux = aux->prox;
    }

    return cont;
}

int aux_tamanho_rec (No *p)
{
    if (p == NULL)
       return 0;

    return 1 + aux_tamanho_rec(p->prox);
}

int tamanho_rec (lista *l)
{
    return aux_tamanho_rec(l->head);
}

void aux_exibir_rec(No *p)
{
    if (p == NULL)
        return;

    printf("Chave: %d | Nome: %s\n",
           p->info.chave,
           p->info.nome);

    aux_exibir_rec(p->prox);
}

void exibir_rec (lista *l)
{
    aux_exibir_rec(l->head);
}

void aux_exibir_inverso_rec(No *p)
{
    if (p == NULL)
        return;

    aux_exibir_inverso_rec(p->prox);

    printf("Chave: %d | Nome: %s\n",
           p->info.chave,
           p->info.nome);
}

void exibir_inverso_rec (lista *l)
{
    aux_exibir_inverso_rec(l->head);
}

int contar_maiores (lista *l, int chave)
{
    int cont = 0;
    No *aux;

    aux = l->head;

    while (aux != NULL)
    {
        if (aux->info.chave > chave)
            cont++;

        aux = aux->prox;
    }

    return cont;
}

int aux_contar_maiores_rec(No *p, int chave)
{
    if (p == NULL)
        return 0;

    if (p->info.chave > chave)
        return 1 + aux_contar_maiores_rec(p->prox, chave);

    return aux_contar_maiores_rec(p->prox, chave);
}

int contar_maiores_rec (lista *l, int chave)
{
    aux_contar_maiores_rec(l->head, chave);
}