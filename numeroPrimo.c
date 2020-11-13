#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n);
bool isPrime2(int n);
bool isOdd(int check);
int main()
{
    /*
    * This program calculate prime  numbers 
    */
    printf("Inicio el programa! \n");
    int n[10];
    int i, j;

    // bool isP = isPrime2(25);
    // printf(" Primo?: %i  \n",  isP);

    for (i = 2; i <= 100; i++)
    {
        bool isP = isPrime2(i);
        if (isP)
        {
            printf("iteración %i, Primo?: %s  \n", i, isP ? "true" : "false");
            j++;
        }
    }

    printf("Cantidad de números primos: %i \n", j);
    return 0;
}

void calcularNumeros(int n)
{
    int i,j;
    for (i = 0; i < n; i++)
    {
        bool isP = isPrime2(i);
        if (isP)
        {
            printf("iteración %i, Primo?: %s  \n", i, isP ? "true" : "false");
            j++;
        }
    }
}

bool isPrime(int n)
{
    if (n <= 3)
    {
        return n > 1;
    }
    else if ((n % 2) == 0 || (n % 3) == 0)
    {
        return false;
    }
    int i = 5;
    while (i * i <= n)
    {
        if ((n % i) == 0 || (n % (i + 2) == 0))
        {
            return false;
        }
    }

    return true;
}

bool isPrime2(int n)
{
    int i;
    if (n == 2) return true;
    if (n < 2) return false;
    if(isOdd(n))
    {
        for ( i = 3; i <=(n/3); i+=2)
        {
            if(n % i == 0) return false;
        }
        return true;
        
    }
    else return false;
    
}

bool isOdd(int check)
{
    return ((check % 2) != 0) ? true : false;
}
