// Write a program in C++ to solve Producer-Consumer problem using Semaphore

#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

// Shared buffer
int buffer[5];

int in = 0;
int out = 0;

// Semaphores
sem_t empty, full;

// Mutex lock
pthread_mutex_t mutex;

// Producer Function
void* producer(void* arg) {

    for(int i = 1; i <= 5; i++) {

        // Check for empty space
        sem_wait(&empty);

        // Lock buffer
        pthread_mutex_lock(&mutex);

        // Insert item
        buffer[in] = i;

        cout << "Produced: " << i << endl;

        // Move index
        in = (in + 1) % 5;

        // Unlock buffer
        pthread_mutex_unlock(&mutex);

        // Increase full count
        sem_post(&full);

        sleep(1);
    }

    return NULL;
}

// Consumer Function
void* consumer(void* arg) {

    for(int i = 1; i <= 5; i++) {

        // Check for available item
        sem_wait(&full);

        // Lock buffer
        pthread_mutex_lock(&mutex);

        // Remove item
        cout << "Consumed: " << buffer[out] << endl;

        // Move index
        out = (out + 1) % 5;

        // Unlock buffer
        pthread_mutex_unlock(&mutex);

        // Increase empty count
        sem_post(&empty);

        sleep(1);
    }

    return NULL;
}

int main() {

    pthread_t p, c;

    // Initialize semaphores
    sem_init(&empty, 0, 5);
    sem_init(&full, 0, 0);

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    // Wait for completion
    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}