// // Producer Consumer Problem in simple and easy way

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <pthread.h>

// #define MAX 10

// int buffer[MAX];
// int fill = 0;
// int use = 0;
// int count = 0;

// void put(int value)
// {
//     buffer[fill] = value;
//     fill = (fill + 1) % MAX;
//     count++;
// }

// int get()
// {
//     int tmp = buffer[use];
//     use = (use + 1) % MAX;
//     count--;
//     return tmp;
// }

// void *producer(void *arg)
// {
//     int i;
//     for (i = 0; i < 20; i++)
//     {
//         // print the buffer
//         printf("\nBuffer: ");
//         for (int j = 0; j < MAX; j++)
//         {
//             printf("%d ", buffer[j]);
//         }
//         printf("\n");
//         while (count == MAX)
//             ;
//         put(i);
//     }
// }

// void *consumer(void *arg)
// {
//     int i;
//     for (i = 0; i < 20; i++)
//     {
//         while (count == 0)
//             ;
//         printf("\nGot %d", get());
//     }
// }

// int main()
// {
//     pthread_t p, c;
//     pthread_create(&p, NULL, producer, NULL); // this is used to create a thread, this thread will execute the function producer
//     pthread_create(&c, NULL, consumer, NULL); // this is used to create a thread, this thread will execute the function consumer
//     pthread_join(p, NULL); // this is used to wait for the thread to finish
//     pthread_join(c, NULL); // this is used to wait for the thread to finish
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/wait.h>
// #include <unistd.h>

// // Semaphore variable S
// int S = 1;

// // empty and full variables
// int empty = 10, full = 0;

// // buffer array
// int buffer[10];

// // in and out variables
// int in = 0, out = 0;

// // wait function
// void _wait(int *S)
// {
//     while (*S <= 0)
//         ;
//     *S = *S - 1;
// }

// // signal function
// void _signal(int *S)
// {
//     *S = *S + 1;
// }

// // produce item function
// void produce_item()
// {
//     int item = rand() % 100;
//     printf("\nProduced item: %d", item);
//     // insert item into buffer
//     buffer[in] = item;
//     in = (in + 1) % 10;
// }

// // producer function
// void producer()
// {
//     _wait(&empty);
//     _wait(&S);
//     produce_item();
//     _signal(&S);
//     _signal(&full);
// }

// // consume item function
// void consume_item()
// {
//     int item = buffer[out];
//     printf("\nConsumed item: %d", item);
//     out = (out + 1) % 10;
// }

// // consumer function
// void consumer()
// {
//     _wait(&full);
//     _wait(&S);
//     consume_item();
//     _signal(&S);
//     _signal(&empty);
// }

// int main()
// {
//     int pid = fork();
//     if (pid == 0)
//     {
//         // child process
//         while (1)
//         {
//             producer();
//         }
//     }
//     else
//     {
//         // parent process
//         while (1)
//         {
//             consumer();
//         }
//         _wait(NULL);
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

// Semaphore variable S
int S = 1;

// empty and full variables
int empty = 10, full = 0;

// buffer array
int buffer[10];

// in and out variables
int in = 0, out = 0;

// wait function
void _wait(int *S)
{
    while (*S <= 0)
        ;
    *S = *S - 1;
}

// signal function
void _signal(int *S)
{
    *S = *S + 1;
}

// produce item function
void produce_item()
{
    int item = rand() % 100;
    printf("\nProduced item: %d", item);
    // insert item into buffer
    buffer[in] = item;
    in = (in + 1) % 10;
}

// producer function
void producer()
{
    static int count = 0;
    if (count < 100) {
        _wait(&empty);
        _wait(&S);
        produce_item();
        _signal(&S);
        _signal(&full);
        count++;
    } else {
        exit(0);
    }
}

// consume item function
void consume_item()
{
    int item = buffer[out];
    printf("\nConsumed item: %d", item);
    out = (out + 1) % 10;
}

// consumer function
void consumer()
{
    _wait(&full);
    _wait(&S);
    consume_item();
    _signal(&S);
    _signal(&empty);
}

int main()
{
    // Initialize buffer to 0
    memset(buffer, 0, sizeof(buffer));

    int pid = fork();
    if (pid == 0)
    {
        // child process
        while (1)
        {
            producer();
        }
    }
    else
    {
        // parent process
        while (1)
        {
            consumer();
        }
        wait(NULL);
    }
    return 0;
}
