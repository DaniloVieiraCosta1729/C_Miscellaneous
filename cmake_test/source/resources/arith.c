#include <stdio.h>
int add(int x, int y)
{
    return x + y;
}
int sub(int x, int y)
{
    return x - y;
}
int mult(int x, int y)
{
    return x * y;
}
int div(int x, int y)
{
    return x / y;
}

int op(int (* func) (int, int), int x, int y)
{
    printf("%d\n", func(x, y));
    return 0;
}

void calc(char c, int x, int y)
{
    switch ((char)c)
    {
    case 'a':
        op(add, x, y);
        break;    
    case 's':
        op(sub, x, y);
        break; 
    case 'm':
        op(mult, x, y);
        break;   
    case 'd':
        op(div, x, y);
        break;        
    default:
        printf("invalid option.");
        break;
    }
}