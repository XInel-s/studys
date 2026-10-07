#include <stdio.h>
#include "lista.h"

void ler_elemento (tipo_elem *v)
{
    printf("\nDigite a chave: "); 
    scanf("%d", &v->chave); 
    
    printf("Digite o nome: "); 
    scanf(" %[^\n]", v->nome); 
}

int main()
{
    int op;
    lista l;
    tipo_elem v;
    int chave;

    iniciar(&l);

    do
    {
        printf("\n1 - Vazia\n");
        printf("2 - Inserir no inicio\n");
        printf("3 - Inserir no final\n");
        printf("4 - Inserir ordenadamente\n");
        printf("5 - Remover do inicio\n");
        printf("6 - Remover do final\n");
        printf("7 - Remover por chave\n");
        printf("8 - Buscar elemento\n");
        printf("9 - Exibir lista\n");
        printf("10 - Exibir lista (rec)\n");
        printf("11 - Exibir lista em ordem inversa (rec)\n");
        printf("12 - Informar tamanho\n");
        printf("13 - Informar tamanho (rec)\n");
        printf("14 - Buscar (rec)\n");
        printf("15 - Contar chaves maiores que X\n");
        printf("16 - Contar chaves maiores que X (rec)\n");
        printf("17 - Destruir lista\n");
        printf("0 - Sair\n");

        printf("> ");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                if (vazia(&l))
                    printf("\nLista esta atualmente vazia!\n");
                else
                    printf("\nLista nao esta vazia!\n");
                break;

            case 2:
                ler_elemento(&v);

                if (inserir_inicio(&l, v))
                    printf("\nElemento Inserido no inicio!\n");
                else
                    printf("Nao foi possivel inserir\n");
                break;

            case 3:
                ler_elemento(&v);

                if (inserir_final(&l, v))
                    printf("\nElemento Inserido no final!\n");
                else
                    printf("Nao foi possivel inserir\n");
                break;

            case 4:
                ler_elemento(&v);

                if (inserir_ord(&l, v))
                    printf("\nElemento Inserido ordenado!\n");
                else
                    printf("Nao foi possivel inserir\n");
                break;

            case 5:
                if (remover_inicio(&l))
                    printf("\nElemento do inicio removido com sucesso!\n");
                else
                    printf("Falha ao remover\n");
                break;

            case 6:
                if (remover_final(&l))
                    printf("\nElemento do final removido com sucesso!\n");
                else
                    printf("Falha ao remover\n");
                break;

            case 7:
                printf("\nChave do elemento que deseja remover: ");
                scanf("%d", &chave);

                if (remover(&l, chave))
                    printf("\nElemento removido com sucesso!\n");
                else
                    printf("\nChave nao encontrada\n");
                break;

            case 8:
                printf("\nChave que deseja buscar: ");
                scanf("%d", &chave);

                if (buscar(&l, chave, &v))
                    printf("\n%d encontrado!\n", v.chave);
                else
                    printf("\nChave nao encontrada na lista\n");
                break;

            case 9:
                printf("\n");
                exibir(&l);
                printf("\n");
                break;

            case 10:
                printf("\n");
                exibir_rec(&l);
                printf("\n");
                break;

            case 11:
                printf("\n");
                exibir_inverso_rec(&l);
                printf("\n");
                break;

            case 12:
                printf("\n%d elemento/os\n", tamanho(&l));
                break;

            case 13:
                printf("\n%d elemento/os\n", tamanho_rec(&l));
                break;

            case 14:
                printf("\nChave que deseja buscar: ");
                scanf("%d", &chave);

                if (buscar_rec(&l, chave, &v))
                    printf("\n%d encontrado\n", v.chave);
                else
                    printf("\nChave nao encontrada na lista\n");
                break;

            case 15:
                printf("\nChave: ");
                scanf("%d", &chave);

                if (buscar(&l, chave, &v))
                    printf("\n%d chaves maiores que %d\n",
                           contar_maiores(&l, chave), chave);
                else
                    printf("\nChave nao encontrada na lista\n");
                break;

            case 16:
                printf("\nChave: ");
                scanf("%d", &chave);

                printf("\n%d chaves maiores que %d\n",
                       contar_maiores_rec(&l, chave), chave);
                break;

            case 17:
                destruir(&l);
                printf("\nLista destruida!\n");
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nValor invalido! Tente novamente\n");
                break;
        }

    } while (op != 0);

    return 0;
}
