#include<cstdio>

int main(int argc, char const *argv[])
{
    int a, b, c;
    char s[100];

    scanf("%d", &a);
    scanf("%d %d", &b, &c);
    scanf("%s", s);

    printf("%d %s\n", a+b+c, s);

    return 0;
}
