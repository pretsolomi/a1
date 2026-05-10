
// Program to simulate Non-Preemptive CPU Scheduling Algorithms
// a) FCFS
// b) SJF
// c) Priority Scheduling
// and find Average Waiting Time
#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int pid;
    int bt;   // Burst Time
    int pr;   // Priority
    int wt;   // Waiting Time
};
    // -------- FCFS --------
void fcfs(Process p[], int n) {
    int total_wt = 0;
    p[0].wt = 0;
    // Calculate waiting time
    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }
    cout << "\n===== FCFS Scheduling =====\n";
    cout << "PID\tBT\tWT\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << "\t"
             << p[i].bt << "\t"
             << p[i].wt << endl;

        total_wt += p[i].wt;
    }
    cout << "Average Waiting Time = "
         << (float)total_wt / n << endl;
}
// ---------- SJF (Non-Preemptive) ----------
bool compareBT(Process a, Process b) {
    return a.bt < b.bt;
}

void sjf(Process p[], int n) {
    int total_wt = 0;

    // Sort by Burst Time
    sort(p, p + n, compareBT);

    p[0].wt = 0;

    // Calculate waiting time
    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }

    cout << "\n===== SJF Scheduling =====\n";
    cout << "PID\tBT\tWT\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << "\t"
             << p[i].bt << "\t"
             << p[i].wt << endl;

        total_wt += p[i].wt;
    }

    cout << "Average Waiting Time = "
         << (float)total_wt / n << endl;
}

// ---------- Priority Scheduling ----------
bool comparePR(Process a, Process b) {
    return a.pr < b.pr;   // Lower number = Higher priority
}

void priorityScheduling(Process p[], int n) {
    int total_wt = 0;

    // Sort by Priority
    sort(p, p + n, comparePR);

    p[0].wt = 0;

    // Calculate waiting time
    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }

    cout << "\n===== Priority Scheduling =====\n";
    cout << "PID\tBT\tPR\tWT\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << "\t"
             << p[i].bt << "\t"
             << p[i].pr << "\t"
             << p[i].wt << endl;

        total_wt += p[i].wt;
    }

    cout << "Average Waiting Time = "
         << (float)total_wt / n << endl;
}

// ---------------- Main Function ----------------
int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    Process p[100], temp[100];
    // Input
    cout << "\nEnter Burst Time and Priority:\n";

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        cout << "\nProcess P" << i + 1 << endl;

        cout << "Enter Burst Time: ";
        cin >> p[i].bt;

        cout << "Enter Priority: ";
        cin >> p[i].pr;
    }
    // FCFS
    for (int i = 0; i < n; i++) {
        temp[i] = p[i];
    }
    fcfs(temp, n);
    
    // SJF
    for (int i = 0; i < n; i++) {
        temp[i] = p[i];
    }
    sjf(temp, n);
    // Priority
    for (int i = 0; i < n; i++) {
        temp[i] = p[i];
    }
    priorityScheduling(temp, n);
    return 0;
}
   
