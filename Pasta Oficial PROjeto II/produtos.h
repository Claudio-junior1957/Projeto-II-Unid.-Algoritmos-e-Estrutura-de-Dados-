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

void menu();
int validarEmail(char *email);
void cadastrarusuario(struct User *usuarios, int *qtd);
void cadastrarproduto();
void listar();
void editarProduto();
void excluirProduto();
void sair();
int login(struct User *usuarios, int qtd);
int compararProdutos(const void *a, const void *b);
int buscaBinaria(struct Produto produtos[], int esquerda, int direita, int codigo);
void buscarProduto();

#endif // PRODUTOS_H

