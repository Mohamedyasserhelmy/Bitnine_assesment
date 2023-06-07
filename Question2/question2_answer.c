#include<stdio.h>
#include<stdlib.h>

// Recursive Way
unsigned long long fibo_1(int n)
{
    if (n < 0)
    {
        printf("Please Enter a non-negative integer ");
        exit(1);
    }
    else if (n <=2 && n>=0)
    {
        return n;
    }

    return fibo_1(n-2) + fibo_1(n-3);

}
// Dynamic Programming (Top Down Approach)
unsigned long long fibo_2(int n)
{
    unsigned long long* fib_arr = (unsigned long long*) malloc(sizeof(unsigned long long)*(n+1));
    fib_arr[0] = 0;
    fib_arr[1] = 1;
    fib_arr[2] = 2;
    if (n < 0)
    {
        printf("Please Enter a non-negative integer ");
        exit(1);
    }
    else if (n <=2 && n>=0)
    {
        return fib_arr[n];
    }
    return fibo_2(n-2) + fibo_2(n-3);

}
unsigned long long fibo_3(int n)
{
    if (n < 0)
    {
        printf("Please Enter a non-negative integer ");
        exit(1);
    }
    else if (n <=2 && n>=0)
    {
        return n;
    }
    unsigned long long f_0 = 0;     //F0
    unsigned long long f_1 = 1;     //F1
    unsigned long long f_2 = 2;     //F2
    unsigned long long f_n = 0;     // Current value

    for (int i=3; i <= n; i++)
    {
        f_n = f_0 + f_1;

        f_0 = f_1;
        f_1 = f_2;
        f_2 = f_n;
    }
    return f_n;
}

int main()
{
    printf("fibo__1 : %d\n", fibo_1(15));
    printf("fibo__2 :%d\n", fibo_2(15));
    printf("fibo__3 :%d\n", fibo_3(15));

    return 0;
}
