#include <cstdio>

int main()
{
    unsigned int a = 0xffffe000;
    unsigned int b = 0x015fa878;
    unsigned int c = -8192;
    printf("%x|%x|%x\n",a,b,c);
    return 0;
}
