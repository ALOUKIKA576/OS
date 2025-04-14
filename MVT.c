#include <stdio.h>

int main() {
    int totalMemory, usedMemory = 0, processSize;
    int choice, processCount = 0;

    printf("Enter total memory available (in KB): ");
    scanf("%d", &totalMemory);

    do {
        printf("\nEnter memory required for process %d (in KB): ", processCount + 1);
        scanf("%d", &processSize);

        if (processSize <= (totalMemory - usedMemory)) {
            usedMemory += processSize;
            processCount++;
            printf("Process %d allocated. Used memory: %d KB, Remaining memory: %d KB\n", processCount, usedMemory, totalMemory - usedMemory);
        } else {
            printf("Memory not available for process %d. Remaining memory: %d KB\n", processCount + 1, totalMemory - usedMemory);
        }

        printf("\nDo you want to add another process? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("\nTotal memory allocated: %d KB\n", usedMemory);
    printf("Total internal fragmentation: 0 KB\n");
    printf("Total external fragmentation: %d KB\n", totalMemory - usedMemory);

    return 0;
}
//output
//Enter total memory available (in KB): 1000
//Enter memory required for process 1 (in KB): 300
//Process 1 allocated. Used memory: 300 KB, Remaining memory: 700 KB

//Do you want to add another process? (1 for Yes / 0 for No): 1

//Enter memory required for process 2 (in KB): 500
//Process 2 allocated. Used memory: 800 KB, Remaining memory: 200 KB

//Do you want to add another process? (1 for Yes / 0 for No): 1

//Enter memory required for process 3 (in KB): 250
//Memory not available for process 3. Remaining memory: 200 KB

//Do you want to add another process? (1 for Yes / 0 for No): 0

//Total memory allocated: 800 KB
//Total internal fragmentation: 0 KB
//Total external fragmentation: 200 KB
