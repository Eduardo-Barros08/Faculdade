#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LIVROS 100
#define MAX_USUARIOS 100

typedef struct
{
    char titulo[100];
    char autor[100];
    int disponivel;
    int indice;
    int ano;
    time_t dia_emprestimo; //rastrear data do emprestimo
}Livro;

typedef struct
{
   int id_usuario;
   char nome[100];
   int num_livros_emprestados;
   int livros_emprestados[MAX_LIVROS];
}Usuario;



//variaveis
Livro biblioteca [MAX_LIVROS];
Usuario usuarios[MAX_USUARIOS];
int numLivros = 0;
int numUsuarios = 0;




//funções
void adicionarLivros()
{
    if(numLivros >= MAX_LIVROS)
    {
     printf("A biblioteca está cheia. Impossivel adicionar livros.\n");
     return;
    };


Livro novoLivro;
printf("Digite o titulo do livro: ");
fgets(novoLivro.titulo, sizeof(novoLivro.titulo),stdin);
novoLivro.titulo[strcspn(novoLivro.titulo,"\n")] = '0';

printf("Digite o nomde do autor do livro: ");
fgets(novoLivro.autor, sizeof(novoLivro.autor),stdin);
novoLivro.autor[strcspn(novoLivro.autor, "\n")] = '0';


int anoValido = 0;
  do{
    printf("Digite o ano de publicação do Livro: ");
    if(scanf("%d",&novoLivro.ano) !=1)
     {
       printf("Ano inválido. Por favor, insira um número inteiro.\n");
       getchar();//buffer do teclado é limpo
     }
     else
        {
          anoValido=1;
        }

  }while(!anoValido);

        printf("Digite a disponibilidade do livro:\n0- Disponivel\n2- Indisponivel\n>");
        scanf("%d",&novoLivro.disponivel);

        getchar();//buffer do teclado é limpo

  novoLivro.indice = numLivros + 1;
  biblioteca[numLivros++] = novoLivro;

  printf("Novo livro adicionado com sucesso!\n");

};

void listarLivros()
{
    if(numLivros==0)
    {
        printf("A biblioteca esta vazia.\n");
        return;
    }

    printf("Livros cadastrados:\n");
    for (int i=0; i< numLivros; i++)
        {
        printf("Livro: %d\n", biblioteca[i].indice);
        printf("Tituto: %s\n", biblioteca[i].titulo);
        printf("Autor: %s\n",biblioteca[i].autor);
        printf("Ano publicado: %d\n", biblioteca[i].ano);
        printf("Disponivel: %s\n",biblioteca[i].disponivel? "Sim" : "Não");
         }

}

void atualizarLivro()
{
       if(numLivros==0)
       {
           printf("A biblioteca está vazia.");
           return;
       }

       int indiceLivro;
       printf("Digite o número do livro que deseja atualizar: ");
       scanf("%d",&indiceLivro);
         if(indiceLivro < 1 || indiceLivro > numLivros)
         {
             printf("Número do livro inválido.\n");
             return;
         }

         Livro *livro = &biblioteca[indiceLivro - 1];

         printf("Digite o novo titulo do livro: ");
         getchar();
         fgets(livro->titulo, sizeof(livro->titulo),stdin);
         livro->titulo[strcspn(livro->titulo, "\n")] = '\0';

         printf("Digite o novo autor do livro: ");
         getchar();
         fgets(livro->autor, sizeof(livro->autor),stdin);
         livro->autor[strcspn(livro->autor, "\n")] = '\0';

         printf("Digite o novo ano de publicação do livro: \n");
         scanf("%d", &livro->ano);

         printf("O livro esta disponivel?\n0-sim\n1-Não\n>");
         scanf("%d",&livro->disponivel);

         printf("Livro atualizado.\n");

}


void deletarLivro()
{
     if(numLivros==0)
     {
         printf("A biblioteca está vazia.\n");
         return;
     }

     int indiceLivro;
     printf("Digite o numero do livro que deseja deletar: ");
     scanf("%d", &indiceLivro);

     if(indiceLivro < 1 || indiceLivro > numLivros)
     {
         printf("Numero de livro invalido.\n");
         return;
     }
     for(int i = indiceLivro - 1; i < numLivros; i++)
     {
         biblioteca[i] = biblioteca[i + 1];
     }
     numLivros--;

     printf("Livro deletado.\n");
}


void emprestarLivro()
{
    if(numLivros==0)
    {
        printf("A biblioteca está vazia!\n");
        return;
    }

    if(numUsuarios==0)
    {
        printf("Não há usuarios cadastrados!\n");
        return;
    }

    int indiceLivro;
    printf("Digite o numero do livro que deseja emprestar: \n");
    scanf("%d", &indiceLivro);

    if(indiceLivro < 1 || indiceLivro > numLivros)
    {
        printf("Numero de livro invalido.\n");
        return;
    }

    int indiceUsuario;
    printf("Digite o numero do usuario para quem deseja emprestar o livro: \n");
    scanf("%d", &indiceUsuario);

    if(indiceUsuario < 1 || indiceUsuario > numUsuarios)
    {
        printf("Numero do usuario invalido.\n");
        return;
    }

    Livro *livro = &biblioteca[indiceLivro - 1];
    Usuario *usuarios = &biblioteca[indiceUsuario - 1];

    if(livro-> disponivel == 0)
    {
        printf("O livro selecionado não esta disponivel para emprestimo no momento.\n");
        return;
    }

    if(usuarios-> num_livros_emprestados >= MAX_LIVROS)
    {
        printf("O usuario atingiu o maximo de livros emprestados.\n");
        return;
    }

    livro-> disponivel = 0;
    time(&livro-> dia_emprestimo);
    usuarios-> livros_emprestados[usuarios-> num_livros_emprestados++] = indiceLivro;

    printf("Livro emprestado com sucesso!\n");

}


void devolverLivro()
{
    if(numLivros==0)
    {
        printf("A biblioteca esta vazia!\n");
        return;
    }

    if(numUsuarios==0)
    {
        printf("Não ha usuarios cadastrados.\n");
        return;
    }

    int indiceUsuario;
    printf("Diga o número do usuario que deseja devolver o livro: \n");
    scanf("%d", &indiceUsuario);

    if(indiceUsuario < 1 || indiceUsuario > numUsuarios)
    {
        printf("Numero de usuario invalido!\n");
        return;
    }

    Usuario *usuario = &usuarios[indiceUsuario - 1];

    if(usuario-> num_livros_emprestados == 0)
    {
        printf("O usuario nao possui livros emprestados");
        return;
    }

    int indiceLivro;
    printf("Digite o numero do livro que deseja devolver: \n");
    scanf("&d",&indiceLivro);

    if(indiceLivro < 1 || indiceLivro > usuario->  num_livros_emprestados)
    {
        printf("Numero de livro invalido");
        return;
    }

    Livro *livro = &biblioteca[usuario-> livros_emprestados[indiceLivro - 1] - 1];

    livro-> disponivel = 1;

    for( int i = indiceLivro - 1; i < usuario-> num_livros_emprestados - 1; i++)
    {
        usuario->livros_emprestados[i] = usuario->livros_emprestados[i = 1];
    }

    usuario->num_livros_emprestados--;

    printf("Livro devolvido com êxito!\n");

}


void adicionarUsuarios()
{
      if(numUsuarios >= MAX_USUARIOS)
      {
          printf("O numero maximo de usuarios foi atingido. Não é possível adicionar mais usuários.");
          return;
      }

      Usuario novoUsuario;
      printf("Digite o nome do usuario: ");
      fgets(novoUsuario.nome, sizeof(novoUsuario.nome),stdin);
      novoUsuario.nome[strcspn(novoUsuario.nome, "\n")] = '\0';

      novoUsuario.num_livros_emprestados = 0;
      novoUsuario.id_usuario = numUsuarios + 1;

      usuarios[numUsuarios++] = novoUsuario;

      printf("Novo usuario cadastrado com sucesso");

}


void listarUsuarios()
{
    if (numUsuarios == 0)
    {
        printf("Não há usuários cadastrados.\n");
        return;
    }

    printf("Usuários cadastrados:\n");
    for (int i = 0; i < numUsuarios; i++)
    {
        printf("Usuário %d:\n", usuarios[i].id_usuario);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("\n");
    }
}


void atualizarUsuario()
{
    if (numUsuarios == 0)
    {
        printf("Não há usuários cadastrados.\n");
        return;
    }

    int indiceUsuario;
    printf("Digite o número do usuário que deseja atualizar: ");
    scanf("%d", &indiceUsuario);

    if (indiceUsuario < 1 || indiceUsuario > numUsuarios)
    {
        printf("Número de usuário inválido.\n");
        return;
    }

    Usuario *usuario = &usuarios[indiceUsuario - 1];

    printf("Digite o novo nome do usuário: ");
    getchar(); // Limpa o buffer do teclado
    fgets(usuario->nome, sizeof(usuario->nome), stdin);
    usuario->nome[strcspn(usuario->nome, "\n")] = '\0';

    printf("Usuário atualizado com sucesso!\n");
}


void deletarUsuario()
{
    if (numUsuarios == 0)
    {
        printf("Não há usuários cadastrados.\n");
        return;
    }

    int indiceUsuario;
    printf("Digite o número do usuário que deseja deletar: ");
    scanf("%d", &indiceUsuario);

    if (indiceUsuario < 1 || indiceUsuario > numUsuarios)
    {
        printf("Número de usuário inválido.\n");
        return;
    }

    for (int i = indiceUsuario - 1; i < numUsuarios - 1; i++)
    {
        usuarios[i] = usuarios[i + 1];
    }

    numUsuarios--;

    printf("Usuário deletado com sucesso!\n");
}

void menuLivros()
{
    int res;
   do
    {
    printf("Escolha as opções abaixo: \n");
    printf("0- Voltar\n1- Adicionar Livro\n2- Listar Livros\n3- Atualizar Livros\n");
    printf("4- Deletar Livros\n5- Emprestar livros\n6- Devolver Livro\n>\n");
    scanf("%d", &res);

    getchar();

       switch(res)
           {
           case 0:
               printf("Voltando ao meu principal...");
              break;

           case 1:
               adicionarLivros();
              break;

           case 2:
               listarLivros();
              break;

           case 3:
               atualizarLivro();
              break;

           case 4:
               deletarLivro();
              break;

           case 5:
               emprestarLivro();
              break;

           case 6:
               devolverLivro();
              break;

           default:
            printf("Opção inválida. Tente as opções acima.");
              break;

           }
           printf("\n");
    }while (res !=0);
}


void menuUsuarios()
{
    int res;
      do
      {
          printf("Escolha as opções abaixo:");
          printf("0-Voltar\n1-Adicionar Usuario\n2-Listar Usuario\n");
          printf("3-Atualizar Usuario\n4- Deletar Usuario");
          scanf("%d", &res);
          getchar();

            switch(res)
               {

           case 0:
                printf("Voltando ao meu principal...");
             break;

           case 1:
                adicionarUsuarios();
             break;

           case 2:
                listarUsuarios();
             break;

           case 3:
                atualizarUsuario();
             break;

           case 4:
                deletarUsuario();
             break;

           default:
                printf("Opção inválida. Tente as opções acima.");
             break;
      }
      printf("\n");
    }   while (res !=0);
}

int main()
{
int res;

  do{
    printf("Bem vindo ao sistema da Biblioteca!!\n");
    printf("Escolha as opções abaixo: \n");
    printf("0- Sair do Sistema\n1- Menu de Livros\n2- Menu de Usuarios\n>");
    scanf("%d", &res);
    getchar();

      switch(res)
         {
         case 0:
            printf("Saindo do sistema...");
           break;

         case 1:
            menuLivros();
           break;

         case 2:
            menuUsuarios();
           break;

         default:
            printf("Escolha as opçoes abaixo.");
           break;
         }

    } while (res !=0);


    return 0;
}
