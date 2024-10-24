#include <stdio.h>

void sortProcessesByBurstTime(int n, int burst_time[], int process[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (burst_time[j] > burst_time[j + 1]) {
                // Swap burst times
                int temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;

                // Swap corresponding process IDs
                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst_time[n], waiting_time[n], turnaround_time[n], process[n];

    // Input burst times
    for (int i = 0; i < n; i++) {
        process[i] = i + 1; // Process IDs from 1 to n
        printf("Enter Burst Time for Process %d: ", process[i]);
        scanf("%d", &burst_time[i]);
    }

    // Sort processes by burst time
    sortProcessesByBurstTime(n, burst_time, process);

    // Calculate waiting times
    waiting_time[0] = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
    }

    // Calculate turnaround times
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    // Print results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", process[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    return 0;
}
