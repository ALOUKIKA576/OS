#include <stdio.h>

int main() {
    int bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;

   
    printf("\nEnter number of processes: ");
    scanf("%d", &n);  // Correct usage of &n

   
    for (i = 0; i < n; i++) {
        printf("\nEnter the burst time of process %d: ", i);
        scanf("%d", &bt[i]);  
    }

   
    wt[0] = 0;  
    tat[0] = bt[0];  

    wtavg = 0;  
    tatavg = 0;  

    
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];  
        tat[i] = wt[i] + bt[i]; 
        wtavg += wt[i];  
        tatavg += tat[i];  
    }

    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");

    for (i = 0; i < n; i++) {
        printf("\n\tP%d\t\t%d\t\t%d\t\t%d", i, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %f", wtavg / n);
    printf("\nAverage Turnaround Time: %f", tatavg / n);

    return 0;
}
