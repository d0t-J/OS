#include <stdio.h>

int avgWaitingTime = 0;
int avgTurnAroundTime = 0;

struct Process
{
    int pid;
    int arrivalTime;
    int burstTime;
    // * Waiting time = Turnaround time - Burst time
    int waitingTime;
    // * Turnaround time = Completion time - Arrival time
    int turnaroundTime;
    // * Completion time = Turnaround time + Arrival time
    // * Completion time indicates the "time at which" the process completes its execution
    int completionTime;
};

// * An example of 3 processes with predefined values
struct Process PredefinedProcesses[3] = {
    {1, 0, 5, 0, 0},
    {2, 2, 10, 0, 0},
    {3, 4, 6, 0, 0}};

void swap(struct Process *a, struct Process *b)
{
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void FCFS_Scheduling(struct Process processes[], int n)
{
    // * This loop sorts the processes according to their arrival time in case the user inputs the processes in random order w.r.t to arrival time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (processes[i].arrivalTime > processes[j].arrivalTime)
            {
                swap(&processes[i], &processes[j]);
            }
        }
    }

    // * currentTime: Variable to keep track of current time in the CPU during the scheduling of each process in the queue
    int currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        if (currentTime < processes[i].arrivalTime)
        {
            currentTime = processes[i].arrivalTime;
        }
        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        currentTime += processes[i].burstTime;
        processes[i].turnaroundTime = currentTime - processes[i].arrivalTime;
        processes[i].completionTime = currentTime;

        avgWaitingTime += processes[i].waitingTime;
        avgTurnAroundTime += processes[i].turnaroundTime;
    }
}

void DisplayResults(struct Process processes[], int n)
{
    printf("PID\t|| Arrival Time\t||  Burst Time\t|| Waiting Time\t||   Turnaround Time\t|| Completion Time\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d\t||\t%d\t||\t%d\t||\t%d\t||\t  %d\t\t||\t%d\n", processes[i].pid, processes[i].arrivalTime, processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime, processes[i].completionTime);
    }
    printf("\nAverage Waiting Time: %.2f\n", (float)avgWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)avgTurnAroundTime / n);

    printf("\nGantt Chart:\n");
}

void GanttChart(struct Process processes[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            printf("|");
        }
        for (int j = 0; j <= processes[i].burstTime; j++)
        {
            if (j == processes[i].burstTime)
            {
                printf("|");
            }
            else if (j == processes[i].burstTime / 2)
            {
                printf("P%d", processes[i].pid);
                if (processes[i].burstTime % 2 == 0)
                {
                    printf("-");
                }
            }
            else
            {
                printf("-");
            }
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            printf("0");
        }
        for (int j = 0; j <= processes[i].burstTime; j++)
        {
            if (j == processes[i].burstTime)
            {
                printf("%d", processes[i].completionTime);
            }
            else if (j == processes[i].burstTime / 2)
            {
                printf("  ");
                if (processes[i].burstTime % 2 == 0)
                {
                    printf(" ");
                }
            }
            else
            {
                printf(" ");
            }
        }
    }
    printf("\n");
}

void CustomProcesses()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    if (n <= 1)
    {
        do
        {
            printf("Enter number greater than 1 (for more than one process): ");
            scanf("%d", &n);
        } while (n <= 1);
    }

    struct Process processes[n];
    for (int i = 0; i < n; i++)
    {
        processes[i].pid = i + 1;
        printf("For process %d: \n", i + 1);
        printf("Enter arrival time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burstTime);
        printf("\n");
    }

    FCFS_Scheduling(processes, n);
    DisplayResults(processes, n);
    GanttChart(processes, n);
}

void ExampleProcesses()
{
    int n = 3;
    FCFS_Scheduling(PredefinedProcesses, n);
    DisplayResults(PredefinedProcesses, n);
    GanttChart(PredefinedProcesses, n);
}

int main()
{
    int choice;

    printf("Select an option for FCFS:\n");
    printf("1. Enter custom sequence of processes\n");
    printf("2. Use a predefined example of processes\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
    } while (choice != 1 && choice != 2);

    if (choice == 1)
    {
        CustomProcesses();
    }
    else if (choice == 2)
    {
        ExampleProcesses();
    }
    return 0;
}