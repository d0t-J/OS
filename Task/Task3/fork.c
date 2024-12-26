#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int n;
    do
    {
        printf("Enter number for the child process to be created: ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Existing Parent ID: %d\n", getpid());
    // * This statement Prints out the parent ID of the current existing process alloted to the running program.
    // * For the sake of understanding the pid that will be printed by this statement will be of the VS Code instance at the run time or the compiled file of this code during its runtime.
    // * Next thing we want to do is to create n number of child processes from the same parent.

    for (int i = 0; i < n; i++)
    {
        pid_t childP = fork();
        // * This fork will be called n times and will create n number of child processes.
        // * The child process will be alloted a different process ID of its own but they all will have the same parent process ID

        if (childP < 0)
        {
            printf("Fork Failed. Try Again!\n");
            exit(1);
            continue;
        }
        else if (childP == 0)
        {
            printf("Child PID: %d of Parent PID: %d\n", getpid(), getppid());
            exit(0);
            // * Successfully terminates the child process that is created and returns to the original parent process.
            // * For the next iteration, the same parent will fork another child process.
        }
        // * This else block can be used to check if for the i-th iteration of the loop, the child processes has the same parent ID or not.
        // else
        // {
        //     printf(" ChID: %d\n ", getpid());
        // }
    }
    for (int i = 0; i < n; i++)
    {
        wait(NULL);
    }
    // * At the end of the program, the parent process should remain alive (ln: 16) and print its own process ID.
    // printf("Parent Process ID: %d\n", getpid());
    return 0;
}