#include <stdio.h>

// função que mostra um dado de acordo com o tipo informado
void printData(void *data, char dataType)
{
    if (dataType == 'c')
    {
        printf("%c\n", *((char *)data));
    } else if (dataType == 'i')
    {
        printf("%d\n", *((int *)data));
    } else if (dataType == 'f')
    {
        printf("%E\n", *((float *)data));
    }
    
    
    
}

int main(int argc, char const *argv[])
{
    long letra = 'a'; // usar im tipo de dado como char e tentar ler como um int (ou qualquer outro tipo maior do que char) pode causar um problema, pois o compilador vai ler os bits ao redor de letra como se fizessem parte de letra, o que vai produzir números sem sentido.

    printData(&letra, 'c');
    printData(&letra, 'i');
    printData(&letra, 'f');

    printf("%d\n", letra);

    return 0;
}
