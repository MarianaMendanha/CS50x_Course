#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for height
    int blocks;
    do
    {
        blocks = get_int("Height: ");
    }
    while (blocks > 8 || blocks < 1);

    // Stored tower
    char tower[20][20] = {"       #  #       ",
                          "      ##  ##      ",
                          "     ###  ###     ",
                          "    ####  ####    ",
                          "   #####  #####   ",
                          "  ######  ######  ",
                          " #######  ####### ",
                          "########  ########"
                         };
    /*
    for (int i = 0; i < blocks ; i++)
    {
        printf("%s\n", tower[i]);
    }
    */

    int begLine = 8 - blocks;
    //printf("[%d](%d)\n", begLine, lenLine);

    // Arrangement of the tower
    for (int i = 0; i < blocks ; i++)
    {
        int lenLine = (8 + 2) + (i + 1);
        for (int j = begLine; j < lenLine; j++)
        {
            printf("%c", tower[i][j]);
        }
        printf("\n");
    }


}