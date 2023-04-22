#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 1000 // Define a constant MAX with value 1000

int main()
{
    int n, head, i, j, k, pos, total=0, temp, m;
    int q[MAX]; // Declare an array to hold requests
    float avg;

    printf("Enter the number of requests: ");
    scanf("%d",&n);

    printf("Enter the requests in order: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&q[i]); // Read in the requests
    }

    printf("Enter the initial head position: ");
    scanf("%d",&head); // Read in the initial head position

    q[n] = head; // Add the initial head position to the end of the request queue
    n++; // Increment the number of requests

    // Sort the requests in ascending order
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(q[i]>q[j])
            {
                temp = q[i];
                q[i] = q[j];
                q[j] = temp;
            }
        }
    }

    // Find the position of the initial head in the sorted request queue
    for(i=0;i<n;i++)
    {
        if(q[i]==head)
        {
            pos = i;
            break;
        }
    }

    // If the initial head position is less than or equal to 100, scan from the initial head position to the end of the request queue and then reverse direction and scan back to the beginning
    if(head<=100)
    {
        for(i=pos;i>=0;i--)
        {
            printf("%d ",q[i]); // Print the requests being scanned
        }
        printf("0 "); // Print the track 0
        for(i=pos+1;i<n;i++)
        {
            printf("%d ",q[i]); // Print the requests being scanned
        }
    }
    // If the initial head position is greater than 100, scan from the initial head position to the beginning of the request queue and then reverse direction and scan back to the end
    else
    {
        for(i=pos;i<n;i++)
        {
            printf("%d ",q[i]); // Print the requests being scanned
        }
        printf("200 "); // Print track 200
        for(i=pos-1;i>=0;i--)
        {
            printf("%d ",q[i]); // Print the requests being scanned
        }
    }

    // Calculate the total seek time by adding the distance between each request and the previous request in the order they were scanned
    total = head + q[n-2];

    for(i=n-2;i>0;i--)
    {
        total += abs(q[i]-q[i-1]);
    }

    // Print the total seek time and average seek time
    printf("\nTotal seek time: %d",total);
    avg = (float)total/(n-1);
    printf("\nAverage seek time: %.3f\n",avg);

    return 0;
}