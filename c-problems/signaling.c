#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_error_counts(char *server, int *errorCountsArray)
{
    int index = server[1] - '1';
    return errorCountsArray[index];
}

void set_error_count(char *server, int *errorCountsArray, int count)
{
    int index = server[1] - '1';
    errorCountsArray[index] = count;
}

void main()
{
    unsigned int n; // number if servers
    int m;          // number of logs

    scanf("%u", &n);
    scanf("%d", &m);

    char ***serverLogs = malloc(m * sizeof(char **));
    int *error_count_array = calloc(n, sizeof(int));

    for (int i = 0; i < m; i++)
    {
        serverLogs[i] = malloc(2 * sizeof(char *));
        serverLogs[i][0] = malloc(2 * sizeof(char));  // holds server name
        serverLogs[i][1] = malloc(10 * sizeof(char)); // holds server status

        scanf("%s", serverLogs[i][0]);
        scanf("%s", serverLogs[i][1]);
    }

    int faulty_servers = 0;

    for (int i = 0; i < m; i++)
    {
        char *serverName = serverLogs[i][0];
        char *serverStatus = serverLogs[i][1];
        if (strcmp("error", serverStatus) == 0)
        { // error detected
            if (get_error_counts(serverName, error_count_array) > 1)
            { // server is faulty
                faulty_servers++;
            }
            else
            {
                set_error_count(serverName, error_count_array,
                                get_error_counts(serverName, error_count_array) + 1);
            }
        }
        else
        { // success
            set_error_count(serverName, error_count_array, 0);
        }
    }

    printf("Total faulty Servers: %d\n", faulty_servers);
    free(serverLogs);
    return;
}