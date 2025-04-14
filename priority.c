#include <stdio.h>

int main() {
    int p[20], bt[20], pri[20], wt[20], tat[20], i, k, n, temp;
    float wtavg = 0, tatavg = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i] = i + 1; // Process IDs start from 1
        printf("Enter the Burst Time & Priority of Process %d: ", i + 1);
        scanf("%d %d", &bt[i], &pri[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (k = i + 1; k < n; k++) {
            if (pri[i] > pri[k]) {
                // Swap process ID
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
                // Swap burst time
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                // Swap priority
                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];  
        tat[i] = wt[i] + bt[i];         
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    for (i = 0; i < n; i++) {
        printf("\n%d\t%d\t\t%d\t\t%d\t\t%d", p[i], pri[i], bt[i], wt[i], tat[i]);
    }

    wtavg /= n;
    tatavg /= n;

    printf("\nAverage Waiting Time: %.2f", wtavg);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg);

    return 0;
}
//output
//Enter the number of processes: 3
//Enter the Burst Time & Priority of Process 1: 24 2
//Enter the Burst Time & Priority of Process 2: 3  1
//Enter the Burst Time & Priority of Process 3: 12 3

//PROCESS	PRIORITY	BURST TIME	WAITING TIME	TURNAROUND TIME
//2	1		3		0		3
//1 2		24	3		27
//3	3		12	27	39
//Average Waiting Time: 10.00
//Average Turnaround Time: 22.00
