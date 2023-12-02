#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STRINGS 1000



int main(){
    char scarmbled_strings[MAX_STRINGS][70]; 
    FILE *file; 
    char a,b,c[2];
    int d, totalSum = 0; 
    char s[70]; 
    int N =0;
    file = fopen("source.txt", "r"); 
    if (file == NULL) {
            printf("Something went wrong when opening the file");
            return 0;
    }

    while(fgets(s, 70, file)!=NULL){N++;}
    rewind(file);
    for(int i=0;i<N && i<MAX_STRINGS;i++){

        fgets(s, 70, file);
        strcpy(scarmbled_strings[i], s);
        //printf("%s", s );
    }

    fclose(file); 

    for(int i = 0; i < sizeof(scarmbled_strings)/sizeof(scarmbled_strings[0]); i++)
    {
        for(int j = 0; j < strlen(scarmbled_strings[i]); j++)
        {
            if(isdigit(scarmbled_strings[i][j]))
            {
                a = scarmbled_strings[i][j]; 
                //printf("%c", a);
                break; 
            }
            
        }

        for(int k = strlen(scarmbled_strings[i]); k >= 0; k--)
        {
            if(isdigit(scarmbled_strings[i][k]))
                {
                b = scarmbled_strings[i][k]; 
                //printf("%c", b);
                break; 
                }
          
        }
    c[0] = a;
    c[1] = b;
    c[2] = '\0';
    d = atoi(c); 
    printf("%d\n",d);
    totalSum += d;
    }

printf("\n%d", totalSum); 


}