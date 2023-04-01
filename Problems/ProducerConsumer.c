// Producer Consumer Problem in simple and easy way

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX 10

int buffer[MAX];
int fill = 0;
int use = 0;
int count = 0;

void put(int value)
{
    buffer[fill] = value;
    fill = (fill + 1) % MAX;
    count++;
}

int get()
{
    int tmp = buffer[use];
    use = (use + 1) % MAX;
    count--;
    return tmp;
}

void *producer(void *arg)
{
    int i;
    for (i = 0; i < 20; i++)
    {
        // print the buffer
        printf("\nBuffer: ");
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", buffer[j]);
        }
        printf("\n");
        while (count == MAX)
            ;
        put(i);
    }
}

void *consumer(void *arg)
{
    int i;
    for (i = 0; i < 20; i++)
    {
        while (count == 0)
            ;
        printf("\nGot %d", get());
    }
}

int main()
{
    pthread_t p, c;
    pthread_create(&p, NULL, producer, NULL); // this is used to create a thread, this thread will execute the function producer
    pthread_create(&c, NULL, consumer, NULL); // this is used to create a thread, this thread will execute the function consumer
    pthread_join(p, NULL); // this is used to wait for the thread to finish
    pthread_join(c, NULL); // this is used to wait for the thread to finish
    return 0;
}