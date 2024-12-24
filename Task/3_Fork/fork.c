#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 5

int nums[SIZE] = {0, 1, 2, 3, 4};

int main()
{
    int n;
    do
    {
        printf("Enter number for the child process to be created: ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Existing Parent ID: %d\n", getpid());

    for (int i = 0; i < n; i++)
    {
        pid_t childP = fork();

        if (childP < 0)
        {
            printf("Fork Failed. Try Again!\n");
            exit(1);
            continue;
        }
        else if (childP == 0)
        {
            printf("Child Process ID: %d\t of Parent Process ID: %d\n", getpid(), getppid());
            exit(0);
            continue;
        }
        // else
        // {
        //     // printf(" ChID: %d   Parent Process ID: %d\n", getpid(), getppid());
        //     printf(" ChID: %d\n ", getpid());
        // }
    }
    for (int i = 0; i < n; i++)
    {
        wait(NULL);
    }
    //  printf("Parent Process ID: %d\n", getpid());

    return 0;
}