#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

struct NoProduto {
    struct Produto produto;
    struct NoProduto *prox;
};

struct ListaProdutos {
    struct NoProduto *inicio;
};

void inicializarListaProdutos(struct ListaProdutos *lista) {
    lista->inicio = NULL;
}

void cadastrarproduto(struct ListaProdutos *lista) {
    struct NoProduto *novo = (struct NoProduto*) malloc(sizeof(struct NoProduto));
    if (!novo) {
        printf("Erro de alocação de memória.\n");
        return;
    }

    printf("Informe o código do produto: ");
    scanf("%d", &novo->produto.codigo);
    printf("Informe o nome do produto: ");
    scanf(" %[^\n]s", novo->produto.nome);
    printf("Informe o preço do produto: R$ ");
    scanf("%f", &novo->produto.preco);
    printf("Informe a quantidade em estoque: ");
    scanf("%d", &novo->produto.quantidade);
    novo->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        struct NoProduto *temp = lista->inicio;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }

    printf("Produto cadastrado com sucesso!\n");
}

void listar(struct ListaProdutos *lista) {
    struct NoProduto *temp = lista->inicio;
    if (temp == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\n== Produtos Cadastrados ==\n");
    while (temp != NULL) {
        printf("Código: %d\n", temp->produto.codigo);
        printf("Nome: %s\n", temp->produto.nome);
        printf("Preço: R$ %.2f\n", temp->produto.preco);
        printf("Quantidade em estoque: %d\n\n", temp->produto.quantidade);
        temp = temp->prox;
    }
}

void editarProduto(struct ListaProdutos *lista) {
    int codigo;
    printf("Informe o código do produto que deseja editar: ");
    scanf("%d", &codigo);

    struct NoProduto *temp = lista->inicio;
    while (temp != NULL) {
        if (temp->produto.codigo == codigo) {
            printf("Produto encontrado! Informe os novos dados.\n");
            printf("Novo nome: ");
            scanf(" %[^\n]s", temp->produto.nome);
            printf("Novo preço: R$ ");
            scanf("%f", &temp->produto.preco);
            printf("Nova quantidade: ");
            scanf("%d", &temp->produto.quantidade);
            printf("Produto editado com sucesso!\n");
            return;
        }
        temp = temp->prox;
    }

    printf("Produto com código %d não encontrado.\n", codigo);
}

void excluirProduto(struct ListaProdutos *lista) {
    int codigo;
    printf("Informe o código do produto que deseja excluir:\n");
    scanf("%d", &codigo);

    struct NoProduto *temp = lista->inicio, *anterior = NULL;
    while (temp != NULL && temp->produto.codigo != codigo) {
        anterior = temp;
        temp = temp->prox;
    }

    if (temp == NULL) {
        printf("Produto com código %d não encontrado.\n", codigo);
        return;
    }

    if (anterior == NULL) {
        lista->inicio = temp->prox;
    } else {
        anterior->prox = temp->prox;
    }

    free(temp);
    printf("Produto excluído com sucesso!\n");
}

void buscarProduto(struct ListaProdutos *lista) {
    int codigo;
    printf("Informe o código do produto que deseja buscar: ");
    scanf("%d", &codigo);

    struct NoProduto *temp = lista->inicio;
    while (temp != NULL) {
        if (temp->produto.codigo == codigo) {
            printf("Produto encontrado: %s\n", temp->produto.nome);
            printf("Preço: R$ %.2f\n", temp->produto.preco);
            printf("Quantidade: %d\n", temp->produto.quantidade);
            return;
        }
        temp = temp->prox;
    }

    printf("Produto com código %d não encontrado.\n", codigo);
}

void liberarListaProdutos(struct ListaProdutos *lista) {
    struct NoProduto *temp = lista->inicio;
    while (temp != NULL) {
        struct NoProduto *proximo = temp->prox;
        free(temp);
        temp = proximo;
    }
    lista->inicio = NULL;
}
