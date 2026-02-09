#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than maxPages
        if (arr[i] > maxPages)
            return 0;

        if (pagesSum + arr[i] <= maxPages) {
            pagesSum += arr[i];
        } else {
            students++;
            pagesSum = arr[i];

            if (students > m)
                return 0;
        }
    }
    return 1;
}

int findMinPages(int arr[], int n, int m) {
    if (m > n)
        return -1; // Not possible

    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int low = max;
    int high = sum;
    int result = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1; // try smaller value
        } else {
            low = mid + 1; // increase limit
        }
    }

    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int ans = findMinPages(arr, n, m);
    printf("%d\n", ans);

    return 0;
}