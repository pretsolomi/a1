// Write a C++ program to solve Producer Consumer Problem using Semaphore

#include <iostream>
#include <cstdlib>

using namespace std;

int mutex1 = 1;
int full = 0;
int empty = 3;
int x = 0;

// Wait function
int wait(int s)
{
    return (--s);
}

// Signal function
int signal(int s)
{
    return (++s);
}

// Producer function
void producer()
{
    mutex1 = wait(mutex1);

    full = signal(full);
    empty = wait(empty);

    x++;

    cout << "\nProducer produces item " << x;

    mutex1 = signal(mutex1);
}

// Consumer function
void consumer()
{
    mutex1 = wait(mutex1);

    full = wait(full);
    empty = signal(empty);

    cout << "\nConsumer consumes item " << x;

    x--;

    mutex1 = signal(mutex1);
}

int main()
{
    int choice;

    while (1)
    {
        cout << "\n\n1. Produce";
        cout << "\n2. Consume";
        cout << "\n3. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                if ((mutex1 == 1) && (empty != 0))
                    producer();
                else
                    cout << "\nBuffer Full!";
                break;

            case 2:
                if ((mutex1 == 1) && (full != 0))
                    consumer();
                else
                    cout << "\nBuffer Empty!";
                break;

            case 3:
                exit(0);

            default:
                cout << "\nInvalid Choice!";
        }
    }

    return 0;
}