#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int maxSubArraySum(int a[], int size) {
    int max_so_far = a[0];
    int curr_max = a[0];

    for (int i = 1; i < size; i++) {
        curr_max = max(a[i], curr_max + a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

/* Driver program to test maxSubArraySum */
int main()
{
    int a[] = {1, 3, 7, -10, 5, 8};
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    printf("Maximum contiguous sum is %d\n",  max_sum);
    return 0;
}
