#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define N 5
#define MAX_SIZE 1000

void nonPreemptivePriorityScheduling(int n, int arrivalTimes[], int burstTimes[], int startTimes[], int finishTimes[], int priorities[], int hasArrived[], int currentProcesses[]) {
    int totalTime = 0;
    for (int i = 0; i < n; i++) {
        totalTime += burstTimes[i];
    }

    int currentTime = 0, processPointer = 0;
    while (currentTime < totalTime) {
        for (int i = 0; i < n; i++) {
            if (arrivalTimes[i] <= currentTime && !hasArrived[i]) {
                hasArrived[i] = 1;
            }
        }

        int maxPriority = -1;
        int maxIndex = -1;
        for (int i = 0; i < n; i++) {
            if (hasArrived[i] && priorities[i] > maxPriority) {
                maxPriority = priorities[i];
                maxIndex = i;
            }
        }

        if (maxIndex != -1) {
            currentProcesses[processPointer] = maxIndex + 1;
            processPointer++;
            startTimes[maxIndex] = currentTime;
            currentTime += burstTimes[maxIndex];
            finishTimes[maxIndex] = currentTime;
            priorities[maxIndex] = -1; // In non-preemptive, the process completes without interruption
        } else {
            break;
        }
    }
}

void printProcessQueue(int n, int currentProcesses[]) {
    int i;
    for (i = 0;; i++) {
        if (currentProcesses[i + 1] == -1) {
            break;
        }
        printf("P%d->", currentProcesses[i]);
    }
    printf("P%d\n", currentProcesses[i]);
}

void printProcessDetails(int n, int arrivalTimes[], int burstTimes[], int startTimes[], int finishTimes[]) {
    int waitingTimes = 0;
    int responseTimes = 0;

    for (int i = 0; i < n; i++) {
        printf("P%d:\n", i + 1);
        printf("Start Time: %d\n", startTimes[i]);
        printf("Finish Time: %d\n", finishTimes[i]);
        printf("Waiting Time: %d\n", finishTimes[i] - arrivalTimes[i] - burstTimes[i]);
        printf("Response Time: %d\n", startTimes[i] - arrivalTimes[i]);

        waitingTimes += finishTimes[i] - arrivalTimes[i] - burstTimes[i];
        responseTimes += startTimes[i] - arrivalTimes[i];
    }

    printf("Average Waiting Time: %lf\n", (double)waitingTimes / n);
    printf("Average Response Time: %lf\n", (double)responseTimes / n);
}

int main() {
    int arrivalTimes[N] = {3, 0, 1, 4, 5};
    int burstTimes[N] = {10, 1, 2, 7, 5};
    int startTimes[N], finishTimes[N];
    int priorities[N] = {3, 1, 3, 4, 2};
    int hasArrived[N], currentProcesses[MAX_SIZE];

    for (int i = 0; i < N; i++) {
        startTimes[i] = -1;
        finishTimes[i] = 0;
        hasArrived[i] = 0;
        currentProcesses[i] = 0;
    }

    memset(currentProcesses, -1, sizeof(currentProcesses));
    nonPreemptivePriorityScheduling(N, arrivalTimes, burstTimes, startTimes, finishTimes, priorities, hasArrived, currentProcesses);

    printf("Non-Preemptive Priority Scheduling:\n");
    printProcessQueue(N, currentProcesses);
    printProcessDetails(N, arrivalTimes, burstTimes, startTimes, finishTimes);

    return 0;
}
