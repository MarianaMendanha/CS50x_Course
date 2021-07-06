#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool VALID(string card);

int main(void)
{
    // Prompt Card Number
    string card;
    bool isnum = true;

    do
    {
        card = get_string("Number: ");
        isnum = true;
        for (int i = 0; i < strlen(card); i++)
        {
            if (!isdigit(card[i]))
            {
                isnum = false;
            }
        }
    }
    while (!isnum);

    // Entering validation
    if (!VALID(card) || strlen(card) > 16 || strlen(card) < 13)
    {
        printf("INVALID\n");
    }
    else if (card[0] == '4')
    {
        if (VALID(card) && (strlen(card) == 13 || strlen(card) == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");

        }
    }
    else if ((card[0] == '3' && card[1] == '4') || (card[0] == '3' && card[1] == '7'))
    {
        if (VALID(card) && (strlen(card) == 15))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");

        }
    }
    else if ((card[0] == '5' && card[1] == '1') || (card[0] == '5' && card[1] == '2') || (card[0] == '5' && card[1] == '3')
             || (card[0] == '5' && card[1] == '4') || (card[0] == '5' && card[1] == '5'))
    {
        if (VALID(card) && strlen(card) == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");

        }
    }
    else
    {
        printf("INVALID\n");
    }

}






// Validation function
bool VALID(string card)
{
    int chk = 0, cntr = 0, len = strlen(card);

    for (int i = len - 1; i >= 0; i--)
    {
        //printf("%d\n", chk);
        if (cntr % 2 == 0)
        {
            chk += card[i] - '0';
            //printf("[%c]", card[i]);
        }
        else
        {
            if ((card[i] - '0') * 2 >= 10)
            {
                int aux = (card[i] - '0') * 2;
                char saux[3];
                //itoa(aux, saux, 10);
                sprintf(saux, "%d", aux);
                //printf("(%s) ", saux);
                //printf("-0-(%c)", saux[0]);
                //printf("+1+(%c)\n", saux[1]);
                chk += (saux[0] - '0') + (saux[1] - '0');
            }
            else
            {
                chk += (card[i] - '0') * 2;
            }
            //printf("(%c)", card[i]);

        }
        cntr++;
    }

    //printf("%d\n", chk);

    // Validating last digit
    if (chk % 10 == 0)
    {
        return true;

    }
    else
    {
        return false;
    }

}