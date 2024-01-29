#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; 
}

int main() {

    key_t key = ftok("shmfile", 65);

    int shmid = shmget(key, 5 * sizeof(int), 0666 | IPC_CREAT);

    int *arr = (int*) shmat(shmid, NULL, 0);

    int keyToSearch;
    printf("Enter the value to search: ");
    scanf("%d", &keyToSearch);

    int result = binarySearch(arr, 0, 4, keyToSearch);

   
    printf("Sorted array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    if (result != -1) {
        printf("Value %d found at index %d\n", keyToSearch, result);
    } else {
        printf("Value %d not found\n", keyToSearch);
    }

    shmdt(arr);

    return 0;
}
