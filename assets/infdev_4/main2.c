#include <stdio.h>

int main()
{
    float y = 3.135223;
    int x = (int)y;
    printf("%d\n", x);
    printf("%d\n", *(int *)&y);  // 3 em binario 00000000.00000000.00000000.00000011

    return 0;
}