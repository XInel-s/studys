#include "lista.h"

void iniciar (lista *l)
{
    l -> n = 0;
}

void destruir (lista *l)
{
    l -> n = 0;
}

int vazia (lista *l)
{
    return (l -> n == 0);
}

int inserir_inicio (lista *l, tipo_elem v)
{
    if (l -> n == MAX) return 0;

    for (int i = 1; i <= l -> n; i++)
    {
        l -> dados[i] = l -> dados[i - 1];
    }

    l -> dados[0] = v;
    l -> n++;

    return 1;
}

int inserir_final (lista *l, tipo_elem v)
{
    if (l -> n == MAX) return 0;

    l -> dados[l -> n] = v;
    l -> n++;
}

int inserir_ord (lista *l, tipo_elem v)
{
    if (l -> n == MAX) return 0;

    int i = l -> n - 1;

    for (i; i >= 0 && l -> dados[i].chave > v.chave; i--)
    {
        l -> dados[i + 1] = l -> dados[i];
    }

    l -> dados[i + 1] = v;
    l -> n++;

    return 1;
}

int remover (lista *l, int chave)
{
    int pos = -1;

    for (int i = 0; i < l -> n; i++)
    {
        if (l -> dados[i].chave == chave)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1) return 0;

    for (int i = pos; i < l -> n - 1; i ++)
    {
        l -> dados [i] = l -> dados[i + 1];
    }

    l -> n--;

    return 1;
}

int remover_inicio (lista *l)
{
    if (vazia(l)) return 0;

    for (int i = 0; i < l -> n - 1; i++)
    {
        l -> dados[i] = l -> dados[i + 1];
    }

    l -> n--;

    return 1;
}

int remover_final (lista *l)
{
    if (vazia(l)) return 0;

    l -> n--;

    return 1;

}

void exibir (lista *l)
{
    if (!vazia(l))
    {
       for (int i = 0; i < l -> n; i++)
        {
            printf("[%d]: Chave: %d | Nome: %s\n", i + 1, l -> dados[i].chave, l -> dados[i].nome);
        }
    }
    else printf ("Erro: Lista sem elementos");
}

int buscar (lista *l, int chave, tipo_elem *v)
{
    for (int i = 0; i < l -> n; i++)
    {
        if (l -> dados[i]. chave == chave)
        {
            *v = l -> dados[i];
            return 1;
        }
    }

    return 0;
}

int buscar_rec (lista *l, int n, int chave, tipo_elem *v)
{
    if (n <= 0) return 0;

    if (l -> dados[0].chave == chave)
    {
        *v = l -> dados[0];
        return 1;
    }

    return buscar_rec (l, n - 1, chave, v);
}

int tamanho (lista *l)
{
    return l -> n;
}

int tamanho_rec (lista *l)
{
    if (l -> n == 0) return 0;

    lista aux = *l;
    aux.n--;

    return 1 + tamanho_rec(&aux);
}

void aux_exibir_rec (tipo_elem *dados, int n)
{
    if (n <= 0) return;

    printf("Chave: %d | Nome: %s\n", dados[0].chave, dados[0].nome);
    aux_exibir_rec (dados +1, n - 1);
}

void exibir_rec (lista *l)
{
    aux_exibir_rec (l -> dados, l -> n);
}

void aux_exibir_inverso_rec (tipo_elem *dados, int n)
{
    if (n <= 0) return;

    aux_exibir_inverso_rec (dados + 1, n - 1);
    printf("Chave: %d | Nome: %s\n", dados[0].chave, dados[0].nome);
}

void exibir_inverso_rec (lista *l)
{
    aux_exibir_inverso_rec (l -> dados, l -> n);
}

int contar_maiores (lista *l, int chave)
{
    int cont = 0;

    for (int i = 0; i < l -> n; i++)
    {
        if (l -> dados[i].chave > chave)
        {
            cont++;
        }
    }

    return cont;
}

int aux_contar_maiores_rec (tipo_elem *dados, int n, int chave)
{
    if (n <= 0) return 0;

    if (dados[0].chave > chave)
    {
        return 1 + aux_contar_maiores_rec (dados + 1, n - 1, chave);
    }

    return aux_contar_maiores_rec (dados + 1, n - 1, chave);
}

int contar_maiores_rec (lista *l, int chave)
{
    return aux_contar_maiores_rec (l -> dados, l -> n, chave);
}