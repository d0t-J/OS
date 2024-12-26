#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_RESOURCES 3

int availableResource[MAX_RESOURCES] = {0, 0, 0};
int Processes_No = 0, Resources_No = 0;
char resource_labels[] = {'A', 'B', 'C'};

struct Process
{
    int id;
    int allocation[MAX_RESOURCES];
    int max[MAX_RESOURCES];
    int need[MAX_RESOURCES];
    bool terminated;
};

void input(struct Process *processes)
{
    do
    {
        printf("Enter the number of Resources: ");
        scanf("%d", &Resources_No);
    } while (Resources_No <= 0 || Resources_No > MAX_RESOURCES);

    printf("Enter the available resources (in order %c to %c):\n", resource_labels[0], resource_labels[Resources_No - 1]);
    for (int i = 0; i < Resources_No; i++)
    {
        do
        {
            printf("Resource %d: ", i + 1);
            scanf("%d", &availableResource[i]);
        } while (availableResource[i] < 0);
    }

    for (int i = 0; i < Processes_No; i++)
    {
        processes[i].id = i + 1;
        processes[i].terminated = false;

        // * Allocation Resources
        printf("Enter the allocation for process %d (in order %c to %c):\n", i + 1, resource_labels[0], resource_labels[Resources_No - 1]);
        for (int j = 0; j < Resources_No; j++)
        {
            printf("%c: ", resource_labels[j]);
            scanf("%d", &processes[i].allocation[j]);
        }
        //* Max Resources
        printf("Enter the max resources for process %d (in order %c to %c):\n", i + 1, resource_labels[0], resource_labels[Resources_No - 1]);
        for (int j = 0; j < Resources_No; j++)
        {
            printf("%c: ", resource_labels[j]);
            scanf("%d", &processes[i].max[j]);
        }

        // * Need Matrix = Max - Allocation
        for (int j = 0; j < Resources_No; j++)
        {
            processes[i].need[j] = processes[i].max[j] - processes[i].allocation[j];
            if (processes[i].need[j] < 0)
            {
                printf("Error: Need matrix can't be negative\n");
                input(processes);
                return;
            }
        }
    }
}

bool is_Safe(struct Process *processes)
{
    int *currentResources = (int *)malloc(Resources_No * sizeof(int));

    for (int i = 0; i < Resources_No; i++)
    {
        currentResources[i] = availableResource[i];
    }

    bool safeProcess;
    // * safeProcess is a flag variable to check if there is a process that can be executed
    // * If there is at least one process that completely executes, the safeProcess will be true and bankers algorithm will indicate that there is no deadlock
    do
    {
        safeProcess = false;
        for (int i = 0; i < Processes_No; i++)
        {
            if (processes[i].terminated == false)
            {
                bool canExecute = true;
                for (int j = 0; j < Resources_No; j++)
                {
                    if (processes[i].need[j] > currentResources[j])
                    {
                        canExecute = false;
                        break;
                    }
                }

                if (canExecute == true)
                {
                    safeProcess = true;
                    processes[i].terminated = true;
                    for (int j = 0; j < Resources_No; j++)
                    {
                        currentResources[j] += processes[i].allocation[j];
                    }
                }
            }
        }
    } while (safeProcess == true);

    for (int i = 0; i < Processes_No; i++)
    {
        if (processes[i].terminated == false)
        {
            return false;
        }
    }
    free(currentResources);
    return true;
}

int main()
{
    do
    {
        printf("Enter the number of Processes: ");
        scanf("%d", &Processes_No);
    } while (Processes_No <= 0);

    struct Process *processes = (struct Process *)malloc(Processes_No * sizeof(struct Process));
    if (processes == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    input(processes);
    if (is_Safe(processes) == true)
    {
        printf("The system is in a safe state\n");
    }
    else
    {
        printf("The system is in an unsafe state\n");
    }

    free(processes);
    return 0;
}