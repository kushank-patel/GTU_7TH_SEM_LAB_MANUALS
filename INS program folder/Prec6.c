// Aim : Write a program to Implement simple DES.
#include <stdio.h>
#include <conio.h>
void main()
{
    int p10[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6}, p8[8] = {6, 3, 7, 4, 8, 5, 10, 9};
    int i, key1[10], key[10], ls1[5], ls2[5], temp, p1[10], j, temp1;

    printf(" Enter Key Value:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &key[i]);
    }

    printf(" \n P10 Value: ");
    for (i = 0; i < 10; i++)
    {
        printf(" %d ", p10[i]);
    }

    printf(" \n P8 Value: ");
    for (i = 0; i < 8; i++)
    {
        printf(" %d ", p8[i]);
    }
    for (i = 0; i < 10; i++)
    {
        temp = p10[i];
        for (j = 0; j < temp; j++)
        {
            temp1 = key[j];
        }
        p1[i] = temp1;
    }

    printf(" \n After Applying Permutation P10: ");
    for (i = 0; i < 10; i++)
    {
        printf(" %d ", p1[i]);
    }
    for (i = 0; i < 10; i++)
    {
        temp1 = p1[i];
        if (i < 5)
        {
            ls1[i] = temp1;
        }
        else
        {
            ls2[i - 5] = temp1;
        }
    }
    ls1[5] = ls1[0];
    for (i = 0; i < 5; i++)
    {
        ls1[i] = ls1[i + 1];
    }

    ls1[4] = ls1[5];
    printf(" \n After Left Shifting By 1 \n ");
    printf(" \n First 5 Bits: ");

    for (i = 0; i < 5; i++)
    {
        printf(" %d ", ls1[i]);
    }

    ls2[5] = ls2[0];
    for (i = 0; i < 5; i++)
    {
        ls2[i] = ls2[i + 1];
    }

    ls2[4] = ls2[5];
    printf(" \n Second 5 Bits: ");
    for (i = 0; i < 5; i++)
    {
        printf(" %d ", ls2[i]);
    }

    for (i = 0; i < 10; i++)
    {
        p1[i] = ls1[i];
        if (i > 5)
        {
            p1[i] = ls2[i - 5];
        }
    }

    for (i = 0; i < 10; i++)
    {
        temp = p8[i];
        for (j = 0; j < temp; j++)
        {
            temp1 = p1[j];
        }
        key1[i] = temp1;
    }

    printf("\n Key K1 is: ");
    for (i = 0; i < 8; i++)
    {
        printf(" %d ", key1[i]);
    }
    getch();
}
