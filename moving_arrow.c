#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define RED "\x1B[31m"
#define GRE "\x1B[32m"
#define RESET "\x1B[0m"
#define YEL "\x1B[33m"
int main()
{
    int i, j, k, l;

    for (i = 0; i < 79; i++)
    {
        printf("\n\n\n\n\n\n\n");
        printf("                                 ");
        for (j = 0; j <= i; j++)
        {
            printf(" ");
        }
        printf(YEL "}}====>" RESET);
        for (k = 78; k >= i; k--)
        {
            printf(" ");
        }
        printf(RED "TARGET\n" RESET);
        if (i == 78)

        {
            usleep(40000);
            system("clear");
            printf("\n\n\n\n\n\n\n");
            printf("                                 ");
            for (l = 0; l <= 85; l++)
            {
                printf(" ");
            }
            printf(GRE "DESTROYED !\n" RESET);
            sleep(2);
        }

        usleep(40000);
        system("clear");
    }
}
