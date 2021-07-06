#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int llamas, end_llamas;
    do
    {
        llamas = get_int("Start size: ");
    }
    while (llamas < 9);

    // TODO: Prompt for end size
    do
    {
        end_llamas = get_int("End size: ");
    }
    while (end_llamas < llamas);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;

    if (llamas != end_llamas)
    {
        while (llamas < end_llamas)
        {
            int born_llamas = (float)llamas / 3.0;
            int pass_llamas = (float)llamas / 4.0;
            llamas = llamas + born_llamas - pass_llamas;
            years++;
            // printf("[%d][%d][%d](years: %d)\n", llamas, born_llamas, pass_llamas, years);
        }
        printf("Years: %d\n", years);
    }
    else
    {
        printf("Years: 0\n");
    }


    // int pop_llamas = llamas + born_llamas - pass_llamas;
    // printf("[%d]\n", pop_llamas);


    // TODO: Print number of years
}