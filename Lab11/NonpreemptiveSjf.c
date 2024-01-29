#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define N 5
#define MAX_SIZE 1000

void nonPreemptiveShortestJobFirst(int n, int arrivalTimes[], int burstTimes[], int startTimes[], int finishTimes[], int hasArrived[], int hasVisited[], int currentProcesses[]) {
    int totalTime = 0;
    for (int i = 0; i < n; i++) {
        totalTime += burstTimes[i];
    }

    int currentTime = 0;
    int processPointer = 0;
    while (currentTime < totalTime) {
        for (int i = 0; i < n; i++) {
            if (arrivalTimes[i] <= currentTime && !hasArrived[i]) {
                hasArrived[i] = 1;
            }
        }

        int minBurst = INT_MAX;
        int minIndex = -1;
        for (int i = 0; i < n; i++) {
            if (hasArrived[i] && !hasVisited[i] && burstTimes[i] < minBurst) {
                minBurst = burstTimes[i];
                minIndex = i;
            }
        }

        if (minIndex != -1) {
            currentProcesses[processPointer] = minIndex + 1;
            processPointer++;
            startTimes[minIndex] = currentTime;
            currentTime += burstTimes[minIndex];
            finishTimes[minIndex] = currentTime;
            hasVisited[minIndex] = 1;
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

    printf("Average Waiting Time: %.2lf\n", (double)waitingTimes / n);
    printf("Average Response Time: %.2lf\n", (double)responseTimes / n);
}

int main() {
    int arrivalTimes[N] = {3, 0, 1, 4, 5};
    int burstTimes[N] = {10, 1, 2, 7, 5};
    int startTimes[N], finishTimes[N];
    int hasArrived[N], hasVisited[N];
    int currentProcesses[MAX_SIZE];

    for (int i = 0; i < N; i++) {
        startTimes[i] = -1;
        finishTimes[i] = 0;
        hasArrived[i] = 0;
        hasVisited[i] = 0;
        currentProcesses[i] = 0;
    }

    memset(currentProcesses, -1, sizeof(currentProcesses));
    nonPreemptiveShortestJobFirst(N, arrivalTimes, burstTimes, startTimes, finishTimes, hasArrived, hasVisited, currentProcesses);

    printf("Non-Preemptive Shortest Job First:\n");
    printProcessQueue(N, currentProcesses);
    printProcessDetails(N, arrivalTimes, burstTimes, startTimes, finishTimes);

    return 0;
}
