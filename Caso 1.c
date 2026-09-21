
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main() {

    char nome[50], esp[50];
    int idade, opc, horario;
    int dia, mes, ano;

    setlocale(LC_ALL, "Portuguese");

    printf("========================================\n");
    printf("     SISTEMA DE AGENDAMENTO CLINICA\n");
    printf("========================================\n\n");

    printf("Digite seu nome completo: ");
    scanf(" %s[^\n]", nome);

    printf("Qual sua idade? ");
    scanf("%d", &idade);

    printf("Qual especialidade deseja consultar? ");
    scanf(" %s[^\n]", esp);

    printf("\nDeseja agendar um horario?\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    printf("Digite uma opcao: ");
    scanf("%d", &opc);

    if (opc == 1) {

        printf("\nDigite a data da consulta:\n");

        printf("Dia: ");
        scanf("%d", &dia);

        printf("Mes: ");
        scanf("%d", &mes);

        printf("Ano: ");
        scanf("%d", &ano);

        printf("\nData escolhida: %02d/%02d/%d\n", dia, mes, ano);

        printf("\n========================================\n");
        printf("         HORARIOS DA CLINICA\n");
        printf("========================================\n");
        printf("1 - 08:00 - 08:30\n");
        printf("2 - 08:30 - 09:00\n");
        printf("3 - 09:00 - 09:30\n");
        printf("4 - 09:30 - 10:00\n");
        printf("5 - 10:00 - 10:30\n");
        printf("6 - 10:30 - 11:00\n");
        printf("7 - 14:00 - 14:30\n");
        printf("8 - 14:30 - 15:00\n");
        printf("9 - 15:00 - 15:30\n");
        printf("10 - 15:30 - 16:00\n");
        printf("========================================\n");

        printf("Escolha um horario: ");
        scanf("%d", &horario);

        if (horario == 1) {

            printf("\n========================================\n");
            printf("       AGENDAMENTO CONFIRMADO!\n");
            printf("========================================\n");
            printf("Paciente: %s\n", nome);
            printf("Idade: %d\n", idade);
            printf("Especialidade: %s\n", esp);
            printf("Data: %02d/%02d/%d\n", dia, mes, ano);
            printf("Horario: 08:00 - 08:30\n");

        } else if (horario == 2) {

            printf("\nAGENDAMENTO CONFIRMADO!\n");
            printf("Paciente: %s\n", nome);
            printf("Especialidade: %s\n", esp);
            printf("Data: %02d/%02d/%d\n", dia, mes, ano);
            printf("Horario: 08:30 - 09:00\n");

        } else if (horario == 3) {

            printf("\nAGENDAMENTO CONFIRMADO!\n");
            printf("Paciente: %s\n", nome);
            printf("Especialidade: %s\n", esp);
            printf("Data: %02d/%02d/%d\n", dia, mes, ano);
            printf("Horario: 09:00 - 09:30\n");

        } else if (horario == 4) {

            printf("\nAGENDAMENTO CONFIRMADO!\n");
            printf("Paciente: %s\n", nome);
            printf("Especialidade: %s\n", esp);
            printf("Data: %02d/%02d/%d\n", dia, mes, ano);
            printf("Horario: 09:30 - 10:00\n");

        } else if (horario == 5) {

            printf("\nAGENDAMENTO CONFIRMADO!\n");
            printf("Paciente: %s\n", nome);
            printf("Especialidade: %s\n", esp);
            printf("Data: %02d/%02d/%d\n", dia, mes, ano);
            printf("Horario: 10:00 - 10:30\n");

        } else if (horario == 6) {

            printf("\nAGENDAMENTO CONFIRMADO!\n");
            printf("Paciente: %s\n", nome);
            printf("Especialidade: %s\n", esp);
            printf("Data: %02d/%02d/%d\n", dia, mes, ano);
            printf("Horario: 10:30 - 11:00\n");

        } else if (horario == 7) {

            printf("\nAGENDAMENTO CONFIRMADO!\n");
            printf("Paciente: %s\n", nome);
            printf("Especialidade: %s\n", esp);
            printf("Data: %02d/%02d/%d\n", dia, mes, ano);
            printf("Horario: 14:00 - 14:30\n");

        } else if (horario == 8) {

            printf("\nAGENDAMENTO CONFIRMADO!\n");
            printf("Paciente: %s\n", nome);
            printf("Especialidade: %s\n", esp);
            printf("Data: %02d/%02d/%d\n", dia, mes, ano);
            printf("Horario: 14:30 - 15:00\n");

        } else if (horario == 9) {

            printf("\nAGENDAMENTO CONFIRMADO!\n");
            printf("Paciente: %s\n", nome);
            printf("Especialidade: %s\n", esp);
            printf("Data: %02d/%02d/%d\n", dia, mes, ano);
            printf("Horario: 15:00 - 15:30\n");

        } else if (horario == 10) {

            printf("\nAGENDAMENTO CONFIRMADO!\n");
            printf("Paciente: %s\n", nome);
            printf("Especialidade: %s\n", esp);
            printf("Data: %02d/%02d/%d\n", dia, mes, ano);
            printf("Horario: 15:30 - 16:00\n");

        } else {

            printf("\nHorario invalido!\n");
            printf("O agendamento foi cancelado.\n");
        }

    } else if (opc == 2) {

        printf("\nAgendamento cancelado.\n");

    } else {

        printf("\nOpcao invalida!\n");
    }

    return 0;
}
