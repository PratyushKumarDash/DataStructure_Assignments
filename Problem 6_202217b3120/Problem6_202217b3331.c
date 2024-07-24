#include <stdio.h>

void main() {
    int n, a[10], b[10], t[10], w[10], g[10], i;
    float att = 0, awt = 0;

    // Initialize arrays to zero
    for (i = 0; i < 10; i++) {
        a[i] = 0;
        b[i] = 0;
        w[i] = 0;
        g[i] = 0;
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    printf("Enter the arrival times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    g[0] = a[0]; // The start time of the first process is its arrival time
    for (i = 0; i < n; i++) {
        if (i > 0) {
            g[i] = g[i - 1] + b[i - 1];
            if (g[i] < a[i]) {
                g[i] = a[i];
            }
        }
    }

    for (i = 0; i < n; i++) {
        w[i] = g[i] - a[i];
        t[i] = g[i] + b[i] - a[i];
        awt += w[i];
        att += t[i];
    }

    awt /= n;
    att /= n;

    printf("\n\tProcess\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("\tp%d\t\t%d\t\t%d\n", i, w[i], t[i]);
    }

    printf("The average waiting time is: %.2f\n", awt);
    printf("The average turnaround time is: %.2f\n", att);
}

