#include <stdio.h>

int main() {
    int n, i, time_quantum, remaining[10], turnaround[10], waiting[10];
    int burst[10], total_time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    int t = 0;
    while (completed < n) {
        for (i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                if (remaining[i] <= time_quantum) {
                    t += remaining[i];
                    turnaround[i] = t;
                    waiting[i] = turnaround[i] - burst[i];
                    remaining[i] = 0;
                    completed++;
                } else {
                    t += time_quantum;
                    remaining[i] -= time_quantum;
                }
            }
        }
    }

    float avg_wt = 0, avg_tat = 0;
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        avg_wt += waiting[i];
        avg_tat += turnaround[i];
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burst[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat / n);

    return 0;
}
//Enter number of processes: 3
//Enter Burst Time for process 1: 24
//Enter Burst Time for process 2: 3
//Enter Burst Time for process 3: 3
//Enter time quantum: 4

//PROCESS	BURST TIME	WAITING TIME	TURNAROUND TIME
//1	24		6		30
//2	3		4		7
//3	3		7		10

//Average Waiting Time: 5.67
//Average Turnaround Time: 15.67
