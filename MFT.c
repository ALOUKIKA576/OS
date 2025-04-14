
#include <stdio.h>

int main() {
    int memSize, partSize, numParts;
    int numProcesses, processSize[10];
    int i, allocated[10] = {0};

    printf("Enter total memory size (in KB): ");
    scanf("%d", &memSize);

    printf("Enter partition size (in KB): ");
    scanf("%d", &partSize);

    numParts = memSize / partSize;
    printf("Number of partitions available: %d\n", numParts);

    printf("Enter number of processes: ");
    scanf("%d", &numProcesses);

    for (i = 0; i < numProcesses; i++) {
        printf("Enter memory required for process %d (in KB): ", i + 1);
        scanf("%d", &processSize[i]);
    }

    printf("\n--- Memory Allocation in MFT ---\n");
    int part = 0;

    for (i = 0; i < numProcesses; i++) {
        if (part < numParts) {
            if (processSize[i] <= partSize) {
                printf("Process %d of size %d KB is allocated to Partition %d\n", i + 1, processSize[i], part + 1);
                allocated[i] = 1;
                printf("Internal Fragmentation for Partition %d: %d KB\n", part + 1, partSize - processSize[i]);
                part++;
            } else {
                printf("Process %d of size %d KB cannot be allocated (Too large)\n", i + 1, processSize[i]);
            }
        } else {
            printf("No more partitions available for Process %d\n", i + 1);
        }
    }

    int totalIF = 0;
    for (i = 0; i < numProcesses; i++) {
        if (allocated[i]) {
            totalIF += partSize - processSize[i];
        }
    }

    printf("\nTotal Internal Fragmentation: %d KB\n", totalIF);
    return 0;
}
//output
//Enter total memory size (in KB): 1000
//Enter partition size (in KB): 200
//Number of partitions available: 5
//Enter number of processes: 4
//Enter memory required for process 1 (in KB): 120
//Enter memory required for process 2 (in KB): 350
//Enter memory required for process 3 (in KB): 200
//Enter memory required for process 4 (in KB): 90

--- Memory Allocation in MFT ---
//Process 1 of size 120 KB is allocated to Partition 1
//Internal Fragmentation for Partition 1: 80 KB
//Process 2 of size 350 KB cannot be allocated (Too large)
//Process 3 of size 200 KB is allocated to Partition 2
//Internal Fragmentation for Partition 2: 0 KB
//Process 4 of size 90 KB is allocated to Partition 3
//Internal Fragmentation for Partition 3: 110 KB

//Total Internal Fragmentation: 190 KB
