#include <stdio.h>
#include <limits.h>

int main() {
    int n = 5; // Number of processes
    int m = 6; // Number of memory partitions

    int PID[] = {1, 2, 3, 4, 5};               
    int mem_req[] = {100, 250, 30, 300, 150};  
    int RAM[] = {100, 150, 300, 10, 400, 100}; 
    int internal_frag[6] = {0};                
    int status[6] = {0};                       
    int job[6];                                

    
    for (int i = 0; i < m; i++) {
        job[i] = -1;
    }


    for (int i = 0; i < n; i++) {
        int allocation = 0;  
        int index = -1;   
        int max = INT_MIN;

        
        for (int j = 0; j < m; j++) {
            if (RAM[j] >= mem_req[i] && status[j] == 0) {
                if (RAM[j] > max) {
                    max = RAM[j];
                    index = j;
                }
            }
        }

        
        if (index != -1) {
            status[index] = 1;                       
            internal_frag[index] = RAM[index] - mem_req[i]; 
            job[index] = PID[i];                     
            allocation = 1;                         
        }

        
        if (!allocation) {
            printf("Process ID %d with memory requirement %d can't be allocated\n", PID[i], mem_req[i]);
        }
    }

   
    printf("\nMemory Allocation Table:\n");
    printf("Partition\tSize\tProcess\tInternal Fragmentation\tStatus\n");
    for (int i = 0; i < m; i++) {
        if (job[i] != -1) {
            printf("%d\t\t%d\t%d\t%d\t\t\t%d\n", i + 1, RAM[i], job[i], internal_frag[i], status[i]);
        } else {
            printf("%d\t\t%d\tNone\t%d\t\t\t%d\n", i + 1, RAM[i], internal_frag[i],status[i]);
        }
    }

    return 0;
}
