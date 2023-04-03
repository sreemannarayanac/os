#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count = 0;  // Number of items in the buffer
int in = 0;     // Index for next item to be inserted
int out = 0;    // Index for next item to be removed

sem_t mutex;       // Semaphore for mutual exclusion
sem_t empty_slots; // Semaphore for keeping track of empty slots in the buffer
sem_t full_slots;  // Semaphore for keeping track of full slots in the buffer

// Function for producing an item and inserting it into the buffer
void produce(int item) {
    sem_wait(&empty_slots);
    sem_wait(&mutex);

    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
    count++;

    sem_post(&mutex);
    sem_post(&full_slots);
}

// Function for consuming an item from the buffer
int consume() {
    sem_wait(&full_slots);
    sem_wait(&mutex);

    int item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    count--;

    sem_post(&mutex);
    sem_post(&empty_slots);

    return item;
}

int main() {
    int choice;
    int item;

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&empty_slots, 0, BUFFER_SIZE);
    sem_init(&full_slots, 0, 0);

    // Run loop to allow user to produce or consume items
    do {
        printf("\nSelect an option:\n");
        printf("1. Produce item\n");
        printf("2. Consume item\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to produce: ");
                scanf("%d", &item);
                if(count == BUFFER_SIZE) {
                    printf("Buffer is full. Cannot produce more items.\n");
                    break;
                }
                produce(item);
                printf("Produced %d\n", item);
                break;

            case 2:
                if(count == 0) {
                    printf("Buffer is empty. Cannot consume more items.\n");
                    break;
                }
                item = consume();
                printf("Consumed %d\n", item);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    // Clean up semaphores
    sem_destroy(&mutex);
    sem_destroy(&empty_slots);
    sem_destroy(&full_slots);

    return 0;
}
