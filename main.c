#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int d6(){
    return (rand() % 6) + 1;
}

void delay(int seconds){
    sleep(seconds);
}
// nessa funcao, para colocar um intervalo de tempo em segundos entre a execucao de um texto/funcao e outro, como por exemplo 1 segundo, precisa escrever 'delay(1)'

char* imprimirTracos(){
    char* tracos = "\n----------------------------------------------------------------------\n";
    return tracos;
}

char* imprimirCreditos(){
    char* creditos = "Esse trabalho foi realizado em conjunto por:\nAna Leticia\nCalebe\nDavi\nKeven\nMarcos\nSannayra\n\nObrigada pela atencao!";
    return creditos;
}
typedef struct{
    char* nome;
    int dano;
    int municao;
}Arma;


typedef struct{

    int vigor;
    int forca;
    int agilidade;
    int intelecto;
    int pv_total;
    int pv;
    int sanidade;
    int armadura;
    Arma armas;

}Agente;


typedef struct{
    char* nome;
    int resistencia_dano;
    int pv;
    int pv_total;
    int dano;
}Monstro;

int girar_teste(){
    printf("\nGirando dado...\n");
    delay(3);
    int dado = d6();
    printf("Seu dado resultou em %d\n", dado);
    delay(2);
    return dado;
}

//TURNO DO MONSTRO
void ataquemonstro(Agente *ag, Monstro *mo, int dano_recebido, int num_luta, int tatica, int reduz_dano_ag){
    if(mo->pv > 0){
        if(num_luta == 1){
        if ((dano_recebido >= 12 && mo->resistencia_dano > 0) || (dano_recebido < 12 && mo->resistencia_dano <= 0) || (dano_recebido < 12 && mo->resistencia_dano > 0)) {
            int dado_mo = d6();
            int dano_bruto_mo = dado_mo + mo->dano - reduz_dano_ag;
            int dano_sofrido = dano_bruto_mo - ag->armadura;
            ag->armadura--;

            if (dano_sofrido < 0) dano_sofrido = 0;

            ag->pv -= dano_sofrido;

            printf("\nO %s avanca e desfere um golpe.\n", mo->nome);
            printf("Voce recebe %d de dano.\n\n", dano_sofrido);
            delay(3);
        }
        else if(dano_recebido >= 12 && mo->resistencia_dano <= 0){
            printf("Criatura esta desnorteada por esse turno\n\n");
            delay(2);
        }
    }
    }
    else{
        printf("Criatura está incapacitada de se mover\n");
        delay(2);
    }
}

// TURNO DO AGENTE
void luta(Agente *ag, Monstro *mo, int tatica,int num_luta, int fraqueza){
    int dano_bruto_ag;
    int dado;
    int dano_rest;
    int reduz_dano_ag;
    if(num_luta == 1){
        //ATIRAR
        if (tatica == 1){
            if(ag->armas.municao > 0){
                dado = girar_teste();
                ag->armas.municao--;
                dano_bruto_ag = dado + ag->armas.dano;
                delay(2);

                if(dano_bruto_ag <= 8){
                    if(mo->resistencia_dano > 0){
                        mo->pv -= 1;
                        mo->resistencia_dano -= dano_bruto_ag;
                        printf("Voce causou 1 de dano a criatura, foi um dano muito superficial\n\n");
                        if(mo->resistencia_dano < 0){
                            mo->resistencia_dano = 0;
                        }
                    }else{
                        mo->pv = mo->pv - dano_bruto_ag;
                        printf("Voce causou %d de dano a criatura, embora superficial, parece ter causado efeito\n\n", dano_bruto_ag);
                    }
                    delay(3);
                    ataquemonstro(ag,mo,dano_bruto_ag,num_luta,tatica,reduz_dano_ag = 0);
                }

                else if(dano_bruto_ag == 9 || dano_bruto_ag == 10){
                    if(mo->resistencia_dano > 0){
                        mo->pv -= 2;
                        mo->resistencia_dano -= dano_bruto_ag;
                        printf("Voce causou 2 de dano na regiao do torax da criatura. \n\n");
                        if(mo->resistencia_dano < 0){
                            mo->resistencia_dano = 0;
                        }
                    }else{
                        mo->pv = mo->pv - dano_bruto_ag;
                        printf("Voce causou %d de dano a criatura, parece ter causado efeito\n\n", dano_bruto_ag);
                    }
                    delay(3);
                    ataquemonstro(ag,mo,dano_bruto_ag,num_luta,tatica,reduz_dano_ag = 0);
                }

                else if(dano_bruto_ag == 11 || dano_bruto_ag == 12){
                    if(mo->resistencia_dano > 0){
                        mo->pv -= 3;
                        mo->resistencia_dano -= dano_bruto_ag;
                    printf("Voce acerta 3 de dano na criatura, sua resistencia parece ter sido bastante afetada\n\n");
                    if(mo->resistencia_dano < 0){
                            mo->resistencia_dano = 0;
                    }
                    }else{
                        mo->pv = mo->pv - dano_bruto_ag;
                        printf("Voce causou %d de dano a criatura,parece ter nocauteado a criatura mas logo se reergue\n\n", dano_bruto_ag);
                    }
                    delay(3);
                    ataquemonstro(ag,mo,dano_bruto_ag,num_luta,tatica,reduz_dano_ag = 0);
                    }
                }else{
                    printf("\n*CLIC!* Voce tenta disparar, mas a pistola esta sem municao.\n\n");
                    delay(3);
            }
        }

        //PROCURAR POR OBJETO
        else if (tatica == 2){
            printf("Voce desesperadamente procura por algo que ajude a lidar com o zumbi a sua frente\n\n");
            delay(3);
            dado = girar_teste();

            if (dado >= 1 && dado <= 3){
                printf("Voce nao encontra nada que te ajude e a criatura avança\n\n");
                delay(3);
                printf("Tera de fazer um teste para se esquivar da criatura\n\n");
                delay(3);
                dado = girar_teste();
                if(dado >= 1 && dado <= 3){
                    reduz_dano_ag=1;
                    printf("Voce nao consegue se mover direito devido ao nevorsismo, e a criatura avança para cima\n\n");
                }
                else if(dado>=5 && dado<=6){
                    reduz_dano_ag = 5;
                    printf("Voce conseguiu se esquivar bem da criatura embora ainda tenha se machucado\n\n");
                }
                delay(3);
                ataquemonstro(ag,mo,dano_bruto_ag = 0,num_luta,tatica,reduz_dano_ag);
            }

            else if(dado >= 4 && dado <= 5){
                printf("Voce avança para o movel mais próximo de levantar, talvez isso possa ajudar ao menos a afastar a criatura\n\n");
                delay(3);
                dado = girar_teste();
                dano_bruto_ag = dado + 7;
                if(mo->resistencia_dano > 0){
                        mo->pv -= 1;
                        mo->resistencia_dano -= dano_bruto_ag;
                        printf("Voce causou 1 de dano, dano tao proximo assim com uma criatura bem resistente e perigosum. \n\n");
                        if(mo->resistencia_dano < 0){
                            mo->resistencia_dano = 0;
                        }
                    }else{
                        mo->pv -= dano_bruto_ag;
                        printf("Voce causou %d no monstro, de fato\n\n", dano_bruto_ag);
                    }
                    delay(3);
                    ataquemonstro(ag,mo,dano_bruto_ag,num_luta,tatica,reduz_dano_ag=0);
            }

            else if(dado == 6){
                printf("Em meio a situacao desesperadora, por uma sorte milagrosamente milagrosa voce encontra uma arma de outro agente\n");
                delay(3);
                dado = girar_teste();
                dano_bruto_ag = dado + 9;
                if(dado >= 1 && dado <= 4){
                    if(mo->resistencia_dano > 0){
                        mo->pv -= 4;
                        mo->resistencia_dano -= dano_bruto_ag;
                        printf("Voce causou 4 de dano, parece ter atravessado sua resistencia. \n\n");
                        if(mo->resistencia_dano < 0){
                            mo->resistencia_dano = 0;
                        }
                    }else{
                        mo->pv -= dano_bruto_ag;
                        printf("Voce causou %d no monstro, de fato", dano_bruto_ag);
                    }
                }
                else if(dado>=5 && dado<=6){
                    if(mo->resistencia_dano > 0){
                        mo->pv -= 6;
                        mo->resistencia_dano -= dano_bruto_ag;
                        printf("Voce causou 4 de dano, parece ter acabado com sua resistencia \n\n");
                        if(mo->resistencia_dano < 0){
                            mo->resistencia_dano = 0;
                        }
                    }else{
                        mo->pv -= dano_bruto_ag;
                        printf("Voce golpeou e deu %d de dano, o zumbi de forma estrondosa, quase injusta por sua parte",dano_bruto_ag);
                        delay(3);
                    }
                }
                delay(3);
                ataquemonstro(ag,mo,dano_bruto_ag,num_luta,tatica,reduz_dano_ag=0);
            }

        }
        else if (tatica == 3){//PROCURAR FRAQUEZA
            girar_teste();
        //
        }
        else if (tatica == 4){// FUGIR
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
        }
}
}
//SISTEMA DE BATALHA(APENAS ATIRAR E FUGIR FUNCIONAM)
int batalha(Agente *ag,Monstro *mo,int num_luta,int decisao){
    int fraqueza = 0;
    int dado;
    while(mo->pv > 0){
        if(ag->pv > 0 && ag->sanidade > 0){
            printf("\n\n========== AGENTE ==========\n");
            printf("PV: %d/%d | Sanidade: %d | Proteção: %d \n", ag->pv, ag->pv_total, ag->sanidade, ag->armadura);
            printf("ARMA: %s (Dano: %d)(Munição: %d)\n\n", ag->armas.nome, ag->armas.dano, ag->armas.municao);

            printf("========== MONSTRO ==========\n");
            printf("NOME: %s ", mo->nome);
            printf("PV: %d/%d | Resistência a dano: %d\n\n", mo->pv, mo->pv_total, mo->resistencia_dano);
            delay(3);
            printf("===== O QUE IRÁ FAZER? =====\n");
            delay(1);
            printf("1 - Atirar\n");
            printf("2 - Procurar por algo ao redor que ajude\n");
            if (fraqueza == 0){
                printf("3 - Procurar Fraqueza\n");
            }
            else{
                printf("3 - Fraqueza Encontrada\n");
            }
            printf("4 - Fugir\n\n");
            printf("Escolha:");
            int tatica = 0;
            scanf("%d", &tatica);

            if(tatica == 1){
                luta(ag, mo, 1,num_luta,fraqueza);
                // dados de agente e monstro, escolha, numero da luta, variável para caso o agente tenha achado ou não a fraqueza do monstro;
            }
            else if(tatica == 2){
                luta(ag, mo, 2,num_luta,fraqueza);
            }
            else if(tatica == 3){
                luta(ag, mo, 3,num_luta,fraqueza);
            }
            else if(tatica == 4){
                luta(ag, mo, 4,num_luta,fraqueza);
            }
            else{
                printf("\nOpção inválida. Escolha um valor entre 1 e 4, e rápido.\n");
                delay(3);
            }
            }
        //MORTE POR ZERAR A VIDA
        else if(ag->pv <= 0){
            printf("\nA criatura matou o agente em meio à escuridão entre as árvores, enquanto a casa continua esperando sua próxima vítima...");
            delay(5);
            printf("%s\n", imprimirTracos());
            printf("%s\n", imprimirCreditos());
            break;

        }
        //MORTE POR ZERAR SANIDADE(não foi decidido se vai ter esse tipo de morte mas por enquanto vou manter a caixa de texto)
        else if(ag->sanidade <= 0){
            printf("\nVocê não aguenta mais a pressão de continuar lutando e enlouquece, enquanto isso a criatura aproveita a chance para atacar e então seu corpo é devorado pelo zumbi, \nassim a criatura matou o agente em meio à escuridão entre as árvores, enquanto a casa continua esperando sua próxima vítima...");
            delay(5);
            printf("%s\n", imprimirTracos());
            printf("%s\n", imprimirCreditos());
            break;

        }
        }
    if(mo->pv <=0){
        printf("Parabéns, você matou a criatura\n\n");
        delay(3);
        return 3;
    }

    return 0;
    }

int main(){
    srand(time(NULL));
    // PV são pontos de vida, para você testar, caso precise passar pela rota da luta(quando abandona floresta) recomendo trocar a pontuação de vida do zumbi para 1 antes da execução "monst.pv = 1;"
    Agente persona;
    persona.vigor = 2;
    persona.forca = 2;
    persona.agilidade = 3;
    persona.intelecto = 2;
    persona.pv_total = 25;
    persona.pv = 25;
    persona.sanidade = 12;
    persona.armadura = 5;

    persona.armas.nome = "Beretta 92FS";
    persona.armas.dano = 6;
    persona.armas.municao = 7;

    Monstro monst;

    monst.nome = "Zumbi de sangue";
    monst.resistencia_dano = 15;
    //para facilitar caso precise
    monst.pv = 45;

    monst.pv_total = 25;
    monst.dano = 10;

    char *nomePlayer;

    printf("Bem vindo ao jogo X.");
    printf("Digite seu nome:");
    scanf("%s", &nomePlayer);

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

            printf("Uma criatura coberta de sangue surge entre as árvores. Você ja lutou com algo parecido...\n");
            printf("Um Zumbi de Sangue.\n");
            printf("Ela permanece parada por alguns segundos, olhando diretamente para você.\n\n");
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
	                // LUTAR COM O ZUMBI(incompleto)
	                decisao2 = batalha(&persona,&monst,1,decisao2);
	                if(decisao2 != 3){
                        break;
	                }
	                printf("\nDepois de uma longa e dura batalha contra o zumbi, você decide entrar na casa pela porta da frente e enfim investigar o interior da casa\n\n");
	                delay(5);

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
	        break;
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
					printf("Voce tenta sair da floresta, comeca a correr, mas o radio irrompe o silencio.\n");
					printf("... \"Voce sabe o que aconteceu aqui. Nao pode simplesmente ir embora.\" ...\n");
					printf("Mesmo assim, voce continuar correndo e tentando achar uma saida, mas depois de algum tempo percebe que sempre retorna para o mesmo lugar: em frente a casa abandonada.\n");
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
        int irAoPorao = 0;

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
        		printf("Livia responde:\n");
        		printf("\"Os homens que vieram antes de voce, eles tambem fizeram perguntas.\"\n");
        		printf("\"Eles estavam procurando meu pai...\"\n");
        		printf("Voce pergunta: \"Onde ele esta?\"\n");
        		printf("Ela aponta para o porao.\n");

                irAoPorao = 1;

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
                printf("Voce percebe que ela esta indo para uma pequena passagem que te leva ao porao");

                irAoPorao = 1;

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

                        irAoPorao = 1;

        				break;

					} else if (decisao3a == 2){
						//ABAIXAR A ARMA

						printf("Voce abaixa a arma.\n");
						printf("A garota desaparece pelo corredor.\n");
                        printf("A garota aparece por tras de voce e fala:\n");
                        printf("\"Por favor nao va!\"\n");
                        printf("Ela corre e voce vai atras dela.\n");
                        printf("Voce percebe que ela esta indo para uma pequena passagem que te leva ao porao");

                        irAoPorao = 1;

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

        // rota do porão
        if(irAoPorao == 1){
            int decisao4;
            int decisao5;

            imprimirTracos();

            printf("Voce segue ate o porao...\n");
            delay(1);

            printf("Ao descer as escadas, voce encontra varios objetos pertencentes a antiga equipe espalhados pelo chao.\n");
            delay(1);

            printf("No centro do local existe um circulo desenhado no chao, com a fotografia de Livia no meio.\n");

            printf("Ao lado, esta o corpo de um dos agentes. Voce o conhecia.\n");
            printf("O nome dele era Aaron, um atirador de elite importante para a agencia.\n\n");
            delay(1);

            printf("\nVoce encontra um documento:\n");
            delay(1);

            printf("\"O pai tentou trazer sua esposa de volta, apos morrer em um tragico acidente.\n");
            printf("Para isso, sacrificou a propria filha.\"\n");
            delay(2);

            printf("\nVoce finalmente entende o que aconteceu...\n");
            delay(1);

            printf("Livia morreu durante o ritual.\n");
            delay(1);

            printf("Mas durante o ritual, algo deu errado, liberando uma entidade e deixando a alma de sua filha presa a casa.\n");
            delay(2);

            printf("\nDe repente, Livia aparece no final da escada.\n");
            delay(1);

            printf("\nLivia: \"Voce veio me matar tambem?\"\n");
            
            imprimirTracos();

            delay(2);

            printf("\n1- Perguntar o que aconteceu com ela.\n");
            printf("2- Apontar a arma para Livia.\n");

            printf("\nEscolha: ");
            scanf("%d", &decisao4);

            if(decisao4 == 1){
                imprimirTracos();

                printf("\n%s: O que aconteceu com voce?\n", nomePlayer);
                delay(1);

                printf("\nLivia permanece em silencio por alguns segundos.\n");
                delay(1);

                printf("Livia: Eu nao deveria estar aqui...\n");
                delay(1);

                printf("Livia: Meu pai fez um ritual. Ele queria trazer minha mae de volta.\n");
                printf("Mas precisava de alguem para oferecer em troca.\n");
                delay(2);

                printf("\n%s: E ele escolheu voce...\n", nomePlayer);
                delay(1);

                printf("Livia: Sim. Eu fui o sacrificio.\n");
                delay(2);

                printf("Voce percebe que Livia nao estava protegendo a casa.\n");
                printf("Ela estava presa nela.\n");
                delay(2);
                
                decisao5 = 1;
            } else if (decisao4 == 2){
                imprimirTracos();

                printf("\nVoce aponta a arma para Livia.\n");
                delay(1);

                printf("Livia nao demonstra medo.\n");
                delay(1);

                printf("Livia: Foi isso que mandaram voce fazer?\n\n");
                delay(2);

                printf("Voce se lembra da sua missao: impedir que a manifestacao escape.\n");
                delay(2);

                printf("Livia olha para o circulo no chao.\n\n");
                delay(1);

                printf("Livia: Se voce me matar, ela vai sair.\n");
                delay(2);

                printf("Voce olha para o circulo e hesita.\n\n");
                delay(1);

                printf("Livia: Eu sei o que voce esta pensando.");
                delay(2);
                printf("Livia: Mas, se puxar o gatilho, nao vai conseguir impedir o que esta aqui.\n\n");
                delay(2);

                printf("\nVoce fica em duvida sobre o que fazer.\n");
                delay(2);

                imprimirTracos();
                int decisao4a;

                printf("1- Abaixar a arma");
                printf("2- Atirar");


                printf("Escolha: ");
                scanf("%d", &decisao4a);

                if(decisao4a == 1){
                    imprimirTracos();

                    printf("\nVoce abaixa a arma.\n");
                    delay(1);

                    decisao5 = 1;

                    imprimirCreditos();

                } else if(decisao4a == 2){ // FINAL - A MISSAO
                    printf("\nVoce dispara.\n");
                    delay(1);

                    printf("Livia cai no chao.\n");
                    delay(2);

                    printf("\nPor alguns segundos, tudo fica em silencio.\n");
                    delay(2);

                    printf("A sombra desaparece.\n");
                    delay(1);

                    printf("Voce pensa que conseguiu cumprir sua missao.\n");
                    delay(2);

                    printf("\nEntao, voce escuta um barulho atras de voce.\n");
                    delay(2);

                    printf("A sombra surge novamente.\n");
                    delay(2);

                    printf("\nVoce percebe tarde demais que Livia nao era a prisao.\n");
                    delay(2);

                    printf("Ela era a unica coisa mantendo a entidade sob controle.\n");
                    delay(2);

                    printf("Voce cumpriu sua missao, mas acabou libertando a entidade.\n");
                    delay(2);

                    printf("A sombra avanca em sua direcao. E dessa vez, nao ha para onde fugir...\n");
                    delay(2);

                    imprimirCreditos();

                }else{
                    printf("\nOpcao invalida. Escolha um valor entre 1 e 2\n");
                }

            } else{ 
                printf("\nOpcao invalida. Escolha um valor entre 1 e 2");
            }

            if(decisao5 == 1){
                // ENCONTRO FINAL
            }
        }

    }

    return 0;

}