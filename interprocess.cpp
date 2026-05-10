// Write a C++ program to implement IPC using Shared Memory
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>

using namespace std;

class IPC {
    int shmid;
    char *str;
public:
    void create() {
        shmid = shmget(IPC_PRIVATE, 1024, 0666 | IPC_CREAT);
        str = (char*) shmat(shmid, NULL, 0);
    }
    void writeData() {
        strcpy(str, "Hello from Parent");
        cout << "Parent wrote: " << str << endl;
    }
    void readData() {
        cout << "Child read: " << str << endl;
    }
    void remove() {
        shmdt(str);
        shmctl(shmid, IPC_RMID, NULL);
    }
};
int main() {

    IPC obj;
    obj.create();
    pid_t pid = fork();

    if(pid > 0) {
        obj.writeData();
        wait(NULL);
        obj.remove();
    }
    else {
        sleep(1);
        obj.readData();
    }
    return 0;
}
