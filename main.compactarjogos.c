#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_TENTATIVAS 6
#define TAMANHO_PALAVRA 20
#define TAMANHO_ARRAY 5


int main()
{
    int res;
    while (res != 4)
    {
        printf("Escolha o jogo:\n\n");
        printf("1. Adivinhe o Numero\n2-Forca\n3-Jankenpo\n4-Sair\n");
        printf("Escolha: ");
        scanf("%d", &res);

        switch (res)
        {
        case 1:
            printf("\nIniciando Jogo de Adivinhacao...\n");
            res = jogoadivinha();
            break;
        case 2:
            printf("\nIniciando Jogo da Forca...\n");
            res = forca();
            break;
        case 3:
            printf("\nIniciando Jogo do Jokenpo...\n");
            res = jankenpo();
            break;
        case 4:
            return 0;
            break;
        default:
            printf("\nOpcao invalida!\n\n");
            break;
        }
    }

    return 0;
}

int jogoadivinha(){
    int numeroAleatorio, tentativa, escolha, res, tentativasRestantes = 5;

    // Inicializando o gerador de numeros aleatorios com base no tempo atual
    srand(time(NULL));

    // Gerando um numero aleatorio entre 1 e 100
    numeroAleatorio = rand() % 100 + 1;

    printf("Bem-vindo ao jogo de adivinhacao!\n");
    printf("Tente adivinhar o numero secreto entre 1 e 100.\n");

    // Loop do jogo
    do {
        printf("Voce tem %d tentativas restantes.\n", tentativasRestantes);
        printf("Digite seu palpite: ");
        scanf("%d", &tentativa);

        // Verificando o palpite do jogador
        if (tentativa > numeroAleatorio) {
            printf("Tente um numero menor.\n");
        } else if (tentativa < numeroAleatorio) {
            printf("Tente um numero maior.\n");
        } else {
            printf("Parabens! Voce adivinhou o numero secreto %d!\n", numeroAleatorio);
            break; // Sai do loop do jogo
        }

        tentativasRestantes--;
    } while (tentativasRestantes > 0);

    // Se o jogador esgotar todas as tentativas sem adivinhar o numero
    if (tentativasRestantes == 0) {
        printf("Suas tentativas acabaram. O numero secreto era %d.\n", numeroAleatorio);
    }
    printf("Deseja jogar novamente?\n1-Sim\n2-Não\n>");
    scanf("%d", &res);

 while (escolha==1);

    return 1;}



void imprimirForca(int tentativasRestantes)
{
    printf("\n");
    printf("  +---+\n");
    printf("  |   |\n");

    if (tentativasRestantes < MAX_TENTATIVAS)
        printf("  |   O\n");
    else
        printf("  |\n");

    if (tentativasRestantes < MAX_TENTATIVAS - 1)
        printf("  |   |\n");
    else if (tentativasRestantes < MAX_TENTATIVAS)
        printf("  |  /|\n");
    else
        printf("  |\n");

    if (tentativasRestantes < MAX_TENTATIVAS - 3)
        printf("  |  / ");
    else if (tentativasRestantes < MAX_TENTATIVAS - 2)
        printf("  |  /|");
    else if (tentativasRestantes < MAX_TENTATIVAS - 1)
        printf("  |  /|\\");
    else if (tentativasRestantes < MAX_TENTATIVAS)
        printf("  |  /|\\");
    else
        printf("  |\n");

    printf("  |\n");
    printf("======\n\n");
}

int verificarLetra(char letra, char palavra[], char palavraEscondida[])
{
    int i, encontrou = 0;
    for (i = 0; i < strlen(palavra); i++)
    {
        if (tolower(letra) == tolower(palavra[i]))
        {
            palavraEscondida[i] = palavra[i];
            encontrou = 1;
        }
    }
    return encontrou;
}

int forca()
{
    char *palavras[TAMANHO_ARRAY];
    char letra;
    char palavra[TAMANHO_PALAVRA];
    char palavraEscondida[TAMANHO_PALAVRA];
    int palavraRevelada = 0;
    int escolha;
    do
    {
        int tentativasRestantes = MAX_TENTATIVAS;
        printf("\nEscolha a categoria:\n");
        printf("1. Animal\n");
        printf("2. Cor\n");
        printf("3. Veiculo\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("\nForca na categoria Animal\n");
            palavras[0] = "cachorro";
            palavras[1] = "gato";
            palavras[2] = "passarinho";
            palavras[3] = "peixe";
            palavras[4] = "coelho";
            break;
        case 2:
            printf("\nForca na categoria Cor\n");
            palavras[0] = "vermelho";
            palavras[1] = "azul";
            palavras[2] = "verde";
            palavras[3] = "amarelo";
            palavras[4] = "roxo";
            break;
        case 3:
            printf("\nForca na categoria Veiculo\n");
            palavras[0] = "carro";
            palavras[1] = "moto";
            palavras[2] = "bicicleta";
            palavras[3] = "aviao";
            palavras[4] = "barco";
            break;
        default:
            printf("\nOpçao invalida!\n");
            break;
        }
        int numeroAleatorio = rand() % TAMANHO_ARRAY;
        strcpy(palavra, palavras[numeroAleatorio]);
        int tamanho_palavra = strlen(palavra);
        // Inicializa a palavra escondida com "-"
        memset(palavraEscondida, '-', strlen(palavra));
        palavraEscondida[strlen(palavra)] = '\0';

        // Loop principal do jogo
        while (tentativasRestantes > 0 && !palavraRevelada)
        {
            printf("\nPalavra: %s\n", palavraEscondida);
            printf("Tentativas restantes: %d\n", tentativasRestantes);

            printf("Digite uma letra: ");
            scanf(" %c", &letra);

            // Verifica se a letra j� foi tentada
            if (strchr(palavraEscondida, tolower(letra)) != NULL)
            {
                printf("\033[1;33mVoce ja tentou esta letra. Tente outra.\033[0m\n");
                continue;
            }

            // Verifica se a letra est� presente na palavra
            if (verificarLetra(letra, palavra, palavraEscondida))
            {
                printf("\033[1;32mLetra correta!\033[0m\n");

                // Verifica se todas as letras foram adivinhadas
                if (strcmp(palavra, palavraEscondida) == 0)
                {
                    palavraRevelada = 1;
                }
            }
            else
            {
                printf("\033[1;31mLetra incorreta.\033[0m\n");
                tentativasRestantes--;
            }

            // Imprime a forca
            imprimirForca(tentativasRestantes);
        }

        // Verifica se o jogador venceu ou perdeu
        if (palavraRevelada)
        {
            printf("\n\033[1;32mVoce venceu!\033[0m Voce acertou a palavra \"%s\"!\n", palavra);
            palavraRevelada = 0;
        }
        else
        {
            printf("\n\033[1;31mVoce perdeu!\033[0m Voce errou a palavra \"%s\".\n", palavra);
        }
        printf("\nDeseja jogar novamente? (1 = Sim, 0 = Nao): ");
        scanf("%d", &escolha);
    } while (escolha == 1);

    printf("\nObrigado por jogar!\n\n");

    return 2;
}



int obterEscolha()
{
    int escolha;
    printf("\nEscolha:\n");
    printf("1. Pedra\n");
    printf("2. Papel\n");
    printf("3. Tesoura\n\n");
    printf("Digite o numero correspondente a sua escolha: ");
    scanf("%d", &escolha);
    return escolha;
}

void determinarVencedor(int escolhaUsuario, int escolhaComputador)
{
    if (escolhaUsuario == escolhaComputador)
    {
        printf("\n\033[1;33mEmpate!\033[0m\n");
    }
    else if ((escolhaUsuario == 1 && escolhaComputador == 3) ||
             (escolhaUsuario == 2 && escolhaComputador == 1) ||
             (escolhaUsuario == 3 && escolhaComputador == 2))
    {
        printf("\n\033[1;32mVoce venceu!\033[0m\n");
    }
    else
    {
        printf("\n\033[1;31mVoce perdeu!\033[0m\n");
    }
}

int jankenpo()
{
    int escolhaUsuario, escolhaComputador;

    printf("\nBem-vindo ao jogo Pedra, Papel e Tesoura!\n");

    // Inicializa o gerador de n�meros aleat�rios com base no tempo atual
    srand(time(NULL));

    // Loop principal do jogo
    do
    {
        escolhaUsuario = obterEscolha();

        // Gera a escolha do computador (n�mero aleat�rio entre 1 e 3)
        escolhaComputador = rand() % 3 + 1;

        // Imprime a escolha do computador
        switch (escolhaComputador)
        {
        case 1:
            printf("\nO computador escolheu Pedra.\n");
            break;
        case 2:
            printf("\nO computador escolheu Papel.\n");
            break;
        case 3:
            printf("\nO computador escolheu Tesoura.\n");
            break;
        }

        // Determina o vencedor
        determinarVencedor(escolhaUsuario, escolhaComputador);

        // Pergunta se o jogador deseja jogar novamente
        printf("\nDeseja jogar novamente? (1 = Sim, 0 = Nao): ");
        scanf("%d", &escolhaUsuario);
    } while (escolhaUsuario == 1);

    printf("\nObrigado por jogar!\n");

    return 3;
}



