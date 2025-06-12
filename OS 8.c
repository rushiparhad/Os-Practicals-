#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m, i, j, k;
    printf("Enter number of processes and resources: ");
    scanf("%d%d", &n, &m);

    int alloc[n][m], max[n][m], avail[m], need[n][m];
    bool finish[n], safe = true;
    int safeSeq[n];

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Maximum Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for(i = 0; i < n; i++) finish[i] = false;
    int count = 0;

    while(count < n) {
        bool found = false;
        for(i = 0; i < n; i++) {
            if(!finish[i]) {
                for(j = 0; j < m; j++)
                    if(need[i][j] > avail[j])
                        break;

                if(j == m) {
                    for(k = 0; k < m; k++)
                        avail[k] += alloc[i][k];
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if(!found) {
            safe = false;
            break;
        }
    }

    if(safe) {
        printf("Safe Sequence: ");
        for(i = 0; i < n; i++)
            printf("P%d ", safeSeq[i]);
        printf("\n");
    } else {
        printf("System is not in safe state.\n");
    }

    return 0;
}
