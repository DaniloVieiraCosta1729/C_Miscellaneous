#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // Vamos declarar um ponteiro do tipo FILE, associar ele ao arquivo de texto nesse diretório e então usar as funções de stdio para manipular ele.

    FILE *arquivo;

    arquivo = fopen("texto_C.txt", "at");

    if (arquivo == NULL)
    {
        printf("Algo errado, não deu certo.");
    } else
    {
        fprintf(arquivo, "Escrevendo uma monte de coisas aqui!\nVamos ver se funcionou.\n");
        fclose(arquivo);
    }  

    printf("Finalizado.");

    return 0;
}
