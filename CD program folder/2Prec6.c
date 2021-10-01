// AIM 6.2 : Program To Find Whether The String Is Constant Or Not ?
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
void main()
{
    char str[10];
    int len, a;

    printf("\n Input a string :");
    gets(str);
    len = strlen(str);
    a = 0;
    while (a < len)
    {
        if (isdigit(str[a]))
        {
            a++;
        }
        else
        {
            printf(" It is not a Constant");
            break;
        }
    }

    if (a == len)
    {
        printf(" It is a Constant");
    }
    getch();
}