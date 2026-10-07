#include "lista.h"

void ler_dados (tipo_elem *v)
{
    printf ("Digite a chave: ");
    scanf ("%d", &v -> chave);

    printf ("Digite o nome: ");
    scanf (" %[^\n]", v -> nome);
}

int main () 
{
    lista l;
    tipo_elem v;
    int op;
    int chave; 

    iniciar(&l);

    do 
    {
        printf ("\n+++++ Menu +++++\n");
        printf ("1 - Verificar se a lista esta vazia\n");
        printf ("2 - Inserir no inicio\n");
        printf ("3 - Inserir no final\n");
        printf ("4 - Inserir de forma ordenada\n");
        printf ("5 - Remover do inicio\n");
        printf ("6 - Remover do final\n");
        printf ("7 - Remover por chave\n");
        printf ("8 - Buscar elemento\n");
        printf ("9 - Buscar elemento recursivamente\n");
        printf ("10 - Exibir lista\n");
        printf ("11 - Exibir lista recursivamente\n");
        printf ("12 - Exibir lista em ordem inversa\n");
        printf ("13 - Informar tamanho\n");
        printf ("14 - Informar tamanho recursivamente\n");
        printf ("15 - Contar maiores\n");
        printf ("16 - Contar maiores recursivamente\n");
        printf ("17 - Destruir lista\n");
        printf ("0 - Sair\n");

        printf ("\n> ");
        scanf ("%d", &op);

        switch (op)
        {
            case 1:
                if (vazia(&l))
                    printf ("Lista vazia\n");
                else
                    printf ("Lista possui elementos\n");
                break;

            case 2:
                ler_dados(&v);
                if (inserir_inicio(&l, v))
                    printf ("Elemento inserido\n");
                else
                    printf ("Erro: Lista esta cheia\n");
                break;

            case 3:
                ler_dados(&v);
                if (inserir_final(&l, v))
                    printf ("Elemento inserido\n");
                else
                    printf ("Erro: Lista esta cheia\n");
                break;

            case 4:
                ler_dados(&v);
                if (inserir_ord(&l, v))
                    printf ("Elemento inserido\n");
                else
                    printf ("Erro: Lista esta cheia\n");
                break;

            case 5:
                if (remover_inicio(&l))
                    printf ("Elemento removido\n");
                else
                    printf ("Erro: Lista esta vazia\n");
                break;
            case 6:
                if (remover_final(&l))
                    printf ("Elemento removido\n");
                else
                    printf ("Erro: Lista esta vazia\n");
                break;

            case 7:
                printf ("Digite a chave a ser removida");
                printf ("\n> ");
                scanf ("%d", &chave);
                if (remover(&l, chave))
                    printf ("\nElemento removido\n");
                else
                    printf ("Erro: Elemento nao encontrado\n");
                break;

            case 8:
                printf ("------ Busca normal ------\n");
                printf ("Digite a chave a ser buscada");
                printf ("\n> ");
                scanf ("%d", &chave);

                if (buscar(&l, chave, &v))
                    printf ("\nElemento encontrado: \nChave: %d | Nome: %s \n", v.chave, v.nome);
                else
                    printf ("Erro: elemento nao encontrado\n");
                break;
                    
            case 9:
                printf ("------ Busca por recursão ------\n");
                printf ("Digite a chave a ser buscada");
                printf ("\n> ");

                if (buscar_rec(&l, l.n, chave, &v))
                    printf ("\nElemento encontrado: \nChave: %d | Nome: %s\n", v.chave, v.nome);
                else
                    printf ("Erro: Elemento nao encontrado\n");
                break;

            case 10:
                printf ("------ Exibir normal------\n");
                exibir(&l);
                break;

            case 11:
                printf ("------ Exibir recursivo ------\n");
                exibir_rec(&l);
                break;

            case 12:
                printf ("------ Exibir inverso ------\n");
                exibir_inverso_rec(&l);
                break;

            case 13:
                printf ("------ Tamanho normal ------\n");
                printf ("> %d\n", tamanho(&l));
                break;

            case 14:
                printf ("------ Tamanho recursivo ------\n");
                printf ("> %d", tamanho_rec(&l));
                break;

            case 15:
                printf ("------ Contagem de maiores normal ------\n");
                printf ("Digite a chave");
                printf ("\n> ");
                scanf ("%d", &chave);

                printf ("\nQuantidade de elementos maiores que %d\n", chave);
                printf ("> %d", contar_maiores(&l, chave));

                break;
            case 16:
                printf ("------ Contagem de maiores recursivamente ------\n");
                printf ("Digite a chave");
                printf ("\n> ");
                scanf ("%d", &chave);
                    
                printf ("\nQuantidade de elementos maiores que %d\n", chave);
                printf ("> %d", contar_maiores_rec(&l, chave));

                break;
            case 17:
                destruir(&l);
                printf ("Lista destruida\n");
                break;

            case 0:
                printf ("Encerrado\n");
                break;

            default:
                printf ("opcao invalida\n");
        }

    } while (op != 0);
    destruir(&l);

    return 0;
}