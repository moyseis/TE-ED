
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Portuguese");

    int produto, quantidade;
    int confirmar, pagamento, restaurante;
    float preco, total, valorPago, troco;

    printf("========================================\n");
    printf("          SISTEMA DE DELIVERY\n");
    printf("========================================\n");

    

    printf("\n--- CARDAPIO ---\n");
    printf("1 - Hambúrguer  - R$ 20,00\n");
    printf("2 - Pizza       - R$ 35,00\n");
    printf("3 - Sanduiche   - R$ 15,00\n");
    printf("4 - Refrigerante - R$ 7,00\n");

    printf("\nCliente, escolha um produto: ");
    scanf("%d", &produto);

    if (produto == 1) {
        preco = 20.00;
    }
    else if (produto == 2) {
        preco = 35.00;
    }
    else if (produto == 3) {
        preco = 15.00;
    }
    else if (produto == 4) {
        preco = 7.00;
    }
    else {
        printf("\nProduto inválido!\n");
        return 0;
    }

    printf("Digite a quantidade: ");
    scanf("%d", &quantidade);

    total = preco * quantidade;

    printf("\nValor do pedido: R$ %.2f\n", total);

    

    printf("\nDeseja confirmar o pedido?\n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    printf("Escolha: ");
    scanf("%d", &confirmar);

    if (confirmar == 2) {
        printf("\nPedido cancelado pelo cliente.\n");
        return 0;
    }

    if (confirmar != 1) {
        printf("\nOpção inválida.\n");
        return 0;
    }


    printf("\n--- PAGAMENTO ---\n");
    printf("1 - Cartão\n");
    printf("2 - Pix\n");
    printf("3 - Dinheiro\n");
    printf("Escolha a forma de pagamento: ");
    scanf("%d", &pagamento);

    if (pagamento == 3) {

        printf("Digite o valor pago: R$ ");
        scanf("%f", &valorPago);

        if (valorPago < total) {
            printf("\nFALHA NO PAGAMENTO!\n");
            printf("Valor insuficiente.\n");
            printf("Pedido não será enviado ao restaurante.\n");
            return 0;
        }

        troco = valorPago - total;

        printf("Pagamento aprovado!\n");
        printf("Troco: R$ %.2f\n", troco);
    }
    else if (pagamento == 1 || pagamento == 2) {

        printf("\nPagamento aprovado!\n");

    }
    else {

        printf("\nForma de pagamento inválida.\n");
        printf("Pedido não será enviado.\n");
        return 0;
    }



    printf("\n3 - Sistema enviando pedido ao restaurante...\n");



    printf("\n--- RESTAURANTE ---\n");
    printf("O restaurante aceita o pedido?\n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    printf("Escolha: ");
    scanf("%d", &restaurante);



    if (restaurante == 2) {

        printf("\n4A - RESTAURANTE RECUSOU O PEDIDO.\n");
        printf("Pedido cancelado.\n");

        return 0;
    }

    if (restaurante != 1) {

        printf("\nOpção inválida.\n");
        return 0;
    }

    

    printf("\n4 - Restaurante aceitou o pedido.\n");



    printf("Tempo estimado para preparo: 30 minutos.\n");



    printf("\n5 - Pedido está sendo preparado...\n");
    printf("Pedido pronto!\n");



    printf("\n6 - Entregador recebeu o pedido.\n");
    printf("Entregador está realizando a entrega...\n");



    printf("\n7 - Cliente recebeu o pedido.\n");

    printf("\n========================================\n");
    printf("          PEDIDO FINALIZADO!\n");
    printf("========================================\n");

    return 0;
}
