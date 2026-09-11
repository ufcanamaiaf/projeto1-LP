#include<stdio.h>
#include<stdlib.h>

char* imprimirTracos(){
    char* tracos = "\n----------------------------------------------------------------------\n";
    return tracos;
}

int main(){
    printf("\nVoce acorda no meio de uma floresta.\nEsta frio. Nao sabe ha quanto tempo esta ali nem como chegou aquele lugar.\n");
    printf("\nAo verificar seus bolsos, encontra alguns objetos:\n");

    printf("%s\n", imprimirTracos());

    // INÍCIO DAS DECISÕES: VER ITENS 
    int decisao1;
    while(decisao1 != 6){

    printf("1- Ver arma\n");
    printf("2- Ver radio\n");
    printf("3- Ver simbolo da ordem\n");
    printf("4- Ver fotografia\n");
    printf("5- Ver lanterna\n");
    printf("6- Proxima acao\n");

    printf("\nEscolha: ");
    scanf("%d", &decisao1);

    if(decisao1 == 1){
        // ver arma
        printf("\nVoce encontrou uma arma...\n\n");

    } else if(decisao1 == 2){
        // ver radio
        printf("\nVoce encontrou um radio...\n\n");

    } else if(decisao1 == 3){
        // ver simbolo
        printf("\nVoce encontrou um simbolo da ordem...\n\n");

    } else if(decisao1 == 4){
        // ver fotografia
        printf("\nVoce encontrou uma fotografia antiga...\n\n");

    } else if(decisao1 == 5){
        // ver lanterna
        printf("\nVoce encontrou uma lanterna...\n\n");

    } else if(decisao1 == 6){
        // o while vai terminar
        printf("%s\n", imprimirTracos());
    } else {
        printf("\nOpcao invalida. Escolha um valor entre 1 e 6.\n\n");
    }
}

    // 1ª ACAO: ENTRAR NA CASA OU FUGIR?
    printf("Na sua frente, ha uma grande casa abandonada.\n");
    printf("Voce se lembra bem disso: e agora que a sua missao comeca.\n");

    int decisao2;

    printf("1- Abandonar a floresta\n");
    printf("2- Analisar o perimetro\n");
    printf("3- Entrar na casa\n");

    printf("\nEscolha: ");
    scanf("%d", &decisao2);

    if(decisao2 == 1){
        // ABANDONAR A FLORESTA

    } else if(decisao2 == 2){
        // ANALISAR O PERIMETRO

    } else if(decisao2 == 3){
        // ENTRAR NA CASA

    } else {
        printf("\nOpcao invalida. Escolha um valor entre 1 e 3\n");
    }

    return 0;
}