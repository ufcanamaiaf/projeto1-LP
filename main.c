#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

void d6(){
    srand(time(NULL));
    int d6 = (rand() % 6) + 1;
    int res;
}

void delay(int seconds){
    sleep(seconds);
}
//nessa função, para colocar um intervalo de tempo em segundos entre a execução de um texto/função e outro, como por exemplo 1 segundo, precisa escrever 'delay(1)'

char* imprimirTracos(){
    char* tracos = "\n----------------------------------------------------------------------\n";
    return tracos;
}

char* imprimirCreditos(){
    char* creditos = "Esse trabalho foi realizado em conjunto por:\n Ana Leticia\nCalebe\nDavi\nKeven\nMarcos\nSannayra\n\nObrigada pela atenção!";
    return creditos;
}

int main(){
    printf("\nVocê acorda no meio de uma floresta.\nEsté frio. Não sabe há quanto tempo está ali nem como chegou aquele lugar.\n");
    printf("\não verificar seus bolsos, encontra alguns objetos:\n");

    printf("%s\n", imprimirTracos());

    // INÍCIO DAS DECISÕES: VER ITENS
    int decisao1;
    while(decisao1 != 6){

    printf("1- Ver arma\n");
    printf("2- Ver rádio\n");
    printf("3- Ver símbolo da ordem\n");
    printf("4- Ver fotografia\n");
    printf("5- Ver lanterna\n");
    printf("6- Proxima ação\n");

    printf("\nEscolha: ");
    scanf("%d", &decisao1);

    if(decisao1 == 1){
        // ver arma
        printf("\nVocê encontrou a sua arma.\n");
        delay(1);
        printf("Uma pistola de acabamento escuro e metal polido, com detalhes discretos no cabo.\n");
        printf("Mesmo sob a pouca luz, ela parece bem conservada e transmite uma sensacão de confiança.\n\n");
        delay(5);

        printf("%s\n", imprimirTracos());

    } else if(decisao1 == 2){
        // ver radio
        printf("\nVocê encontrou um rádio antigo.\n");
        delay(1);
        printf("Apesar de estar bastante desgastado, ele ainda parece funcionar.\n");
        printf("Ao tentar sintonizá-lo, voce escuta uma voz distante...\n\n");
        delay(4);
        printf("- Agente... se estiver ouvindo isso, não entre na casa.");
        delay(2);
        printf("\n - Você entendeu? NÃO ENTRE NA-\n");
        delay(1);
        printf("O radio corta, e você não ouve mais nada.");
        delay(3);

        printf("%s\n", imprimirTracos());

    } else if(decisao1 == 3){
        // ver simbolo
        printf("\nVocê encontrou um símbolo da ordem.\n");
        delay(2);
        printf("O desenho parece ter sido feito cuidadosamente em um pedaço de metal.\n");
        printf("Você não reconhece o símbolo, mas sente que ele pode estar relacionado ao lugar.\n\n");
        delay(5);

        printf("%s\n", imprimirTracos());

    } else if(decisao1 == 4){
        // ver fotografia
        printf("\nVocê encontrou uma fotografia antiga.\n");
        printf("A imagem mostra algumas pessoas reunidas em frente a uma casa.\n\n");
        delay(5);

        printf("Voce nota que um dos rostos esta rasgado, como se alguém tivesse usado uma faca para apagar alguém da foto.\n");
        printf("No verso, há uma data quase apagada e uma pequena anotação:\n\n");
        delay(6);
        printf("\"Não deixe que ela saia...\"\n\n");
        delay(2);

        printf("%s\n", imprimirTracos());

    } else if(decisao1 == 5){
        // ver lanterna
        printf("\nVocê encontrou uma lanterna.\n");
        delay(3);
        printf("Ela está velha e coberta de sujeira, mas ainda possui algumas pilhas.\n");
        printf("Talvez ela seja útil para explorar as partes mais escuras da floresta.\n\n");
        delay(5);

        printf("%s\n", imprimirTracos());


    } else if(decisao1 == 6){
        // o while vai terminar
        printf("%s\n", imprimirTracos());
    } else {
        printf("\nOpção inválida. Escolha um valor entre 1 e 6.\n\n");
        delay(3);
    }
}

    // 1ª ACAO: ENTRAR NA CASA OU FUGIR?
    printf("Na sua frente, há uma grande casa abandonada.\n");
    printf("Voce se lembra bem disso: e agora que a sua missão começa.\n");
    delay(4);
    int decisao2;

    printf("1- Abandonar a floresta\n");
    printf("2- Analisar o perímetro\n");
    printf("3- Entrar na casa\n");

    printf("\nEscolha: ");
    scanf("%d", &decisao2);

    if(decisao2 == 1){
        // ABANDONAR A FLORESTA
        printf("\nVocê decide ignorar a casa e seguir pela floresta.\n");
        printf("Talvez continuar andando seja a melhor maneira de encontrar uma saida.\n\n");
        delay(5);

        printf("Você caminha por alguns minutos, depois por horas.\n");
        printf("As árvores parecem ficar cada vez mais densas, e a luz do sol desaparece entre as copas.\n\n");
        delay(5);

        printf("Depois de algum tempo, algo chama sua atenção.\n");
        printf("Aquela árvore... voce já passou por ela antes.\n\n");
        delay(4);

        printf("Você continua andando, mas a sensação permanece.\n");
        printf("Nao importa qual caminho escolha, a floresta parece sempre levá-lo para o mesmo lugar.\n\n");
        delay(6);

        printf("Após mais algum tempo, você percebe marcas escuras nos troncos das árvores.\n");
        printf("Ao se aproximar, percebe que são marcas de sangue.\n\n");
        delay(5);

        printf("Poucos metros adiante, há uma mochila abandonada no chão.\n");
        printf("Pela aparência, ela parece pertencer a equipe que esteve aqui antes de voce.\n\n");
        delay(5);

        printf("Dentro da mochila, você encontra alguns documentos e registros.\n");
        printf("Um deles chama sua atencão.\n\n");
        delay(5);

        printf("\"A entidade não está presa na casa.\"\n\n");
        delay(3);

        printf("Voce mal consegue terminar de ler.\n");
        printf("Um barulho vem de dentro da floresta.\n\n");
        delay(4);

        printf("Galhos quebram. Folhas se movimentam.\n");
        printf("Você se vira lentamente na direção do som.\n\n");
        delay(4);

        printf("Uma criatura coberta de sangue surge entre as árvores. Você já lutou com algo parecido...\n");
        printf("Um Zumbi de Sangue.\n");
        printf("Ela permanece parada por alguns segundos, olhando diretamente para você.\n\n");
        delay(7);

        printf("Essa é a sua primeira batalha...\n\n");
        delay(3);

        printf("%s\n", imprimirTracos());

        int decisao2a;

        // 1.1: LUTAR OU FUGIR
        printf("1- Lutar\n");
        printf("2- Fugir\n");

        printf("\nEscolha: ");
        scanf("%d", &decisao2a);

        if(decisao2a == 1){
            // LUTAR COM O ZUMBI (fazer sistema de luta)

            printf("Voce luta e vence");
            delay(2);

            printf("%s\n", imprimirTracos());

        } else if(decisao2a == 2){
            // FUGIR E MORRER
            printf("Desesperado e com medo, voce faz de tudo para fugir da criatura\n");
            printf("Voce tenta retornar a casa, mas a floresta fica cada vez mais sufocante.\n\n");
            delay(7);

            printf("E tarde demais, voce deixou tudo para tras. Sua casa, sua familia, e voce sabe o que vai acontecer.\n");
            printf("Voce vai morrer aqui\n\n");
            delay(7);

            printf("O seu rádio comeca a transmitir uma voz angelical, doce e sutil\n");
            printf("E uma crianca, e ela te diz:\n");
            delay(5);

            printf("- Voce nao deveria ter vindo.\n\n");
            delay(2);

            printf("As arvores voltam a mexer violentamente atrás de você, você percebe que não está mais sozinho. \n");
            printf("Assim como você percebeu que o caminho que escolheu no ínicio acabou de levá-lo a morte.\n\n");
            delay(7);

            printf("O Zumbi de Sangue te alcanca.");
            delay(2);

            printf("%s\n", imprimirTracos());


        } else {
            printf("\nOpção inválida. Escolha um valor entre 1 e 2\n");
            delay(3);
        }

    } else if(decisao2 == 2){
        // ANALISAR O PERIMETRO

    } else if(decisao2 == 3){
        // ENTRAR NA CASA

    } else {
        printf("\nOpção inválida. Escolha um valor entre 1 e 3\n");
    }

    return 0;
}
