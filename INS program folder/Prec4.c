// Aim : -Implement Polyalphabetic Cipher Encryption - Decryption.
#include <stdio.h>
#include <conio.h>
#include <string.h>
void main()
{
    char pt[20] = {'\0'}, ct[20] = {'\0'}, key[20] = {'\0'}, rt[20] = {'\0'};
    int i, j;
    printf("\n enter the plain text:");
    scanf("%s", pt);
    printf("\n enter the key:");
    scanf("%s", key);

    //length of plaintext equal to length of key
    j = 0;
    for (i = strlen(key); i < strlen(pt); i++)
    {
        if (j == strlen(key))
        {
            j = 0;
        }
        key[i] = key[j];
        j++;
    }
    printf("\n new key is:%s", key);

    //converting plain text to cipher text (encryption)
    for (i = 0; i < strlen(pt); i++)
    {
        ct[i] = (((pt[i] - 97) + (key[i] - 97)) % 26) + 97;
    }
    printf("\n \n cipher text is:%s", ct);

    //converting cipher text to plain text (decryption)
    for (i = 0; i < strlen(ct); i++)
    {
        if (ct[i] < key[i])
        {
            rt[i] = 26 + ((ct[i] - 97) - (key[i] - 97)) + 97;
        }
        else
            rt[i] = (((ct[i] - 97) - (key[i] - 97)) % 26) + 97;
    }
    printf("\n \n plain text is:%s", rt);
    getch();
}
