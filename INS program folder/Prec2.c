// Aim : Implement Mono - alphabetic cipher encryption and decryption.Introduction :
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    char plain[200], encr[200], encr1[200], decr[200];
    int ch, flag[26];
    char ch1;
    char per[26];
    int i, j, size, k = 0, a = 0;
    char pos;
    printf("\nEnter the plain text");
    gets(plain);
    size = strlen(plain);
    printf("\n size= %d", size);
    for (i = 0; i < 26; i++)
        flag[i] = 0;

    for (i = 0; i < 26; i++)
    {
        a = rand() % 26;
        while (flag[a] == 1)
            a = rand() % 26;
        flag[a] = 1;
        per[i] = (char)(a + 97);
    }
    printf("\nPermuted array is: ");
    for (i = 0; i < 26; i++)
    {
        printf("%c ", per[i]);
    }
    for (j = 0; j < size; j++)
    {
        ch = plain[j];
        ch = ch - 97;
        ch1 = per[ch];
        encr1[j] = ch1;
    }
    //encr1[25]='\0';
    //print
    printf("\nthe encrypted string is ");
    for (i = 0; i < size; i++)
    {
        printf("%c", encr1[i]);
    }

    //decryption
    i = 0;
    while (i < size)
    {
        //a=ct[i];
        //a=a-97;
        //pt[i]=key[a];
        a = 0;
        while (a != 26)
        {
            if (per[a] == encr1[i])
            {
                decr[i] = a + 97;
                break;
            }
            a++;
        }
        i++;
    }
    decr[i] = '\0';
    printf("\nDecrypted string: %s\n", decr);
    getch();
}
