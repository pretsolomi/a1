// Write a C++ program to create and use Shared Memory

#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>

using namespace std;

#define SHM_SIZE 1024

int main() {

    int shmid;
    char* str;

    // Create shared memory
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, 0666 | IPC_CREAT);

    // Attach shared memory
    str = (char*) shmat(shmid, NULL, 0);

    // Write into shared memory
    strcpy(str, "Hello, Shared Memory!");

    // Display data
    cout << "Data written in shared memory: " << str << endl;

    // Detach shared memory
    shmdt(str);

    // Delete shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
