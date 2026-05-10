// Write a C++ program to demonstrate process creation using fork()

#include <iostream>
#include <unistd.h>   // fork(), getpid(), getppid()
#include <sys/types.h>

using namespace std;
void gg(pid_t pid){
    
    if (pid < 0) {
        // Fork failed
        cout << "Fork failed!" << endl;
        return ;
    }
    else if (pid == 0) {
        // Child process
        cout << "This is the child process." << endl;
        cout << "Child PID1: " << getpid() << endl;
        cout << "Parent PID1: " << getppid() << endl;
    }
    else {
        // Parent process
        cout <<endl<< "This is the parent process." << endl;
        cout << "Parent PID: " << getpid() << endl;
        cout << "Child PID: " << pid << endl;
    }
}
int main() {
    pid_t pid;

    // Create a child process
    pid = fork();
    gg(pid);
    return 0;
}
