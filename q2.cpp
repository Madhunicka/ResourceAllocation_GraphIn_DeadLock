#include <iostream>

int main() {
    int n = 3; // number of processes
    int r = 2; // number of resources

    int available[2] = {0, 0}; // Initial available resources

    int allocation[3][2] = {
        {0, 1},
        {1, 0},
        {1, 0}
    };
    int request[3][2] = {
        {1, 0},
        {0, 0},
        {0, 1}
    };

    bool finish[3] = {false, false, false}; // Finish flag for each process
    int work[2]; // Work array
    for (int i = 0; i < r; i++) {
        work[i] = available[i];
    }

    bool deadlock = false;

    while (true) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < r; j++) {
                    if (request[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < r; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            for (int i = 0; i < n; i++) {
                if (!finish[i]) {
                    deadlock = true;
                }
            }
            break;
        }
    }

    if (deadlock) {
        std::cout << "Detection of Deadlock\n";
    } else {
        std::cout << "No Deadlock detected\n";
    }

    return 0;
}
