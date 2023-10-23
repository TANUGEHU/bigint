#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* createnode(int data) { 
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtFront(struct node** head, int data) {
    struct node* newNode = createnode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) 
        *head = newNode;
    else {
        struct node* current = *head;
        while (current->next != NULL) 
            current = current->next;
        current->next = newNode;
    }
}
void display(struct node* node) {
    if (!node) {
        printf("0");
        return;
    }

    while (node) {
        printf("%d", node->data);
        node = node->next;
    }
    printf("\n");
}
void addBigIntegers(struct node* num1, struct node* num2) {
    struct node* result = NULL;
    int carry = 0;

    while (num1 || num2 || carry) {
        int x = (num1) ? num1->data : 0;
        int y = (num2) ? num2->data : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        sum = sum % 10;
        insertAtFront(&result, sum);

        if (num1) num1 = num1->next;
        if (num2) num2 = num2->next;
    }
    printf("sum: ");
    display(result);
    while (result != NULL && result->data == 0) {
        struct node* temp = result;
        result = result->next;
        free(temp);
    }
}


void freeList(struct node* head) {
    while (head) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
}

void subtractBigIntegers(struct node* num1, struct node* num2) {
    struct node* result = NULL;
    int borrow = 0;

    while (num1 != NULL || num2 != NULL) {
        int val1 = (num1 != NULL) ? num1->data : 0;
        int val2 = (num2 != NULL) ? num2->data : 0;
        
        int diff = val1 - val2 - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else 
            borrow = 0;

        insertAtFront(&result, diff);

        if (num1 != NULL) num1 = num1->next;
        if (num2 != NULL) num2 = num2->next;
    }
    printf("subtraction: ");
    display(result);
    while (result != NULL && result->data == 0) {
        struct node* temp = result;
        result = result->next;
        free(temp);
    }
}


void divideNumbers(char input[], int divisor) {
    struct node* dividend = NULL;
   int i;

    for (i = 0; input[i] != '\0'; i++) 
        insertAtEnd(&dividend, input[i] - '0');

    if (divisor == 0) {
        printf("Division by zero is not allowed.\n");
        return;
    }

    struct node* quotient = NULL;
    int carry = 0;

    while (dividend != NULL) {
        int currentDigit = dividend->data + carry * 10;
        carry = currentDigit % divisor;
        currentDigit /= divisor;
        insertAtEnd(&quotient, currentDigit);
        dividend = dividend->next;
    }

    if (quotient == NULL) 
        insertAtEnd(&quotient, 0);
    if (quotient != NULL) {
        printf("Quotient: ");
        display(quotient);
    }
    while (dividend != NULL) {
        struct node* temp = dividend;
        dividend = dividend->next;
        free(temp);
    }
    while (quotient != NULL) {
        struct node* temp = quotient;
        quotient = quotient->next;
        free(temp);
    }
}
void multiplyNumbers(struct node* cnum1, struct node* cnum2) {
    struct node* result = createnode(0);
    struct node* tresult = result;

    while (cnum2) {
        int carry = 0;
        struct node* itr1 = cnum1;

        while (itr1 || carry) {
            int product = carry;
            
            if (itr1) {
                product += itr1->data * cnum2->data;
                itr1 = itr1->next;
            }


            carry = product / 10;
            product %= 10;

            if (carry || product || itr1) {
                if (!tresult->next) {
                    tresult->next = createnode(0);
                }
                tresult = tresult->next;
                tresult->data = product;
            }
        }

        cnum2 = cnum2->next;
    }
     printf("multiplication: ");
    display(result->next);
}






