#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
char keys[500000][10];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %s", keys[i]);
    }
    for (int i = 1; i < n; i++)
    {
        if (keys[i][0] == keys[i - 1][strlen(keys[i - 1]) - 1])
            for (int j = 0; j < i; j++)
            {
                if (!strcmp(keys[i], keys[j]))
                {
                    i % 2 ? printf("Alice") : printf("Bob");
                    exit(0);
                }
            }
        else
        {
            i % 2 ? printf("Alice") : printf("Bob");
            exit(0);
        }
    }
    if(n%2){
        printf("Alice");
    }
    else{
        printf("Bob");
    }
}