// Write a program that creates three child processes using fork()
#include <iostream>
#include <unistd.h>     // fork(), getpid(), getppid()
#include <sys/types.h>
#include <sys/wait.h>   // wait()

using namespace std;
class Process {
public:
    void createChildren() {
        for (int i = 1; i <= 3; i++) {
            pid_t pid = fork();
            if (pid < 0) {
                cout << "Fork Failed!" << endl;
                return;
            }
            else if (pid == 0) {
                // Child Process
                cout << "\nChild Process " << i << endl;
                cout << "Child PID  : " << getpid() << endl;
                cout << "Parent PID : " << getppid() << endl;

                return; // Prevent child from creating more children
            }
            else {      // Parent Process
                wait(NULL); // Parent waits for child
            }
        }
        cout << "\nParent Process Finished" << endl;
        cout << "Parent PID : " << getpid() << endl;
    }
};
int main() {
    Process p;
    p.createChildren();
    return 0;
}
