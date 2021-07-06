#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Getting name of the User
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}