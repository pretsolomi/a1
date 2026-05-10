// Write a C++ program to generate safe sequence using Banker's Algorithm
#include <iostream>
#include <vector>

using namespace std;

class Banker {
private:
    int n, m; // n = processes, m = resources

    vector<vector<int>> allocation;
    vector<vector<int>> max_claim;
    vector<vector<int>> need;

    vector<int> available;

public:

    // Function to take input
    void input() {
        cout << "Enter number of processes: ";
        cin >> n;
        cout << "Enter number of resource types: ";
        cin >> m;
        allocation.assign(n, vector<int>(m));
        max_claim.assign(n, vector<int>(m));
        need.assign(n, vector<int>(m));
        available.assign(m, 0);
        // Allocation Matrix Input
        cout << "\nEnter Allocation Matrix:\n";

        for (int i = 0; i < n; i++) {

            cout << "For Process P" << i << ":\n";

            for (int j = 0; j < m; j++) {
                cin >> allocation[i][j];
            }
        }

        // Max Matrix Input
        cout << "\nEnter Max Matrix:\n";

        for (int i = 0; i < n; i++) {

            cout << "For Process P" << i << ":\n";

            for (int j = 0; j < m; j++) {
                cin >> max_claim[i][j];
            }
        }
        // Available Resources Input
        cout << "\nEnter Available Resources:\n";

        for (int i = 0; i < m; i++) {
            cin >> available[i];
        }
        // Calculate Need Matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                need[i][j] = max_claim[i][j] - allocation[i][j];
            }
 } }
    // Function to display Need Matrix
    void displayNeed() {
        cout << "\nNeed Matrix:\n";

        for (int i = 0; i < n; i++) {
            cout << "P" << i << " : ";
            for (int j = 0; j < m; j++) {
                cout << need[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function to find safe sequence
    void findSafeSequence() {
        vector<int> work = available;
        vector<bool> finish(n, false);
        vector<int> safeSequence;
        int count = 0;
        while (count < n) {
            bool found = false;
            for (int p = 0; p < n; p++) {       // Process should not be finished
                if (!finish[p]) {
                    int j;
                    // Check if resources can be allocated
                    for (j = 0; j < m; j++) {
                        if (need[p][j] > work[j]) {
                            break;
                        }       }
                    // If all resources are available
                    if (j == m) {
                        // Release allocated resources
                        for (int k = 0; k < m; k++) {
                            work[k] += allocation[p][k];
                        }
                        safeSequence.push_back(p);
                        finish[p] = true;
                        found = true;
                        count++;
                    }
                }
            }
            // No process could execute
            if (!found) {
                cout << "\nSystem is NOT in safe state.\n";
                return;
            }
        }
        cout << "\nSystem is in SAFE state.\n";
        cout << "Safe Sequence:\n";

        for (int i = 0; i < n; i++) {

            cout << "P" << safeSequence[i];

            if (i != n - 1) {
                cout << " -> ";
            }     }
        cout << endl;
    }       };

int main() {

    Banker b;

    b.input();

    b.displayNeed();

    b.findSafeSequence();

    return 0;
}
