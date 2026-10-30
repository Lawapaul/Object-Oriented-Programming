
#include <stdio.h>
int Bits(int n)
{
    int count = 0;
    while (n > 0) {
        count++;
        n &= (n - 1);
    }
    return count;
}
 
int FCount(int a, int b)
{
    return Bits(a ^ b);
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
   
    printf("%d\n", FCount(a, b));
    return 0;
}