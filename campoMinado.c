#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char mapa [10][10];
int linhaJog, colunaJog;
int linhaTesouro, colunaTesouro;
int tentativas = 5;

void limparTela(){
    printf("\033[H\033[J");
}

void telaGameover(){// Tela de fim de jogo
    printf("\nFIM DE JOGO VOCE PERDEU\n");
    printf("Localização do tesouro L = %i  C = %i", linhaTesouro, colunaTesouro);
}

void iniciaMapa(){
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            mapa[i][j] = '.';
        }
    }
}

void sortearTesouro(){// Aqui vai gerar numeros aleatórios para a posição do tesouro
    srand(time(NULL)); 
    linhaTesouro = rand() % 10;
    colunaTesouro = rand() % 10;
    printf("%i, %i", linhaTesouro, colunaTesouro);
}

void desenharMapa(){
    int linha, coluna;

    printf("           -----MAPA-----\n");
    printf("VIDA: %i\n", tentativas);
    printf("    ");
    //Desenha as coordenadas das colunas
    for (coluna = 0; coluna < 10; coluna++)
    {
        printf(" %i ", coluna);
    }
    printf("\n");
    
    for (linha = 0; linha < 10; linha++)
    {
        //Desenha as coordenadas das linhas
        printf(" %2i ", linha);
        for (coluna = 0; coluna < 10; coluna++)
        {
            printf(" %c ", mapa[linha][coluna]);
        }
        printf("\n");
    }
    printf("-------------------------------------\n");
}

void comecaJogo(){// Usuario escolhe as coordenadas para posicinar a primeira estação
    printf("Coordenadas para a escavação\n");
    printf("Linha do mapa: ");
    scanf("%i", &linhaJog); 
    printf("Coluna do mapa: ");
    scanf("%i", &colunaJog);
    printf("\nVIDA: 5\n");
    limparTela();
}

void campoMinado(){
    int ganhou = 0;
    while (ganhou == 0 && tentativas > 0)
    {
        desenharMapa();
        comecaJogo();
        if (linhaJog == linhaTesouro && colunaJog == colunaTesouro)
        {
            ganhou = 1;
            mapa[linhaJog][colunaJog] = 'O'; //Usuario encontrou o tesouro O
            desenharMapa();
            printf("Achou o tesouro!!!");
            break;
        }
        else{
            mapa[linhaJog][colunaJog] = 'X'; // marca comn X a posição ja escolhida pelo usuario
            tentativas--;
        }
    }
    if (tentativas = 0)
    {
        telaGameover();
    }
}

int main(){
    char resposta;
    do
    { // laço dentro da main para poder recomeçar o jogo
        tentativas = 5;
        sortearTesouro();
        iniciaMapa();
        campoMinado();
        printf("\nDeseja recomeçar? (S/N): ");
        scanf(" %c", &resposta);

    } while (resposta == 's' || resposta == 'S');
    printf("\nAté a próxima\n");    
    return 0;
}
