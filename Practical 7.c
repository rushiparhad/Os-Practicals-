#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], p[n], pri[n], wt[n], tat[n], temp;
    for(i = 0; i < n; i++) {
        printf("Enter burst time and priority for P%d: ", i+1);
        scanf("%d%d", &bt[i], &pri[i]);
        p[i] = i+1;
    }

    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(pri[i] > pri[j]) {
                temp = pri[i]; pri[i] = pri[j]; pri[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }

    wt[0] = 0;
    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("Process\tPriority\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t\t%d\t%d\t%d\n", p[i], pri[i], bt[i], wt[i], tat[i]);

    return 0;
}
