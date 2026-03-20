#include <algorithm>
#include <chrono>


int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }
    return mx;
}


void countSortForRadix(int arr[], int n, int exp) {
    int* output = new int[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    delete[] output;
}

std::pair<long long, double> radixSort(int arr[], int n) {
    long long comp = 0;
    auto start = std::chrono::high_resolution_clock::now();
    if (n <= 1) return { 0, 0 };

    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSortForRadix(arr, n, exp);
    }
    std::chrono::duration<double, std::milli> duration = std::chrono::high_resolution_clock::now() - start;

    return { comp, duration.count() };
}