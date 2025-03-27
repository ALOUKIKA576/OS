#include <stdio.h>

int main() {
    int bt[20], wt[20], tat[20], p[20], i, j, n, temp;
    float wtavg = 0, tatavg = 0;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i] = i; // Process IDs (P0, P1, P2, ...)
        printf("\nEnter the burst time for process P%d: ", i);
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                // Swap burst times
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
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
    printf("\n\tProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %f", wtavg / n);
    printf("\nAverage Turnaround Time: %f", tatavg / n);

    return 0;
}
