// Write a C++ program to generate Fibonacci sequence using fork()
#include <iostream>
#include <unistd.h>   // for fork()
#include <sys/types.h>
#include <sys/wait.h> // for wait()

using namespace std;
class A{
public:
void fibo(int n){
    int i;
    pid_t pid = fork();

    if (pid < 0) {  // Fork failed
        cout << "Fork failed!" << endl;
        return;
    }
    else if (pid == 0) {        // Child process
        int t1 = 0, t2 = 1, next;

        cout << "\nChild process generating Fibonacci sequence:\n";

        for (i = 0; i < n; i++) {
            cout << t1 << " "<<endl;
            next = t1 + t2;
            t1 = t2;
            t2 = next;
        }
        cout << endl;
    }
    else {       // Parent process
        wait(NULL);  // wait for child to finish
        cout << "\nParent process: Child completed execution." << endl;
    }
}

};
int main() {
    int n, i;

    cout << "Enter number of terms: ";
    cin >> n;
    A o;
    o.fibo(n);
  
     return 0;
}
