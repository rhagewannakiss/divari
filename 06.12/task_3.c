#include <stdio.h>

//3.	Функции Аккермана, определяемая для  m≥0,  n≥0
//  a(m,n)=n+1,                       если m=0
//   a(m,n)=a(m-1,1),                 если m≠0, и n=0
//   a(m,n)=a(m-1,a(m,n-1)) ,    если m≠0 и n≠0

unsigned int AckermannFunc(unsigned int m, unsigned int n);

int main() {
    unsigned int m = 0;
    unsigned int n = 0;

    printf("Please enter values m and n: ");
    scanf("%u %u", &m, &n);

    printf("Ackermann(%u, %u) = %u\n", m, n, AckermannFunc(m, n));

    return 0;
}

unsigned int AckermannFunc(unsigned int m, unsigned int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (n == 0)
    {
        return AckermannFunc(m - 1, 1);
    }
    else
    {
        return AckermannFunc(m - 1, AckermannFunc(m, n - 1));
    }
}