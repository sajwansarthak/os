#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time of P%d: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }

    // Sorting by Burst Time
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (bt[j] > bt[j+1]) {
                int temp = bt[j]; bt[j] = bt[j+1]; bt[j+1] = temp;
                temp = p[j]; p[j] = p[j+1]; p[j+1] = temp;
            }
        }
    }

    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = bt[i-1] + wt[i-1];

    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    printf("\nP\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);

    return 0;
}
