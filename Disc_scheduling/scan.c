#include <stdio.h>
#include <stdlib.h>

int main() {
    int requests[] = {40, 10, 22,35,60, 70, 50};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head = 35;
    int  dirpref=0;  // Change to "left" to start moving left first
    int disk_size = 100;
    
    int total_seek_time = 0;
    int path[100];
    int path_index = 0;
    
    // Start the path with the initial head position
    path[path_index++] = head;

    // Sort the requests array
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (requests[i] > requests[j]) {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    // Split requests into left and right of the head position
    int left[100], right[100];
    int left_count = 0, right_count = 0;

    for (int i = 0; i < n; i++) {
        if (requests[i] < head) {
            left[left_count++] = requests[i];
        } else{
            right[right_count++] = requests[i];
        }
    }

    // Handle direction
    if (dirpref==0) {  // Moving left first
        // Traverse left side
        for (int i = left_count - 1; i >= 0; i--) {
            total_seek_time += abs(head - left[i]);
            head = left[i];
            path[path_index++] = head;
        }

        // After reaching the start, reverse to right if there are remaining requests
        if (right_count > 0) {
            total_seek_time += head;  // Move from current head to 0 (start of disk)
            head = 0;
            path[path_index++] = head;

            // Traverse right side
            for (int i = 0; i < right_count; i++) {
                total_seek_time += abs(head - right[i]);
                head = right[i];
                path[path_index++] = head;
            }
        }

    } else if (dirpref==1) {  // Moving right first
        // Traverse right side
        for (int i = 0; i < right_count; i++) {
            total_seek_time += abs(head - right[i]);
            head = right[i];
            path[path_index++] = head;
        }

        // After reaching the end, reverse to left if there are remaining requests
        if (left_count > 0) {
            total_seek_time += abs(head - disk_size);  // Move from head to end of disk
            head = disk_size;
            path[path_index++] = head;

            // Traverse left side
            for (int i = left_count - 1; i >= 0; i--) {
                total_seek_time += abs(head - left[i]);
                head = left[i];
                path[path_index++] = head;
            }
        }
    }

    // Print the results
    printf("Total Seek Time: %d\n", total_seek_time);
    printf("Path: ");
    for (int i = 0; i < path_index; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");

    return 0;
}
