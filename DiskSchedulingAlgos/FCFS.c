#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int n, head, i, total=0;
    float avg;

    printf("Enter the number of requests: ");
    scanf("%d",&n);

    int req[n];

    printf("Enter the requests in order: ");
    for(i=0;i<n;i++)
        scanf("%d",&req[i]);

    printf("Enter the current head position: ");
    scanf("%d",&head);

    total = abs(head-req[0]);
    for(i=0;i<n-1;i++)
        total += abs(req[i]-req[i+1]);

    printf("\nTotal seek time: %d\n",total);
    avg = (float)total/n;
    printf("\nAverage seek time: %.3f\n",avg);

    return 0;
}