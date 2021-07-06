#include <stdio.h>
#include <string.h>

void displaySTR(char str[]); 

int main(void){
    char c[] = "c string";
    printf("%s\n",c);

    char name[100];
    fgets(name, sizeof(name), stdin);
    printf("\nName: [%s][",name);
    puts(name);
    printf("]");
    displaySTR(name);
 
}

void displaySTR(char str[]){
    char dest_str[10];
    printf("Function display: ");
    puts(str);
    int a = sizeof(str);
    printf("(%d)Function display 2: \n", a);
    int j=0, i=0;
    for(i = 0; i < strlen(str)-1; i+=2)
    {
        if(str[i] == ' '){i++;}
        if(str[i] != ' ')
        {
            printf("(%c)[%d]\n", *(str+i), i); 
            dest_str[j] = str[i];
            j++;
        }
    }
    // DIFERENTES POR CONTA DA POSIÇÃO DO NULL
    printf("size1(%zu)\n", strlen(str));
    printf("size2(%zu)\n", strlen(dest_str));

    str[i] = '\0';
    dest_str[j] = '\0';
    printf("dest(%s)\n", dest_str);
    strcat(str, dest_str);
    puts(str);

    printf("size1(%zu)\n", strlen(str));
    printf("size2(%zu)\n", strlen(dest_str));

    
}
/*
Commonly Used String Functions
    strlen() - calculates the length of a string (até null)
    strcpy(dst,src) - copies a string to another 
    strcmp() - compares two strings (0: equal, 1: different)
    strcat(dst,src) - concatenates two strings
*/