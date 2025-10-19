#include <stdlib.h>
#include <stdio.h>

int add(int x, int y);
int multiply(int x, int y);
int callbackMath(int x, int y, int (*op)(int, int));

int main(int argc, char const *argv[])
{
    char c;
    c = argv[1][0];

    switch (c)
    {
    case 'a':
    case 'A':
        callbackMath(5, 4, add);
        break;

    case 'm':
    case 'M':
        callbackMath(5, 4, multiply);
        break;
    
    default:
        break;
    }
    
    return 0;
}

int add(int x, int y)
{
    printf("5 + 4 = %d\n", x+y);
    return x + y;
}

int multiply(int x, int y)
{
    printf("5 x 4 = %d\n", x*y);
    return x*y;
}

int callbackMath(int x, int y, int (*op)(int, int))
{
    return op(x, y);
}