#ifndef PRODUTOS_H
#define PRODUTOS_H

struct Produto {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
};

struct User {
    char name[30];
    char email[50];
    char pass[10];
};

struct NoProduto {
    struct Produto dado;
    struct NoProduto *prox;
};

struct ListaProduto {
    struct NoProduto *inicio;
};

void inicializarListaProdutos(struct ListaProduto *lista);
void cadastrarproduto(struct ListaProduto *lista);
void listar(struct ListaProduto *lista);
void editarProduto(struct ListaProduto *lista);
void excluirProduto(struct ListaProduto *lista);
void buscarProduto(struct ListaProduto *lista);
void liberarListaProdutos(struct ListaProduto *lista);

void menu();
int validarEmail(char *email);
void cadastrarusuario(struct User *usuarios, int *qtd);
int login(struct User *usuarios, int qtd);
void sair();

#endif // PRODUTOS_H
