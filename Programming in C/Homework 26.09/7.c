//. Разгледайте и имплементирайте quicksort алгоритъма

#include <stdio.h>

void quick_sort (int *a, int n) {
    if (n < 2)
        return;
    int p = a[n / 2];
    int *left = a;
    int *right = a + n - 1;
    while (left <= right) {
        if (*left < p) {
            left++;
        }
        else if (*right > p) {
            right--;
        }
        else {
            int temp = *left;
            *left = *right;
            *right = temp;
            left++;
            right--;
        }
    }
    quick_sort(a, right - a + 1);
    quick_sort(left, a + n - left);
}

int main () {
    int a[] = {1,123,8698,234,8,9,345,9,12,5,5};
    int n = sizeof a / sizeof a[0];
    quick_sort(a, n);

    for(int i=0;i<n;i++)
    {
    printf(" %d ", a[i]);
    }
    return 0;
}
