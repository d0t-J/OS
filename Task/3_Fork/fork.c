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

    pid_t p = fork();

    if (p < 0)
    {
        printf("Fork Failed. Try Again!\n");
        exit(1);
    }
    else if (p == 0)
    {
        printf("Child Process ID: %d\t of Parent Process ID: %d\n", getpid(), getppid());
        for (int i = 1; i < n; i++)
        {
            pid_t childP = fork();
            if (childP == 0)
            {
                printf("Child Process ID: %d\t of Parent Process ID: %d\n", getpid(), getppid());
                exit(0);
                continue;
            }
        }
        exit(0);
        return 0;
    }
    else if (p > 0)
    {
        wait(NULL);
        printf("Parent Process ID: %d\n", getppid());
    }
    return 0;
}