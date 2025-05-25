#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void printElements(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d th - %d\n", i + 1, i[arr] % 20 + 1);
    }
    
}

int main(int argc, char const *argv[])
{
    int v[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        *(v + i) = rand();
    }    

    printElements(v, SIZE);

    return 0;
}
