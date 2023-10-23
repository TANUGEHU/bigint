#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"
struct node
{
    int data;
    struct node *next;
};
int main()
{
    int i, n1, n2;
    struct node *num1 = NULL;
    struct node *num2 = NULL;

    int divisor;
    int choice;
    while (1)
    {
        printf("1. add big integers\n");
        printf("2. subtract big integers\n");
        printf("3. divide big integers\n");
        printf("4. multiply big integers\n");
        printf("5. exit\n");
        printf("enter your choice\n");
        scanf("%d", &choice);
        printf("enter size of number\n");
        scanf("%d%d", &n1, &n2);
        char str1[n1], str2[n2];
        switch (choice)
        {
        case 1:
            printf("Enter first big number: ");
            scanf("%s", str1);

            printf("Enter second big number: ");
            scanf("%s", str2);
            for (i = 0; i <= strlen(str1) - 1; i++)
                insertAtFront(&num1, str1[i] - '0');

            for (i = 0; i <= strlen(str2) - 1; i++)
                insertAtFront(&num2, str2[i] - '0');
            addBigIntegers(num1, num2);
            
            break;
        case 2:

            printf("Enter first big number: ");
            scanf("%s", str1);

            printf("Enter second big number: ");
            scanf("%s", str2);
            for (i = 0; i <= strlen(str1) - 1; i++)
                insertAtFront(&num1, str1[i] - '0');

            for (i = 0; i <= strlen(str2) - 1; i++)
                insertAtFront(&num2, str2[i] - '0');
            subtractBigIntegers(num1, num2);
            break;
        case 3:
            printf("Enter the dividend : ");
            char dividend[100];
            scanf("%s", dividend);
            printf("Enter the divisor: ");
            scanf("%d", &divisor);
            divideNumbers(dividend, divisor);
            break;
        case 4:
            printf("Enter first big number: ");
            scanf("%s", str1);

            printf("Enter second big number: ");
            scanf("%s", str2);
            for (i = 0; i <= strlen(str1) - 1; i++)
                insertAtEnd(&num1, str1[i] - '0');

            for (i = 0; i <= strlen(str2) - 1; i++)
                insertAtEnd(&num2, str2[i] - '0');
            multiplyNumbers(num1, num2);
            
            break;
        case 5:
            return 0;
        default:
            printf("wrong choice\n");
        }
    }
    freeList(num1);
    freeList(num2);
    return 0;
}