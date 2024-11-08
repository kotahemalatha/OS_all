#include <stdio.h>
#include <limits.h>

int main() {
    int n = 5;
    int i = 0;
    int requests[] = {30, 10, 40, 70, 60};
    int initial_head = 50;
    int vis[100] = {0};
    int current_position = initial_head;
    int distance;
    int total_seek_time = 0;

    while (i < n) {
        int min = INT_MAX;
        int index = -1;
        int leastdiff;

        for (int j = 0; j < n; j++) {
            if (vis[j] == 0) {  // Only consider unvisited requests
                if (current_position > requests[j]) {
                    leastdiff = current_position - requests[j];
                } else {
                    leastdiff = requests[j] - current_position;
                }

                // Update min if the current difference is smaller
                if (leastdiff < min) {
                    min = leastdiff;
                    index = j;
                }
            }
        }

        // Mark the selected request as visited
        if (index != -1) {
            vis[index] = 1;
            distance = min;  // The minimum distance found
            total_seek_time += distance;
            current_position = requests[index];  // Move to the selected request
            i++;
        }
    }

    printf("Total seek time is %d\n", total_seek_time);
    return 0;
}
