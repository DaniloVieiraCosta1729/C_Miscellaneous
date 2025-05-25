#include <stdio.h>

int main(int argc, char const *argv[])
{
    char * str;
    char **ptr;

    str = "Texto"; // basicamente, estamos atribuindo o valor do endereço de 'T' em str.

    //printf("%p vs %p\n", str, &str[0]);

    ptr = &str;

    printf("%p %p", *ptr, str);

    return 0;
}
