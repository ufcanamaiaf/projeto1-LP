#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void d6(){
    srand(time(NULL));
    int d6 = (rand() % 6) + 1;
    int res;
}

/*

int turno(){
}

void luta(){
}

typedef struct agente(){
    int vida = 20;
    int dano = 2;
    // int def = 4;
}

typedef struct arma(){
    int dano = 3;
}

typedef struct zumbi de sangue() {
    int dano = 4;
    int vida = 18;
    // int def = 0;
}*/

void delay(int seconds){
    sleep(seconds);
}

// nessa funcao, para colocar um intervalo de tempo em segundos entre a execucao de um texto/funcao e outro, como por exemplo 1 segundo, precisa escrever 'delay(1)'

char* imprimirTracos(){
    char* tracos = "\n----------------------------------------------------------------------\n";
    return tracos;
}

char* imprimirCreditos(){
    char* creditos = "Esse trabalho foi realizado em conjunto por:\n Ana Leticia\nCalebe\nDavi\nKeven\nMarcos\nSannayra\n\nObrigada pela atencao!";
    return creditos;
}

int main(){

    printf("\nVoce acorda no meio de uma floresta.\nEsta frio. Nao sabe ha quanto tempo esta ali nem como chegou aquele lugar.\n");
    printf("\nAo verificar seus bolsos, encontra alguns objetos:\n");

    printf("%s\n", imprimirTracos());

    // INICIO DAS DECISOES: VER ITENS

    int decisao1 = 0;

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
            printf("\nVoce encontrou a sua arma.\n");
            printf("Uma pistola de acabamento escuro e metal polido, com detalhes discretos no cabo.\n");
            printf("Mesmo sob a pouca luz, ela parece bem conservada e transmite uma sensacao de confianca.\n\n");

            delay(3);
            printf("%s\n", imprimirTracos());

        } else if(decisao1 == 2){
            // ver radio
            printf("\nVoce encontrou um radio antigo.\n");
            printf("Apesar de estar bastante desgastado, ele ainda parece funcionar.\n");
            printf("Ao tentar sintoniza-lo, voce escuta uma voz distante...\n\n");

            delay(3);
            printf("- Agente... se estiver ouvindo isso, nao entre na casa.");
            delay(2);
            printf("\n - Voce entendeu? NAO ENTRE NA-\n");
            delay(1);
            printf("O radio corta, e voce nao ouve mais nada.");

            delay(3);
            printf("%s\n", imprimirTracos());

        } else if(decisao1 == 3){
            // ver simbolo
            printf("\nVoce encontrou um simbolo da ordem.\n");
            printf("O desenho parece ter sido feito cuidadosamente em um pedaco de metal.\n");
            printf("Voce nao reconhece o simbolo, mas sente que ele pode estar relacionado ao lugar.\n\n");
            
            delay(3);
            printf("%s\n", imprimirTracos());

        } else if(decisao1 == 4){
            // ver fotografia
            printf("\nVoce encontrou uma fotografia antiga.\n");
            printf("A imagem mostra algumas pessoas reunidas em frente a uma casa.\n\n");
            printf("Voce nota que um dos rostos esta rasgado, como se alguem tivesse usado uma faca para apagar alguem da foto.\n");
            printf("No verso, ha uma data quase apagada e uma pequena anotacao:\n\n");

            delay(3);
            printf("\"Nao deixe que ela saia...\"\n\n");

            delay(3);
            printf("%s\n", imprimirTracos());

        } else if(decisao1 == 5){
            // ver lanterna
            printf("\nVoce encontrou uma lanterna.\n");
            printf("Ela esta velha e coberta de sujeira, mas ainda possui algumas pilhas.\n");
            printf("Talvez ela seja util para explorar as partes mais escuras da floresta.\n\n");
            
            delay(3);
            printf("%s\n", imprimirTracos());

        } else if(decisao1 == 6){
            // o while vai terminar

            printf("%s\n", imprimirTracos());
        } else {
            printf("\nOpcao invalida. Escolha um valor entre 1 e 6.\n\n");
            delay(2);
        }

    }

    // 1a ACAO: ENTRAR NA CASA OU FUGIR?

    printf("Na sua frente, ha uma grande casa abandonada.\n");
    printf("Voce se lembra bem disso: e agora que a sua missao comeca.\n");
    delay(2);

    int decisao2 = 0;
    while (decisao2 < 1 || decisao2 > 3){
        printf("1- Abandonar a floresta\n");
        printf("2- Analisar o perimetro\n");
        printf("3- Entrar na casa\n");

        printf("\nEscolha: ");
        scanf("%d", &decisao2);

        if(decisao2 == 1){
            // ABANDONAR A FLORESTA
            printf("\nVoce decide ignorar a casa e seguir pela floresta.\n");
            printf("Talvez continuar andando seja a melhor maneira de encontrar uma saida.\n\n");
            delay(2);

            printf("Voce caminha por alguns minutos, depois por horas.\n");
            printf("As arvores parecem ficar cada vez mais densas, e a luz do sol desaparece entre as copas.\n\n");
            delay(2);

            printf("Depois de algum tempo, algo chama sua atencao.\n");
            printf("Aquela arvore... voce ja passou por ela antes.\n\n");
            delay(2);

            printf("Voce continua andando, mas a sensacao permanece.\n");
            printf("Nao importa qual caminho escolha, a floresta parece sempre leva-lo para o mesmo lugar.\n\n");
            delay(2);

            printf("Apos mais algum tempo, voce percebe marcas escuras nos troncos das arvores.\n");
            printf("Ao se aproximar, percebe que sao marcas de sangue.\n\n");
            delay(2);

            printf("Poucos metros adiante, ha uma mochila abandonada no chao.\n");
            printf("Pela aparencia, ela parece pertencer a equipe que esteve aqui antes de voce.\n\n");
            delay(2);

            printf("Dentro da mochila, voce encontra alguns documentos e registros.\n");
            printf("Um deles chama sua atencao.\n\n");
            delay(2);

            printf("\"A entidade nao esta presa na casa.\"\n\n");
            delay(2);

            printf("Voce mal consegue terminar de ler.\n");
            printf("Um barulho vem de dentro da floresta...\n\n");

            delay(5);

            printf("Galhos quebram. Folhas se movimentam.\n");
            printf("Voce se vira lentamente na direcao do som.\n\n");
            delay(2);

            printf("Uma criatura coberta de sangue surge entre as arvores. Voce ja lutou com algo parecido...\n");
            printf("Um Zumbi de Sangue.\n");
            printf("Ela permanece parada por alguns segundos, olhando diretamente para voce.\n\n");
            delay(4);

            printf("Essa e a sua primeira batalha...\n\n");
            delay(2);

            printf("%s\n", imprimirTracos());

            int decisao2a = 0;

            // 1.1: LUTAR OU FUGIR
            while (decisao2a < 1 || decisao2a > 2){
                printf("1- Lutar\n");
	            printf("2- Fugir\n");
	            printf("\nEscolha: ");
	
	            scanf("%d", &decisao2a);
	
	            if(decisao2a == 1){
	                // LUTAR COM O ZUMBI 
	                printf("Voce luta e vence");
	                delay(2);
	                decisao2 = 3;
	
	                printf("%s\n", imprimirTracos());
	
	            } else if(decisao2a == 2){
	                // FUGIR E MORRER
	                printf("Desesperado e com medo, voce faz de tudo para fugir da criatura\n");
	                printf("Voce tenta retornar a casa, mas a floresta fica cada vez mais sufocante.\n\n");
	
	                delay(2);
	
	                printf("E tarde demais, voce deixou tudo para tras. Sua casa, sua familia, e voce sabe o que vai acontecer.\n");
	                printf("Voce vai morrer aqui\n\n");
	                delay(3);
	
	                printf("O seu radio comeca a transmitir uma voz angelical, doce e sutil\n");
	                printf("E uma crianca, e ela te diz:\n");
	
	                delay(4);
	                printf("- Voce nao deveria ter vindo.\n\n");
	                delay(2);
	
	                printf("As arvores voltam a mexer violentamente atras de voce, voce percebe que nao esta mais sozinho. \n");
	                printf("Assim como voce percebeu que o caminho que escolheu no inicio acabou de leva-lo a morte.\n\n");
	                delay(5);
	
	                printf("O Zumbi de Sangue te alcanca.\n\n");
	                delay(2);
	
	                printf("Voce esta morto, agente.");
	
	                printf("%s\n", imprimirTracos());
	
	                delay(5);
	            } else {
	                printf("\nOpcao invalida. Escolha um valor entre 1 e 2\n");
	            }
	        }
        }

        else if(decisao2 == 2){
            // ANALISAR O PERIMETRO
            printf("Ao olhar ao redor da casa voce percebe marcas no chao, simbolos estranhos gravados nas arvores, restos de velas, e...\n");
			printf("pequenas pegadas, provavelmente de uma crianca;\n");
			printf("Voce segue andando em direcao ao que parece ser os fundos da casa, la ha uma porta e perto dela uma janela quebrada.\n\n");
			
			printf("Perto da janela tem uma caixa velha de madeira enterrada ate a metade.\n");
			printf("Ao abri-la voce acha um medalhao e um papel manchado.\n");
			printf("Voce pega o medalhao primeiro, nele ha uma foto de uma garota pequena e na parte de tras esta gravado \"Livia - 8 anos\"\n");
			printf("Voce solta o medalhao e pega o papel, nele esta escrito \"Ela nao nasceu assim\", as letras fundas no papel manchado.\n");
			
			printf("%s\n", imprimirTracos());
			
			int decisao2b;
			
			while (decisao2b < 1 || decisao2b > 4) {
				
				printf("\nQual sera seu proximo passo?\n");
				printf("1- Entrar pela porta da frente\n");
				printf("2- Entrar pela porta dos fundos\n");
				printf("3- Continuar investigando os arredores da casa\n");
				printf("4- Ir embora\n");
			
				printf("\nEscolha: ");
	    		scanf("%d", &decisao2b);
	    	
	    		if (decisao2b == 1){
				//ENTRAR PELA PORTA DA FRENTE	
	    			decisao2 = 3;
	    			break;
	    			
				} else if (decisao2b == 2){
				//ENTRAR PELA PORTA DOS FUNDOS	
					printf("Voce entra pela porta dos fundos. Perto da porta, encontra marcas de sangue seco no chao e um pedaco de tecido preso em uma lasca da madeira.\n");
					printf("Ao pega-lo, percebe que e parte do uniforme de um agente da Ordem.\n");
					printf("Junto do tecido ha um pequeno bilhete: \"Nao confie no que ela parece ser.\". Voce guarda o bilhete e continua andando pela casa.\n");
					
					decisao2 = 3;
					break;
					
				} else if (decisao2b == 3){
				//CONTINUAR INVESTIGANDO
					printf("Ao se distanciar um pouco da casa, voce ve uma arvore seca, o que parece estranho comparado a grande mata verde e densa da floresta.\n");
					printf("Voce caminha ate a arvore seca, chegando mais perto voce percebe que ha marcas estranhas entalhadas na arvore, iguais as que tem perto da casa.\n");
					printf("Perto da arvore tem uma pequena mesa de madeira, ela parece estar la ha bastante tempo, esta velha e com a madeira rachada, em cima dela ha algumas velas velhas, alguns pedacos de vidro e uma velha fotografia.\n");
					printf("Na fotografia, tem a menina da foto anterior, Livia, ela aparece sorridente ao lado de um homem e uma mulher bem parecidos com ela, seus pais.\n");
					printf("Atras da foto esta escrito: \"O ritual comecou na noite em que Livia se foi\".");
					printf("Voce volta para a casa e decide entrar nela.\n\n");
				
					printf("%s\n", imprimirTracos());
				
					decisao2 = 3;
					break;
						
				} else if (decisao2b == 4){
				//IR EMBORA
					printf("Você tenta sair da floresta, começa a correr, mas o radio irrompe o silencio.\n");
					printf("... \"Voce sabe o que aconteceu aqui. Nao pode simplesmente ir embora.\" ...\n");
					printf("Mesmo assim, voce continuar correndo e tentando achar uma saída, mas depois de algum tempo percebe que sempre retorna para o mesmo lugar: em frente a casa abandonada.\n");
					printf("Juntando toda a sua coragem, voce decide entao entrar na casa.\n");
					
					printf("%s\n", imprimirTracos());
					
					decisao2 = 3;
					break;
					
				} else {
					printf("Decisao invalida! Escolha um valor entre 1 e 4\n");
				}
			}
		} else if (decisao2 == 3){
			break;
		}else {
        printf("\nOpcao invalida. Escolha um valor entre 1 e 3\n");	
		}
    }

    if(decisao2 == 3){
        // ENTRAR NA CASA
        
        printf("Voce abre a porta da casa e observa que ela esta completamente escura.\n");
        printf("Ha moveis antigos, fotografias na parede e brinquedos espalhados pelo chao\n");
        printf("No corredor da casa uma das fotografias se destaca, nela contem uma familia: pai, mae e filha.\n");
        printf("Voce escuta um barulho de algo correndo no andar de cima!\n");
        printf("Logo depois, escuta uma forte batida!\n");
        printf("Um silencio ensurdecedor toma conta da casa...\n");
        printf("Entao uma voz diz:...\n");
        printf("\"Voce demorou.\"\n");
        printf("Voce sobe as escadas e no final do corredor tem uma menina parada contra a parede, vestindo um vestido branco e sujo.\n");
        
        int decisao3 = 0;
        
        while (decisao3 < 1 || decisao3 > 3 ){
        	
        	printf("1- Perguntar quem ela e.\n");
        	printf("2- Tentar fugir.\n");
        	printf("3- Apontar a arma para ela.\n");
        	
        	printf("\nEscolha: ");
        	scanf("%d", &decisao3);
        	
        	if(decisao3 == 1){
        		//PERGUNTAR QUEM ELA E
        		
        		printf("Voce pergunta qual e o nome da garota.\n");
        		printf("Ela responde:\n");
        		printf("\"O meu nome e Livia.\"\n");
        		printf("A menina permanece parada. Depois de alguns segundos, pergunta:\n");
        		printf("\"Voce veio terminar o trabalho deles?\"\n");
        		printf("Ela olha para o seu simbolo da Ordem no uniforme. Voce nao entende o que ela quer dizer.\n");
        		printf("Voce pergunta: \"Quem sao eles?\"\n");
        		printf("Livia responde apontando para o corredor:\n");
        		printf("\"Os homens que vieram antes de voce, eles tambem fizeram perguntas.\"\n");
        		printf("Voce percebe marcas de sangue espalhadas pelo chao.\n");
        		
        		break;
        	
			} else if(decisao3 == 2){
				//TENTAR FUGIR
				
				printf("Voce desce rapidamente as escadas. A porta da frente esta aberta. \n");
				printf("Voce corre!\n");
				printf("Porem, ao atravessa-la, acaba entrando novamente na casa pela porta dos fundos.\n");
				printf("Voce esta preso.\n");
				printf("A garota aparece por tras e fala:\n");
				printf("\"Por favor nao va!\"\n");
				printf("Ela corre e voce vai atras dela.\n");
				
				break;
			
			}else if(decisao3 == 3){
				//APONTAR A ARMA PARA ELA
				
				printf("Voce aponta a arma para a garota.\n");
				printf("Ela olha para a arma, mas nao demonstra medo.\n");
				printf("E fala: \"foi isso que eles disseram para voce fazer?\"\n");
				printf("Voce precisa decidir.\n");
				
				int decisao3a = 0;
        
        		while (decisao3a < 1 || decisao3a > 2 ){
        	
        			printf("1- Disparar a arma.\n");
        			printf("2- Abaixar a arma.\n");
        	
        			printf("\nEscolha: ");
        			scanf("%d", &decisao3a);
        	
        			if(decisao3a == 1){
        				//DISPARAR A ARMA
        				
        				printf("Voce dispara a arma!\n");
        				printf("A garota desaparece e a casa comeca a tremer. Voce percebe que o tiro nao atingiu ela. \n");
        				printf("Entao, escuta um barulho vindo do porao.");
        				
        				break;
        				
					} else if (decisao3a == 2){
						//ABAIXAR A ARMA
						
						printf("Voce abaixa a arma.\n");
						printf("A garota desaparece pelo corredor.\n");
						
						break;
						
					}else{
				
						printf("\nOpcao invalida. Escolha um valor entre 1 e 2\n");
					}
				}
					
				break;
				
			}else{
				
				printf("\nOpcao invalida. Escolha um valor entre 1 e 3\n");
				
				
			}
		}
        
    }

    return 0;

}
