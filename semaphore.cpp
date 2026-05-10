// Write a program in C++ to solve Producer-Consumer problem using Semaphore 

#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;
#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t emptySlots, fullSlots;   // renamed
pthread_mutex_t mutex;

// Producer function
void* producer(void* arg) {
    for(int i = 0; i < 10; i++) {
        int item = i;

        sem_wait(&emptySlots);
        pthread_mutex_lock(&mutex);

        buffer[in] = item;
        cout << "Produced: " << item << endl;
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&fullSlots);

        sleep(1);
    }
    return NULL;
}

// Consumer function
void* consumer(void* arg) {
    for(int i = 0; i < 10; i++) {

        sem_wait(&fullSlots);
        pthread_mutex_lock(&mutex);

        int item = buffer[out];
        cout << "Consumed: " << item << endl;
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&emptySlots);

        sleep(1);
    }
    return NULL;
}
int main() {
    pthread_t p, c;

    sem_init(&emptySlots, 0, BUFFER_SIZE);
    sem_init(&fullSlots, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    sem_destroy(&emptySlots);
    sem_destroy(&fullSlots);
    pthread_mutex_destroy(&mutex);

    return 0;
}
