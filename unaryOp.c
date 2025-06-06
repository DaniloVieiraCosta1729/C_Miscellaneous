// Dos operadores unarios, o que eu usei menos e é o ~ (complemento)

#include <stdio.h>

void showBinaryForm(int n);

int main(int argc, char const *argv[])
{
    printf("~7 = %d\n", ~7);
    printf("~8 = %d\n", ~8);
    printf("~9 = %d\n", ~9);
    printf("~10 = %d\n", ~10);

    showBinaryForm(98);
    showBinaryForm(~98);
    showBinaryForm((98 & ~98));

    return 0;
}

// se um número é par ele, obrigatóriamente tem uma representação em binário que termina em 0. Se é ímpar, então termina em 1. 
/* Podemos usar esse fato para escrever a forma binária de um número. O operador & é equivalente a multiplicação na álgebra booleana, ou seja, se fizemos k & 1 obteremos 0 se k for par e 1, se for ímpar, ou seja, o resultado é igual a casa da unidade na representação binária. Combinando isso com o operador x >> y, que divide x por 2^y, conseguiremos aplicar a multiplicação & em todas as casas binárias. 
*/

void showBinaryForm(int n)
{
    int start = 0;

    int position = 31;

    for (position >= 0; position--;)
    {
        if (start == 0)
        {
            start = ((n >> position) & 1) ? 1 : 0;            
        }
        if (start == 1)
        {
            printf("%d", (n >> position) & 1);
        }      
        
    }
    printf("\n");
}