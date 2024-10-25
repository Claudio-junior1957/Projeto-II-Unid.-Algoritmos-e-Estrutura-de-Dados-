#include <stdio.h>
#include <locale.h>
#include "produtos.h"

// representar nó de usuário
struct NoUsuario {
    User usuario;
    struct NoUsuario *prox;
};

// representar lista de usuários
struct ListaUsuarios {
    struct NoUsuario *inicio;
};

int main() {
    setlocale(LC_ALL, "");
    struct ListaUsuarios usuarios;
    usuarios.inicio = NULL; // inicializar lista de usuários vazia
    int op;
    int logado = 0;

    printf("Bem-vindo ao Sistema de Cadastro de Produtos da Reudis Tecnology!\n");
    printf("Antes de prosseguir, por favor, faça o seu cadastro.\n");

    cadastrarusuario(&usuarios);

    while (!logado) {
        logado = login(&usuarios);
    }

    do {
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                cadastrarproduto();
                break;
            case 2:
                listar();
                break;
            case 3:
                editarProduto();
                break;
            case 4:
                excluirProduto();
                break;
            case 5:
                buscarProduto();
                break;
            case 0:
                sair();
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(op != 0);

    return 0;
}
