/*take string from the user and print every word in a line*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() 
{ 
    char *name = malloc(sizeof(char)*1024);
    gets(name);
    name = realloc(name , strlen(name));
    int i = 0;
    while(*(name+i) != '\0')
    {
        printf("%c",name[i]);
        if(*(name+i) == 32){printf("\n");}
        i++;
    }
    free(name);
    return 0;
}    
        



