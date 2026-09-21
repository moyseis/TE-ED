
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Aluno {
    char nome[50];
    int matricula;
    int livrosEmprestados;
    float multa;
};

struct Livro {
    int codigo;
    char titulo[50];
    int disponivel;
};

int main() {

    setlocale(LC_ALL, "Portuguese");

    struct Aluno aluno;
    struct Livro livro;

    int opcao;

    /* Dados do aluno */
    printf("===== SISTEMA DE BIBLIOTECA =====\n");

    printf("\nDigite o nome do aluno: ");
    scanf(" %s[^\n]", aluno.nome);

    printf("Digite a matricula: ");
    scanf("%d", &aluno.matricula);

    aluno.livrosEmprestados = 0;
    aluno.multa = 0;

    /* Dados do livro */
    printf("\n===== CADASTRO DO LIVRO =====\n");

    printf("Digite o codigo do livro: ");
    scanf("%d", &livro.codigo);

    printf("Digite o titulo do livro: ");
    scanf(" %[^\n]", livro.titulo);

    /* 1 = disponível */
    livro.disponivel = 1;

    do {

        printf("\n===== MENU =====\n");
        printf("1 - Realizar emprestimo\n");
        printf("2 - Devolver livro\n");
        printf("3 - Consultar livro\n");
        printf("4 - Consultar aluno\n");
        printf("0 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {

            printf("\n===== EMPRESTIMO =====\n");

            if (livro.disponivel == 0) {

                printf("Livro indisponivel.\n");
                printf("Aluno entrara na fila de espera.\n");

            } else if (aluno.multa > 0) {

                printf("Emprestimo bloqueado!\n");
                printf("O aluno possui multa de R$ %.2f\n", aluno.multa);

            } else if (aluno.livrosEmprestados >= 5) {

                printf("Emprestimo bloqueado!\n");
                printf("O aluno ja possui 5 livros emprestados.\n");

            } else {

                livro.disponivel = 0;
                aluno.livrosEmprestados++;

                printf("Emprestimo realizado com sucesso!\n");
                printf("Livro: %s\n", livro.titulo);
                printf("Aluno: %s\n", aluno.nome);

                printf("Data de devolucao: 30/09/2026\n");
            }

        } else if (opcao == 2) {

            printf("\n===== DEVOLUCAO =====\n");

            if (livro.disponivel == 1) {

                printf("Este livro nao esta emprestado.\n");

            } else {

                livro.disponivel = 1;

                if (aluno.livrosEmprestados > 0) {
                    aluno.livrosEmprestados--;
                }

                printf("Livro devolvido com sucesso!\n");

                /* Exemplo de multa */
                printf("A devolucao teve atraso? (1-Sim / 0-Nao): ");
                int atraso;
                scanf("%d", &atraso);

                if (atraso == 1) {

                    aluno.multa = 5.00;

                    printf("Multa registrada: R$ %.2f\n",
                           aluno.multa);

                } else {

                    printf("Devolucao realizada sem multa.\n");
                }
            }

        } else if (opcao == 3) {

            printf("\n===== CONSULTA DO LIVRO =====\n");

            printf("Codigo: %d\n", livro.codigo);
            printf("Titulo: %s\n", livro.titulo);

            if (livro.disponivel == 1) {
                printf("Situacao: Disponivel\n");
            } else {
                printf("Situacao: Emprestado\n");
            }

        } else if (opcao == 4) {

            printf("\n===== CONSULTA DO ALUNO =====\n");

            printf("Nome: %s\n", aluno.nome);
            printf("Matricula: %d\n", aluno.matricula);
            printf("Livros emprestados: %d\n",
                   aluno.livrosEmprestados);
            printf("Multa: R$ %.2f\n", aluno.multa);

        } else if (opcao == 0) {

            printf("\nSistema encerrado.\n");

        } else {

            printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
